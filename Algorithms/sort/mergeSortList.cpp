/*! Author: qwchen
 *! Date: 2017-03-18
 *! 链表的归并排序
 *  思路：
 *    与数组的归并排序类似
 *  时间复杂度：O(nlogn)
 *  空间复杂度：O(logn), 取决于树的深度
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* theNext): val(x), next(theNext) {}
};

// 获取链表的中间结点
ListNode* getMid(ListNode* head) {
    ListNode dummp(0);
    dummp.next = head;
    ListNode *pFast = &dummp,
             *pSlow = &dummp;
    while (pFast != nullptr && pFast->next != nullptr) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    return pSlow;
}

// 合并两个有序链表
ListNode* merge(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    ListNode* head;
    if (head1->val <= head2->val) {
        head = head1;
        head->next = merge(head1->next, head2);
    }
    else {
        head = head2;
        head->next = merge(head1, head2->next);
    }
    return head;
}

// 归并排序
ListNode* mergeSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* mid = getMid(head);
    ListNode* head2 = mid->next;
    mid->next = nullptr;
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return merge(head, head2);
}

int main() {
    // 10, 4, 2, 9, 5
    ListNode* p4 = new ListNode(5);
    ListNode* p3 = new ListNode(9, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(4, p2);
    ListNode* head = new ListNode(10, p1);
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    head = mergeSort(head);
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;    
}




/*! Author: Jiawch
 *! Date: 2021-10-10
 *! 链表的归并排序
 *  思路：
 *    与数组的归并排序类似
 *  时间复杂度：O(nlogn)
 *  空间复杂度：O(1)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode *next): val(val), next(next) {}
};

ListNode* mergeSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *mid = getMid(head);
    ListNode *head2 = mid->next;
    mid->next = nullptr;

    head = mergeSort(head);
    head2 = mergeSort(head2);
    return merge(head, head2);
}

ListNode* merge(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    ListNode *head;
    if (head1->val <= head2->val) {
        head = head1;
        head->next = merge(head1->next, head2);
    } else {
        head = head2;
        head->next = merge(head1, head2->next);
    }
    return head;
}

/*
 * getMid这里需要注意的是：
 * 如果有头节点（注意不是首节点），则奇数个取中间，偶数个去中间靠左；
 * 如果没有头节点，则奇个取中间，偶数个取中间靠右。
 */
ListNode* getMid(ListNode *head){
    ListNode *dummp = new ListNode(0, head);
    ListNode *p_fast = dummp;
    ListNode *p_slow = dummp;

    while (p_fast != nullptr && p_fast->next != nullptr) {
        p_fast = p_fast->next->next;
        p_slow = p_slow->next;
    }
    return p_slow;
}
