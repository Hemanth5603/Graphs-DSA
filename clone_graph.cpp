#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();    
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
Node* clone(Node* node, unordered_map<Node*, Node*> &mp){
    Node* newNode = new Node(node->val);
    mp[node] = newNode;

    for(auto it: node->neighbors){
        if(mp.find(it) == mp.end()){
            (newNode->neighbors).push_back(clone(it, mp));
        }else{
            (newNode->neighbors).push_back(mp[it]);

        }
    }
    return newNode;
}
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        unordered_map<Node*, Node*> mp;
        return clone(node, mp);
    }
};