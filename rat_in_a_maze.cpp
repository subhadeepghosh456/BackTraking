#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<bool> >&visited,vector < vector < int >> & arr,int n){
	if((newx >= 0 && newy>= 0) && (newx<=n-1 && newy<=n-1) && (arr[newx][newy]==1 && visited[newx][newy]==0)){
		return true;
	}else{
		return false;
	}
	
}

void solve(int x,int y,vector < vector < int >> & arr, int n,vector<string>&ans,vector<vector<bool> >&visited,string path){
	if(x==n-1 && y==n-1){
		ans.push_back(path);
		return;
	}
	//down
	if(isSafe(x+1,y,visited,arr,n)){
		visited[x][y] = 1;
		path = path+'D';
		solve(x+1,y,arr,n,ans,visited,path);
		path.pop_back();
		visited[x][y] = 0;
		
	}
	//left
	if(isSafe(x,y-1,visited,arr,n)){
		visited[x][y] = 1;
		solve(x,y-1,arr,n,ans,visited,path+'L');
		visited[x][y] = 0;
	}
	
	//right
	if(isSafe(x,y+1,visited,arr,n)){
		visited[x][y] = 1;
		solve(x,y+1,arr,n,ans,visited,path+'R');
		visited[x][y] = 0;
	}
	//up
	if(isSafe(x-1,y,visited,arr,n)){
		visited[x][y] = 1;
		solve(x-1,y,arr,n,ans,visited,path+'U');
		visited[x][y] = 0;
	}
	
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
	
	vector<string>ans;
	vector<vector<bool> >visited(n,vector<bool>(n,0));
	string path = "";
	
	if(arr[0][0]==0){
		return ans;
	}
	
	solve(0,0,arr,n,ans,visited,path);
	
	return ans;
}