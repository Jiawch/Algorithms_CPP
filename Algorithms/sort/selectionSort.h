/*! Author: qwchen
 *! Date: 2016-10-23
 * 选择排序
 */

#ifndef SelectionSort_
#define SelectionSort_

#include <vector>

using namespace std;

template <class T>
class SelectionSort{
public:
    static void selectionSort(vector<T> &a, int n){
        for (int i = 0; i < n; i++){
            int min = i;
            for (int j = i+1; j < n; j++){
                if(a[j] < a[min]){
                    min = j;
                }
            }
            swap(a[i], a[min]);
        }
    }
};

#endif



/*! Author: Jiawch
 *! Date: 2021-10-07
 * 选择排序
 */

void selectionSort(vector<int> &a){
    for (int i = 0; i < a.size()-1; i++){       // 遍历n-1次
        int min = i;
        for (int j = i; j < a.size(); j++){     // 每次遍历，寻找第i个元素开始最小的元素
            if (a[min] > a[j]){
                min = j;
            }
        }
        swap(a[min], a[i]);                     // 交换第i个元素与最小元素的位置
    }
}
