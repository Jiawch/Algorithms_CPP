/*! Author: qwchen
 *! Date: 2016-11-6
 * ���ֲ���
 * ������a�в��Ҵ�����Ԫ��x���±꣬
 *     �����ҳɹ��������±�
 *     ������ʱʧ�ܣ�����-1
 */

#ifndef binarySearch_
#define binarySearch_

#include <iostream>

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
int binarySearch(T *a, int n, const T &x) {
    int low = 0, high = n - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < a[mid])      high = mid - 1;
        else if (x > a[mid]) low = mid + 1;
        else                 return mid;
    }
    return -1;
}

#endif