/*! Author: qwchen
 *! Date: 2016-9-21
 * 
 * ������ʵ�ֵĶ��У���ͷ����ѭ�����У�
 * ͷָ��ָ��ͷ��㣬����һ��Ԫ�ص�ǰһ�����
 * βָ��ָ�����һ��Ԫ��
 */

#ifndef arrayQueue_
#define arrayQueue_

#include <sstream>
#include <iostream>
#include <algorithm>
#include "queue.h"

using namespace std;

template <class T>
class arrayQueue : public queue<T> {
public:
    arrayQueue(int capacity = 10);
    ~arrayQueue();
    bool empty() const;            // ������Ϊ��ʱ������true
    int size() const;              // ���ض�����Ԫ�صĸ�����ע�⣺��Ԫ�ظ���������������
    T& front();                    // ����ͷԪ�ص�����
    T& back();                     // ����βԪ�ص�����
    void pop();                    // ɾ����Ԫ��
    void push(const T &theElem);   // ��Ԫ��theElem�����β
private:
    T *queue;          // ����洢����
    int arrayLength;   // ���е�������ע�⣺����Ԫ�ظ�������������
    int theFront;      // ��Ԫ��
    int theBack;       // βԪ��
};

template <class T>
arrayQueue<T>::arrayQueue(int capacity) {
    if (capacity <= 0) {
        stringstream s;
        s << "capacity must be > 0" << endl;
        throw invalid_argument(s.str());
    }
    queue = new T[capacity];
    arrayLength = capacity;
    theFront = theBack = 0;
}

template <class T>
arrayQueue<T>::~arrayQueue() {
    delete []queue;
    queue = NULL;
}

template <class T>
bool arrayQueue<T>::empty() const {
    return theFront == theBack;
}

template <class T>
int arrayQueue<T>::size() const {
    return (theBack - theFront + arrayLength) % arrayLength;
}

template <class T>
T& arrayQueue<T>::front() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    return queue[(theFront + 1) % arrayLength];
}

template <class T>
T& arrayQueue<T>::back() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    return queue[theBack];
}

template <class T>
void arrayQueue<T>::pop() {
    if (empty()) {
        stringstream s;
        s << "Queue is empty" << endl;
        throw range_error(s.str());
    }
    theFront = (theFront + 1) % arrayLength;
    queue[theFront].~T();
}

template <class T>
void arrayQueue<T>::push(const T &theElem) {
    // ����������������������ݳ���
    if ((theBack + 1) % arrayLength == theFront) {
        T* newQueue = new T[2 * arrayLength];
        if (theFront == 0) {
            copy(queue, queue + arrayLength, newQueue);
        }
        else { // �������������Գ���theFront=0ʱ�������ܳ���theFront��theBackǰ���������
            copy(queue + theFront, queue + arrayLength, newQueue);
            copy(queue, queue + theBack + 1, newQueue + arrayLength - theFront);
        }
        theFront = 0;
        theBack = arrayLength - 1;
        queue = newQueue;
        arrayLength *= 2;
    }
    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElem;
}

#endif // !arrayQueue_
