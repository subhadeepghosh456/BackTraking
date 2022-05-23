#include<iostream>
using namespace std;

void generate(string output,int n,int open,int close,int i){

    if(i==2*n){
        cout<<output<<endl;
    }

    if(open<n){
        generate(output+'(',n,open+1,close,i+1);
    }

    if(close<open){
        generate(output+')',n,open,close+1,i+1);
    }

}

int main(){
    string output;
    int n;
    cin>>n;
    generate(output,n,0,0,0);

}