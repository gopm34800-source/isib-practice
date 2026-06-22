#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    string word;
    cin>>word;
    for(int i=0;i<k;++i){
        string drow=word;
        for(int j=0;j<n;++j){
            drow[arr[j]-1]=word[j];
        }
        word=drow;
    }
    cout<<word<<endl;
}
