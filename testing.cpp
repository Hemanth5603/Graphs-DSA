#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
      
        if (k % 2 == 0) {
            cout << "YES" << endl;
        } else {
            
            if (n % 2 == 0) {
                cout <<"YES"<< endl; 
            } else {
                cout <<"NO"<< endl;  
            }
        }
    }
    
    return 0;
}
