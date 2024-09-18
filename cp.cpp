#include <bits/stdc++.h>
using namespace std;

/*#define mod 1000000007
#define ll long long
#define l "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int t = 0;
        string temp = s;
        int temp2 = stoi(s);
        int mini = stoi(s);
        for(int i = 0;i<n-2;i++){
            s[i] = '1';
            s[i+1] = '0';
            s[i+2] = '0';
            t = stoi(s);
            mini = min(mini,t);
            s = temp;
        }
        if(temp2 == mini) cout<<temp<<endl;
        else cout<<mini<<endl;
        
        
        
    }
}
*/
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define l "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        vector<int> v;
        bool check = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int i = 0,j = n-1;
        while(i<j){
            if(arr[i] < arr[j]){
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                
            }else{
                check = true;
                break;
            }
            i++;
            j--;
        }
        if(check == false){
            if(n&1){
                v.push_back(arr[n/2]);
            }
            for(auto x: v){
                cout<<x<<" ";
            }
        }else cout<<-1;
        cout<<endl;
        
        
    }
}
