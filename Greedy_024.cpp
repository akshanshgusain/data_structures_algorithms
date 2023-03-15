//
// Created by Akshansh Gusain on 13/09/22.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int c;//number of test cases
    long long n,k,b,t;
    long long X[51], V[51];
    cin>>c;
    for(int i= 1; i<=c; i++){
        cin>>n>>k>>b>>t;
        for(int j =0; j<n;j++){
            cin>> X[j];
        }
        for(int j =0; j<n;j++){
            cin>> V[j];
        }


        long num =0;
        long result =0;
        long swaps =0;

        //we'll start from the chick closest to the barn
        for(int j = n-1; j>=0 ; j--){
            long long distanceCovered = V[j]*t;
            long long distanceToCover = b - X[j];

            if(distanceToCover <= distanceCovered){
                num++;
                if(swaps > 0){
                    result += swaps;
                }
            }else{
                swaps++;
            }
            if(num == k){
                break;
            }
        }
        if(num<k){
            cout<<"Case #"<<i<<"Impossible"<<endl;
        }else{
            cout << "Case #" << i << ": " << result << endl;
        }
    }
    return 0;
}