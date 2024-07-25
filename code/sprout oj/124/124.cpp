int n,lx,ly,a[1025][1025]={};
void f(int x,int y,int s,int b) {
    int mx=x+s/2,my=y+s/2;
    if(s==2) {
        if(b==0) {
            if(lx==x && ly==y) Report(x+2,y+1,x+1,y+2,x+2,y+2);
            if(lx==x && ly!=y) Report(x+2,y+1,x+1,y+1,x+2,y+2);
            if(lx!=x && ly==y) Report(x+1,y+1,x+1,y+2,x+2,y+2);
            if(lx!=x && ly!=y) Report(x+1,y+1,x+2,y+1,x+1,y+2);
        }
        if(b==1) Report(x+2,y+1,x+1,y+1,x+2,y+2);
        if(b==2) Report(x+2,y+1,x+1,y+2,x+2,y+2);
        if(b==3) Report(x+1,y+1,x+1,y+2,x+2,y+2);
        if(b==4) Report(x+1,y+1,x+2,y+1,x+1,y+2);
    }
    else if(b==0){
        if(lx<mx && ly<my) {
            Report(mx+1,my+1,mx,my+1,mx+1,my);
            f(x,y,s/2,0);
            f(x,my,s/2,3);
            f(mx,y,s/2,1);
            f(mx,my,s/2,2);
        }
        if(lx<mx && ly>=my) {
            Report(mx+1,my+1,mx,my,mx+1,my);
            f(x,y,s/2,4);
            f(x,my,s/2,0);
            f(mx,y,s/2,1);
            f(mx,my,s/2,2);
        }
        if(lx>=mx && ly<my) {
            Report(mx+1,my+1,mx,my+1,mx,my);
            f(x,y,s/2,4);
            f(x,my,s/2,3);
            f(mx,y,s/2,0);
            f(mx,my,s/2,2);
        }
        if(lx>=mx && ly>=my) {
            Report(mx,my,mx,my+1,mx+1,my);
            f(x,y,s/2,4);
            f(x,my,s/2,3);
            f(mx,y,s/2,1);
            f(mx,my,s/2,0);
        }
    }
    else if(b==1){
        Report(mx+1,my+1,mx,my,mx+1,my);
        f(x,y,s/2,4);
        f(x,my,s/2,1);
        f(mx,y,s/2,1);
        f(mx,my,s/2,2);
    }
    else if(b==2){
        Report(mx+1,my+1,mx,my+1,mx+1,my);
        f(x,y,s/2,2);
        f(x,my,s/2,3);
        f(mx,y,s/2,1);
        f(mx,my,s/2,2);
    }
    else if(b==3){
        Report(mx+1,my+1,mx,my+1,mx,my);
        f(x,y,s/2,4);
        f(x,my,s/2,3);
        f(mx,y,s/2,3);
        f(mx,my,s/2,2);
    }
    else if(b==4){
        Report(mx,my,mx,my+1,mx+1,my);
        f(x,y,s/2,4);
        f(x,my,s/2,3);
        f(mx,y,s/2,1);
        f(mx,my,s/2,4);
    }
}
void solve(int N,int X,int Y) {
    n=N; lx=X-1; ly=Y-1;
    f(0,0,n,0);
}
