/*! Author: qwchen
 *! Date: 2016-10-10
 * ��������ʵ�ֵĶ�����
 */

#ifndef linkedBinaryTree_
#define linkedBinaryTree_

#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

/*
 * ���������
 */
template <class T>
struct binaryTreeNode {
    T element;                      // ���Ԫ��
    binaryTreeNode<T> *leftChild;   // ������
    binaryTreeNode<T> *rightChild;  // ������
    
    binaryTreeNode() {
        leftChild = rightChild = NULL;
    }

    binaryTreeNode(const T& theElement):element(theElement) {
        leftChild = rightChild = NULL;
    }

    binaryTreeNode(const T& theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild) :element(theElement) {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

/*
 * ����ʵ�ֵĶ�����
 */
template <class T>
class linkedBinaryTree {
public:
    linkedBinaryTree() { // ����������
        root = NULL;
        treeSize = 0;
    }
    ~linkedBinaryTree() { // ���ٶ�����
        visit = dispose;
        postOrder(root);
        root = NULL;
    }
    bool empty() const {  // �ж����Ƿ�Ϊ��
        return treeSize == 0;
    }
    int size() const {    // �������Ľ����
        return treeSize;
    }
    T* rootElement() const {  //�������ĸ�����ֵ
        if (empty()) return NULL;
        else return &root->element;
    }
    void makeTree(const T& element, linkedBinaryTree<T>&, linkedBinaryTree<T>&); // ��������㡢��������������������һ���µ���
    linkedBinaryTree<T>& removeLeftSubtree();  // ɾ��������������
    linkedBinaryTree<T>& removeRightSubtree(); // ɾ��������������
    void preOrder() {    // �������
        visit = output;
        preOrder(root);
        cout << endl;
    }
    void inOrder() {    // �������
        visit = output;
        inOrder(root);
        cout << endl;
    }
    void postOrder() {  // ��������
        visit = output;
        postOrder(root);
        cout << endl;
    }
    void levelOrder() { // ��α���
        visit = output;
        levelOrder(root);
        cout << endl;
    }
    int height() {      // ���ĸ߶�
        return height(root);
    }
    void preOrderUnRecursive() { // ����������ǵݹ�汾��
        visit = output;
        preOrderUnRecursive(root);
        cout << endl;
    }
    void inOrderUnRecursive() {  // ����������ǵݹ�汾��
        visit = output;
        inOrderUnRecursive(root);
        cout << endl;
    }
    void postOrderUnRecursive() {// ����������ǵݹ�汾��
        visit = output;
        postOrderUnRecursive(root);
        cout << endl;
    }

protected:
    binaryTreeNode<T> *root;                      // ������
    int treeSize;                                 // �����������
    static int count;                             // �����������������
    static void(*visit)(binaryTreeNode<T> *t);    // visit������һ��ָ�뺯�������Ը��ݹ���ָ��ͬ�ĺ���
    static void preOrder(binaryTreeNode<T> *t);   // �������
    static void inOrder(binaryTreeNode<T> *t);    // �������
    static void postOrder(binaryTreeNode<T> *t);  // ��������
    static void levelOrder(binaryTreeNode<T> *t); // ��α���
    static void preOrderUnRecursive(binaryTreeNode<T> *t);  // ����������ǵݹ�汾��
    static void inOrderUnRecursive(binaryTreeNode<T> *t);   // ����������ǵݹ�汾��
    static void postOrderUnRecursive(binaryTreeNode<T> *t); // ����������ǵݹ�汾��
    static int height(binaryTreeNode<T> *t);                // ���ĸ߶�
    static void output(binaryTreeNode<T> *t) { cout << t->element << " "; } // visit����ָ��Ĺ��ܺ����������ǰ����ֵ
    static void addToCount(binaryTreeNode<T> *t) { count++; }  // visit����ָ��Ĺ��ܺ���������
    static void dispose(binaryTreeNode<T> *t) { delete t; }    // visit����ָ��Ĺ��ܺ�����ɾ�����
    static int countNode(binaryTreeNode<T> *t) {
        count = 0;
        visit = addToCount;
        preOrder(t);
        return count;
    }
};

template <class T> 
void (*linkedBinaryTree<T>::visit)(binaryTreeNode<T>*);

template <class T>
void linkedBinaryTree<T>::makeTree(const T&element, linkedBinaryTree<T>& left, linkedBinaryTree<T>& right) {
    root = new binaryTreeNode<T>(element, left.root, right.root);
    treeSize = left.treeSize + right.treeSize + 1;
    left.root = NULL;
    right.root = NULL;
    left.treeSize = right.treeSize = 0;
}

template <class T>
linkedBinaryTree<T>& linkedBinaryTree<T>::removeLeftSubtree() {
    if (treeSize == 0) {
        stringstream s;
        s << "tree is empty." << endl;
        throw range_error(s.str());
    }
    linkedBinaryTree<T> leftSubtree;
    leftSubtree.root = root->leftChild;
    leftSubtree.treeSize= countNode(leftSubtree.root);
    treeSize -= leftSubtree.treeSize;
    root->leftChild = NULL;
    return leftSubtree;
}

template <class T>
linkedBinaryTree<T>& linkedBinaryTree<T>::removeRightSubtree() {
    if (treeSize == 0) {
        stringstream s;
        s << "tree is empty." << endl;
        throw range_error(s.str());
    }
    linkedBinaryTree<T> rightSubtree;
    rightSubtree.root = root->rightChild;
    rightSubtree.treeSize = countNode(rightSubtree.root);
    treeSize -= rightSubtree.treeSize;
    root->rightChild = NULL;
    return rightSubtree;
}


template <class T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *t) {
    if (t != NULL) {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *t) {
    if (t != NULL) {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *t) {
    if (t != NULL) {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

template <class T>
void linkedBinaryTree<T>::levelOrder(binaryTreeNode<T> *t) {
    queue<binaryTreeNode<T>*> q;
    while (true) {
        visit(t);
        if (t->leftChild != NULL) q.push(t->leftChild);
        if (t->rightChild != NULL) q.push(t->rightChild);
        if (!q.empty()) t = q.front();
        else break;
        q.pop();
    }
}

template <class T>
int linkedBinaryTree<T>::height(binaryTreeNode<T> *t) {
    if (t == NULL) return 0;
    int hl = height(t->leftChild);
    int hr = height(t->rightChild);
    if (hl > hr) return hl+1;
    else return hr+1;
}

template <class T>
void linkedBinaryTree<T>::preOrderUnRecursive(binaryTreeNode<T> *t) {
    stack<binaryTreeNode<T>*> s;
    binaryTreeNode<T> *p = t;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            visit(p);
            s.push(p);
            p = p->leftChild;
        }
        if (!s.empty()) {
            p = s.top();
            p = p->rightChild;
            s.pop();
        }
    }
}

template <class T>
void linkedBinaryTree<T>::inOrderUnRecursive(binaryTreeNode<T> *t) {
    stack<binaryTreeNode<T>*> s;
    binaryTreeNode<T> *p = t;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->leftChild;
        }
        if (!s.empty()) {
            p = s.top();
            visit(p);
            p = p->rightChild;
            s.pop();
        }
    }
}

template <class T>
void linkedBinaryTree<T>::postOrderUnRecursive(binaryTreeNode<T> *t) {
    stack<binaryTreeNode<T>*> s;
    binaryTreeNode<T> *p = t;
    binaryTreeNode<T> *pre = NULL; // ���ǰһ�����ʹ��Ľ��
    while (p != NULL || !s.empty()) { // ���Ϊ����ջΪ��ʱ���ܽ���
        while (p != NULL) {
            s.push(p);
            p = p->leftChild;
        }
        if (!s.empty()) {
            p = s.top();
            if (p->rightChild == NULL || p->rightChild == pre) { //�Һ���Ϊ�ջ����Һ����Ѿ����ʹ������ܷ��ʸý��
                visit(p);
                pre = p; // ���ʹ������preָ����
                s.pop();
                p = NULL; // ����Ӧ���ٴ�pop,������Ҫ���ջ�Ƿ��. ���ֱ����p=NULL,������if(!s.empty()){}�������.
            }
            else {
                p = p->rightChild;
            }
        }
    }
}

#endif // !linkedBinaryTree_
