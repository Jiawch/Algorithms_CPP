/*! Author: qwchen
 *! Date: 2016-10-23
 * 快速排序
 */

#ifndef QuickSort_
#define QuickSort_

#include <vector>

using namespace std;

template <class T>
class QuickSort{
public:
    static void quickSort(vector<T> &a, int n);
private:
    static void sort(vector<T> &a, int low, int high);
    static int partition(vector<T> &a, int low, int high);  // 将数组切分为a[low, mid-1], a[mid], a[mid+1]
};

template <class T>
void QuickSort<T>::quickSort(vector<T> &a, int n){
    sort(a, 0, n - 1);
}

template <class T>
void QuickSort<T>::sort(vector<T> &a, int low, int high){
    if (low >= high) return;
    int mid = partition(a, low, high);  // 切分
    sort(a, low, mid - 1);              // 将左半部分排序
    sort(a, mid + 1, high);             // 将右半部分排序
}

template <class T>
int QuickSort<T>::partition(vector<T> &a, int low, int high){
    T key = a[low];
    while(low < high){
        while(low < high && key <= a[high]) high--;  // 注意是key <= a[high]，而不是key < a[high]，否则陷入死循环
        a[low] = a[high];
        while(low < high && key >= a[low]) low++;
        a[high] = a[low];
    }
    a[low] = key;
    return low;
}

#endif



/*! Author: Jiawch
 *! Date: 2021-10-10
 * 快速排序
 */

void quickSort(vector<int> &a) {
    int low = 0;
    int high = a.size() - 1;
    _quickSort(a, low, high);
}

void _quickSort(vector<int> &a, int low, int high) {
    if (low >= high)    return;

    int mid = partition(a, low, high);  // 切分
    _quickSort(a, low, mid - 1);        // 将左半部分排序
    _quickSort(a, mid + 1, high);       // 将右半部分排序
}

int partition(vector<int> &a, int low, int high) {
    int key = a[low];
    while (low < high) {
        while (low < high && a[high] >= key)    high--;     // 注意是key <= a[high]，而不是key < a[high]，否则陷入死循环
        a[low] = a[high];                                   // 因为左和右分别是`不大于`与`不小于`key的数
        while (low < high && a[low] <= key)     low++;
        a[high] = a[low];
    }

    a[low] = key;
    return low;
}
