//
// Created by Akshansh Gusain on 22/01/21.
//
#include<stdc++.h>

using namespace std;

int values(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

int romanToDecimal(string& str){
    int res = 0;

    //traverse the given input
    for(int i =0; i<str.size() ;i++){
        int s1 = values(str[i]);

        if(i+1< str.length()){
            int s2 = values(str[i+1]);

            if(s1>=s2){
                //value of current symbol is greater than or equal to next symbol
                res+=s1;
            }else{
                //value of current symbol is less than to the next symbol
                res+= s2-s1;
                i++;
            }
        }else{
            res+=s1;
        }
    }

    return res;
}

int main() {
    string str = "MCMIV";
    str="III";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
    return 0;
}
