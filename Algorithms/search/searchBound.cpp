#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> a, int x);
int searchLowerBound(vector<int> a, int target); // 第一个>=的数
int searchUpperBound(vector<int> a, int target); // 第一个>的数


int main() {
    const int N = 8;
    int _a[N] = {1,2,2,3,4,4,6,7};
    vector<int> a(_a, _a+N);

    cout << binarySearch(a, 5) << " (binarySearch)" << endl;

    cout << searchLowerBound(a, 1) << " " << lower_bound(a.begin(), a.end(), 1) - a.begin() << endl;
    cout << searchLowerBound(a, 2) << " " << lower_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    cout << searchLowerBound(a, 3) << " " << lower_bound(a.begin(), a.end(), 3) - a.begin() << endl;
    cout << searchLowerBound(a, 4) << " " << lower_bound(a.begin(), a.end(), 4) - a.begin() << endl;
    cout << searchLowerBound(a, 5) << " " << lower_bound(a.begin(), a.end(), 5) - a.begin() << endl;
    cout << searchLowerBound(a, 6) << " " << lower_bound(a.begin(), a.end(), 6) - a.begin() << endl;
    cout << searchLowerBound(a, 7) << " " << lower_bound(a.begin(), a.end(), 7) - a.begin() << endl;
    cout << searchLowerBound(a, 8) << " " << lower_bound(a.begin(), a.end(), 8) - a.begin() << endl;
    cout << searchLowerBound(a, 9) << " " << lower_bound(a.begin(), a.end(), 9) - a.begin() << endl;

    cout << searchUpperBound(a, 1) << " " << upper_bound(a.begin(), a.end(), 1) - a.begin() << endl;
    cout << searchUpperBound(a, 2) << " " << upper_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    cout << searchUpperBound(a, 3) << " " << upper_bound(a.begin(), a.end(), 3) - a.begin() << endl;
    cout << searchUpperBound(a, 4) << " " << upper_bound(a.begin(), a.end(), 4) - a.begin() << endl;
    cout << searchUpperBound(a, 5) << " " << upper_bound(a.begin(), a.end(), 5) - a.begin() << endl;
    cout << searchUpperBound(a, 6) << " " << upper_bound(a.begin(), a.end(), 6) - a.begin() << endl;
    cout << searchUpperBound(a, 7) << " " << upper_bound(a.begin(), a.end(), 7) - a.begin() << endl;
    cout << searchUpperBound(a, 8) << " " << upper_bound(a.begin(), a.end(), 8) - a.begin() << endl;
    cout << searchUpperBound(a, 9) << " " << upper_bound(a.begin(), a.end(), 9) - a.begin() << endl;

    return 0;
}


int binarySearch(vector<int> a, int x) {
    int low = 0;
    int high = a.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < a[mid]) high = mid - 1;
        else if (x > a[mid]) low = mid + 1;
        else return mid;
    }

    return -1;
}


int searchLowerBound(vector<int> a, int target) {
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (a[mid] < target)    low = mid + 1;
        else if (a[mid] > target)   high = mid - 1;
        else    high = mid;
    }

    if (a[low] >= target)   return low;
    return low + 1;
}

int searchUpperBound(vector<int> a, int target) {
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (a[mid] < target)    low = mid + 1;
        else if (a[mid] > target)   high = mid - 1;
        else    low = mid;
    }

    if (a[low] <= target)   return low + 1;
    return low;
}

