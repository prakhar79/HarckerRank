/*
You are given a list of size , initialized with zeroes. You have to perform  operations on the list and output the maximum of final values of all the  elements in the list. For every operation, you are given three integers ,  and  and you have to add value  to all the elements ranging from index  to (both inclusive).

Input Format

First line will contain two integers  and  separated by a single space.
Next  lines will contain three integers ,  and  separated by a single space.
Numbers in list are numbered from  to .

Constraints






Output Format

A single line containing maximum value in the updated list.

Sample Input

5 3
1 2 100
2 5 100
3 4 100
Sample Output

200

*/
#include <iostream>
#include <vector>

using namespace std;


int main (){

	long int n,t;

	cin >> n;
	cin >> t;

	vector<long int> v(n+1,0);

	long int start,stop,val;
	for(long int i=0; i<t; i++){

		cin >> start;
		cin >> stop;
		cin >> val;

		v[start-1] = v[start -1] + val;
		v[stop] = v[stop] - val;
	}
	long int max = v[0];
	for(long int i=1;i<n;i++){
		v[i] = v[i-1] + v[i];
		if(v[i] > max)
			max = v[i];
	}

	cout << max << endl;




	return 0;
}