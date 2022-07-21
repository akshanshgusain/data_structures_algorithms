//
// Created by Akshansh Gusain on 09/05/21.
//
#include<stdc++.h>
using namespace std;
#define NULL 0
#define MAX_CHAR 26

//Trie Data structure

struct Trie{
    char data;
    int wordEnd;
    Trie *children[MAX_CHAR];
};

Trie nodePool[100000]; // Pool of 100k Trie Nodes
Trie *root; // Root of the tree
int poolCount;//Always points to the next free trie node

//Initialize Trie
void init(){
    poolCount = 0;
    root = &nodePool[poolCount++];
    root->data = '%';
    for(auto & i : root->children){
        i = nullptr;
    }
}

Trie *getNewNode(char ch){
    Trie *newNode = &nodePool[poolCount++];
    newNode->data = ch;
    for(auto & i : newNode->children){
        i = nullptr;
    }
    newNode->wordEnd = 0;
    return newNode;
}

void insertWord(char *s){
    Trie *curr = root;
    int index;
    for(int i =0; s[i] != '\0'; i++){
        index = s[i] - 'a'; // relative position of character s[i]
        if(curr->children[index] == nullptr){
            curr->children[index] = getNewNode(s[i]);
        }
        curr->children[index]->wordEnd += 1;
    }
}

bool search(char *s){
    Trie *curr = root;
    int index;
    for(int i=0; s[i] != '\0'; i++){
        index = s[i] - 'a'; // relative position of character s[i]
        if(curr->children[index] == nullptr or curr->children[index]->wordEnd==0){
            return false;
        }
        curr->children[index]->wordEnd += 1;
        curr = curr->children[index];
    }
    return true;
}

bool deleteWord(char *s){
    if(search(s)){
        Trie *curr = root;
        int index;
        for(int i=0; s[i] != '\0'; i++){
            index = s[i] - 'a';
            curr->children[index]->wordEnd -= 1;
            curr = curr->children[index];
        }
    }
}

int countPrefix(string s)
{
    Trie *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->children[index]==nullptr || curr->children[index]->wordEnd == 0)
            return 0;   //No string with given prefix is present
        curr = curr->children[index];
    }
    return curr->wordEnd;
}

int main(){

    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insertWord(a);
    insertWord(b);
    insertWord(c);
    insertWord(d);
    insertWord(e);
    insertWord(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}
