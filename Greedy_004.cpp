//
// Created by Akshansh Gusain on 20/08/22.
//
#include<bits/stdc++.h>

using namespace std;
#define int double

class Item {
public:
    int value;
    int weight;

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

bool comparator(Item &a, Item &b) {
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &arr, int n) {
    sort(arr.begin(), arr.end(), comparator);
    int ans = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++) {
        //check for overflow
        if(currWeight + arr[i].weight <= W){
            // Pick the item
            ans += arr[i].value;
            currWeight += arr[i].weight;
        }else{
            //Fractional
            int remaining = W - arr[i].weight;
            int unit = arr[i].value / arr[i].weight;
            ans += unit * remaining;
            break;
        }
    }
    return ans;
}

int_fast32_t main() {
    int W = 50;
    int n = 3;
    vector<Item> arr = {Item(60, 10),
                        Item(100, 20),
                        Item(120, 30)};
    cout << fractionalKnapsack(W, arr, n);
    return 0;
}