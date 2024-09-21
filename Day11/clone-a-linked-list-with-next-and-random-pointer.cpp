#include <iostream>
using namespace std;

// Definition for the Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyList(Node *head) {
        if (head == NULL) return NULL;
        
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = new Node(curr->data);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* clonedHead = head->next;
        Node* clonedCurr = clonedHead;

        while (curr != NULL) {
            curr->next = curr->next->next;
            if (clonedCurr->next != NULL) {
                clonedCurr->next = clonedCurr->next->next;
            }
            curr = curr->next;
            clonedCurr = clonedCurr->next;
        }

        return clonedHead;
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << "Node data: " << head->data;
        if (head->random != NULL) {
            cout << ", Random points to: " << head->random->data;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        head = head->next;
    }
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next;
    head->next->random = head->next->next->next;

    Solution sol;
    Node* clonedHead = sol.copyList(head);

    cout << "Original list:" << endl;
    printList(head);

    cout << "\nCloned list:" << endl;
    printList(clonedHead);

    return 0;
}
