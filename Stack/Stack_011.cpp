//
// Created by Akshansh Gusain on 08/02/24
//

//https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

#include<stdc++.h>

using namespace std;

class Stack{
private:
    vector<int> inStack;// Internal Stack
    vector<int> nextMin;// Maintain next min. value
    int size;
    int min;

public:

    Stack(int size){
        this->size = size;
        this->min = INT_MAX;
    }

    bool push(int value){
        try{
            this->inStack.push_back(value);
            this->size++;

            if(value < this->min){
                nextMin[this->size] = this->min;
                this->min = value;
            }

            return true;
        }
        catch(...){
                return false;
        }
    }

    int top(){
        if(size <= 0){
            return -1; // underflow
        }else{
            return this->inStack[size-1];
        }
    }

    void pop(){
        if(size <= 0){
           cout<<"underflow";
        }else{
            this->inStack.pop_back();
            min = nextMin[size];
            size--;
        }
    }

    int getMin(){
        return this->min;
    }
};

int main() {
    string expr = "akshansh_gusain";

    return 0;
}

