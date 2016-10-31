/*! Author: qwchen
 *! Date: 2016-9-24
 * 
 * ��������
 */

#include <iostream>
#include <sstream>
#include "dictionary.h"

using namespace std;

// ��������Ľ��(element(pair<key, value>), next)
template <class K, class E>
struct pairNode {
    typedef pair<const K, E> pairType;
    pairType element;
    pairNode *next;
    
    pairNode(const pairType &thePair):element(thePair) { 
        next = NULL; 
    }
    pairNode(const pairType &thePair, pairNode<K, E> *theNext):element(thePair) {
        next = theNext;
    }
};


// ��������
template <class K, class E>
class sortedChain : public dictionary<K, E> {
public:
    sortedChain();
    ~sortedChain();
    bool empty() const { return dSize == 0; }  // ���ֵ�Ϊ��ʱ������true
    int size() const { return dSize; }         // �����ֵ������Ե���Ŀ
    pair<const K, E>* find(const K&) const;    // ����ƥ�����Ե�ָ��
    void erase(const K&);                      // ɾ��ƥ�������
    void insert(const pair<const K, E>&);      // ���ֵ��в���һ������
    void output(ostream& out) const;
private:
    pairNode<K, E> *firstNode;
    int dSize;
};

template<class K, class E>
sortedChain<K, E>::sortedChain() {
    firstNode = NULL;
    dSize = 0;
}

template<class K, class E>
sortedChain<K, E>::~sortedChain() {
    pairNode<K, E> *deleteNode;
    while (firstNode != NULL) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
        delete deleteNode;
    }
    deleteNode = NULL;
    firstNode = NULL;
}

template<class K, class E>
pair<const K, E>* sortedChain<K, E>::find(const K& theKey) const {
    pairNode<K, E> *p = firstNode;
    while (p != NULL && p->element.first != theKey) {
        p = p->next;
    }
    if (p != NULL && p->element.first == theKey)
        return &p->element;
    return NULL;
}

template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey) {
    pairNode<K, E> *p = firstNode;
    pairNode<K, E> *tp = NULL;
    while (p!=NULL && p->element.first != theKey) {
        tp = p;
        p = p->next;
    }
    if (p != NULL && p->element.first == theKey) {
        if (tp == NULL) firstNode = firstNode->next;
        else tp->next = p->next;
        delete p;
        dSize--;
    }
    p = NULL;
    tp = NULL;
}

template <class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair) {
    pairNode<K, E> *p = firstNode;
    pairNode<K, E> *tp = NULL;
    while (p != NULL && p->element.first < thePair.first) {
        tp = p;
        p = p->next;
    }
    if (p != NULL && p->element.first == thePair.first) {
        p->element.second = thePair.second;
    }
    else {
        pairNode<K, E> *newNode = new pairNode<K, E>(thePair, p);
        if (tp == NULL) firstNode = newNode;
        else tp->next = newNode;
        dSize++;
        newNode = NULL;
    }
    p = NULL;
    tp = NULL;
}

template <class K, class E>
void sortedChain<K, E>::output(ostream &out) const {
    for (pairNode<K, E> *p = firstNode; p != NULL; p = p->next) {
        out << p->element.first << " : " << p->element.second << endl;
    }
}

template <class K, class E>
ostream& operator<<(ostream& out, sortedChain<K, E> &x) {
    x.output(out);
    return out;
}

