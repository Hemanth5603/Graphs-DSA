#include<bits/stdc++.h>
using namespace std;
// Solution using Trie + DFS

// Time complexity:O(N×M×4^L)


class Node{
    public:
    vector<Node*> child;
    bool isEnd = false;
    int idx;
    
    Node(){
        vector<Node*> temp(26, NULL);
        child = temp;
        idx = -1; 
    }

    bool containsKey(char ch){
        return child[ch - 'a'] != NULL;
    }
    Node* get(char ch){
        return child[ch - 'a'];
    }

    void setFlag(int idx){
        isEnd = true;
        this->idx= idx;
    }
    void put(char ch, Node* node){
        child[ch - 'a'] = node;
    }

    bool getFlag(){
        return isEnd;
    }

    int getIdx(){
        return idx;
    }
};

class Trie{
    private:
    Node* root;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word, int idx){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
         node->setFlag(idx);
    }
    void solveUtil(Node* node, int row, int col, vector<vector<char>> &board, int n, int m, vector<int> &inc, vector<vector<int>> &vis){
        if(node->getFlag() && !inc[node->getIdx()]){
            inc[node->getIdx()] = 1;
        }
        vis[row][col] = 1;

        for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && node->containsKey(board[nrow][ncol])){
                solveUtil(node->get(board[nrow][ncol]), nrow, ncol, board, n,m,inc,vis);
            } 
        }
        vis[row][col] = 0;
        return;
    }

    void solve(vector<vector<char>> &board, int n, int m, vector<int> &inc){
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(root->containsKey(board[i][j])){
                    vector<vector<int>> vis(n, vector<int>(m));
                    solveUtil(root->get(board[i][j]), i, j, board, n, m, inc, vis);
                }
            }
        }
    } 

};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        vector<string> res;
        Trie trie;
        int s = words.size();
        for(int i=0;i<s;i++){
            trie.insert(words[i], i);
        }
        vector<int> inc(s);
        trie.solve(board, n, m, inc);

        for(int i=0;i<s;i++){
            if(inc[i]){
                res.push_back(words[i]);
            }
        }
        return res;

    }
};