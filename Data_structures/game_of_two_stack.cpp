/*
Alexa has two stacks of non-negative integers, stack  and stack where index  denotes the top of the 
stack. Alexa challenges Nick to play the following game:

In each move, Nick can remove one integer from the top of either stack  or stack .
Nick keeps a running sum of the integers he removes from the two stacks.
Nick is disqualified from the game if, at any point, his running sum becomes greater than some 
integer  given at the beginning of the game.
Nick's final score is the total number of integers he has removed from the two stacks.
Given , , and  for  games, find the maximum possible score Nick can achieve (i.e., 
the maximum number of integers he can remove without being disqualified) during each game and print it on a new line.
*/

#include <bits/stdc++.h>

using namespace std;

//Solving with dynamic programming. 
//Some test case not working

#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        vector<int> b(m);
        for(int b_i = 0; b_i < m; b_i++){
           cin >> b[b_i];
        }
        int mat_a[n+1];
        int mat_b[m+1];
        int count_a =0;
        int count_b =0;
        int count_ab = 0;
        int max_count = 0;
        mat_a[0] = 0;
        mat_b[0] = 0;

        for(int i=1;i<n+1;i++){
            count_a++;
            mat_a[i] = mat_a[i-1] + a[i-1];
            if(mat_a[i] > x)
                break;    
            
        }
        
        if(count_a > max_count)
            max_count = count_a;
        
        for(int i=1;i<m+1;i++){
            
            mat_b[i] = mat_b[i-1] + b[i-1];
            count_b++;

            if(mat_b[i-1] + mat_a[count_a] > x){
                count_a--;
            } else {
                if (count_b + count_a > count_ab)
                    count_ab = count_b + count_a; 
            }

            if(mat_b[i] > x)
                break;            
        }
        if(count_b > max_count){
            cout << "b" << " ";
            max_count = count_b;
        }
        if(count_ab > max_count){
            max_count = count_ab;
            cout << "ab" << " ";
        }

        cout << --max_count << endl;
    }
}