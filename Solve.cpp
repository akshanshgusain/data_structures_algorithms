#include<stdc++.h>

using namespace std;

vector<int> countSort(vector<int> &ip){
    int maxi = 0;
    for(auto it: ip){
        maxi = max(maxi, it);
    }

    vector<int> countArray(maxi+1, 0);
    for(auto it: ip){
        countArray[it]++;
    }

    // pre sum
    for(int i=1;i <= maxi; i++){
        countArray[i] += countArray[i-1];
    }

    vector<int> outputArray(ip.size());

    for(auto it: ip){
        outputArray[countArray[it] - 1] = it;
        countArray[it]--;
    }

    return outputArray;
}


// Driver Code
int main() {
    vector<int> ip = {2, 5, 3, 0, 2, 3, 0, 3};
    vector<int> op = countSort(ip);

    for (auto it: op) {
        cout << it << " ";
    }
    return 0;
}

