//
// Created by Akshansh Gusain on 25/02/21.
//
#include<stdc++.h>
using namespace std;
int t,n,c;

//int func(int num, int array[], int n, int c){
//    int cows=1, pos = array[0];
//    for(int i=1; i<n; i++){
//        if(array[i]-pos >= num){
//            pos = array[i];
//            cows++;
//            if(cows==c){
//                return 1;
//            }
//        }
//    }
//    return 0;
//}
//
//int distance(int array[], int  n, int c){
//    int init =0 ,last = array[n-1], max= -1;
//
//    while(last>init){
//        int mid = (init+last)/2;
//        if(func(mid, array,n,c)==1){
//            if(mid>max){
//                max = mid;
//            }
//            init = mid+1;
//        }else{
//            last = mid;
//        };
//    }
//    return max;
//}
//
//int main(){
//    int t;
//    cin>>t;
//    int n,c;
//    while(t--){
//        cin>>n>>c;
//        int a[n];
//        for(int i=0;i<n;i++){
//            cin>>a[i];
//        }
//        sort(a,a+n);
//        cout<<distance(a,n,c);
//    }
//    return 0;
//}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>c;
        int a[n];
        for(int i= 0; i<n; i++){
            cin>>a[i];
        }

        sort(a,a+n); //sor the input test case
        int low=0, high = a[n-1], mid, best =0;
        while(low <= high){
            mid = (low+high+1)/2;
            int cnt = 1, left = 0;

            for(int i=1; i<n && cnt < c;i++){
                if(a[i]-a[left] >= mid){
                    left = i;
                    cnt++;
                }
            }
            if(cnt >= c){
                best = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        cout<<best<<endl;
    }
}