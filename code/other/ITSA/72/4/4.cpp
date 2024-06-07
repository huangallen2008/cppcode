#include<bits/stdc++.h>
using namespace std;
string p,t,tt,s;
vector<string> v;
int n,c=0;
stringstream ss;
vector<pair<string,int>> an;
bool so(pair<string,int> p1,pair<string,int> p2) {
    if(s=="L") return p1.first<p2.first;
    else return p1.second<p2.second;
}
main()
{
    cin>>p>>n>>s;
    getline(cin,t);
    getline(cin,t);
    ss<<t;
    while(ss>>tt) v.push_back(tt);
    for(int i=0;i<p.size();i++) p[i]=toupper(p[i]);
    for(int i=0;i<v.size();i++) {
        if(v[i].size()==p.size()) {
            bool sa=true;
            for(int j=0;j<p.size();j++) {
                if(toupper(v[i][j])!=p[j]) {
                    sa=false;
                    break;
                }
            }
            if(sa) {
                string a="";
                int ttt=0;
                for(int j=max(0,i-3);j<=min((int)v.size()-1,i+3);j++) {
                    if(j==i) a+=p;
                    else for(int k=0;k<v[j].size();k++) a+=(char)tolower(v[j][k]);
                    if(j<min((int)v.size()-1,i+3)) a+=" ";
                    if(j=i+1) ttt=v[j][0];
                }
                an.push_back({a,ttt});
            }
        }
    }
    sort(an.begin(),an.end(),so);
    for(int i=0;i<an.size();i++) cout<<an[i].first<<"\n";
    return 0;
}
