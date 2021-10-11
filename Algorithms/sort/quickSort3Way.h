/*! Author: qwchen
 *! Date: 2016-10-24
 * 三向切分快速排序
 */

#ifndef QuickSort3Way_
#define QuickSort3Way_

#include <vector>

using namespace std;

template <class T>
class QuickSort3Way{
public:
    static void quickSort(vector<T> &a, int n);
private:
    static void sort(vector<T> &a, int low, int high);
};

template <class T>
void QuickSort3Way<T>::quickSort(vector<T> &a, int n){
    sort(a, 0, n-1);
}

template <class T>
void QuickSort3Way<T>::sort(vector<T> &a, int low, int high){
    if (low >= high) return;
    int lt = low,       // 指向小于比较元素的向右下一位，即等于比较元素的第一位 
        mid = low + 1,  // 指向当前正在比较的元素
        gt = high;      // 指向大于比较元素的向左下一位，最终指向等于比较元素的最后一位
    T key = a[low];
    while(mid <= gt){
        if (a[mid] < key)      swap(a[mid++], a[lt++]); //当前lt是指向等于比较元素的第一位
        else if (a[mid] > key) swap(a[mid], a[gt--]);
        else                   mid++;
    }
    sort(a, low, lt - 1);   // 比较小于key的部分a[low ... lt-1]
    sort(a, gt + 1, high);  // 比较大于key的部分a[gt+1 ... high]
}


#endif


/*! Author: Jiawch
 *! Date: 2021-10-11
 * 三向切分快速排序
 * ref: https://www.jianshu.com/p/d70aeccaee19
 */

void quickSort3Way(vector<int> &a) {
    int low = 0;
    int high = a.size() - 1;
    _quickSort3Way(a, low, high);
}

void _quickSort3Way(vector<int> &a, int low, int high) {
    if (low >= high)    return;

    int lt = low,           // 指向小于比较元素的向右一位，即等于比较元素的第一位 
        mid = low + 1,      // 指向当前正在比较的元素
        gt = high;          // 指向大于比较元素的向左一位，最终指向等于比较元素的最后一位

    int key = a[low];
    while (mid <= gt) {
        if (a[mid] < key)   swap(a[mid++], a[lt++]);
        else if (a[mid] > key)  swap(a[mid], a[gt--]);
        else    mid++;
    }

    _quickSort3Way(a, low, lt-1);
    _quickSort3Way(a, gt+1, high);
}
