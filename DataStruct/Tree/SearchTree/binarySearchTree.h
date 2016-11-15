/*! Author: qwchen
 *! Date: 2016-10-10
 * ����������
 */

#ifndef binarySearchTree_
#define binarySearchTree_

#include <iostream>

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

template <class K, class E>
class binarySearchTree {
public:
    binarySearchTree();
    ~binarySearchTree();
    int size() const;
    pair<const K, E>* find(const K& theKey) const; // ���ҽ��
    pair<const K, E>* findLE(const K& theKey) const; // ����С�ڵ���theKey�����Ԫ��
    pair<const K, E>* findGE(const K& theKey) const; // ���Ҵ��ڵ���theKey����СԪ��
    void insert(const pair<const K, E>& thePair);  // ������
    void erase(const K& theKey);                   // ɾ�����
    void ascend();                                 // ����������

private:
    binaryTreeNode<pair<const K, E>> *root; // ���ĸ��ڵ�
    int treeSize;                           // ���Ľڵ����
    void postOrderDeleteTree(binaryTreeNode<pair<const K, E>>* t); // ����������ķ�ʽɾ����
    void inOrderOutputTree(binaryTreeNode<pair<const K, E>>* t);   // ����������ķ�ʽ�����
};

template <class K, class E>
binarySearchTree<K, E>::binarySearchTree(){
    root = NULL;
    treeSize = 0;
}

template <class K, class E>
binarySearchTree<K, E>::~binarySearchTree(){
    postOrderDeleteTree(root);
    root = NULL;
}

template <class K, class E>
void binarySearchTree<K, E>::postOrderDeleteTree(binaryTreeNode<pair<const K, E>>* t){
    if (t != NULL){
        postOrderDeleteTree(t->leftChild);
        postOrderDeleteTree(t->rightChild);
        delete t;
    }
}

template <class K, class E>
void binarySearchTree<K, E>::inOrderOutputTree(binaryTreeNode<pair<const K, E>>* t){
    if (t != NULL){
        inOrderOutputTree(t->leftChild);
        cout << "(" << t->element.first << ", " << t->element.second << ") ";
        inOrderOutputTree(t->rightChild);
    }
}

template <class K, class E>
int binarySearchTree<K, E>::size() const {
    return treeSize;
}

template <class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K &theKey) const {
    binaryTreeNode<pair<const K, E>> *p = root;
    while (p != NULL) {
        if (theKey < p->element.first) p = p->leftChild;       // theKey < ���Ĺؼ���
        else if (theKey > p->element.first) p = p->rightChild; // theKey > ���Ĺؼ���
        else return &p->element;                               // theKey = ���Ĺؼ���
    }
    return NULL;
}

template <class K, class E>
pair<const K, E>* binarySearchTree<K, E>::findLE(const K& theKey) const {
    binaryTreeNode<pair<const K, E>> *p = root;
    pair<const K, E> *bestElement = NULL; // Ŀǰ���ҵ���Ԫ�أ���ؼ�����С�ڵ���theKey�����Ԫ��
    while(p != NULL){
        // p->element��һ����ѡ����
        if (p->element.first <= theKey){
            // �ǣ�p->element�Ǳ�bestElement���õĺ�ѡ��
            bestElement = &p->element;
            p = p->rightChild;
        } else {
            // ���ǣ�p->element.first̫��
            p = p->leftChild;
        }
    }
    return bestElement;
}

template <class K, class E>
pair<const K, E>* binarySearchTree<K, E>::findGE(const K& theKey) const {
    binaryTreeNode<pair<const K, E>> *p = root;
    pair<const K, E> *bestElement = NULL;
    while(p != NULL){
        if (p->element.first >= theKey){
            bestElement = &p->element;
            p = p->leftChild;
        } else {
            p = p->rightChild;
        }
    }
    return bestElement;
}

template <class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E> &thePair) {
    binaryTreeNode<pair<const K, E>> *p = root, 
                                     *pp = NULL;    // ppָ��p�ĸ��ڵ�
    while (p != NULL) {
        if (thePair.first < p->element.first) {
            pp = p;
            p = p->leftChild;
        }
        else if (thePair.first > p->element.first) {
            pp = p;
            p = p->rightChild;
        }
        else { // �������ͬ��key�Ľ�㣬ֱ���滻
            p->element.second = thePair.second;
            return;
        }
    }
    binaryTreeNode<pair<const K, E>> *newNode = new binaryTreeNode<pair<const K, E>>(thePair);
    if (root != NULL) { // ������Ϊ�գ�pp���ӽڵ���ǲ���λ�ã����ӻ����Һ��ӣ�
        if (thePair.first < pp->element.first) pp->leftChild = newNode;
        else pp->rightChild = newNode;
    }
    else { // ������Ϊ��
        root = newNode;
    }
    treeSize++;
}

template <class K, class E>
void binarySearchTree<K, E>::erase(const K &theKey) {
    binaryTreeNode<pair<const K, E>> *p = root,
                                     *pp = NULL;
    // ��������ɾ���Ľ��
    while (p != NULL) {
        if (theKey < p->element.first) {
            pp = p;
            p = p->leftChild;
        }
        else if (theKey > p->element.first) {
            pp = p;
            p = p->rightChild;
        }
        else break;
    }
    // �����ɾ���Ľ�㲻���ڣ�ֱ�ӷ���
    if (p == NULL)
        return;
    // �����ɾ���Ľ�����������������3�������
    if (p->leftChild != NULL && p->rightChild != NULL) {
        // ��Ѱ�����������Ľ��
        binaryTreeNode<pair<const K, E>> *s = p->leftChild,
                                         *ps = p;
        while (s->rightChild) {
            ps = s;
            s = s->rightChild;
        }
        binaryTreeNode<pair<const K, E>> *q = new binaryTreeNode<pair<const K, E>>(s->element, p->leftChild, p->rightChild);
        // �޸Ĵ�ɾ�����ĸ����ĺ���ָ���ָ��
        if (p == root) {
            root = q;
        }
        else {
            if (p == pp->leftChild)
                pp->leftChild = q;
            else
                pp->rightChild = q;
        }
        // ����ת��Ϊɾ�����s(����0��1�������Ľ��)��������pָ��s��ppָ��s�ĸ��ڵ㣬�������ɾ��p�����⣨��ʱp�ǵ�1���2������ˣ�
        if (ps == p) pp = q; // ����û��������
        else pp = ps;
        delete p;
        p = s;
    }
    // �����ɾ���Ľ�����ֻ����һ������
    binaryTreeNode<pair<const K, E>> *c = NULL;
    if (p->leftChild != NULL) c = p->leftChild;
    else c = p->rightChild;
    // �����ɾ���Ľ���Ǹ����
    if (p == root) {
        root = c;
    }
    else {
        if (p == pp->leftChild) pp->leftChild = c;
        else pp->rightChild = c;
    }
    delete p;
    treeSize--;
}

template <class K, class E>
void binarySearchTree<K, E>::ascend(){
    inOrderOutputTree(root);
    cout << endl;
}


#endif // !binarySearchTree_