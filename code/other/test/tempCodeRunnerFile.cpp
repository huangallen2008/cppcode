
    int n=100;
    REP1(i,n) {
        vector<int> v;
        REP1(j,i) {
            if(isp(i^j)) {
                // cout<<i<<' '<<j<<'\n';
                v.pb(j);
            }
        }
        op(i)oparr(v)
    }