void SA(string s) {
    s+='$';
    int n=SZ(s);
    Vi p(n),rk(n);
    REP(i,n) p[i]=i;
    sort(ALL(p),[&](int a,int b) { return s[a]<s[b]; });
    rk[p[0]]=0;
    REP1(i,n-1) rk[p[i]]=rk[p[i-1]]+(s[p[i]]!=s[p[i-1]]);
    auto count_sort=[&]() {
        vector<Vi> cnt(n);
        for(int x:p) cnt[rk[x]].pb(x);
        int it=0;
        REP(i,n) for(int x:cnt[i]) p[it++]=x;
    };
    for(int k=1;k<n;k<<=1) {
        REP(i,n) p[i]=(p[i]-k+n)%n;
        count_sort();
        Vi nrk(n);
        nrk[p[0]]=0;
        REP1(i,n-1) nrk[p[i]]=nrk[p[i-1]]+(rk[p[i]]!=rk[p[i-1]]||rk[(p[i]+k)%n]!=rk[(p[i-1]+k)%n]);
        swap(rk,nrk);
    };
    //lcp
    int k=0;
    Vi lcp(n);
    REP(i,n-1) {
        int j=p[rk[i]-1];
        while(i+k<n-1&&j+k<n-1&&s[i+k]==s[j+k]) k++;
        lcp[i]=k;
        k=max(0ll,k-1);
    }
    // p[]  rk[]  lcp[]  
}