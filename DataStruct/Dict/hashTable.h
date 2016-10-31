/*! Author: qwchen
 *! Date: 2016-9-24
 * 
 * ����̽��Ĺ�ϣ��
 */

#ifndef hashTable_
#define hashTable_

#include <sstream>
#include <iostream>

using namespace std;

template <class K, class E>
class hashTable {
public:
    hashTable(int theDivisor = 11);
    ~hashTable();
    bool empty() const;                      // ���ֵ�Ϊ��ʱ������true
    int size() const;                        // �����ֵ������Ե���Ŀ
    pair<const K, E>* find(const K&) const;  // ����ƥ�����Ե�ָ��
    void insert(const pair<const K, E>&);    // ���ֵ��в���һ������
    void erase(const K&) {}                  // ɾ��ƥ�������(û��ʵ��)
    void output(ostream &out) const;

private:
    int search(const K&) const;
    pair<const K, E> **table;  // ��ϣ��
    int dSize;                 // Ԫ�ظ���
    int diviosr;               // Ͱ�ĸ���
    hash<K> hash;              // STL�Ĺ�ϣ���� 
};

template <class K, class E>
hashTable<K, E>::hashTable(int theDivisor) {
    if (theDivisor <= 0) {
        stringstream s;
        s << "Divisor must be > 0" << endl;
        throw invalid_argument(s.str());
    }
    dSize = 0;
    diviosr = theDivisor;
    table = new pair<const K, E>*[diviosr];
    for (int i = 0; i < diviosr; i++) {
        table[i] = NULL;
    }
}

template <class K, class E>
hashTable<K, E>::~hashTable() { 
    delete []table; 
}

template <class K, class E>
bool hashTable<K, E>::empty() const {
    return dSize == 0;
}

template <class K, class E>
int hashTable<K, E>::size() const {
    return dSize;
}

template <class K, class E>
int hashTable<K, E>::search(const K& theKey) const {
    int i = (int)hash(theKey) % diviosr;
    int j = i;
    do {
        if (table[j] == NULL || table[j]->first == theKey)    // �ҵ�ΪNULL�����ҵ�ȷ��ֵ
            return j;
        j = (j + 1) % diviosr;
    } while (i == j);
    return j;    // ɢ�б���
}

template <class K, class E>
pair<const K, E>* hashTable<K, E>::find(const K& theKey) const {
    int i = search(theKey);
    if (table[i] == NULL || table[i]->first != theKey)    // �Ҳ�������ɢ�б���
        return NULL;
    return table[i];    // �ҵ���
}

template <class K, class E>
void hashTable<K, E>::insert(const pair<const K, E>& thePair) {
    int i = search(thePair.first);
    if (table[i] == NULL) {    // �Ҳ�������NULL��ֱ�Ӳ���
        table[i] = new pair<const K, E>(thePair);
        dSize++;
    }
    else {
        if (table[i]->first == thePair.first) {    // �ҵ��ˣ��滻
            table[i]->second = thePair.second;
        }
        else {    // ɢ�б��������쳣
            stringstream s;
            s << "hashTable have already full." << endl;
            throw range_error(s.str());
        }
    }
}

template <class K, class E>
void hashTable<K, E>::output(ostream& out) const {
    for (int i = 0; i < diviosr; i++) {
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else
            cout << table[i]->first << " : " << table[i]->second << endl;
    }
}

template <class K, class E>
ostream& operator<<(ostream &out, const hashTable<K, E> &x) {
    x.output(out);
    return out;
}
#endif // !hashTable_




