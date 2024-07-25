#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
struct Matrix {
    vector<vector<int>> m;
    Matrix(){}
    Matrix(vector<vector<int>> p) {
        m=p;
    }
    Matrix operator*(Matrix p) {
        vector<vector<int>> r(m.size(),vector<int>(p.m[0].size()));
        REP(i,m.size())
            REP(j,p.m[0].size())
                REP(k,p.m.size())
                    r[i][j]=(r[i][j]+m[i][k]*p.m[k][j])%mod;
        Matrix res(r);
        return res;
    }
};
Matrix pw(vector<vector<int>> init,Matrix x,int p) {
    Matrix r(init);
    while(p>0) {
        if(p&1) r=r*x;
        p>>=1;
        x=x*x;
    }
    return r;
}
signed main() {
    IOS();
    vector<vector<int>> init={{1,1}};
    Matrix x({{1,1},{1,0}});
    int n;
    while(cin>>n) {
        Matrix an=pw(init,x,n-1);
        cout<<an.m[0][0]<<'\n';
    }
    return 0;
}
