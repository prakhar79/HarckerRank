/*
Given a word , rearrange the letters of  to construct another word  in such a way that  is lexicographically greater than . In case of multiple possible answers, find the lexicographically smallest one among them.

Input Format

The first line of input contains , the number of test cases. Each of the next  lines contains .

Constraints

 will contain only lower-case English letters and its length will not exceed .
Output Format

For each testcase, output a string lexicographically bigger than  in a separate line. In case of multiple possible answers, print the lexicographically smallest one, and if no answer exists, print no answer.

Sample Input

5
ab
bb
hefg
dhck
dkhc
Sample Output

ba
no answer
hegf
dhkc
hcdk

*/


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

	while(n>0){

		string word,ns;
		cin >> word;
		int i,pivot=0;

		for(i=word.length()-1;i>0;i--){
			if (word[i] > word[i-1]){
				pivot = i-1;
				break;
			}
		}

		ns.append(word);

		//cout << pivot << endl;

		int swap =i;
		for(i=pivot;i<word.length();i++){
			if(word[i] > word[pivot] && word[i] < word[pivot+1]){
				swap = i;
			}
		}

		//cout << swap << endl;

		char temp = word[pivot];
		word[pivot] = word[swap];
		word[swap] = temp;

		for(i=pivot+1;i<word.length();i++){
			for(int j=pivot+1;j<word.length()-1;j++){
				if(word[j] > word[j+1]){
					char temp = word[j];
					word[j] = word[j+1];
					word[j+1] = temp;
				}
			}
		}

		if(word.compare(ns) == 0  || swap == 0){
			cout << "no answer" << endl;
		} else {
			cout << word << endl;
		}

		n--;
	}
    return 0;
}
