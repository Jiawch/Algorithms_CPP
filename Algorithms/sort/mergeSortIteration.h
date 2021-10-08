/*! Author: qwchen
 *! Date: 2016-10-23
 *  迭代实现的归并排序
 */

#ifndef MergeSortIteration_
#define MergeSortIteration_

#include <vector>

using namespace std;

template <class T>
class MergeSortIteration{
public:
    static void mergeSort(vector<T> &a, int n);  // 归并排序
private:
    static void mergePass(vector<T> &a, vector<T> &b, int n, int segmentSize);  // 从a到b 归并相邻的数据段
    static void merge(vector<T> &a, vector<T> &b, int low, int mid, int high);  // 将a[low ... mid]和a[mid+1 ... high]归并到a[low ... high]
};

// n是数组的长度
template <class T>
void MergeSortIteration<T>::mergeSort(vector<T> &a, int n){
    vector<T> b(n);
    int segmentSize = 1;
    while(segmentSize < n){
        mergePass(a, b, n, segmentSize);
        segmentSize += segmentSize;
        mergePass(b, a, n, segmentSize);
        segmentSize += segmentSize;
    }
}

// n是数组的长度
// segmentSize是一个归并的片的大小, 每一个segmentSize里有序
template <class T>
void MergeSortIteration<T>::mergePass(vector<T> &a, vector<T> &b, int n, int segmentSize){
    int i = 0;
    for (; i + 2 * segmentSize <= n; i += 2 * segmentSize){
        merge(a, b, i, i + segmentSize - 1, i + 2 * segmentSize - 1);
    }
    // 少于两段的数据
    if (i + segmentSize < n){  // 剩有两段的数据
        merge(a, b, i, i + segmentSize - 1, n - 1);
    } else {  // 只剩下一段的数据
        for (int j = i; j < n; j++){
            b[j] = a[j];
        }
    }
}

template <class T>
void MergeSortIteration<T>::merge(vector<T> &a, vector<T> &b, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high){
        if (a[i] < a[j]){
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while(i <= mid){
        b[k++] = a[i++];
    }
    while(j <= high){
        b[k++] = a[j++];
    }
}

#endif



/*! Author: Jiawch
 *! Date: 2021-10-08
 *  迭代实现的归并排序
 */


void mergeSortIteration(vector<int> &a){
    vector<int> b(a.size());
    int segment_size = 1;
    while(segment_size < a.size()){
        sortIteration(a, b, a.size(), segment_size);
        segment_size *= 2;
    }
}
void sortIteration(vector<int> &a, vector<int> &b, int n, int segment_size){
    int i = 0;
    for (; i + 2*segment_size <= n; i += 2*segment_size){
        merge(a, b, i, i + segment_size - 1, i + 2*segment_size - 1);
    }
    // 少于两段的数据
    if (i + segment_size < n){
        merge(a, b, i, i + segment_size - 1, n - 1);  // 剩有两段的数据
    }
}
void merge(vector<int> &a, vector<int> &b, int low, int mid, int high){
    int i = low;                    // i指向a左边数组的第一个元素
    int j = mid + 1;                // j指向a右边数组的第一个元素
    int k = low;                    // k为b中的指针
    while (i <= mid && j <= high){
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    // 将b[low ... high] 拷贝回 a[low ... high]
    for (int i = low; i <= high; i++)
        a[i] = b[i];
}
