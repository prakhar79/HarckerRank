#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
        }
        // your code goes here
        int complete=0;
        int count=0;
        int j=0;
        
        for(int i = 0; i<=n-1;i++) {
            if(q[i]-(i+1) > 2 ){
                j=n;
                count = -1;
                break;
            }
        }
        if(count != -1) {
            count = 0;
            int i=0;
            int done = 0;
            while(i<n){
                done = 0;
                for(int j=0;j<=n-2;j++){
                    if(q[j] > q[j+1]) {

                        int temp = q[j];
                        q[j] = q[j+1];
                        q[j+1] = temp;
                        count++;
                        done = 1;
                    }
                }
            if(!done)
                break;
            i++;    
            } 
        }        
        if(count == -1)
            cout << "Too chaotic";
        else
            cout << count << endl;
    }
    
    return 0;
}
