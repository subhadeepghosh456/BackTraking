#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>& sudoku,int val){
	
	for(int i=0;i<9;i++){
		if(sudoku[i][col]==val){
			return false;
		}
		
		if(sudoku[row][i]==val){
			return false;
		}
		
		if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val){
			return false;
		}
	}
	return true;
}

bool solve(vector<vector<int>>& sudoku){
	for(int row = 0; row<9 ; row++){
		for(int col =0; col<9 ; col++){
			
			if(sudoku[row][col]==0){
				for(int val = 1;val<=9; val++){
					if(isSafe(row,col,sudoku,val)){
						sudoku[row][col] = val;
						
						bool possible = solve(sudoku);
						if(possible){
							return true;
						}
						else{
							sudoku[row][col] = 0;
						}
					}
					
				}
				return false;
			}
		}
	}
	
	return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
	
	solve(sudoku);
}