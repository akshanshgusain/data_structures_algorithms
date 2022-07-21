//
// Created by Akshansh Gusain on 23/03/21.
//
/*

 Sort all pairs(Meetings) in increasing order of second number(Finish time) of each pair.
Select first meeting of sorted pair as the first Meeting in the room and push it into result vector and set a variable time_limet(say) with the second value(Finishing time) of the first selected meeting.
Iterate from the second pair to last pair of the array and if the value of the first element(Starting time of meeting) of the current pair is greater then previously selected pair finish time (time_limit) then select the current pair and update the result vector (push selected meeting number into vector) and variable time_limit.
Print the Order of meeting from vector.

 */
#include<stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1,struct meeting m2){
    return (m1.end < m2.end);
}

void maxMeeting(int s[], int f[], int n){
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = s[i];
            meet[i].end = f[i];
            meet[i].pos = i+1;
        }

        sort(meet, meet+n, comparator);
        vector<int> result;
        result.push_back(meet[0].pos);

        //timelimit to check whether new meeting can be conducted or not;
        int timeLimit = meet[0].end;

        //check for all meeting whether they can be selected or not;
        for(int i =1; i<n; i++){
            if(meet[i].start >= timeLimit){
                result.push_back(meet[i].pos);
                timeLimit = meet[i].end;
            }
        }
        //print all the meetings
        for(auto i: result){
            cout<< i <<" th meeting, starting at: "<<meet[i-1].start <<" ,ending at: "<<meet[i-1].end<<endl;
        }
}

int main(){
    int s[] = {1,3,0,5,8,5};
    int f[] ={2,4,6,7,9,9};

    int n = sizeof(s)/ sizeof (s[0]);
    maxMeeting(s,f,n);
    return 0;
}
