/*! Author: qwchen
 *! Date: 2016-9-28
 * ������ʵ�ֵ�С���ѣ� �����±�0���ã����±�1��ʼ
 */

#ifndef minHeap_
#define minHeap_

#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "heap.h"

using namespace std;

template <class T>
class minHeap: public heap<T> {
public:
    minHeap(int capacity = 10) {
        if (capacity < 2) {
            stringstream s;
            s << "capacity must be > 2";
            throw invalid_argument(s.str());
        }
        heap = new T[capacity];
        arrayLength = capacity;
        heapSize = 0;
    }
    ~minHeap() { delete[]heap; }
    bool empty() const {  // ����true�����ҽ�������Ϊ��
        return heapSize == 0;
    }
    int size() const {    // ���ض��е�Ԫ�ظ���
        return heapSize;
    }
    const T& top() {      // �������ȼ�����Ԫ�ص�����
        if (empty()) {
            stringstream s;
            s << "heap is empty." << endl;
            throw range_error(s.str());
        }
        return heap[1];
    }
    void push(const T& theElement);            // ����Ԫ��
    void pop();                                // ɾ������Ԫ��
    void initialize(T *theHeap, int theSize);  // ��ʼ����
    void deactivateArray() {                   // ��������
        heap = NULL; arrayLength = heapSize = 0;
    }
    void output(ostream& out) const;
private:
    T *heap;         // �������ʾ��
    int arrayLength; // ����ĳ���
    int heapSize;    // ��Ԫ�صĸ���
};

template <class T>
void minHeap<T>::push(const T& theElement) {
    // ��������
    if (arrayLength == heapSize + 1) {
        T *temp = new T[arrayLength * 2];
        copy(heap, heap + arrayLength, temp);
        delete[]heap;
        heap = temp;
    }
    int currentNode = ++heapSize;  // currentNodeָ��Ҫ�����λ��
    while (currentNode != 1 && heap[currentNode / 2] > theElement) {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = theElement;
}

template <class T>
void minHeap<T>::pop() {
    // popʱ����Ϊ��
    if (empty()) {
        stringstream s;
        s << "heap is empty." << endl;
        throw range_error(s.str());
    }
    int currentNode = 1;            // ��ǰ���
    T lastElement = heap[heapSize]; // ȡ�����һ��Ԫ��
    heap[heapSize].~T();
    heapSize--;
    int child = 2;
    while (child <= heapSize) {
        // �ҳ���С�ĺ���
        if (child + 1 <= heapSize && heap[child] > heap[child + 1]) child++;
        // ������Ӷ�û��С�ڸ��ڵ㣬ֹͣ
        if (heap[child] >= lastElement) break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child = 2 * currentNode;
    }
    heap[currentNode] = lastElement;
}

template <class T>
void minHeap<T>::initialize(T *theHeap, int theSize) {
    delete[]heap;
    heap = theHeap;
    heapSize = theSize;
    for (int root = heapSize / 2; root > 0; root--) {
        T rootElement = heap[root];
        int currentNode = root;
        int child = 2 * currentNode;
        while (child <= heapSize) {
            if (child < heapSize && heap[child] > heap[child + 1]) child++;
            if (heap[child] >= rootElement) break;
            heap[currentNode] = heap[child];
            currentNode = child;
            child = 2 * currentNode;
        }
        heap[currentNode] = rootElement;
    }
}

template<class T>
void minHeap<T>::output(ostream& out) const {
    copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

template <class T>
ostream& operator<<(ostream& out, const minHeap<T>& x) {
    x.output(out); return out;
}

#endif // !minHeap_