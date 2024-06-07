#include<bits/stdc++.h>
#include "lib2249.h"
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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
string solve(int n0,int n2) {
    string s1="",s2="";
    int n=n0+n2;
    if(n2&1) {
        if(n2<11) return "-1";
        if(n0<10) return "-1";
        int c1=(n2+11)/2,c2=(n2-11)/2;
        if(c2==0&&n<=21) return "-1";
        if(c2==0) {
            REP(i,c1) s2+="02";
            REP(i,n-c1*2) s2+='0';
            if(n==22) {
                s1=s2;
            }
            else {
                REP(i,c1-1) s1+="20";
                s1+="002";
                REP(i,n-c1*2-1) s1+='0';
            }
            reverse(ALL(s2));
            return s1+" "+s2;
        }
        REP(i,n) {
            if(i&1) {
                if(i/2==c2-1) s2+='0';
                else if(i/2==c2) s2+='2';
                else if(i/2<c2) s2+='2';
                else s2+='0';
            }
            else {
                if(i/2<c1) s2+='2';
                else s2+='0';
            }
        }
        if(c1*2+1<=n) {
            REP(i,n) {
                if(i&1) {
                    if(i/2<c2) s1+='2';
                    else s1+='0';
                }
                else {
                    if(i/2==c1-1) s1+='0';
                    else if(i/2==c1) s1+='2';
                    else if(i/2<c1) s1+='2';
                    else s1+='0';
                }
            }
        }
        else if(c1*2==n) {
            swap(c1,c2);
            REP(i,n) {
                if(i&1) {
                    if(i/2<c2) s1+='2';
                    else s1+='0';
                }
                else {
                    if(i/2<c1) s1+='2';
                    else s1+='0';
                }
            }
        }
        else {
            s1=s2;
        }
        reverse(ALL(s2));
        return s1+" "+s2;
    }
    else {
        if(n0==0) return "-1";
        int c1=(n2)/2,c2=(n2)/2;
        REP(i,n2-2) s2+='2';
        s2+="022";
        REP(i,n0-1) s2+='0';
        if(n0==1) {
            REP(i,n-3) s1+='2';
            s1+="022";
        }
        else {
            REP(i,n2-1) s1+='2';
            s1+="002";
            REP(i,n0-2) s1+='0';
        }
        reverse(ALL(s2));
        return s1+" "+s2;
    }
}
