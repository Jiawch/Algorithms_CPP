/*! Author: qwchen
 *! Date: 2016-10-10
 * ���Ի�������ʵ�ֵĶ�����
 * �����±��1��ʼ
 */

#include <iostream>
#include "arrayBinaryTree.h"

using namespace std;

void testarrayBinaryTree() {
    // ������
    int root = 3;
    arrayBinaryTree<int> *t = new arrayBinaryTree<int>(10, &root);
    
    // ������
    int node2 = 5;
    int node3 = 8;
    t->addNode(1, 0, &node2);
    t->addNode(1, 1, &node3);
    int node4 = 2;
    int node5 = 6;
    t->addNode(2, 0, &node4);
    t->addNode(2, 1, &node5);
    int node6 = 9;
    int node7 = 7;
    t->addNode(3, 0, &node6);
    t->addNode(3, 1, &node7);
    t->treeTrave();
    cout << endl;

    // ����
    int snode = t->searchNode(3);
    cout << "Node 3 : " << snode << endl;

    // ɾ��
    int dnode;
    t->deleteNode(7, &dnode);
    cout << "delete node : " << dnode << endl;
    t->treeTrave();
    delete t;
}


int main(){
    testarrayBinaryTree();
    return 0;
}