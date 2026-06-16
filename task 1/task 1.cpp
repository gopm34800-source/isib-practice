#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> Everest(n,vector<int>(n));
    
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            cin>>Everest[i][j];
        }
    }
    vector<vector<int>> path(n,vector<int>(n));
    
    for(int j=0;j<n;++j){
        path[n-1][j] = Everest[n-1][j];
    }
    
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<=i;j++){
            path[i][j]=Everest[i][j]+min(path[i+1][j],path[i+1][j+1]);
            
        }
    }
    
    cout<<path[0][0]<<endl;
    
    cout<<Everest[0][0]<<" ";
    
    int j=0;
    
    for(int i=0; i<n-1;++i) {
        if(path[i+1][j] < path[i+1][j+1]) {
            cout<<Everest[i+1][j]<<" ";
        }
        else{
            j++; 
            cout<<Everest[i+1][j]<<" ";
        }
    }
    cout<<endl;
}
