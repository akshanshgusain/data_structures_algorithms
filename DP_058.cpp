//
// Created by Akshansh Gusain on 31/12/21.
//

#include<stdc++.h>
using namespace std;

int maxLoot(int value[], int n){
    if(n == 0 ){
        return 0;
    }
    if(n == 1){
        return value[0];
    }
    if(n ==2){
        return max(value[0], value[1]);
    }

    int T[n];

    // T[i] Stores max Value from start to ith position
    T[0] = value[0];
    T[1] = max(value[0], value[1]);

    for(int i =2; i < n; i++){

        T[i] = max(
                // If coming from i-1th house then I can't steel anything from ith house
                T[i-1] ,
                // If coming from i-2th house then I can't steel from ith house
                   T[i-2]+ value[i]
                   );
    }

    return T[n-1];

}

int main(){
    int val[] = {6, 7, 1, 3, 8, 2, 4};
    int n = sizeof(val)/sizeof(val[0]);
    cout << "Maximum loot possible : "
         << maxLoot(val, n);
    return 0;
}