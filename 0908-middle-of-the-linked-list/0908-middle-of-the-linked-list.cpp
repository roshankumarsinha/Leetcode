/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Ofcourse you can solve this problem by counting the length of
        // linkedList and then calculating middle. But below we are increasing
        // fast twice and slow with one so, as soon as fast reaches null, slow
        // will be at somewhere around middle

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            } else if (fast == nullptr) {
                break;
            }
            slow = slow->next;
        }
        return slow;
    }
};