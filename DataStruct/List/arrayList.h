/*! Author: qwchen
 *! Date: 2016-9-14
 * ���Ա����������
 */

#ifndef arrayList_
#define arrayList_

#include <iostream>
#include <sstream>
#include <algorithm>
#include "linearList.h"

using namespace std;

template <class T>
class arrayList : public linearList<T> {
public:
    arrayList(int capacity = 10);         // ���캯��
    arrayList(const arrayList<T> &);      // �������캯��
    ~arrayList();                         // ��������

    bool empty() const;                   // ���ص����Ա�Ϊ��ʱ������true 
    int size() const;                     // �������Ա�Ԫ�صĸ���
    int capacity() const;                 // �������Ա�����
    T& get(int theIndex) const;           // ��������ΪtheIndex��Ԫ��
    int indexOf(const T &theElem) const;  // ����Ԫ��theElement��һ�γ���ʱ������
    void erase(int theIndex);             // ɾ������ΪtheIndex��Ԫ��
    void insert(int theIndex, const T &theElem);  // ��theElement�������Ա�������ΪtheIndex��λ����
    void output(ostream &out) const;      // �����Ա���뵽�����

private:
	bool full() const;                    // �����Ա���������ʱ�򣬷���true
    T *m_pBuffer;       // �洢���Ա�Ԫ�ص�һά����
    int m_iCapacity;    // һά���������
    int m_iSize;        // ���Ա�Ԫ�ظ���
};


template <class T>
arrayList<T>::arrayList(int capacity) {
    if (capacity < 1) {
        stringstream s;
        s << "illegal parameter:  Initial capacity = " << capacity << " Must be > 0";
        throw invalid_argument(s.str());
    }
    m_pBuffer = new T[capacity];
    m_iCapacity = capacity;
    m_iSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList) {
    m_iCapacity = theList.m_iCapacity;
    m_iSize = theList.m_iSize;
    m_pBuffer = new T[m_iCapacity];
    copy(theList.m_pBuffer, theList.m_pBuffer + m_iCapacity, m_pBuffer);
}

template <class T>
arrayList<T>::~arrayList() {
    delete []m_pBuffer;
}


template <class T>
bool arrayList<T>::empty() const {
    return m_iSize == 0;
}

template <class T>
bool arrayList<T>::full() const { 
    return m_iSize == m_iCapacity; 
}

template <class T>
int arrayList<T>::size() const { 
    return m_iSize; 
}

template <class T>
int arrayList<T>::capacity() const { 
    return m_iCapacity; 
}

template <class T>
T& arrayList<T>::get(int theIndex) const {
    if (theIndex < 0 || theIndex >= m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize;
        throw invalid_argument(s.str());
    }
    return m_pBuffer[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T &theElem) const {
    for (int i = 0; i < m_iSize; i++){
        if (m_pBuffer[i] == theElem){
            return i;
        }
    }
    return -1;   // �Ҳ���
}

template <class T>
void arrayList<T>::erase(int theIndex) {
    if (theIndex < 0 || theIndex >= m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize;
        throw invalid_argument(s.str());
    }
    copy(m_pBuffer + theIndex + 1, m_pBuffer + m_iSize, m_pBuffer + theIndex);
    m_pBuffer[--m_iSize].~T();
}

template <class T>
void arrayList<T>::insert(int theIndex, const T& theElem) {
    if (theIndex < 0 || theIndex > m_iSize) {
        stringstream s;
        s << "index = " << theIndex << " size = " << m_iSize;
        throw invalid_argument(s.str());
    }
    if (full()) {
    	// �������С�ӱ�
        T *tmp = new T[2 * m_iCapacity];
        copy(m_pBuffer, m_pBuffer + m_iCapacity, tmp);
        delete m_pBuffer;
        m_pBuffer = tmp;
        tmp = NULL;
        m_iCapacity *= 2;
    }
    copy_backward(m_pBuffer + theIndex, m_pBuffer + m_iSize, m_pBuffer + m_iSize + 1);
    m_pBuffer[theIndex] = theElem;
    m_iSize++;
}

template <class T>
void arrayList<T>::output(ostream &out) const {
    for (int i = 0; i < m_iSize; i++){
        out << m_pBuffer[i] << " ";
    }
}

template <class T>
ostream& operator<<(ostream& out, const arrayList<T> &x) {
    x.output(out);
    return out;
}

#endif
