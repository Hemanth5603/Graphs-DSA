#include<iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int GetAnswer(int n, int q, int c, vector<int> arr, vector<vector<int>> queries){
    int sum = 0;

    for(int i = 0;i<queries.size();i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i >= queries[i][0] && i <= queries[i][1]){
                continue;
            }else{
                cnt++;
            }
        }
        sum += cnt;
    }
    return sum;
}