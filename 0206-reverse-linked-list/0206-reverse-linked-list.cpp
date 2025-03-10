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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* nextNode;
        while (head != nullptr) {
            nextNode = head -> next;
            head -> next = temp;
            temp = head;
            head = nextNode;
        }
        return temp;    // This will become new head for reverse Linked-List
    }
};