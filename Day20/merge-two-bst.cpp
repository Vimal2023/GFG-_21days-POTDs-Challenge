#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    void inorder(Node* root, vector<int>& result) {
        if (root == NULL) return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }

    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        int i = 0, j = 0;
        vector<int> merged;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                merged.push_back(arr1[i]);
                i++;
            } else {
                merged.push_back(arr2[j]);
                j++;
            }
        }

        while (i < arr1.size()) {
            merged.push_back(arr1[i]);
            i++;
        }

        while (j < arr2.size()) {
            merged.push_back(arr2[j]);
            j++;
        }

        return merged;
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> bst1_inorder, bst2_inorder;
        inorder(root1, bst1_inorder);
        inorder(root2, bst2_inorder);
        return mergeSortedArrays(bst1_inorder, bst2_inorder);
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        Node* root2 = buildTree(s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}
