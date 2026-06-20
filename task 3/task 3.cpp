#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> streets(n+1);
    while(k--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            streets[b]+=c;
        }
        else{
            int count=0;
            for(int i=b;i<=c;++i){
                count+=streets[i];
            }
            cout<<count<<endl;
            count=0;
        }
    }
}
