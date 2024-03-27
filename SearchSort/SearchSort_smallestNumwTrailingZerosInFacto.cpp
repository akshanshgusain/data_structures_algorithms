//
// Created by Akshansh Gusain on 01/03/21.
//
#include<stdc++.h>
using namespace std;

bool check(int p, int n)
{
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp/f;
        f = f*5;
    }
    return (count >= n);
}

int findNum(int n){
    if(n ==1){
        return 1;
    }
    int low = 0;
    int high = 5*n;

    while (low <high)
    {
        int mid = (low + high) >> 1;

        // Checking if mid's factorial contains
        // n trailing zeroes.
        if (check(mid, n))
            high = mid;
        else
            low = mid+1;
    }

    return low;
}

int main(){
    int n;
    cin>>n;
    cout<< findNum(n)<<endl;
    return 0;
}

