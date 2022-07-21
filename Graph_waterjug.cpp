//
// Created by Akshansh Gusain on 07/05/21.
//

#include<stdc++.h>
using namespace std;

bool canMeasure(int x, int y, int z) {
    queue<pair<int, int>> q;
    set<pair<int, int>> s;

    q.push({0, 0});
    s.insert({0, 0});

    while (!q.empty()) {

        pair<int, int> p = q.front();
        q.pop();

        int current_x = p.first;
        int current_y = p.second;

        if (current_x + current_y == z) {
            return true;
        }

        //removing x
        if (s.find({0, current_y}) == s.end()) {
            q.push({0, current_y});
            s.insert({0, current_y});
        }

        //removing y
        if (s.find({current_x, 0}) == s.end()) {
            q.push({current_x, 0});
            s.insert({current_x, 0});
        }

        //Refilling x
        if (s.find({x, current_y}) == s.end()) {
            q.push({x, current_y});
            s.insert({x, current_y});
        }

        //Refilling y
        if (s.find({current_x, y}) == s.end())
            q.push({current_x, y});
        s.insert({current_x, y});

        //Transferring x -> y
        if (current_x > 0) {
            if (y - current_y > current_x) {
                if (s.find({0, current_x + current_y}) == s.end()) {
                    q.push({0, current_y + current_x});
                    s.insert({0, current_x + current_y});
                }
            } else if (s.find({current_x - y + current_y, y}) == s.end()) {
                q.push({current_x - y + current_y, y});
                s.insert({current_x - y + current_y, y});
            }
        }


        //Transferring y -> x
        if (current_y > 0) {
            if (x - current_x > current_y) {
                if (s.find({current_y + current_x, 0}) == s.end()) {
                    q.push({current_y + current_x, 0});
                    s.insert({current_y + current_x, 0});
                }
            } else if (s.find({x, current_y - x + current_x}) == s.end()) {
                q.push({x, current_y - x + current_x});
                s.insert({x, current_y - x + current_x});
            }
        }
    }
    return false;
}






int main(){
    cout<<canMeasure(3,5,4);
    return 0;
}