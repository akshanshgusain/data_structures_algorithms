//
// Created by Akshansh Gusain on 05/06/21.
//
#include<stdc++.h>
using namespace std;

void copySetBits(unsigned &x, unsigned y,
                 unsigned l, unsigned r)
{
    // l and r must be between 1 to 32
    if (l < 1 || r > 32)
        return ;

    // get the length of the mask
    int maskLength = (1<<(r-l+1)) - 1;

    // Shift the mask to the required position
    // "&" with y to get the set bits at between
    // l ad r in y
    int mask = ((maskLength)<<(l-1)) & y ;
    x = x | mask;
}

int main(){

    unsigned x = 10, y = 13, l = 2, r = 3;
    copySetBits(x, y, l, r);
    cout << "Modified x is " << x;

    return 0;
}
