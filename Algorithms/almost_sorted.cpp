/*
Given an array with  elements, can you sort this array in ascending order using only one of the following operations?

Swap two elements.
Reverse one sub-segment.
Input Format 
The first line contains a single integer, , which indicates the size of the array. 
The next line contains  integers separated by spaces.

n  
d1 d2 ... dn  
Constraints 
 
  
All  are distinct.

Output Format 
1. If the array is already sorted, output yes on the first line. You do not need to output anything else.

If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:

a. If you can sort the array by swapping  and , output swap l r in the second line.  and  are the indices of the elements to be swapped, assuming that the array is indexed from  to .

b. Else if it is possible to sort the array by reversing the segment , output reverse l r in the second line.  and  are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from  to .

 represents the sub-sequence of the array, beginning at index  and ending at index , both inclusive.

If an array can be sorted by either swapping or reversing, stick to the swap-based method.

If you cannot sort the array in either of the above ways, output no in the first line.

Sample Input #1

2  
4 2  
Sample Output #1

yes  
swap 1 2
Sample Input #2

3
3 1 2
Sample Output #2

no
Sample Input #3

6
1 5 4 3 2 6
Sample Output #3

yes
reverse 2 5
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int down_point = 0;
	int peak_point = 0;
	int p1 = -1;
	int p2 = -1;
	bool swap = false;
	bool rev = false;

	if(n==2 && a[0] > a[1]){
		p1=0;
		p2 = 1;
		swap = true;
	}

	for(int i=1;i<n-1;i++){
		if (n==3){
			if(a[1] > a[0] && a[1] > a[2] && a[2] > a[0]){
				p1=1;
				p2=2;
				swap = true;
				break;
			} else if (a[1] < a[0] && a[1] < a[2] && a[2] > a[0]){
				p1=0;
				p2=1;
				swap = true;
				break;
			} else if(a[1] < a[0] && a[1] > a[2] && a[0] > a[1]){
				p1=0;
				p2=2;
				swap = true;
			}
            break;
		}
		if(a[i] > a[i-1] && a[i] > a[i+1]){
			peak_point++;
			if(peak_point == 1)
				p1 = i;
			if(peak_point == 2){
				p2 = i+1;
			}
		} else if (a[i] < a[i-1] && a[i] < a[i+1]){
			down_point++;
			if(peak_point <=1)
				p2=i;
		}
	}
	if(peak_point == 2 && (a[p2]) > a[p1-1]){
		swap = true;
	}else if(peak_point == 1 && down_point == 1){
		if(p2-p1 > 1)
			rev = true;
		else
			swap = true;
	}else if(peak_point ==1 && down_point == 0){
		p2 = p1+1;
		swap = true;
	}else if(peak_point ==0 && down_point == 1){
		p1 = p2-1;
		swap = true;
	}

    if(swap && rev)
        rev = false;
    
	if(swap){
		cout << "yes" << endl;
		cout <<"swap "<< p1+1 << " " << p2+1 << endl;
	}else if(rev){
		cout << "yes" << endl;
		cout <<"reverse "<< p1+1 << " "<<p2+1 << endl;
	}else{
		cout << "no" << endl;
	}
    return 0;
}

