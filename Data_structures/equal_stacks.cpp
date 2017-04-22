/*
You have three stacks of cylinders where each cylinder has the same diameter, but 
they may vary in height. You can change the height of a stack by removing and discarding its 
topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the 
same height. This means you must remove zero or more cylinders from the top of zero or more 
of the three stacks until they're all the same height, then print the height. The removals 
must be performed in such a way as to maximize the height.

Note: An empty stack is still a stack.

Input Format

The first line contains three space-separated integers, , , and , describing the respective 
number of cylinders in stacks , , and . The subsequent lines describe the respective heights 
of each cylinder in a stack from top to bottom:

The second line contains  space-separated integers describing the cylinder heights in stack .
The third line contains  space-separated integers describing the cylinder heights in stack .
The fourth line contains  space-separated integers describing the cylinder heights in stack .

*/

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
    int n1;
    int n2;
    int n3;
    int total[3] = {0,0,0};
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       total[0] = total[0] + h1[h1_i]; 
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
       total[1] = total[1] + h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
       total[2] = total[2] + h3[h3_i];
    }

    int i1,i2,i3;
    i1=0;
    i2=0;
    i3=0;

    int min = (total[0] < total[1] ? total[0] : total[1]);
    min = (min < total[2] ? min : total[2]);
 

    while(!(total[0] == min && total[1] == min && total[2] == min)){
    	if(h1.size() <= i1 || h2.size() <= i2 || h3.size() <=i3){
    		min =0;
    		break;
    	}
    	if(total[0] > min){
    		total[0] = total[0] - h1[i1];
    		i1++;
    	}
    	if(total[1] > min){
    		total[1] = total[1] - h2[i2];
    		i2++;
    	}
    	if(total[2] > min){
    		total[2] = total[2] - h3[i3];
    		i3++;
    	}
    	min = (total[0] < total[1] ? total[0] : total[1]);
    	min = (min < total[2] ? min : total[2]);
    }
    cout << min << endl;
    return 0;
}
