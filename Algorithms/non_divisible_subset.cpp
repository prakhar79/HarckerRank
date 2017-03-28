/*
Non Divisble Subset...

Given a set, , of  distinct integers, print the size of a maximal subset, , of  where the sum of any  numbers in  is not evenly divisible by .

Input Format

The first line contains  space-separated integers,  and , respectively. 
The second line contains  space-separated integers (we'll refer to the  value as ) describing the unique values of the set.

Constraints

All of the given numbers are distinct.
Output Format

Print the size of the largest possible subset ().

Sample Input

4 3
1 7 2 4
Sample Output

3

*/

/*#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int non_divisible_subset(vector<int>* list,int div,int n){

	unordered_map<int,int> rem_map;
	int i;

	for(i=0;i<n;i++){

		int rem;
		rem = (*list)[i] % div;

		if(rem == 0)
			continue;

		if(rem_map.find(rem) == rem_map.end()) 
			rem_map.insert({rem,1});
		else
			rem_map[rem] = rem_map[rem]+ 1;
	} 
	
	int max_set = 0;

	for(i=1;i<=div/2;i++){
		max_set = max_set + (rem_map[i] > rem_map[n-i] ? rem_map[i] : rem_map[n-i]);
	}
	return max_set;
}

int main(){

	vector<int> list;
	list.push_back(1);
	list.push_back(7);
	list.push_back(2);
	list.push_back(4);

	cout << non_divisible_subset(&list,3,4) << endl;
	return 0;
}*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int non_divisible_subset(vector<int>* list,int div,int n){

	unordered_map<int,int> rem_map;
	int i;

	for(i=0;i<n;i++){

		int rem;
		rem = (*list)[i] % div;

		if(rem == 0)
			continue;

		if(rem_map.find(rem) == rem_map.end()) 
			rem_map.insert({rem,1});
		else
			rem_map[rem] = rem_map[rem]+ 1;
	} 
	
	int max_set = 0;

	for(i=1;i<=div/2;i++){
		cout <<  i << ' ' << rem_map[i] << endl;
		cout <<  div-i << ' ' << rem_map[div-i] << endl;
		max_set = max_set + (rem_map[i] > rem_map[div-i] ? rem_map[i] : rem_map[div-i]);
	}
	return max_set;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,div;
    cin >> n;
    cin >> div;
    vector<int> list(n);
    
    for(int i=0;i<n;i++)
        cin >> list[i];
    
    cout << non_divisible_subset(&list,div,n);
    
    return 0;
}
