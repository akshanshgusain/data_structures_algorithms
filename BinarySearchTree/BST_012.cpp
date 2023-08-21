//
// Created by Akshansh Gusain on 21/02/22.
//

#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right, *next;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
        next = nullptr;
    }
};

void inOrder(Node *head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}


void preOrder(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void buildArray(Node *root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    buildArray(root->left, arr);
    arr.push_back(root->data);
    buildArray(root->right, arr);
}

vector<int> mergeTwoSortedArrays(vector<int> arr1, vector<int> arr2) {
    int m = arr1.size();
    int n = arr2.size();
    vector<int> mergedArr(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m and j < n) {
        // Pick the smaller element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }

    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }

    return mergedArr;
}

Node *BSTFromSortedArray(vector<int> &arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = BSTFromSortedArray(arr, start, mid - 1);
    root->right = BSTFromSortedArray(arr, mid + 1, end);

    return root;
}

Node *mergeTrees(Node *root1, Node *root2, int m, int n) {
    if (m == 0) {
        return root2;
    }
    if (n == 0) {
        return root1;
    }

    vector<int> sortedArray1, sortedArray2;
    buildArray(root1, sortedArray1);
    buildArray(root2, sortedArray2);
    vector<int> mergedArrays = mergeTwoSortedArrays(sortedArray1, sortedArray2);
    return BSTFromSortedArray(mergedArrays, 0 , mergedArrays.size()-1);
}



//  Time complexity of this method is O(m+n)

/*
1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m)
 time.
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes
 O(n) time.
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size
 m + n. This step takes O(m+n) time.
4) Construct a balanced tree from the merged array using the technique.
 This step takes O(m+n) time.
 * */

int main() {
/* Create following tree as first balanced BST
        100
       /    \
     50     300
    /  \
  20    70
    */
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /* Create following tree as second balanced BST
            80
          /    \
        40     120
    */
    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    inOrder(mergedTree);

    return 0;
}
