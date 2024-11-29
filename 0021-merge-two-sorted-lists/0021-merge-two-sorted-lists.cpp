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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node
        ListNode* dummy = new ListNode(-1);

        // Create a temp node, which will be used as the merged Linked-List
        ListNode* temp = dummy;

        // Add respective list element into temp list whichever has smallest element
        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // If there are remaining elements left in List1
        if (list1 != nullptr)
            temp->next = list1;
        // If there are remaining elements left in List2
        else
            temp->next = list2;

        // This is the head of merged Linked List
        return dummy->next;
    }
};