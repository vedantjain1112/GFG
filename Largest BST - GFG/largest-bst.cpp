//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
       struct Info {
        int size;      
        int min;        
        int max;    
        int ans;    
        bool isBST;
    };
    
    Info largestBSTUtil(Node* root) {
        if (!root) {
            return {0, INT_MAX, INT_MIN, 0, true};
        }
    
        if (!root->left && !root->right) {
            return {1, root->data, root->data, 1, true};
        }
    
        Info leftInfo = largestBSTUtil(root->left);
        Info rightInfo = largestBSTUtil(root->right);
    
        Info current;
        current.size = 1 + leftInfo.size + rightInfo.size;
    
        if (leftInfo.isBST && rightInfo.isBST &&
            leftInfo.max < root->data && rightInfo.min > root->data) {
            current.min = std::min(leftInfo.min, std::min(rightInfo.min, root->data));
            current.max = std::max(rightInfo.max, std::max(leftInfo.max, root->data));
    
            current.ans = current.size;
            current.isBST = true;
        } else {
            current.ans = std::max(leftInfo.ans, rightInfo.ans);
            current.isBST = false;
        }
    
        return current;
    }

    int largestBst(Node* root) {
        return largestBSTUtil(root).ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends