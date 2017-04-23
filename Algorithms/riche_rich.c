/*
Riche Rich

Sandy likes palindromes. A palindrome is a word, phrase, number, or other sequence of characters 
which reads the same backward as it does forward. For example, madam is a palindrome.

On her  birthday, Sandy's uncle, Richie Rich, offered her an -digit check which she refused because 
the number was not a palindrome. Richie then challenged Sandy to make the number palindromic by 
changing no more than  digits. Sandy can only change  digit at a time, and cannot add digits to 
(or remove digits from) the number.

Given  and an -digit number, help Sandy determine the largest possible number she can make by changing digits.

Note: Treat the integers as numeric strings. Leading zeros are permitted and can't be ignored 
(So 0011 is not a palindrome, 0110 is a valid palindrome). A digit can be modified more than once.

Input Format

The first line contains two space-separated integers,  (the number of digits in the number) and  
(the maximum number of digits that can be altered), respectively. 
The second line contains an -digit string of numbers that Sandy must attempt to make palindromic.

Constraints

Each character  in the number is an integer where .
Output Format

Print a single line with the largest number that can be made by changing no more than  digits; 
if this is not possible, print -1.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* richie_rich(char* str,int n,int l){
	int i=0;
	int end = l-1;
	int n_temp = n;

	if(l==1)
		return "9";

	char changed[l];

	for(i=0;i<l;i++)
		changed[i] = 0;

	i=0;

	while(i<=end){
		if(str[i] != str[end]){
			if(n>=1){
				if(str[i]  > str[end]){
					str[end] = str[i];
					changed[i] = 1;
					n--;
				}else {
					str[i] = str[end];
					changed[i] = 1;
					n--; 
				}
			} else {
				return "-1";
			}
		}
		i++;
		end--;
	}

	i=0;
	end = l-1;

	while(i<=end){
		if(str[i] != '9'){
			if(changed[i] && n>=1){
				str[i] = '9';
				str[end] = '9';
				n-=1;
			} 
			if((!changed[i]) && n>=2){
				str[i] = '9';
				str[end] = '9';
				n-=2;
			}
		}
		i++;
		end--;
	}

	if(l%2 == 1 && n>=1){
		str[(l-1)/2] = '9';
        n--;
    }
	
	return str;

}

int main(){

	int l,n;
	int i;
	scanf("%d %d",&l,&n);
	char str[l];

	scanf("%s",str);

	char *a = richie_rich(str,n,l);

	printf("%s\n",a );

	return 0;
}