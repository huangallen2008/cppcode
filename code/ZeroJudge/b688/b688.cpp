#include<bits/stdc++.h>
using namespace std;
int m(int a,int b,int c,int d) {
    return min(min(abs(b-c),abs(b-d)),min(abs(a-c),abs(a-d)));
}
struct d {
    int x,y;
};
d a[2][2];
int dis(int p,int q,int r,int s) {
    int an=abs(q-s)*abs(q-s)+abs(p-r)*abs(p-r);
    if((a[0][0].x>a[1][0].x && a[0][0].x<a[1][1].x) || (a[0][1].x>a[1][0].x && a[0][1].x<a[1][1].x) || (a[1][1].x>a[0][0].x && a[1][1].x<a[0][1].x))
        an=min(an,m(a[0][0].y,a[0][1].y,a[1][0].y,a[1][1].y));
    if((a[0][0].y>a[1][0].y && a[0][0].y<a[1][1].y) || (a[0][1].y>a[1][0].y && a[0][1].y<a[1][1].y) || (a[1][1].y>a[0][0].y && a[1][1].y<a[0][1].y))
        an=min(an,m(a[0][0].x,a[0][1].x,a[1][0].x,a[1][1].x));
    return an;
}
void f() {
    int p,q,r,s;
    p=min(a[0][1].y,a[1][1].y);
    q=min(a[0][1].x,a[1][1].x);
    r=max(a[0][0].y,a[1][0].y);
    s=max(a[0][0].x,a[1][0].x);
    if(r<p && s<q) cout<<"overlap="<<(p-r)*(q-s)<<"\n";
    else if(p==r && q==s) cout<<"x="<<q<<"\ny="<<p<<"\n";
    else if(p==r) cout<<"touch="<<abs(q-s)<<"\n";
    else if(q==s) cout<<"touch="<<abs(p-r)<<"\n";
    else cout<<"dis=sqrt("<<dis(p,q,r,s)<<")\n";
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>a[0][0].x>>a[0][0].y>>a[0][1].x>>a[0][1].y;
    cin>>a[1][0].x>>a[1][0].y>>a[1][1].x>>a[1][1].y;
    f();
    return 0;
}
