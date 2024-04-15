//
// Created by Akshansh Gusain on 02/04/24.
//


//https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/
// Completeness: https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/

#include "../BinaryTree/BT_000.cpp"

int countNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return (1 + countNodes(root->left)
            + countNodes(root->right));
}

bool isCompleteUtil(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *top = q.front();
            q.pop();

            if (top->left != nullptr) {
                if (flag) {
                    return false;
                }
                q.push(top->left);
            } else {
                flag = true;
            }
            if (top->right != nullptr) {
                if (flag) {
                    return false;
                }
                q.push(top->right);
            } else {
                flag = true;
            }
        }
    }
    return true;
}

bool checkHeapProperty(TreeNode *root) {
    //  Base case : single
    // If Node has No child then it’s a leaf node and returns true
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    //  If Node has one child (it must be left child because it is a complete tree) then we need to compare this
    //  node with its single child only.
    else if (root->right == nullptr) {
        //  check heap property at Node
        //  No recursive call ,
        // because no need to check last level
        return (root->val >= root->left->val);
    }
        // If the Node has both child then check heap property at Node at recur for both subtrees
    else {
        //  Check heap property at Node and
        //  Recursive check heap
        // property at left and right subtree
        if (root->val >= root->left->val and root->val >= root->right->val) {
            return (checkHeapProperty(root->left) and checkHeapProperty(root->right));
        } else {
            return false;
        }

    }
}

bool isHeap(TreeNode *root) {
    //Given a binary tree, we need to check it has heap property or not,
    // Binary tree need to fulfill the following two conditions for being a heap –

    //1. It should be a complete tree (i.e. all levels except last should be full).
    //2 .Every node’s value should be greater than or equal to its child node (considering max-heap).
    int nodeCount = countNodes(root);
    int index = 0;

    if (isCompleteUtil(root) and checkHeapProperty(root)) {
        return true;
    }

    return false;
}

int main() {
    TreeNode *root = NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
    return 0;
}

