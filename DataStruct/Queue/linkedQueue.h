/*! Author: qwchen
 *! Date: 2016-9-21
 * 
 * ��������ʵ�ֵĶ���Queue��û��ͷ���
 */

#ifndef linkedQueue_
#define linkedQueue_

#include <sstream>
#include "Queue.h"

using namespace std;

// ������
template <class T>
struct chainNode {
    T element;
    chainNode *next;
    chainNode(T theElem){
        element = theElem;
    }
};

template <class T>
class linkedQueue : public queue<T> {
public:
    linkedQueue();
    ~linkedQueue();
    bool empty() const;           // ������Ϊ��ʱ������true
    int size() const;             // ���ض�����Ԫ�صĸ�����ע�⣺��Ԫ�ظ���������������
    T& front();                   // ����ͷԪ�ص�����
    T& back();                    // ����βԪ�ص�����
    void pop();                   // ɾ����Ԫ��
    void push(const T &theElem);  // ��Ԫ��theElem�����β
private:
    chainNode<T> *queueFront;
    chainNode<T> *queueBack;
    int queueSize;
};

template <class T>
linkedQueue<T>::linkedQueue() {
    queueFront = NULL;
    queueBack = NULL;
    queueSize = 0;
}

template <class T>
linkedQueue<T>::~linkedQueue() {
    while (!queueFront) {
        queueBack = queueFront->next;
        delete queueFront;
        queueFront = queueBack;
    }
}

template <class T>
bool linkedQueue<T>::empty() const {
    return queueSize == 0;
}

template <class T>
int linkedQueue<T>::size() const {
    return queueSize;
}

template <class T>
T& linkedQueue<T>::front() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    return queueFront->element;
}

template <class T>
T& linkedQueue<T>::back() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    return queueBack->element;
}

template <class T>
void linkedQueue<T>::pop() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    chainNode<T> *deleteNode = queueFront;
    queueFront = queueFront->next;
    delete deleteNode;
    deleteNode = NULL;
    queueSize--;
}

template <class T>
void linkedQueue<T>::push(const T &theElem) {
    chainNode<T> *newNode = new chainNode<T>(theElem);
    if (empty()) {
        queueFront = queueBack = newNode;
    }
    else {
        queueBack->next = newNode;
        queueBack = newNode;
    }
    queueSize++;
}

#endif // !linkedQueue_
