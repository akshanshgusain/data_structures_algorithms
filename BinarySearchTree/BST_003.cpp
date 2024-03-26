//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

// Left-Most value will be the minimum
TreeNode *minValue(TreeNode *root) {
    auto *successor = root;
    while(successor != nullptr and successor->left != nullptr){
        successor = successor->left;
    }
    return successor;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(root == nullptr){
        return root;
    }

    // find the key
    if(root->val > key){
        root->left = deleteNode(root->left, key);
    }else if(root->val < key){
        root->right = deleteNode(root->right, key);
    }else{

        // case 1: no children
        if(root->left  == nullptr and root-> right == nullptr){
            delete(root);
            return nullptr;
        }
        // case 2: only one child
        else if(root->left == nullptr){
            auto temp = root->right;
            delete(root);
            return temp;
        }else if(root->right == nullptr){
            auto temp = root->left;
            delete(root);
            return temp;
        }

        //case 2: both children present
        else{
            // get the inOrder Successor (Smallest value in the right subtree)
            // or ge the inOrder Predecessor (Largest Value in the Left subtree)
            auto temp = minValue(root->right);
            root->val = temp->val;

            // recursively delete inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
    }

    return root;
}

int main(){
    /* Let us create following BST
           50
        /      \
       30      70
    /    \    /   \
   20    40  60    80 */

    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << "Inorder traversal of the given tree \n";
    printBST(root);
    cout<<endl<<endl;

    cout << "Case 1:Leaf Node: Delete 20" << endl;
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    printBST(root);
    cout<<endl<<endl;

    cout << "Case 2:Node with one child:  Delete 30" << endl;
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    printBST(root);
    cout<<endl<<endl;

    cout << "Case 3:Node with two children: Delete 50" << endl;
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    printBST(root);
    cout<<endl<<endl;

    return 0;
}