/*
 * 反转链表
 * 维护三个指针
 *  当前，往前，往后
 */

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr,
             *p = head;
    while (p != nullptr) {
        ListNode *post = p->next;
        p->next = pre;
        pre = p;
        p = post;
    }
    return pre;
}
