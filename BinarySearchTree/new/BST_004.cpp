//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

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