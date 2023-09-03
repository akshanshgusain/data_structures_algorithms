//
// Created by Akshansh Gusain on 02/09/23.
//
#include<bits/stdc++.h>

using namespace std;



// GFG
vector<char> findOrder(vector<string> &dict, int K) {
    // We need to build a graph of this dictionary
    Graph graph(K);

    for (int i = 0; i < dict.size() - 1; i++) {
        string w1 = dict[i];
        string w2 = dict[i + 1];

        for (int j = 0; j < min(w1.length(), w2.length()); j++) {
            if (w1[j] != w2[j]) {
                graph.adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }

    // Initialize queue for BFS
    queue<int> q;
    vector<int> inDegree(K, 0);

    // Calculate in-degrees
    for (int i = 0; i < K; i++) {
        for (int neighbor: graph.adj[i]) {
            inDegree[neighbor]++;
        }
    }

    for (auto it: inDegree) {
        cout << it << " ";
    }
    cout << endl;

    // Find nodes with no incoming edges (initial sources)
    for (int i = 0; i < K; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<char> topo; // Stores the topological order

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node + 'a');

        for (int neighbor: graph.adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return topo;
}


// Leetcode
string alienOrderMap(vector<string> &words) {
    if (words.empty()) {
        return "";
    }

    queue<char> queue;
    unordered_map<char, int> inDegree;

    // init inDegree Map
    for (auto & word : words) {
        for (char c : word) {
            inDegree[c] = 0;
        }
    }

    // construct graph
    unordered_map<char, unordered_set<char>> adj;

    for (int i = 0; i < words.size() - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];
        for (int j = 0; j < min(word1.size(), word2.size()); j++) {
            if (word1[j] != word2[j]) {
                unordered_set<char> neighbours = adj[word1[j]];
                if (neighbours.find(word2[j]) == neighbours.end()) {
                    adj[word1[j]].insert(word2[j]);
                    //calculate inDegree
                    inDegree[word2[j]]++;
                }
                break;
            }
            if (j == min(word1.size(), word2.size()) - 1 and
                word1.size() > word2.size()) {
                return "";
            }
        }
    }

    // run Topological sort

    // find source
    for (auto it: inDegree) {
        if (it.second == 0) {
            queue.push(it.first);
        }
    }

    string result;

    while (!queue.empty()) {
        char currentVertex = queue.front();
        queue.pop();
        result += currentVertex;

        for (auto neighbour: adj[currentVertex]) {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0) {
                queue.push(neighbour);
            }
        }
    }
    // tell if it is cyclic
    return result.length() == inDegree.size() ? result : "";
}


int main() {
    int K = 4;
    vector<string> dict = {"wrt", "wrf", "er", "ett", "rftt"};
//    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    string topo = alienOrderMap(dict);

    for (auto it: topo) {
        cout << it << " ";
    }

    return 0;
}