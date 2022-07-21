//
// Created by Akshansh Gusain on 03/04/21.
//https://www.youtube.com/watch?v=0do2734xhnU


#include<stdc++.h>
using namespace std;

int getMaxArea(int his[], int n){
    //Nearest Smallest element on the right
    int rb[n];
    stack<int> st;

    st.push(n-1);
    rb[n-1] = n;
    for(int i = n-2; i >= 0; i--){
        while(!st.empty() and his[i] <= his[st.top()]){
            st.pop();
        }

        if(st.empty()){
            rb[i] = n;
        }else{
            rb[i] = st.top();
        }
        st.push(i);
    }

    //Nearest Smallest element on the left
    int lb[n];
    stack<int> st2;

    st2.push(0);
    lb[0] = -1;
    for(int i = 1; i < n; i++){
        while(!st2.empty() and his[i] <= his[st2.top()]){
            st2.pop();
        }

        if (st2.empty()) {
            lb[i] = -1;
        } else {
            lb[i] = st2.top();
        }

        st2.push(i);
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int width = rb[i] - lb[i] - 1;
        int area = width * his[i];
        if (area > max) {
            max = area;
        }
    }

    return max;
}

int main(){
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
