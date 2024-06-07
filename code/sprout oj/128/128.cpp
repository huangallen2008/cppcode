int n,a[1025][1025]={};
void f(int x,int y,int t,int p) {
    if(t==2) { a[x][y]=1; a[x][y+1]=2; a[x+1][y]=3; a[x+1][y+1]=1; }
    if(x>0 || y>0) {
        for(int i=0;i<t;i++)
            for(int j=0;j<t;j++)
                a[x+i][y+j]=a[i][j]+p;
        return;
    }
    if(x==0 && y==0 && t==n) return;
    else {
        f(t,y,t,t*2-1);
        f(x,t,t,t*2-1);
        for(int i=0;i<t;i++) a[x+i][t+i]=t*4-1;
        f(t,t,t,0);
        f(0,0,t*2,0);
    }
}
void solve(int N) {
    n=N;
    f(0,0,2,0);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) Report(a[i][j]);
}
