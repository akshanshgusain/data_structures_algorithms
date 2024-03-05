//
// Created by Akshansh Gusain on 23/02/24.
//
#include "BT_000.cpp"

int findComplementaryIndex(string &ip, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return -1;
    }
    stack<char> stack;
    while (startIndex <= endIndex) {
        if (ip[startIndex] == '(') {
            stack.push(ip[startIndex]);
        }
        if (ip[startIndex] == ')') {
            if (stack.top() == '(') {
                stack.pop();
                if (stack.empty()) {
                    return startIndex;
                }
            }
        }
        startIndex++;
    }
    return -1;
}

// time: O(n^2), space: O(n)
TreeNode *treeFromString(string &ip, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return nullptr;
    }

    auto *root = new TreeNode(ip[startIndex] - '0');
    // if the next char is (, then find its complementary )
    int indexOfComplement = -1;
    if (startIndex + 1 <= endIndex and
        ip[startIndex + 1] == '(') {
        indexOfComplement = findComplementaryIndex(ip, startIndex + 1, endIndex);
    }

    // if the index is found
    if (indexOfComplement != -1) {
        root->left = treeFromString(ip, startIndex + 2, indexOfComplement - 1);
        root->right = treeFromString(ip, indexOfComplement + 2, endIndex - 1);
    }

    return root;
}

TreeNode *treeFromStringOptimised(string ip) {
    if (ip.empty()) {
        return nullptr;
    }
    int openingBracketIndex = ip.find('(');
    // if no '(' is found in the sting
    // there is only one Node
    if (openingBracketIndex == string::npos) {
        return new TreeNode(stoi(ip));
    }

    auto root = new TreeNode(stoi(ip.substr(0, openingBracketIndex)));
    int start = openingBracketIndex;
    int count = 0;

    for (int i = openingBracketIndex; i < ip.size(); i++) {
        if(ip[i] == '('){
            count++;
        }else if(ip[i] == ')'){
            count--;
        }
        if(count == 0){
            if(start == openingBracketIndex){
                root->left = treeFromStringOptimised(ip.substr(start+1, i - start - 1));
                start = i + 1;
            }else{
                root->right = treeFromStringOptimised(ip.substr(start+1, i - start - 1));
            }
        }
    }

    return root;
}

int main() {
    string str = "4(2(3)(1))(6(5))"; // 4 2 3 1 6 5
    auto *root = treeFromString(str, 0, str.length() - 1);
    root = treeFromStringOptimised(str);
    printPreorder(root);
    return 0;
}