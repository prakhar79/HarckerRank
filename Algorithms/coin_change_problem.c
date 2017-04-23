/*
The coin change problem in C. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int coin_change_problem(int target,int coins,int *arr){

	int coin_mat[coins+1][target+1];
	int i,j;

	for(i=0;i<=coins;i++)
		coin_mat[i][0] = 1;

	for(i=1;i<=target;i++)
		coin_mat[0][i] = 0;
	
	for(i=1;i<=coins;i++){
		for(j=1;j<=target;j++){

			if(arr[i-1] > j){
				coin_mat[i][j] = coin_mat[i-1][j]; 
			}else {
				coin_mat[i][j] = coin_mat[i-1][j] + coin_mat[i][j-arr[i-1]];
			}
		}
	}

	return coin_mat[coins][target];

}

int main() {

    int n_coin;
    int change;
    int i;

    scanf("%d %d",&change,&n_coin);

    int coin_arr[n_coin];
    for(i=0;i<n_coin;i++)
    	scanf("%d",&coin_arr[i]);

    int ans = coin_change_problem(change,n_coin,coin_arr);

    printf("%d\n",ans);
    return 0;
    
}
