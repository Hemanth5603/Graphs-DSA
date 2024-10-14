#include <bits/stdc++.h> 
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans,string move, 
    vector<vector<int>> &vis, int di[], int dj[]){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for(int ind=0;ind<4;ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if(nexti >= 0 && nexti < n && nextj >=0 && nextj < n && a[nexti][nextj] == 1 &&
                !vis[nexti][nextj]){
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}


vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1,0,0,-1};
    int dj[] = {0, -1, 1, 0};
    if(arr[0][0] == 1) solve(0, 0, arr, n, ans, "", vis, di, dj);
    return ans;

}