//
// Created by Akshansh Gusain on 02/02/21.
//
#include<stdc++.h>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high){
    struct Pair minMax, mml, mmr;
    int mid;

    //if there is only one element
    if(low == high){
        minMax.max = arr[low];
        minMax.min = arr[low];
        return minMax;
    }

    //if there are only two elements
    if(high == low+1){
            if(arr[low] > arr[high]){
                minMax.max = arr[low];
                minMax.min = arr[high];
            }else{
                minMax.min = arr[low];
                minMax.max = arr[high];
            }
            return minMax;
    }

    //if there are more than 2 elements
    mid = (low+high)/2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid+1, high);

    //compare the min of the 2 parts
    if(mml.min < mmr.min){
        minMax.min = mml.min;
    }else{
        minMax.min = mmr.min;
    }

    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minMax.max = mml.max;
    else
        minMax.max = mmr.max;

    return minMax;
}

int main(){
    int arr[] = { 1000, 11, 445,
                  1, 330, 3000 };
    int arr_size = 6;

    struct Pair minmax = getMinMax(arr, 0,
                                   arr_size - 1);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}
