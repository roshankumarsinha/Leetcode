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
    typedef pair<int, ListNode*> Node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node, vector<Node>, greater<Node>>
            minHeap; // Min-heap to store the nodes

        // Push the head of each linked list into the min-heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push({list->val, list});
            }
        }

        ListNode* dummy = new ListNode(0); // Dummy node to simplify the merged list
        ListNode* tail = dummy; // Pointer to the last node in the merged list

        // While the min-heap is not empty
        while (!minHeap.empty()) {
            Node current = minHeap.top(); // Get the smallest node
            ListNode* curr = current.second;
            minHeap.pop();                 // Remove it from the heap

            tail->next = curr; // Add it to the merged list
            tail = tail->next;    // Move to the last node in the merged list

            // If there is a next node in the same linked list, push it into the
            // min-heap
            if (curr->next != nullptr) {
                minHeap.push({curr->next->val, curr->next});
            }
        }

        tail->next = nullptr; // Set the next of the last node to null

        return dummy
            ->next; // Return the merged linked list (skipping the dummy node)
    }
};