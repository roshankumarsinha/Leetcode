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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* nextToNextNode;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // If values are same, store 3rd node adress to 1st node
                // addresesPart, this will unlink 2nd node. In next Iteration
                // the 3rd node will become 2nd node and this goes on.
                nextToNextNode = curr->next->next;
                curr->next = nextToNextNode;
            } else {
                // If values are not same just move to next pointer
                curr = curr->next;
            }
        }
        return head;
    }
};