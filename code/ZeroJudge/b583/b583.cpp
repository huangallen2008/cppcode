#include<bits/stdc++.h>
using namespace std;
int T,v,e,x,y,t[1001]={},h[1001]={};
vector<vector<int>> a;
queue<int> q;
bool tt() {
    for(int i=0;i<v;i++) if(h[i]==0) return true;
    return false;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        cin>>v>>e;
        a=vector<vector<int>>(v);
        memset(t,0,sizeof(t));
        memset(h,0,sizeof(h));
        q=queue<int>();
        for(int i=0;i<e;i++) {
            cin>>x>>y;
            a[x-1].push_back(y-1);
            t[y-1]++;
        }
        for(int i=0;i<v;i++) {
            if(t[i]==0) {
                q.push(i);
                h[i]++;
            }
        }
        while(q.size()) {
            int f=q.front();
            q.pop();
            for(auto &p:a[f]) {
                if(--t[p]<=0 && h[p]==0) {
                    q.push(p);
                    h[p]++;
                }
            }
        }
        if(tt()) cout<<"O______O\n";
        else cout<<"W+W\n";
    }
    return 0;
}
