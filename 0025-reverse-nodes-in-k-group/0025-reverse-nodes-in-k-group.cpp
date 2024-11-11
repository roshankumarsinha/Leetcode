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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head)
            return head; // No need to reverse if k == 1 or list is empty.

        // Count the length of the list
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Calculate the number of full groups of `k` that we can reverse
        int groups = length / k;
        if (groups == 0)
            return head; // If no full k-group, return the list as it is

        // Initial pointers
        ListNode* newHead =
            nullptr; // This will be the new head of the list after reversal
        ListNode* groupPrev = nullptr; // Pointer to connect the end of one
                                       // reversed group to the next
        curr = head;

        while (groups > 0) {
            // Reverse k nodes
            ListNode* groupEnd = curr; // The current group's original head
                                       // becomes its tail after reversal
            ListNode* prev = nullptr;
            int count = 0;

            // Reverse the nodes in the current group
            while (count < k) {
                ListNode* nextNode =
                    curr->next;    // Temporarily store the next node
                curr->next = prev; // Reverse the link
                prev = curr;       // Move prev to current
                curr = nextNode;   // Move to next node
                count++;
            }

            // Now, `prev` is the new head of this reversed group
            if (!newHead)
                newHead = prev; // Set the new head of the list if it is the
                                // first group

            // Connect the previous group with the current reversed group
            if (groupPrev)
                groupPrev->next = prev;

            // Prepare for the next group
            groupPrev = groupEnd; // `groupEnd` now becomes the last node of
                                  // this reversed group
            groups--;
        }

        // After reversing all possible k-groups, attach the remaining nodes
        if (groupPrev)
            groupPrev->next = curr;

        return newHead;
    }
};