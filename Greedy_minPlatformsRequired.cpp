//
// Created by Akshansh Gusain on 22/03/21.
//
#include<stdc++.h>
using namespace std;

//int findPlatform(int arr[], int arr2[], int n){
//    int plat_needed, result = 1;
//    int i = 1, j = 0;
//
//    // run a nested  loop to find overlap
//    for (i = 0; i < n; i++) {
//        // minimum platform
//        plat_needed = 1;
//
//        for (j = i + 1; j < n; j++) {
//            // check for overlap
//            if ((arr[i] >= arr[j] && arr[i] <= dep[j])
//                || (arr[j] >= arr[i]
//                    && arr[j] <= dep[i]))
//                plat_needed++;
//        }
//
//        // update result
//        result = max(result, plat_needed);
//    }
//  return result;
//}


/*The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of
 * trains at any time keeping track of trains that have arrived, but not departed.*/

int findPlatform(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n) {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }

            // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }

        // Update result if needed
        if (plat_needed > result)
            result = plat_needed;
    }

    return result;
}
int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
    return 0;
}