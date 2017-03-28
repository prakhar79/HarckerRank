/*
Bomberman lives in a rectangular grid with  rows and  columns. Each cell in the grid either contains a bomb or nothing at all.

Each bomb can be planted in any cell of the grid but, once planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it's destroyed — along with anything in its four neighboring cells. This means that if a bomb detonates in cell , cells  and  are cleared (note that cells at the edge of the grid have less than four neighboring cells). If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without detonating (i.e., no chain reaction occurs).

Bomberman is immune to bombs, so he can move freely throughout the grid. Here's what he does:

Initially, Bomberman arbitrarily plants bombs in some of the cells.
After one second, Bomberman does nothing.
After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. It is guaranteed that no bombs will detonate at this second.
After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
Bomberman then repeats steps 3 and 4 indefinitely.
Note that during every second Bomberman plants bombs, the bombs are planted simultaneously (i.e., at the exact same moment), and any bombs planted at the same time will detonate at the same time.

Given the initial configuration of the grid with the locations of Bomberman's first batch of planted bombs, determine the state of the grid after  seconds.

Input Format

The first line contains three space-separated integers denoting the respective values of , , and . 
Each line  of the  subsequent lines describes row  of the grid's initial state as a single string of  characters; the . character denotes an empty cell, and the O character (ascii 79) denotes a bomb.

Constraints

Subtask

 for  of the maximum score.
Output Format

Print the grid's final state. This means  lines where each line contains  characters, and each character is either a . or an O (ascii 79). This grid must represent the state of the grid after  seconds.

Sample Input

6 7 3
.......
...O...
....O..
.......
OO.....
OO.....
Sample Output

OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO
Explanation

The initial state of the grid is:

.......
...O...
....O..
.......
OO.....
OO.....
Bomberman spends the first second doing nothing, so this is the state after 1 second:

.......
...O...
....O..
.......
OO.....
OO.....
Bomberman plants bombs in all the empty cells during his second second, so this is the state after 2 seconds:

OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
In his third second, Bomberman sits back and watches all the bombs he planted 3 seconds ago detonate. This is the final state after  seconds:

OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO 
*/

#include <iostream>
#include <unordered_map>
using namespace std;


struct store{
	int r,c;
	store() {};
	store(int i,int j) {
		r =i;
		c=j;
	};
};

int count = 0;
unordered_map<int,struct store*> list;

void plant_bombs(char *grid[],int R,int C) {

	count=0;

	for(int i=0;i<R;i++){
		for(int j =0 ; j<C;j++){
			if(grid[i][j]=='O'){
				if(list.find(count) == list.end()){
					store *temp = new store(i,j);
					list.insert({count,temp});
				}
				else {
					list[count]->r = i;
					list[count]->c = j;
				}

				count++;
			}
		}
	}

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			grid[i][j] = 'O'; 
	}
}

void blow(char *grid[],int R,int C){
	
	for (int i=0; i<count ; i++){
		int r = list[i]->r;
		int c = list[i]->c;
		grid[r][c] = '.';
		
		if(r-1 >=0)
			grid[r-1][c] = '.';

		if(r+1 <R)
			grid[r+1][c] = '.';
		
		if(c+1 < C)
			grid[r][c+1] = '.';

		if(c-1 >=0)
			grid[r][c-1] = '.';
	}
}



int main()
{
	int R,C,sec;
	cin >> R >> C >> sec;

	char grid[R][C];
	char *grid_ptr[R];

	for(int i=0;i<R;i++){
		for(int j =0 ; j<C;j++)
			cin >> grid[i][j];
	}

	for(int i=0;i<R;i++)
		grid_ptr[i] = &grid[i][0];

	if(sec%2 == 0){
		plant_bombs(grid_ptr,R,C);
	}else if(sec%4 == 3){
		plant_bombs(grid_ptr,R,C); 
		blow(grid_ptr,R,C);
	}else if(sec%4 == 1 && sec !=1){
		plant_bombs(grid_ptr,R,C); 
		blow(grid_ptr,R,C);
		plant_bombs(grid_ptr,R,C);
		blow(grid_ptr,R,C);
	}

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			cout<< grid[i][j];
		cout << endl;
	}

	return 0;
}
