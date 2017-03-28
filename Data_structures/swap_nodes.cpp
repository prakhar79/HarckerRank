/*
Input Format 
First line of input contains N, number of nodes in tree. Then N lines follow. 
Here each of ith line (1 <= i <= N) contains two integers, a b, where a is the 
index of left child, and b is the index of right child of ith node. -1 is used to represent null node. 
Next line contain an integer, T. Then again T lines follows. Each of these line contains an integer K.

Output Format 
For each K, perform swap operation as mentioned above and print the inorder traversal of the current state of tree.

Constraints 
1 <= N <= 1024 
1 <= T <= 100 
1 <= K <= N 
Either a = -1 or 2 <= a <= N 
Either b = -1 or 2 <= b <= N 
Index of (non-null) child will always be greater than that of parent.

Sample Input #00

3
2 3
-1 -1
-1 -1
2
1
1
Sample Output #00

3 1 2
2 1 3
Sample Input #01

5
2 3
-1 4
-1 5
-1 -1
-1 -1
1
2
Sample Output #01

4 2 1 5 3
Sample Input #02

11
2 3
4 -1
5 -1
6 -1
7 8
-1 9
-1 -1
10 11
-1 -1
-1 -1
-1 -1
2
2
4
Sample Output #02

2 9 6 4 1 3 7 5 11 8 10
2 6 9 4 1 3 7 5 10 8 11
Explanation

**[s] represents swap operation is done at this depth.

Test Case #00: As node 2 and 3 has no child, swapping will not have any effect on it. 
We only have to swap the child nodes of root node.

    1   [s]       1    [s]       1   
   / \      ->   / \        ->  / \  
  2   3 [s]     3   2  [s]     2   3
Test Case #01: Swapping child nodes of node 2 and 3 we get

    1                  1  
   / \                / \ 
  2   3   [s]  ->    2   3
   \   \            /   / 
    4   5          4   5  
Test Case #02: Here we perform swap operations at the nodes whose depth is either 2 and 4 and then at nodes whose depth is 4.

         1                     1                          1             
        / \                   / \                        / \            
       /   \                 /   \                      /   \           
      2     3    [s]        2     3                    2     3          
     /      /                \     \                    \     \         
    /      /                  \     \                    \     \        
   4      5          ->        4     5          ->        4     5       
  /      / \                  /     / \                  /     / \      
 /      /   \                /     /   \                /     /   \     
6      7     8   [s]        6     7     8   [s]        6     7     8
 \          / \            /           / \              \         / \   
  \        /   \          /           /   \              \       /   \  
   9      10   11        9           11   10              9     10   11 

*/


#include <iostream>
#include <queue>

using namespace std;

struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;

	treeNode(int i){
		data = i;
		left = NULL;
		right = NULL;
	};

};

treeNode* create_tree(int n){
	queue<treeNode*> q;

	treeNode* root = new treeNode(1);
	q.push(root);

	int l;
	int r;

	while(!q.empty()){

		treeNode* curr;
		curr = q.front();

		cin >> l;
		cin >> r;

		if(l == -1)
			curr->left = NULL;
		else{
			curr->left = new treeNode(l);
			q.push(curr->left);
		}

		if(r == -1)
			curr->right = NULL;
		else{
			curr->right = new treeNode(r);
			q.push(curr->right);
		}

		q.pop();

	}
	return root;
}

void inorder_traversal(treeNode* root){
	
	if(root == NULL)
		return;

	inorder_traversal(root->left);
	cout << root->data << ' ';
	inorder_traversal(root->right);

}

void swap_level(treeNode* root, int swap,int curr_level){
	
	if (root == NULL)
		return;
	if(curr_level%swap == 0){
		treeNode *temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp; 
	}
	swap_level(root->left,swap,curr_level+1);
	swap_level(root->right,swap,curr_level+1);
}


int main(){

	treeNode *root;

	int n;
	cin >> n;

	root = create_tree(n); 
	
	int t;
	cin >> t;

	while(t>0){

		int level;
		cin >> level;

		swap_level(root,level,1);

		inorder_traversal(root);
		cout << endl;

		t--;
	}

	return 0;
}