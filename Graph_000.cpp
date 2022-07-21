//
// Created by Akshansh Gusain on 24/02/22.
//
#include<stdc++.h>

using namespace std;

/*Graph class*/
//#include "Graph.cpp"
struct node {
    int u;
    int v;
    int wt;

    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

class Graph {
public:
    int V, E;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        this->adj.assign(V, vector<int>());
    }

    /// Undirected Graph
    void addEdgeU(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }
};




int findParent(vector<int>& parent, int node) {
    if (node == parent[node]) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}


//void unionn(vector<int> &parent, vector<int> &rank, int u, int v) {
//    u = findParent(parent, u);
//    v = findParent(parent, v);
//
//    if (rank[u] < rank[v]) {
//        parent[u] = v;
//    } else if (rank[v] < rank[u]) {
//        parent[v] = u;
//    } else {
//        parent[u] = v;
//        rank[v]++;
//    }
//}


int main() {
//    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
//                                       {"John", "johnsmith@mail.com", "john00@mail.com"},
//                                       {"Mary", "mary@mail.com"},
//                                       {"John", "johnnybravo@mail.com"}};

//    vector<vector<string>> accounts = {{"Gabe",  "Gabe0@m.co",  "Gabe3@m.co",  "Gabe1@m.co"},
//                                       {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
//                                       {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
//                                       {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
//                                       {"Fern",  "Fern5@m.co",  "Fern1@m.co",  "Fern0@m.co"}};
    vector<vector<string>> accounts = {{"Alex",  "Alex5@m.co",  "Alex4@m.co",  "Alex0@m.co"},
                                       {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"},
                                       {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"},
                                       {"Gabe",  "Gabe0@m.co",  "Gabe3@m.co",  "Gabe2@m.co"},
                                       {"Gabe",  "Gabe3@m.co",  "Gabe4@m.co",  "Gabe2@m.co"}};


    unordered_map<string, int> emailToParent;
    int N = accounts.size();

    //Parent, constraint : 2 <= accounts[i].length <= 10
     vector<int> parent(1001);

    //Rank, constraint : 1 <= accounts.length <= 1000
    // vector<int> rank(10001, 0);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        string curr = accounts[i][0];
        for (int j = 1; j < accounts[i].size(); j++) {

            // Check if Email is already mapped to some parent in our MAP - emailsTOParent
            string currEmail = accounts[i][j];
            if (emailToParent.find(accounts[i][j]) != emailToParent.end()) {

                int parent1 = findParent(parent, emailToParent[accounts[i][i]]);
                int parent2 = findParent(parent, i);

                // unionn(parent, rank, parent1, parent2);
                parent[parent2] = parent1;

            } else {

                emailToParent[accounts[i][j]] = parent[i];

            }
        }
    }


    for (auto it: emailToParent) {
        cout << it.first << "  " << it.second << endl;
    }
    cout << endl << endl;

    // Normalize email to Parent Map
    unordered_map<int, vector<string>> normalizedMap;
    for (const auto &it: emailToParent) {
        int uniq_id = findParent(parent, it.second);
        normalizedMap[uniq_id].push_back(it.first);
    }

    vector<vector<string>> ans;
    for (auto &it: normalizedMap) {
        vector<string> emails = it.second;

        sort(emails.begin(), emails.end());

        emails.insert(emails.begin(), accounts[it.first][0]);

        ans.push_back(emails);
    }


    for (auto &it: ans) {
        for (auto &i: it) {
            cout << i << " ";
        }
        cout << endl;
    }

    //return ans;
    return 0;
}



[["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
[["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
[["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
[["Isa","Isa6@m.co","Isa0@m.co","Isa1@m.co","Isa6@m.co","Isa1@m.co"],["David","David10@m.co","David12@m.co","David7@m.co","David6@m.co","David1@m.co"],["Alex","Alex1@m.co","Alex7@m.co","Alex6@m.co","Alex11@m.co","Alex2@m.co"],["Hanzo","Hanzo11@m.co","Hanzo2@m.co","Hanzo5@m.co","Hanzo5@m.co","Hanzo3@m.co"],["Bob","Bob12@m.co","Bob1@m.co","Bob12@m.co","Bob7@m.co","Bob5@m.co"],["Isa","Isa4@m.co","Isa1@m.co","Isa3@m.co","Isa9@m.co","Isa2@m.co"],["Kevin","Kevin0@m.co","Kevin7@m.co","Kevin12@m.co","Kevin3@m.co","Kevin5@m.co"],["David","David12@m.co","David6@m.co","David10@m.co","David0@m.co","David8@m.co"],["Celine","Celine0@m.co","Celine8@m.co","Celine10@m.co","Celine2@m.co","Celine12@m.co"],["Kevin","Kevin1@m.co","Kevin8@m.co","Kevin5@m.co","Kevin9@m.co","Kevin0@m.co"],["Alex","Alex3@m.co","Alex8@m.co","Alex1@m.co","Alex12@m.co","Alex12@m.co"],["Kevin","Kevin8@m.co","Kevin12@m.co","Kevin1@m.co","Kevin10@m.co","Kevin9@m.co"]]