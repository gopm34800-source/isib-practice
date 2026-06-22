#include <bits/stdc++.h>
using namespace std;


vector<int> tree;

void update(int v, int l, int r, int pos, long long val){
    if(l==r){
        tree[v]+=val;
    }
    else{
        int m=(l+r)/2;
        if(pos<=m){
            update(v*2,l,m,pos,val);
        }
        else{
            update(v*2+1,m+1,r,pos,val);
        }
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

long long query(int v,int tl,int tr,int l,int r){
    if(l>r){
        return 0;
    }
    if(l==tl && r==tr){
        return tree[v];
    }
    int tm=(tl+tr)/2;
    long long lsum =query(v*2,tl,tm,l,min(r,tm));
    long long rsum =query(v*2+1,tm+1,tr,max(l,tm+1),r);

    return lsum+rsum;
}


int main() {
    int n,k;
    cin>>n>>k;
    tree.assign(4*n+1,0);
    while(k--){
        int a;
        cin>>a;
        if(a==1){
            int b,c;
            cin>>b>>c;
            update(1,1,n,b,c);
        }
        else if(a==2){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}
