//
// Created by Akshansh Gusain on 22/08/23.
//

#include<stdc++.h>

using namespace std;

void tugOfWarUtil(vector<int> &arr, int n,
                  vector<bool> &curr_elements,
                  int no_of_selected_elements,
                  vector<bool> &sol,
                  int &min_diff,
                  int sum,
                  int curr_sum,
                  int curr_position) {

    if (curr_position == n) {
        return;
    }

    // checks that the numbers of elements left are not less than the
    // number of elements required to form the solution
    if ((n / 2 - no_of_selected_elements) > (n - curr_position)) {
        return;
    }

    // consider the cases when current element is not included in the solution
    tugOfWarUtil(arr, n, curr_elements, no_of_selected_elements,
                 sol, min_diff, sum, curr_sum, curr_position + 1);

    // add the current element to the solution
    no_of_selected_elements++;
    curr_sum = curr_sum + arr[curr_position];
    curr_elements[curr_position] = true;

    // checks if a solution is formed
    if (no_of_selected_elements == n / 2) {
        // checks if the solution formed is better than the best solution so far
        if (abs(sum / 2 - curr_sum) < min_diff) {
            min_diff = abs(sum / 2 - curr_sum);
            for (int i = 0; i < n; i++)
                sol[i] = curr_elements[i];
        }
    } else {
        // consider the cases where current element is included in the solution
        tugOfWarUtil(arr, n, curr_elements, no_of_selected_elements, sol,
                     min_diff, sum, curr_sum, curr_position + 1);
    }

    // removes current element before returning to the caller of this function
    curr_elements[curr_position] = false;

}

void tugOfWar(vector<int> &arr) {
    int n = arr.size();
    vector<bool> currentElement(n, false);

    //the inclusion/exclusion array for final solution
    vector<bool> result(n, false);

    int min_diff = INT_MAX;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Find the solution using recursive function tugOfWarUtil()
    tugOfWarUtil(arr, n, currentElement, 0, result, min_diff, sum, 0, 0);

    //Print solution
    cout << "The first subset is: ";

    for (int i = 0; i < n; i++) {
        if (result[i])
            cout << arr[i] << " ";
    }
    cout << "\nThe second subset is: ";
    for (int i = 0; i < n; i++) {
        if (!result[i])
            cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    tugOfWar(arr);

    return 0;
}

/*
The first subset is: 45 -34 12 98 -1
The second subset is: 23 0 -99 4 189 4

 */