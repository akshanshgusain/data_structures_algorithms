//
// Created by Akshansh Gusain on 30/08/23.
//

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int val) {
        this->val = val;
        neighbors = vector<Node *>();
    }

    Node(int val, vector<Node *> neighbors) {
        this->val = val;
        this->neighbors = neighbors;
    }


};

// Helper function
Node *buildGraph() {
    /*
    Note : All the edges are Undirected
    Given Graph:
    1--2
    | |
    4--3
*/

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    vector<Node*> neighbors;

    neighbors.push_back(node2);
    neighbors.push_back(node4);
    node1->neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(node1);
    neighbors.push_back(node3);
    node2->neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(node2);
    neighbors.push_back(node4);
    node3->neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(node3);
    neighbors.push_back(node1);
    node4->neighbors = neighbors;

    return node1;
}

void bfs(Node *source){
    unordered_map<Node*, bool> used;
    queue<Node*> q;
    q.push(source);
    used[source] = true;

    while(!q.empty()){
        auto currentNode = q.front();
        q.pop();
        cout<<"Val: "<<currentNode->val<<endl;
        cout<<"Address: "<<currentNode<<endl;

        vector<Node*> neighbors = currentNode->neighbors;
        for(auto & neighbor : neighbors){
            if(!used[neighbor]){
                used[neighbor] = true;
                q.push(neighbor);
            }
        }

    }
    cout<<endl;
}

Node* cloneGraph(Node *source){
    queue<Node*> queue;
    unordered_map<Node*, Node*> map;

    Node *newSource = new Node(source->val);

    map[source] = newSource;
    queue.push(source);

    while(!queue.empty()){
        Node *currentNode = queue.front();
        queue.pop();

        for(auto neighbour : currentNode->neighbors){
            if(map[neighbour] == nullptr){
                map[neighbour] = new Node(neighbour->val);
                queue.push(neighbour);
            }

            map[currentNode]->neighbors.push_back(map[neighbour]);
        }
    }

    return newSource;
}


int main(){
    Node *source = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(source);

    Node *ClonedSource = cloneGraph(source);
    cout << "BFS Traversal After cloning\n";
    bfs(ClonedSource);
    return 0;
}