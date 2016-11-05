/*! Author: qwchen
 *! Date: 2016-10-10
 * ��������ʵ�ֵĶ�����
 * �����±��1��ʼ
 */

#ifndef arrayBinaryTree_
#define arrayBinaryTree_

#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class arrayBinaryTree {
public:
    arrayBinaryTree(int size, T *pRoot);                 // �������鳤�Ⱥ����ĸ����Ԫ�أ�����������
    ~arrayBinaryTree();
    T searchNode(int theIndex);                        // ��������Ѱ�ҽ��
    void addNode(int theIndex, int direction, T *pNode); // ��ӽ�㣬theIndex�Ǵ�������ĸ���㣬direction = 0����������,direction = 1����������
    void deleteNode(int theIndex, T *pNode);             // ɾ����㣬����ɾ���Ľ��ŵ�pNode�з���
    void treeTrave();                                    // �������

private:
    T *m_pTree; // ����
    int m_iSize;  // ����Ԫ�صĸ���
};

template <class T>
arrayBinaryTree<T>::arrayBinaryTree(int size, T *pRoot) {
    m_pTree = new T[size + 1];
    m_iSize = size;
    for (int i = 0; i <= size; i++) {
        m_pTree[i] = 0;
    }
    m_pTree[1] = *pRoot;
}

template <class T>
arrayBinaryTree<T>::~arrayBinaryTree() {
    delete []m_pTree;
}

template <class T>
T arrayBinaryTree<T>::searchNode(int theIndex) {
    if (theIndex <= 0 || theIndex > m_iSize) {
        return 0;
    }
    return m_pTree[theIndex];
}

template <class T>
void arrayBinaryTree<T>::addNode(int theIndex, int direction, T *pNode) {
    if (theIndex <= 0 || theIndex > m_iSize) {
        stringstream s;
        s << "index out of range." << endl;
        throw invalid_argument(s.str());
    }
    if (m_pTree[theIndex] == 0) { // ���ڵ㲻���ڣ�����ʧ��
        stringstream s;
        s << "parent node doesn't exist." << endl;
        throw invalid_argument(s.str());
    }
    // Ѱ�Ҳ���λ�ã������ӻ����Һ���
    if (direction == 0) theIndex = 2 * theIndex;
    else if (direction == 1) theIndex = 2 * theIndex + 1;
    else {
        stringstream s;
        s << "direction must be 0 or 1" << endl;
        throw invalid_argument(s.str());
    }
    // �ӽڵ�Խ�磬����ʧ��
    if (theIndex <= 0 || theIndex > m_iSize) {
        stringstream s;
        s << "index out of range." << endl;
        throw invalid_argument(s.str());
    }
    // �ӽڵ��Ѿ����ڣ�����ʧ��
    if (m_pTree[theIndex] != 0) {
        stringstream s;
        s << "node have already exist." << endl;
        throw invalid_argument(s.str());
    }
    m_pTree[theIndex] = *pNode;
}

template <class T>
void arrayBinaryTree<T>::deleteNode(int theIndex, T *pNode) {
    if (theIndex <= 0 || theIndex > m_iSize) {
        stringstream s;
        s << "direction must be 0 or 1" << endl;
        throw invalid_argument(s.str());
    }
    if (m_pTree[theIndex] == 0) {
        stringstream s;
        s << "node doesn't exist." << endl;
        throw invalid_argument(s.str());
    }
    *pNode = m_pTree[theIndex];
    m_pTree[theIndex] = 0;
}

template <class T>
void arrayBinaryTree<T>::treeTrave() {
    for (int i = 1; i <= m_iSize; i++) {
        cout << m_pTree[i] << " ";
    }
}

#endif // !arrayBinaryTree_





