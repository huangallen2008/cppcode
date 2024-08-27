#include<bits/stdc++.h>
using namespace std;
int sti(string str) {
    stringstream ss;
    int ii;
    ss<<str;
    ss>>ii;
    return ii;
}
struct IT {
    bool operator()(string a,string b) const {
        if(a[0]!=b[0]) {
            if(a[0]=='+')
                return false;
            else
                return true;
        }
        else {
            int ia=sti(a.substr(1,a.size()-1)),ib=sti(b.substr(1,b.size()-1));
            if(ia>ib)
                return false;
            else
                return true;
        }
    }
};
int main() {
    int n;
    long long an=0;
    priority_queue<string,vector<string>,IT> pq;
    bool b=true;
    cin>>n;
    pair<int,string> a[n+1];
    for(int i=0;i<n;i++) {
        string x;
        int c;
        cin>>x>>c;
        a[i]={c,x};
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        if(a[i].first>i) {
            cout<<"-1\n";
            b=false;
            break;
        }
    }
    if(b) {
        int cc=0;
        for(int i=0;cc<n;i++) {
            while(cc<n && a[cc].first<=i) {
                pq.push(a[cc].second);
                cc++;
            }
            string ts=pq.top();
            pq.pop();
            if(ts[0]=='+')
                an+=sti(ts.substr(1,ts.size()-1));
            else
                an*=sti(ts.substr(1,ts.size()-1));
        }
        while(pq.size()) {
            string ts=pq.top();
            pq.pop();
            if(ts[0]=='+')
                an+=sti(ts.substr(1,ts.size()-1));
            else
                an*=sti(ts.substr(1,ts.size()-1));
        }
        cout<<an%1000000007<<"\n";
    }
    return 0;
}
