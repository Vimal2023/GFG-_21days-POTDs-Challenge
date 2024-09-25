#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalfHead = reverseList(slow);
    Node* firstHalfHead = head;

    Node* temp = secondHalfHead;
    bool isPalin = true;
    while (temp != nullptr) {
        if (firstHalfHead->data != temp->data) {
            isPalin = false;
            break;
        }
        firstHalfHead = firstHalfHead->next;
        temp = temp->next;
    }

    reverseList(secondHalfHead);
    return isPalin;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

int main() {
    Node* head = nullptr;
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    if (isPalindrome(head)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}
