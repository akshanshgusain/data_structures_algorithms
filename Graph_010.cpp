//
// Created by Akshansh Gusain on 26/08/21.
//
#include<stdc++.h>

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

// Leetcode Question

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
    map<Node*, bool> used;
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

Node *cloneGraph(Node *source) {
    //A Map to keep track of all the nodes which have already been created
    map<Node*, Node*> map;
    queue<Node*> q;

    q.push(source);

    Node* node = new Node(source->val);

    // put clone node into tha map
    map[source] = node;

    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();

        vector<Node*> neighbors = currentNode->neighbors;
        for(auto neighbor : neighbors){
            // Check if this node has already been created
            if(map[neighbor] == nullptr){
                node = new Node(neighbor->val);
                map[neighbor] = node;
                q.push(neighbor);
            }

            // add these neighbours to the cloned graph node
            map[currentNode]->neighbors.push_back(map[neighbor]);
        }
    }

    return map[source];
}


int main() {
    Node *source = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(source);

    Node *ClonedSource = cloneGraph(source);
    cout << "BFS Traversal After cloning\n";
    bfs(ClonedSource);
    return 0;
}
