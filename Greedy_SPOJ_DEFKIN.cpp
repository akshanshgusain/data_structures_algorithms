//
// Created by Akshansh Gusain on 25/03/21.
//
#include<stdc++.h>

using namespace std;

void mergesort(int A[], int low, int mid, int high, int N) {
    int i, j, k, l, m, temp[N];
    i = low;
    l = low;
    m = mid + 1;
    while (i <= mid && m <= high) {
        if (A[i] <= A[m])
            temp[l++] = A[i++];
        else
            temp[l++] = A[m++];
    }
    while (i <= mid)
        temp[l++] = A[i++];
    while (m <= high)
        temp[l++] = A[m++];
    for (i = low; i <= high; i++)
        A[i] = temp[i];
}

void partition(int A[], int LB, int UB, int N) {
    int mid;
    if (LB < UB) {
        mid = (LB + UB) / 2;
        partition(A, LB, mid, N);
        partition(A, mid + 1, UB, N);
        mergesort(A, LB, mid, UB, N);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  temp_x, temp_y;
        int w, h, n;
        int x[40002];
        int y[40002];
        cin >> w >> h >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            cin >> y[i];
        }

        partition(x, 0, n - 1, n);
        partition(y, 0, n - 1, n);

        x[n] = w + 1;
        y[n] = h + 1;

        long long max_x, max_y;
        max_x = x[0];
        max_y = y[0];

        //Calculate the max x-distance between 2 crossbow towers and max y-distance between 2 crossbow towers
        //that will give you the max unprotected area(x*y)
        for (int i = 1; i <= n; i++) {
            temp_x = x[i] - x[i - 1];
            temp_y = y[i] - y[i - 1];
            if (max_x < temp_x)
                max_x = temp_x;
            if (max_y < temp_y)
                max_y = temp_y;
        }

        cout << (max_y - 1) * (max_x - 1) << "\n";
    }
    return 0;
}
