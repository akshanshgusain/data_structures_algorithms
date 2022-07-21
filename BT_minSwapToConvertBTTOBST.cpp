//
// Created by Akshansh Gusain on 13/03/21.
//
#include<stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v, int n, int index){
    if(index>=n)
        return;
    inorder()

}
int main(){
    int a[] = {5,7,8,9,10,11};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> v;
    inorder(a,v,n,0);
    cout<< minSwaps(v)<<endl;
    return 0;
}
