/*! Author: qwchen
 *! Date: 2016-11-6
 * ���ֲ���
 * ������a�в��Ҵ�����Ԫ��x���±꣬
 *     �����ҳɹ��������±�
 *     ������ʱʧ�ܣ�����-1
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Parament:
 *     a������
 *     n������a�ĳ���
 *     x��������Ԫ��
 * Return��
 *     ������Ԫ�ص��±꣬������ʱ����-1
 */
template <class T>
int binarySearch(vector<T>& a, const T x) {
    int low = 0, high = a.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < a[mid])      high = mid - 1;
        else if (x > a[mid]) low = mid + 1;
        else                 return mid;
    }
    return -1;
}

void testSearch(){
    vector<int> a = {0,1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(a, 6) << endl;
}

int main(){
    testSearch();
    return 0;
}

