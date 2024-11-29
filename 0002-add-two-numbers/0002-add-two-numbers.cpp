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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy Node to store answer(addition) List
        ListNode* ans = new ListNode(-1);

        ListNode* head = ans;

        int carry = 0;

        // Add list1->data, list2->data, carry and add it to answer List
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode* value = new ListNode(val);
            ans->next = value;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // If list1 is long and it still has some nodes left
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode* value = new ListNode(val);
            ans->next = value;
            ans = ans->next;
            l1 = l1->next;
        }

        // If list2 is long and it still has some nodes left
        while (l2 != nullptr) {
            int sum = l2->val + carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode* value = new ListNode(val);
            ans->next = value;
            ans = ans->next;
            l2 = l2->next;
        }

        // If carry is left over, when list1 and list2 have same length
        while (carry != 0) {
            int sum = carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode* value = new ListNode(val);
            ans->next = value;
            ans = ans->next;
        }
        return head->next;
    }
};