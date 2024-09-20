//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// Using BFS to find the word ladder of the word
// using queue to traversse and apply bfs
// using set to find the existence of the word in the given wordlist
// traversing a - z on each word and find the existence of the word in the set, 
// if there erasing it 

// Complexity 
// Time - O(N * word.length() * 26 * log n)
// space - O(N)

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if(word == targetWord) return steps;
            q.pop();
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends