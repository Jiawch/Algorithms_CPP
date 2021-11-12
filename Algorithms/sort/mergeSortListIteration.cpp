/*! Author: Jiawch
 *! Date: 2021-11-12
 *! 链表的归并排序-迭代-自底向上-非递归
 *  思路：
 *    与数组的归并排序（迭代）类似
 *  时间复杂度：O(nlogn)
 *  空间复杂度：O(1)
 */

ListNode* mergeSort(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // 获取链表长度
    int length = 0;
    ListNode *p = head;
    while (p != nullptr)
    {
        length++;
        p = p->next;
    }

    int subLength = 1;  // 归并片的大小，subLength内有序
    while (subLength < length)
    {
        ListNode *pre = new ListNode(0);    // 指向待合并链表的首节点，已合并链表的尾节点
        p = head;                           // 指向当前节点
        while (p != nullptr)
        {
            // 第一个subLength片
            ListNode *head1 = p;
            ListNode *tail1 = getTail(head1, subLength);

            // 第二个subLength片
            ListNode *head2 = tail1->next;
            tail1->next = nullptr;      // head1尾节点从链表断开
            ListNode *tail2 = getTail(head2, subLength);

            if (tail2 != nullptr)       // 还剩数据
            {
                p = tail2->next;
                tail2->next = nullptr;  // head2尾节点从链表断开
            }
            else                        // 不剩数据
            {
                p = nullptr;
            }

            pre->next = merge(head1, head2);
            while (pre->next != nullptr)
            {
                pre = pre->next;
            }
        }

        subLength *= 2;
    }

    return head;
}

// 获取链表的尾节点
ListNode* getTail(ListNode* head, int subLength)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *p = dummy;

    int i = 0;
    while(p->next != nullptr && i < subLength)
    {
        p = p->next;
        i++;
    }

    return p;
}

// 合并两个有序链表
ListNode* merge(ListNode* head1, ListNode* head2)
{
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val <= head2->val) {
            p->next = head1;
            head1 = head1->next;
        } else {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }

    if (head1 != nullptr) p->next = head1;
    if (head2 != nullptr) p->next = head2;

    return dummy->next;
}
