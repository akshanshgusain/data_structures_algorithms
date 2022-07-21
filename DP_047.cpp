//
// Created by Akshansh Gusain on 28/12/21.
//

#include<stdc++.h>

using namespace std;

pair<int, int> Maximize(string S, int i, int j)
{
    if(i>j)
        return {0, 0};
    if(i==j)
        return {S[i]-48, S[i]-48};
    int maxim = INT_MIN;
    int minim = INT_MAX;

    int k, res;
    for(k=i+1;k<j;k+=2)
    {
        // evaluate the left expression
        auto leftr = Maximize(S, i, k-1);
        // evaluate the right expression
        auto rightr = Maximize(S, k+1, j);

        for (auto sign1 = 0; sign1 < 2; ++sign1) {
            for (auto sign2 = 0; sign2 < 2; ++sign2) {

                int l = sign1? leftr.first: leftr.second;
                int r = sign2? rightr.first: rightr.second;

                if(S[k]=='/')
                    res = l / r;
                else if(S[k]=='*')
                    res = l * r;
                else if(S[k]=='-')
                    res = l - r;
                else
                    res = l + r;
                // update the minim and the maxim variable
                if(res>maxim)
                    maxim = res;
                if(res<minim)
                    minim = res;
            }
        }

    }
    return {maxim, minim};
}

int main()
{
    string S;
    int j;
    // cin>>S;
    S = "1+2*3+4*5";
    j = S.size()-1;
    auto res = Maximize(S, 0, j);
    cout << res.first << " " << res.second << "\n";

    return 0;
}