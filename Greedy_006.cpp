//
// Created by Akshansh Gusain on 20/08/22.
//
#include<bits/stdc++.h>
using namespace std;

class Train{
public:
    int arrivalTime;
    int departureTime;
    int platformNumber;

    Train(int arrivalTime, int departureTime, int platformNumber) : arrivalTime(arrivalTime),
                                                                    departureTime(departureTime),
                                                                    platformNumber(platformNumber) {}
};

bool comparator(Train &a, Train &b){
    return a.departureTime < b.departureTime;
}

int maxTrainStoppage(vector<Train> &trains){
    sort(trains.begin(), trains.end(), comparator);

    vector<Train> ans;

    ans.emplace_back(trains[0]);
    int lastDeparture1 = INT16_MIN, lastDeparture2 = INT16_MIN;

    trains[0].platformNumber==1 ? lastDeparture1 = trains[0].departureTime : lastDeparture2 = trains[0].departureTime;

    for(int i = 1; i < trains.size(); i++){
        if(trains[i].platformNumber == 1){
            // platform 1
            if(trains[i].arrivalTime >= lastDeparture1){
                ans.emplace_back(trains[i]);
                lastDeparture1 = trains[i].departureTime;
            }

        }else{
            // platform 2
            if(trains[i].arrivalTime >= lastDeparture2){
                ans.emplace_back(trains[i]);
                lastDeparture2 = trains[i].departureTime;
            }

        }
    }
    for(const auto &it: ans){
        cout<<it.arrivalTime <<" "<<it.departureTime<<" "<<it.platformNumber<<endl;
    }
    cout<<endl;
    return ans.size();
}

int main(){
    vector<Train> trains = {Train(1000,1030 ,1),
                            Train(1010,1020 ,1),
                            Train(1025,1040 ,1),
                            Train(1130,1145 ,2),
                            Train(1130,1140 ,2),
                            };
    cout<<maxTrainStoppage(trains);
    return 0;
}