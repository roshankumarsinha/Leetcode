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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next; // Store the next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr;       // Move prev to the current node
        curr = next;       // Move to the next node
    }

    return prev; // New head of the reversed list
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // If 0 or 1 element
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* fast = head;
        ListNode* slow = head;

        // To calculate middle of Linked-List
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        bool isPalindrome = true;

        // Compare both the half's
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }

        return isPalindrome;
    }
};