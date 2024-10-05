maxn<<1) {
        // op(i)
        if(deg[i]&1) {
            ope(i)
            odds.pb(i);
            if(last!=-1) {
                g[i].pb({last,eid});
                g[last].pb({i,eid});
                eid++;
                last=-1;
            } 
            else last=i;
        }
    }