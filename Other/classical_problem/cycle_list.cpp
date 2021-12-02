/*! Author: Jiawch
 *! Date: 20211202
 * ref: https://www.cnblogs.com/lixuejian/p/13385536.html
 * 1. 判断是否有环
 * 2. 寻找环入口
 * 3. 求环长度
 */

#include <iostream>

using namespace std;

struct ListNode {
    int value;
    int next;
    ListNode(): value(0), next(nullptr) {}
    ListNode(int value): value(value) next(nullptr) {}
    ListNode(int value, ListNode* next): value(value) next(next) {}
};

// 证明：https://www.zhihu.com/question/23208893/answer/117115415
// 快慢指针，如果有环，则会相遇，否则快指针指向null
bool hasCycle(ListNode* head) {
    ListNode *fast = head,
             *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}

// 寻找环入口的方法
//  采用两个指针，一个从表头出发，一个从相遇点出发，
//  一次都只移动一步，当二者相等时便是环入口的位置
// 证明：设交点距环入口S，
//      慢指针路程=L+S
//      快指针路程=L+S+nR
//      快指针速度是慢指针的2倍，故相同时间下，快指针路程=2（慢指针路程），即
//      L+S+nR = 2(L+S) ---> L+S = nR
//      当n=1，L = R-S
ListNode* detectCycleEntry(ListNode* head) {
    ListNode *fast = head,
             *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    // 如果没有环
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    slow = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}


// 求有环链表的环长度
// 循环两次
// 当快慢指针相遇时，继续移动直到第二次相遇，此时快指针移动的距离正好比慢指针多一圈
int cycleLength(ListNode* head) {
    ListNode *fast = head,
             *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    int lemgth = 0;
    while (fast != nullptr && fast->next != nullptr) {
        lemgth++;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    return length;
}


