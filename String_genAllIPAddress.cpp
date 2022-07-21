//
// Created by Akshansh Gusain on 26/01/21.
//
#include<stdc++.h>
using namespace std;

//Function to check whether IP digits are valid or not
bool is_valid(string ip){
    //splitting by .
    vector<string> ips;
    string ex="";
    for(int i=0; i<ip.size();i++){
        if(ip[i] == '.'){
            ips.push_back(ex);
            ex="";
        }else{
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
    for(int i = 0; i< ips.size(); i++){

        if(ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255){ //stoi- string to integer
            return false;
        }
        if(ips[i].length() > 1 && stoi(ips[i]) == 0){
            return false;
        }
        if(ips[i].length() >1 && stoi(ips[i]) != 0 && ips[i][0] == '0'){
            return false;
        }
    }
    return true;
}



//Function converts string to IP address
void convert(string ip){
    int l = ip.length();

    //check for string size
    if(l > 12 || l < 4){
        cout<<"Not Valid IP Address";
    }
    string check = ip;
    vector<string> ans;

    //generating different combinations.
    for(int i=1; i< l-2; i++){
        for(int j=i+1; j < l-1 ;j++){
            for(int k= j+1; k < l;k++){

                check = check.substr(0,k)+"."+check.substr(k, l-k+2);
                cout<<check<<endl;

                check = check.substr(0,j)+"."+check.substr(i, l-j-3);
                cout<<check<<endl;

                check = check.substr(0,i)+"."+check.substr(i, l-i+4);
                cout<<check<<endl;
                cout<<"--------"<<endl;
                if(is_valid(check)){
                    ans.push_back(check);
                    cout<<check<<endl;
                }
                check = ip;
            }
        }
    }
}

int main(){
    string A = "25525511135";
    string B = "25505011535";

    convert(A);
    //convert(B);
    return 0;
}
