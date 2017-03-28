/*
There are  strings. Each string's length is no more than  characters. There are also  queries. 
For each query, you are given a string, and you need to find out how many times this string occurred previously.

Input Format

The first line contains , the number of strings.
The next  lines each contain a string.
The nd line contains , the number of queries.
The following  lines each contain a query string.

Sample Input

4
aba
baba
aba
xzxb
3
aba
xzxb
ab
Sample Output

2
1
0
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin >> n;
	string s[n];

	int i=0;
	while(i<n){
		cin >> s[i];
		i++;
	}

	int t;
	cin >> t;
	string tc[t];

	i=0;
	while(i<t){
		cin >> tc[i];
		i++;
	}

	int count;

	for(i=0;i<t;i++){
		count = 0;
		for(int j=0; j<n;j++){

			if(s[j].compare(tc[i]) == 0)
				count++;
		}

		cout << count << endl;
	}



	return 0;
}