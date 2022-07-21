//
// Created by Akshansh Gusain on 08/05/21.
//
#include<stdc++.h>
using namespace std;

int f=0;

void bipartite(int src, int par, int col, vector<int> &color, vector<int> g[]){
    color[src] = col;
    for(auto it: g[src]){
        if(!color[it]){
            bipartite(it,src,3-col,color,g);
        }else if(it!=par and col==color[it]){
            f = 1;
            break;
        }
    }
}

int solve(){
    int v,e;
    cin>>v,e;
    vector<int> g[v];
    for(int i =0; i<e;i++){
        int x,y;
        cin>>x,y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> reverse[v];
    vector<int> dummy(v,0);

    for(int i=0; i< v;i++){
        dummy[i] = 1;
        for(auto it : g[i]){
            dummy[it] = 1;
        }
        for(int j=0; j<v;j++){
            if(dummy[j]==0){
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }

    vector<int> color(v,0);
    bipartite(0,0,1,color,reverse);
    if(!f){
        cout<<"Two Clique"<<endl;
    }else{
        cout<<"Not Possible"<<endl;
    }
}
int main(){

    return 0;
}

