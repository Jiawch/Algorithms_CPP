/*! Author: qwchen
 *! Date: 2016-9-14
 * ��ͷ����˫��ѭ������
 */

#ifndef circularListWithHeader_
#define circularListWithHeader_

#include <iostream>
#include <sstream>

using namespace std;

// ˫����
template <class T>
struct circularListNode {
    T element;                        // ���Ԫ��
    circularListNode<T> *previous;    // ǰ��ָ��
    circularListNode<T> *next;        // ����ָ��

    circularListNode() {}
    circularListNode(T theElement) {
        this->element = theElement;
    }
};

// ��ͷ����˫��ѭ������
template <class T>
class circularListWithHeader {
public:
    circularListWithHeader();                                    // ���캯��
    circularListWithHeader(const circularListWithHeader<T> &);   // �������캯��
    ~circularListWithHeader();                                   // ��������
    
    bool empty() const;                             // �ж��б��Ƿ�Ϊ��
    int size() const;                               // ��������Ԫ�صĸ���
    T& get(int theIndex) const;                     // ��������ΪtheIndex��Ԫ��
    int indexOf(const T &theElement) const;         // ����Ԫ��theElement��һ�γ���ʱ������
    void erase(int theIndex);                       // ɾ������ΪtheIndex��Ԫ��
    void insert(int theIndex, const T &theElement); // ��theElement�������Ա�������ΪtheIndex��λ����
    void output(ostream &out) const;                // �����Ա���뵽�����

private:
    void checkIndex(int theIndex) const;            // �������theIndexʹ�úϸ�, 0 < theIndex < m_iSize
    circularListNode<T> *firstNode;                 // ͷ���
    int m_iSize;
};

template <class T>
circularListWithHeader<T>::circularListWithHeader() { //���캯��
    firstNode = new circularListNode<T>();
    firstNode->previous = firstNode;
    firstNode->next = firstNode;
    m_iSize = 0;
}

template <class T>
circularListWithHeader<T>::circularListWithHeader(const circularListWithHeader<T>& theList) {    //�������캯��
    m_iSize = theList.m_iSize;
    if (m_iSize == 0) { //����Ϊ0�Ļ�����ֻ����ͷ���
        firstNode = new circularListNode<T>();
        firstNode->previous = firstNode;
        firstNode->next = firstNode;
        return;
    }
    // ����Ŀ�����
    // theList.firstNodeָ��Դ�����ͷ��㣬firstNodeָ��Ŀ������ͷ���
    // sourceNodeָ��Դ����ĵ�ǰԪ�أ�targetNodeָ��Ŀ������ĵ�ǰԪ��
    circularListNode<T> *sourceNode = theList.firstNode->next; //source�����п��ƶ���ָ��
    firstNode = new circularListNode<T>();
    circularListNode<T> *targetNode = new circularListNode<T>(sourceNode->element); //targe�����п��ƶ���ָ��
    firstNode->next = targetNode;
    targetNode->previous = firstNode;
    sourceNode = sourceNode->next;
    while (sourceNode != theList.firstNode){
        targetNode->next = new circularListNode<T>(sourceNode->element);
        targetNode->next->previous = targetNode;
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = firstNode;
    firstNode->previous = targetNode;
}

template <class T>
circularListWithHeader<T>::~circularListWithHeader() {
    // �ȶϿ�ѭ�����������һ������nextָ����ΪNULL
    firstNode->previous->next = NULL;    // ���ص㡿������һ�л��ڴ�й¶�������޷�����
    while (firstNode != NULL){
        circularListNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
void circularListWithHeader<T>::checkIndex(int theIndex) const { //�������theIndexʹ�úϸ�, 0 < theIndex < m_iSize
    if (theIndex < 0 || theIndex >= m_iSize) {
        stringstream s;
        s << "Invalid Argument : index = " << theIndex << " size = " << m_iSize << endl;
        throw invalid_argument(s.str());
    }
}

template <class T>
bool circularListWithHeader<T>::empty() const { 
    return m_iSize == 0; 
}

template <class T>
int circularListWithHeader<T>::size() const { 
    return m_iSize; 
}

template <class T>
T& circularListWithHeader<T>::get(int theIndex) const { //��������ΪtheIndex��Ԫ��
    checkIndex(theIndex);
    circularListNode<T> *currentNode = firstNode->next;
    for (int i = 0; i < theIndex; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template <class T>
int circularListWithHeader<T>::indexOf(const T &theElement) const { //����Ԫ��theElement��һ�γ���ʱ������
	// ��ͷ��������Ҫ���ҵ�Ԫ�أ����׽ڵ㿪ʼ���в��ң���������ҵ���λ������ͷ��㣬˵�������в����ڸ�Ԫ��
    firstNode->element = theElement;
    int index = 0;
    circularListNode<T> *currentNode = firstNode->next;
    while (currentNode->element != theElement) {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == firstNode) {
        //firstNode->element = NULL;
        return -1;
    }
    else {
        //firstNode->element = NULL;
        return index;
    }
}

template <class T>
void circularListWithHeader<T>::erase(int theIndex) {    //ɾ������ΪtheIndex��Ԫ��
    checkIndex(theIndex);
    circularListNode<T> *currentNode = firstNode;    //ɾ���׽ڵ�Ҳ�������⴦��
    for (int i = 0; i < theIndex; i++) { //�ҵ�Ҫɾ���Ľ���ǰһ�����
        currentNode = currentNode->next;
    }
    circularListNode<T> *deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    deleteNode->next->previous = deleteNode->previous;
    delete deleteNode;
    m_iSize--;
}

template <class T>
void circularListWithHeader<T>::insert(int theIndex, const T &theElement) { //��theElement�������Ա�������ΪtheIndex��λ����
    if (theIndex < 0 || theIndex > m_iSize) {
        stringstream s;
        s << "Invalid Argument : index = " << theIndex << " size = " << m_iSize << endl;
        throw invalid_argument(s.str());
    }
    circularListNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++) { //�ҵ�Ҫɾ���Ľ���ǰһ�����
        currentNode = currentNode->next;
    }
    circularListNode<T> *newNode = new circularListNode<T>(theElement);
    newNode->previous = currentNode;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    newNode->next->previous = newNode;
    m_iSize++;
}

template <class T>
void circularListWithHeader<T>::output(ostream &out) const { //�����Ա���뵽�����
    for (circularListNode<T> *currentNode = firstNode->next; currentNode != firstNode; currentNode = currentNode->next) {
        out << currentNode->element << " ";
    }
}

template <class T>
ostream& operator<<(ostream& out, const circularListWithHeader<T> theList) {
    theList.output(out);
    return out;
}
#endif // !circularListWithHeader_

