//
// Created by Akshansh Gusain on 05/04/21.
//
#include<stdc++.h>

using namespace std;

class petrolPump {
public:
    int petrol;
    int distance;
};

int printTour(petrolPump arr[], int n) {
    //consider first petrol pump as a starting point
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    /* Run a loop while all petrol pumps are not visited.
    And we have reached first petrol pump again with 0 or more petrol */
    while (end != start or curr_petrol < 0) {

        // If current amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 and start != end) {

            //Remove starting petrol pump. Change start
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;

            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0) {
                return -1;
            }

        }
        //add a apetrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1) % n;
    }

    return start;
}

int main() {

    petrolPump arr[] = {{6, 4},
                        {3, 6},
                        {7, 3}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution" : cout << "Start = " << start;

    return 0;
}
