#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int t;
    string s;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>s;
        if(s.substr(s.size()-2,1)!="r" || s.substr(s.size()-1,1)!="u")
        {
            s=s.substr(0,s.size()-1)+"imasu";
        }
        else
        {
            if(s.substr(s.size()-3,1)=="u" && s.substr(s.size()-4,1)=="s")
            {
                s=s.substr(0,s.size()-4)+"simasu";
            }
            else if(s.substr(s.size()-3,1)=="u" && s.substr(s.size()-4,1)=="k")
            {
                s=s.substr(0,s.size()-4)+"kimasu";
            }
            else if(s.substr(s.size()-3,1)=="a" || s.substr(s.size()-3,1)=="u" || s.substr(s.size()-3,1)=="o")
            {
                s=s.substr(0,s.size()-1)+"imasu";
            }
            else if(s.substr(s.size()-3,1)=="i")
            {
                s=s.substr(0,s.size()-2)+"masu";
            }
            else if(s.substr(s.size()-3,1)=="e")
            {
                s=s.substr(0,s.size()-2)+"masu";
                //cout<<s<<"!"<<endl;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
