/*! Author: qwchen
 *! Date: 2016-9-18
 * ��������ʵ�ֵ�ջ
 */

#ifndef linkedStack_
#define linkedStack_

#include <sstream>
#include "stack.h"

using namespace std;

template <class T>
struct chainNode{
    T element;
    chainNode *next;
    chainNode(T theElem){
        element = theElem;
    }
};

template <class T>
class linkedStack: public stack<T> {
public:
    linkedStack();
    ~linkedStack();
    bool empty() const;           // ��ջΪ��ʱ����true
    int size() const;             // ����ջ��Ԫ�صĸ���
    T& top() const;               // ����ջ��Ԫ�ص�����
    void pop();                   // ɾ��ջ��Ԫ��
    void push(const T& theElem);  // ��Ԫ��theElemѹ��ջ��
private:
    chainNode<T>* stackTop;       // ջ������ͷ���ĵ�������ͷָ��Ϊջ��ָ��
    int stackSize;                // ջ��С
};

template <class T>
linkedStack<T>::linkedStack(){
    stackTop = NULL;
    stackSize = 0;
}

template <class T>
linkedStack<T>::~linkedStack(){
    chainNode<T>* currentNode = stackTop;
    while (stackTop != NULL) {
        currentNode = stackTop->next;
        delete stackTop;
        stackTop = currentNode;
    }
}

template <class T>
bool linkedStack<T>::empty() const {
    return stackSize == 0;
}

template <class T>
int linkedStack<T>::size() const {
    return stackSize;
}

template <class T>
T& linkedStack<T>::top() const {
    if (empty()) {
        stringstream s;
        s << "Stack is empty" << endl;
        throw range_error(s.str());
    }
    return stackTop->element;
}

template <class T>
void linkedStack<T>::pop() {
    if (empty()) {
        stringstream s;
        s << "Stack is empty" << endl;
        throw range_error(s.str());
    }
    chainNode<T> *deleteNode = stackTop;
    stackTop = stackTop->next;
    delete deleteNode;
    deleteNode = NULL;
    stackSize--;
}

template <class T>
void linkedStack<T>::push(const T& theElem) {
    chainNode<T> *newNode = new chainNode<T>(theElem);
    newNode->next = stackTop;
    stackTop = newNode;
    stackSize++;
}

#endif // !linkedStack_