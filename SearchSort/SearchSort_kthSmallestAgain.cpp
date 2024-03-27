//
// Created by Akshansh Gusain on 24/02/21.
//We have to first sort all the intervals and merge the overlapping ones...
//Then we have to find that interval in which the Kth smallest element
// lies and return it.
#include<stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t; //Number of test cases
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> v;

        for(int i=0; i<n ;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }

        sort(v.begin(), v.end());
        int index = 0;

        for(int i=1; i< v.size(); i++){
            if(v[index].second >= v[i].first){
                v[index].second = max(v[index].second, v[i].second);
            }else{
                index++;
                v[index] = v[i];
            }
        }

        while(q--){
            int k;
            cin>>k;
            int ans = -1;
            for(int i=0; i < index; i++){
                if((v[i].second - v[i].first + 1)>=k){
                    ans = v[i].first + k -1;
                    break;
                }else{
                    k = k - (v[i].second - v[i].first +1);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

