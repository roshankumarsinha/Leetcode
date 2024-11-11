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
    bool hasCycle(ListNode* head) {
        // For 0 or 1 node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        if (head->next == head) {
            return true;
        }

        // This follow, fast and slow pointer which is called Floyd's cycle
        // detection
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;

            // If both fast and slow meets that means there is a loop
            if (fast == slow) {
                return true;
            }
        }
        return false;

        // This problem can be solved using map as well: But space-complexity is O(N)
        // unordered_map<ListNode*, bool> visited;
        // Node* temp = head;
        // while (temp) {
        //     if (visited[temp] == true) {
        //         return true;
        //     }
        //     visited[temp] = true;
        //     temp = temp->next;
        // }
        // return false;
    }
};