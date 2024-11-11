/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        bool isCycle = false;

        // Detect Loop using Floyd's
        while (fast) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;
            if (fast == slow) {
                isCycle = true;
                break;
            }
        }
        // If cycle is there then, slow will be in loop where fast and slow
        // intersected. Initialize fast with head and if fast and slow meet
        // again then that will be start of loop. But keep in mind that this
        // time yu have to move fast and slow both by only 1 step at a time.

        if (isCycle) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
        return nullptr;
    }
};