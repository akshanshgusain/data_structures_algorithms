//
// Created by Akshansh Gusain on 26/03/21.
//

/*A[i] = Amplification Factor
 * Signal Strength Y^X(x- received strength, y-loaded in it)
 */
#include<stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>t;
    while (t--){
        cin>>n; // number of amplifiers
        int array[n], count1 =0,count =0, input, j=0;
        for(int i= 0; i<n ;i++){
            cin>>input;//load value of each amplifier
            if(input==1)
                count1++;
            else{
                array[j++] = input;
                count++;
            }
        }
        sort(array, array+count);
        for(int i = 0; i<count1 ; i++){
            cout<<"1 ";
        }
        if(count==2 && array[0]==2 && array[1]==3){
            cout<<2<<" "<<3;
        }else{
            for(int i = count-1 ; i>=0; i--){
                cout<<array[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
