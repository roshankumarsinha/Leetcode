/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* originalList = head;
        Node* temp = new Node(-1);
        Node* clonedTemp = temp;

        // Copy normal list into cloned list without copying random pointers
        while (originalList != nullptr) {
            Node* newNode = new Node(originalList->val);
            temp->next = newNode;
            temp = temp->next;
            originalList = originalList->next;
        }

        // Create a map to store originalList, clonedList together
        unordered_map<Node*, Node*> mp;
        originalList = head;
        Node* clonedList = clonedTemp->next;
        while (originalList != nullptr) {
            mp[originalList] = clonedList;
            originalList = originalList->next;
            clonedList = clonedList->next;
        }
        originalList = head;
        clonedList = clonedTemp->next;

        // With use of map clone random pointers into clonedList
        while (originalList != nullptr) {
            clonedList->random = mp[originalList->random];
            originalList = originalList->next;
            clonedList = clonedList->next;
        }
        return clonedTemp->next;
    }
};