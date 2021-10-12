/*! Author: qwchen
 *! Date: 2016-12-10
 *  二分查找
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 从有重复元素有序数组中找到第一个等于val的元素的下标，找不到时返回-1
 * 设low指针指向数组第一个元素，high指针指向数组最后一个元素
 * 当数组长度为奇数时，mid指向中间元素；数组长度为偶数时，【mid指向前半段的最后一个元素】
 * 当target大于mid的值时，说明target只可能存在[mid+1, high]中，令low = mid + 1
 * 当target小于等于mid的值时，说明第一个等于target的元素可能是mid，也可能是小于mid，即在[low, mid]中，令high = mid
 * (PS. 当target>mid的值时，在右边；当target<mid的值时，在左边，当target==mid的值时，也有可能在左边)
 */
template <class T>
int searchFirst(vector<int>& a, const T target) {
	if (a.size() == 0 || target < a[0] || target > a.back()) {
		return -1;
	}
	int low = 0;
	int high = a.size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (target > a[mid]) low = mid + 1;
		else                 high = mid;
	}
	if (a[low] == target) return low;
	else                  return -1;
}

/*
 * 从有重复元素有序数组中找到最后一个等于val的元素的下标，找不到时返回-1
 * 设low指针指向数组第一个元素，high指针指向数组最后一个元素
 * 当数组长度为奇数时，mid指向中间元素；数组长度为偶数时，【mid指向后半段的第一个元素】
 * 当mid的值大于target时，说明target只可能存在[low, mid-1]中，令high = mid - 1
 * 当mid的值小于等于target时，说明最后一个等于target的元素可能是mid，也可能是大于mid，即在[mid, high]中，令low = mid
 * (PS. 当target<mid的值时，在左边；当target>mid的值时，在右边，当target==mid的值时，也有可能在右边)
 */
template <class T>
int searchLast(vector<int>& a, const T target) {
	if (a.size() == 0 || target < a[0] || target > a.back()) {
		return -1;
	}
	int low = 0;
	int high = a.size() - 1;
	while (low < high) {
		int mid = (low + high + 1) / 2;      // 如果还是 mid = (low + high) / 2 的话，那么`两个一样的数`会在 low = mid 的作用下无限循环
		if (target < a[mid]) high = mid - 1;
		else                 low = mid;
	}
	if (a[high] == target) return high;
	else                   return -1;
}

void test() {
	vector<int> a = {5, 7, 7, 8, 8, 10};
	cout << searchFirst(a, 8) << endl; // 3
	cout << searchLast(a, 8) << endl;  // 4
}

int main() {
	test();
	return 0;
}

