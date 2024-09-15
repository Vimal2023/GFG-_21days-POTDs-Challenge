#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cassert>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <deque>
#include <list>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* prev = NULL;
    Node* head = NULL;

    void convertToDLL(Node* root) {
        if (root == NULL) return;

        convertToDLL(root->left);

        if (prev == NULL) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }

        prev = root;

        convertToDLL(root->right);
    }

    Node* bToDLL(Node* root) {
        convertToDLL(root);
        return head;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    Solution ob;
    Node* head = ob.bToDLL(root);

    printList(head);

    return 0;
}