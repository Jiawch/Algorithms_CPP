/*! Author: qwchen
 *! Date: 2016-10-23
 * 插入排序
 */

#ifndef InsertSort_
#define InsertSort_

#include <vector>

using namespace std;

template <class T>
class InsertSort{
public:
    static void insertSort(vector<T> &a, int n){
        for (int i = 1; i < n; i++){
            for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--){
                swap(a[j], a[j+1]);
            }
        }
    }
};

#endif




/*! Author: Jiawch
 *! Date: 2021-10-07
 * 插入排序
 */

void insertSort(vector<int> &a){
    for (int i = 1; i < a.size(); i++){
        for (int j = i-1; j >= 0 && a[j+1] < a[j]; j--){
            swap(a[j], a[j+1]);
        }
    }
}
