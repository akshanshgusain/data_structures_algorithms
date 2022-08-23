//
// Created by Akshansh Gusain on 19/08/22.
//
#include<bits/stdc++.h>

using namespace std;

struct Job {
    int id;     // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
public:
    Job(int id, int dead, int profit){
        this->id = id;
        this->dead = dead;
        this->profit = profit;
    }
};
bool comparator(Job &a, Job &b){
    return a.profit > b.profit;
}

void maxProfit(vector<Job> &jobs){
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);

    int end = jobs[0].dead;
    cout<<jobs[0].id<<" "<<jobs[0].dead<<" "<<jobs[0].profit<<endl;
    int profit = jobs[0].profit;

    for(int it =1; it < jobs.size(); it++){
       if(end+1 <= jobs[it].dead){
           cout<<jobs[it].id<<" "<<jobs[it].dead<<" "<<jobs[it].profit<<endl;
           end = jobs[it].dead;
           profit += jobs[it].profit;
       }
    }
    cout<<profit;
}


int main() {
    vector<Job> jobs = {Job(1,4,20),Job(2,1,10),Job(3,1,40),Job(4,1,30)};
    maxProfit(jobs);
    return 0;
}