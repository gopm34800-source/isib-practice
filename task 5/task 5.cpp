#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin>>h>>w;
    vector<vector<int>> arr(h,vector<int>(w));
    
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>arr[i][j];
        }
    }
    int min_row=55,min_col=55;
    int max_row=-1,max_col =-1;
    
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
          if(arr[i][j]==1){
              
              min_row=min(min_row,i);
              min_col=min(min_col,j);
              max_col=max(max_col,j);
              max_row=max(max_row,i);
          }  
        }
    }
    cout<<min_row-1<<" "<<min_col-1<<" "<<max_row+1<<" "<<max_col+1;
}
