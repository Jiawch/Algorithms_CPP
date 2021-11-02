/*! Author: qwchen
 *! Date: 2016-10-23
 * 堆排序
 * 用大顶堆来实现
 * 下标从0开始的二叉树，第i个结点的父节点为：(i-1)/2，左孩子为：2*i+1，右孩子为：2*i+2
 */

#ifndef HeapSort_
#define HeapSort_

#include <vector>

using namespace std;

template <class T>
class HeapSort{
public:
    static void heapSort(vector<T> &a, int n);     // 堆排序，n是数组的长度
private:
    static void sink(vector<T> &a, int k, int n);  // 将第k个元素下沉，n是数组最后一个元素的下标（下标从0开始，所以n = 长度 - 1）
};

template <class T>
void HeapSort<T>::heapSort(vector<T> &a, int n){
    n = n - 1;  // 让n指向数组的最后一个元素
    // 第一阶段：构造大顶堆。
    // 从最后一个元素的父结点开始到第一个元素，分别以这些元素作为根结点进行下沉排序。
    for (int i = (n - 1) / 2; i >= 0; i--){
        sink(a, i, n);
    }
    // 第二阶段：下沉排序。
    // 不断将堆顶元素（最大元素）和堆的最后一个元素交换位置，并让堆的大小减1；如此反复，数组将变得有序（从小到大）。
    while (n > 0){
        swap(a[0], a[n--]);
        sink(a, 0, n);
    }
}

template <class T>
void HeapSort<T>::sink(vector<T> &a, int k, int n){
    while(2 * k + 1 <= n){
        int i = 2 * k + 1;
        if (i < n && a[i] < a[i + 1]) i++;  // 取出孩子结点中大的那个
        if (a[i] < a[k]) break;             // 如果孩子结点中大的那个也比a[k]小，则下沉结束，退出循环
        swap(a[i], a[k]);
        k = i;
    }
}

#endif




/*! Author: Jiawch
 *! Date: 2021-10-27
 * 堆排序
 * 用大顶堆来实现
 * 下标从0开始的二叉树，第i个结点的父节点为：(i-1)/2，左孩子为：2*i+1，右孩子为：2*i+2
 * 重复执行如下两个阶段
 *  1. 构造大顶堆
 *  2. 下沉排序
 */


void heapSort(vector<int> &a) {
    int n = a.size();
    n = n - 1;      // 让n指向数组的最后一个元素

    // 构造大顶堆，从第一个有孩子的父节点一直往上走
    for (int i = (n-1) / 2; i >= 0 ; i--)
        sink(a, i, n);

    // 不断将堆顶元素与最后一个元素交换，并让堆的大小减1
    for (int i = n; i >= 0; i--) {
        swap(a[0], a[n--]);
        sink(a, 0, n);
    }
}

// 将第k个元素下沉，构造以k为（完全二叉树）根节点的大顶堆
void sink(vector<int> &a, int k, int n) {
    while (2 * k + 1 <= n) {      // k至少还有一个孩子
        int i = 2 * k + 1;
        if (i < n && a[i] < a[i+1]) i++;   // 取出孩子结点中大的那个
        if (a[k] > a[i]) break;             // 如果孩子结点中大的那个也比a[k]小，则下沉结束，退出循环
        swap(a[k], a[i]);
        k = i;
    }
}
