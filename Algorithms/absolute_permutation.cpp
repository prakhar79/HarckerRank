/*
We define  to be a permutation of the first  natural numbers in the range . Let  denote the position of  in permutation  (please use -based indexing).

 is considered to be an absolute permutation if  holds true for every .

Given  and , print the lexicographically smallest absolute permutation, ; if no absolute permutation exists, print -1.

Input Format

The first line of input contains a single integer, , denoting the number of test cases. 
Each of the  subsequent lines contains  space-separated integers describing the respective  and  values for a test case.

Constraints

Output Format

On a new line for each test case, print the lexicographically smallest absolute permutation; if no absolute permutation exists, print -1.

Sample Input

3
2 1
3 0
3 2
Sample Output

2 1
1 2 3
-1
*/

#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t >0){
		int n,k;
		cin >> n;
		cin >> k;
		int a[n];
		for (int i=0;i<n;i++)
			a[i] = i+1;
		if(k==0){
			for(int i=0;i<n;i++)
				cout << a[i] << ' ';
			cout << endl; 
		} else if(n%2 == 0 && n%k==0){
			for(int i=0;i<n-k;i++){
				int temp = a[i];
				a[i] = a[i+k];
				a[i+k] = temp;
				if((i+1)%k == 0)
					i = i+k;
				
			}
			for(int i=0;i<n;i++)
				cout << a[i] << ' ';
			cout << endl;
		} else {
			cout << "-1" << endl;
		}
		t--;
	}

	return 0;
}