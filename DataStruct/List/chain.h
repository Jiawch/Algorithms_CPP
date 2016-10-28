/*! Author: qwchen
 *! Date: 2016-9-14
 * ���Ա����������
 */

#ifndef chain_
#define chain_

#include <iostream>
#include <sstream>
#include "linearList.h"

using namespace std;

// ������
template <class T>
struct chainNode {
    T element;          // ����Ԫ��
    chainNode<T> *next; // �����nextָ��

    chainNode(){}
    chainNode(const T& element){
        this->element = element;
        this->next = NULL;
    }
    chainNode(const T& element, chainNode<T>* next){
        this->element = element;
        this->next = next;
    }
};

// ����
template <class T>
class chain : public linearList<T> {
public:
    chain();                  // ���캯��
    chain(const chain<T> &);  // �������캯��
    ~chain();                 // ��������

    bool empty() const;                     // ���ص�����Ϊ��ʱ������true
    int size() const;                       // ��������Ԫ�صĸ���
    int capacity() const;                   // û�ã�ֻ��Ϊ��ʵ�ֳ�����linearList�ķ���
    T& get(int theIndex) const;             // ��������ΪtheIndex��Ԫ��
    int indexOf(const T &theElement) const;    // ����Ԫ��theElement��һ�γ���ʱ������
    void erase(int theIndex);               // ɾ������ΪtheIndex��Ԫ��
    void insert(int theIndex, const T &theElement);    // ��theElement�������Ա�������ΪtheIndex��λ����
    void output(ostream &out) const;        // �����Ա���뵽�����

private:
    chainNode<T> *firstNode;    // ͷָ�룬ָ���б�ĵ�һ�����
    int m_iSize;
};

template <class T>
chain<T>::chain() {
    firstNode = NULL;
    m_iSize = 0;
}

template <class T>
chain<T>::chain(const chain<T> &theList) {
    m_iSize = theList.m_iSize;
    if (m_iSize == 0) { //���Ǳ߽�ֵ����ԭ��������Ϊ��
        firstNode = NULL;
        return;
    }
    // ����Ŀ�����
    // theList.firstNodeָ��Դ����firstNodeָ��Ŀ������
    // sourceNodeָ��Դ����ĵ�ǰԪ�أ�targetNodeָ��Ŀ������ĵ�ǰԪ��
    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    chainNode<T> *targetNode = firstNode;
    sourceNode = sourceNode->next;
    while (sourceNode != NULL) {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template <class T>
chain<T>::~chain() {
    while (firstNode != NULL) {
        // chainNode<T> *nextNode = firstNode;  ����д���ʹ������ڴ�й¶
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
bool chain<T>::empty() const{ 
    return m_iSize == 0; 
}

template <class T>
int chain<T>::size() const { 
    return m_iSize;  
}

template <class T>
int chain<T>::capacity() const { 
    return m_iSize; 
}

template <class T>
T& chain<T>::get(int theIndex) const {
    if (theIndex < 0 || theIndex >= m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize << endl;
        throw invalid_argument(s.str());
    }
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template <class T>
int chain<T>::indexOf(const T &theElement) const {
    chainNode<T> *currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement) {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL) return -1;
    else return index;
}

template <class T>
void chain<T>::erase(int theIndex) {
    if (theIndex < 0 || theIndex >= m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize << endl;
        throw invalid_argument(s.str());
    }
    chainNode<T> *deleteNode;
    // ����û��ͷ��������Ҫע��ɾ��λ���ǲ����׽��
    if (0 == theIndex) { // ���ɾ�������׽ڵ�
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T> *currentNode = firstNode;
        for (int i = 0; i < theIndex - 1; i++) {
            currentNode = currentNode->next;
        }
        deleteNode = currentNode->next;
        currentNode->next = currentNode->next->next;
    }
    delete deleteNode;
    m_iSize--;
}

template <class T>
void chain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize;
        throw invalid_argument(s.str());
    }
    chainNode<T> *insertNode = new chainNode<T>(theElement);
    // ����û��ͷ��������Ҫע�����λ���ǲ����׽��
    if (0 == theIndex) { // ��������׽ڵ����
        insertNode->next = firstNode;
        firstNode = insertNode;
    } else { // ����������׽ڵ����
        chainNode<T> *currentNode = firstNode;
        for (int i = 0; i < theIndex - 1; i++) {
            currentNode = currentNode->next;
        }
        insertNode->next = currentNode->next;
        currentNode -> next = insertNode;
    }
    m_iSize++;  // ע�������
}

template <class T>
void chain<T>::output(ostream &out) const {
    for (chainNode<T> *currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next) {
        out << currentNode->element << " ";
    }
}

template <class T>
ostream& operator<<(ostream& out, const chain<T> &x) {
    x.output(out);
    return out;
}

#endif // !chain_
