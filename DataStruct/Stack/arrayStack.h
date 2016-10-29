/*! Author: qwchen
 *! Date: 2016-9-18
 * ��������ʵ�ֵ�ջstack
 */

#ifndef arrayStack_
#define arrayStack_

#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;

template <class T>
class arrayStack : public stack<T> {
public:
    arrayStack(int initCapacity = 10);
    ~arrayStack();
    bool empty() const;           // ��ջΪ��ʱ����true
    int size() const;             // ����ջ��Ԫ�صĸ���
    T& top() const;               // ����ջ��Ԫ�ص�����
    void pop();                   // ɾ��ջ��Ԫ��
    void push(const T& theElem);  // ��Ԫ��theElemѹ��ջ��
private:
    T *stack;         // Ԫ������
    int stackTop;     // ջ����ָ��ջ��Ԫ�أ���ʼΪ-1
    int arrayLength;  // ջ������
};

template <class T>
arrayStack<T>::arrayStack(int initCapacity) {
    if (initCapacity < 0) {
        stringstream s;
        s << "initCapacity must be > 0" << endl;
        throw invalid_argument(s.str());
    }
    arrayLength = initCapacity;
    stackTop = -1;
    stack = new T[arrayLength];
}

template <class T>
arrayStack<T>::~arrayStack() {
    delete []stack;
}


template <class T>
bool arrayStack<T>::empty() const {
    return stackTop == -1;
}


template <class T>
int arrayStack<T>::size() const {
    return stackTop + 1;
}

template <class T>
T& arrayStack<T>::top() const {
    if (empty()) {
        stringstream s;
        s << "Stack is empty" << endl;
        throw range_error(s.str());
    }
    return stack[stackTop];
}

template <class T>
void arrayStack<T>::pop() {
    if (empty()) {
        stringstream s;
        s << "Stack is empty" << endl;
        throw range_error(s.str());
    }
    stack[stackTop--].~T();        // �ص�,new�����Ķ�������
}

template <class T>
void arrayStack<T>::push(const T& theElem) {
    // �����Ѿ�������������������Ϊ����
    if (stackTop + 1 == arrayLength) {
        T *tmp = new T[2 * arrayLength];
        for (int i = 0; i < arrayLength; i++){
            tmp[i] = stack[i];
        }
        delete []stack;
        stack = tmp;
        arrayLength *= 2;
    }
    stack[++stackTop] = theElem;
}


#endif // !arrayStack_
