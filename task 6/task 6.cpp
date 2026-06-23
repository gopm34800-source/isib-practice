#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        
        int count=min(b,x)+min(a,y)+min(a-min(a,y),x-min(b,x));
        
        cout<<count<<" ";
    }
}
