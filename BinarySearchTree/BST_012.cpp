//
// Created by Akshansh Gusain on 08/03/24.
//
#include "BST_000.cpp"

vector<int> mergeTwoSortedArrays(vector<int> arr1, vector<int> arr2) {
    int m = arr1.size();
    int n = arr2.size();
    vector<int> mergedArr(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m and j < n) {
        // Pick the smaller element and put it in mergedArr
        if (arr1[i] < arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are more elements in first array
    while (i < m) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // If there are more elements in second array
    while (j < n) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArr;
}

// Time complexity: O(n)
//Space complexity: O(log n)
TreeNode *helper(vector<int> &nums, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int mid = (l + r) / 2;
    auto root = new TreeNode(nums[mid]);

    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);
    return root;
}


/*
Time complexity of this method is O(m+n)
1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m)
 time.
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes
 O(n) time.
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size
 m + n. This step takes O(m+n) time.
4) Construct a balanced tree from the merged array using the technique.
 This step takes O(m+n) time.

*/
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2, int m, int n) {
    if (m == 0) {
        return root2;
    }
    if (n == 0) {
        return root1;
    }

    vector<int> sortedArray1, sortedArray2;
    buildInOrderArray(root1, sortedArray1);
    buildInOrderArray(root2, sortedArray2);
    vector<int> mergedArrays = mergeTwoSortedArrays(sortedArray1, sortedArray2);
    return helper(mergedArrays, 0, mergedArrays.size() - 1);
}


int main() {
/* Create following tree as first balanced BST
        100
       /    \
     50     300
    /  \
  20    70
    */
    auto root1 = new TreeNode(100);
    root1->left = new TreeNode(50);
    root1->right = new TreeNode(300);
    root1->left->left = new TreeNode(20);
    root1->left->right = new TreeNode(70);

    /* Create following tree as second balanced BST
            80
          /    \
        40     120
    */
    auto root2 = new TreeNode(80);
    root2->left = new TreeNode(40);
    root2->right = new TreeNode(120);

    auto *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printBST(mergedTree);
    return 0;
}