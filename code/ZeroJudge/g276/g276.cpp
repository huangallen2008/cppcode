#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500][4],p[102][102]={};
vector<vector<int> > v;
vector<pair<int,int> > b,c;
int bb() {
    int an=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(p[i][j])
                an++;
    return an;
}
void mo() {
    for(int i=0;i<v.size();i++) {
        v[i][0]+=v[i][2];
        v[i][1]+=v[i][3];
        if(v[i][0]<0 || v[i][0]>=n || v[i][1]<0 || v[i][1]>=m) {
            v.erase(v.begin()+i);
            i--;
        }
    }
}
main() {
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        p[a][b]++;
        v.push_back({a,b,c,d});
    }
    while(v.size()) {
        mo();
        for(int i=0;i<v.size();i++) {
            if(p[v[i][0]][v[i][1]]>0) {
                b.push_back({v[i][0],v[i][1]});
                v.erase(v.begin()+i);
                i--;
            }
            else
            c.push_back({v[i][0],v[i][1]});
        }
        while(b.size()) { p[b[0].first][b[0].second]=0; b.erase(b.begin()); }
        while(c.size()) { p[c[0].first][c[0].second]++; c.erase(c.begin()); }
    }
    cout<<bb();
    return 0;
}
