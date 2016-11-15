/*! Author: qwchen
 *! Date: 2016-10-10
 * ���Ի�������ʵ�ֵĶ�����
 */

#include <iostream>
#include "linkedBinaryTree.h"

using namespace std;

void testLinkedBinaryTree() {
    // ����������
    linkedBinaryTree<int> a, x, y, z;
    y.makeTree(1, a, a);
    z.makeTree(2, a, a);
    x.makeTree(3, y, z);
    y.makeTree(4, x, a);
    
    // ���������
     cout << "Number of nodes = ";
    cout << y.size() << endl;

    // �������߶�
    cout << "height = ";
    cout << y.height() << endl;
    
    // �������
    cout << "PreOrder sequence is (Recursive): ";   // �ݹ�
    y.preOrder();
    cout << "PreOrder sequence is (UnRecursive): "; // �ǵݹ�
    y.preOrderUnRecursive();

    // �������
    cout << "InOrder sequence is (Recursive): ";    // �ݹ�
    y.inOrder();
    cout << "InOrder sequence is (UnRecursive): ";  // �ǵݹ�
    y.inOrderUnRecursive();

    // �������
    cout << "PostOrder sequence is (Recursive): ";   // �ݹ�
    y.postOrder();
    cout << "PostOrder sequence is (UnRecursive): "; // �ǵݹ�
    y.postOrderUnRecursive();

    // ��α���
    cout << "Level order sequence is : ";
    y.levelOrder();
}

int main(){
    testLinkedBinaryTree();
    return 0;
}