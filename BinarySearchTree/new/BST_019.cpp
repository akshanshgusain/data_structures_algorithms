//
// Created by Akshansh Gusain on 24/03/24.
//
#include "BST_000.cpp"

// Time: O(N^2)
// Sol 1: Find the first greater value on right side of current node.
//   Let the index of this node be j. Return true if following
//   conditions hold. Else return false
//    (i)  All values after the above found greater value are
//         greater than current node.
//    (ii) Recursive calls for the sub arrays pre[i+1..j-1] and
//         pre[j+1..n-1] also return true.

// Time: O(N)
// Sol 2: Find Next Greater Element, using stacks
//1) Create an empty stack.
//2) Initialize root as INT_MIN.
//3) Do following for every element pre[i]
//     a) If pre[i] is smaller than current root, return false.
//     b) Keep removing elements from stack while pre[i] is greater
//        then stack top. Make the last removed item as new root (to
//        be compared next).
//        At this point, pre[i] is greater than the removed root
//        (That is why if we see a smaller element in step a), we
//        return false)
//     c) push pre[i] to stack (All elements in stack are in decreasing
//        order)

bool canRepresentBST(vector<int> preorder) {
    int n = preorder.size();
    stack<int> s;

    int root = INT_MIN;

    // Traverse given array
    for (int i = 0; i < n; i++) {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (preorder[i] < root)
            return false;

        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top() < preorder[i]) {
            root = s.top();
            s.pop();
        }

        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(preorder[i]);
    }
    return true;
}

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 10);
    insertInBST(root, 5);
    insertInBST(root, 50);
    insertInBST(root, 1);
    insertInBST(root, 40);
    insertInBST(root, 100);

    vector<int> preorder2 = {5, 3, 4, 1, 6, 10};
    if (canRepresentBST(preorder2))
        cout << "\npreorder2 can represent BST";
    else
        cout << "\npreorder2 can not represent BST";
    return 0;
}