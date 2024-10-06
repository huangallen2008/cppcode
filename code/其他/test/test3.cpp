#include <iostream>
#include <vector>
#include <map>
#define int long long int
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    map<int, int> v;
    map<int, int> mp;
    mp[0] = 0;
    mp[n+1] = 0;
    while (m--) {
        int q, l, r, x;
        long long sum = 0;
        cin >> q;

        if (q == 1) {
            cin >> l >> r >> x;
            auto it = mp.lower_bound(r+1);
            if(it->first != r+1)
                --it;
            int value = it -> second;
            //cout<<it->first<<' '<<value<<endl;
            auto start = mp.upper_bound(l);
            auto end = mp.lower_bound(r+1);
            mp.erase(start, end);
            mp.insert_or_assign(r+1,value);
            mp.insert_or_assign(l,x);
            /*for(const auto& pair:mp)
            {
                cout<<"("<<pair.first<<","<<pair.second<<"), ";
            }
            cout<<endl;*/
        } else {
            cin >> l >> r;
            int index;map<int,int> newmap;
            auto start = mp.lower_bound(l);
            if(start->first != r+1){
                --start;
                newmap[start->second] = 0;
                index = start -> second;
                ++start;
            }
            else{
                newmap[start->second] = 0;
                index = start -> second;
            }
            auto end = mp.upper_bound(r);
            auto it = mp.lower_bound(r+1);
            if(it->first != r+1)
                --it;
            int value = it -> second;
            //cout<<it->first<<' '<<value<<endl;
            
            for(int i=l;i<=r;i++)
            {
                auto search = mp.find(i);
                if (search != mp.end()) {
                    index = search->second;
                    newmap[index]++;
                } else {
                    newmap[index]++;
                }
            }
            mp.erase(start, end);
            mp.insert_or_assign(r+1,value);
            mp.insert_or_assign(l,0);
            for(const auto& pair:newmap)
            {
                int v = pair.second;
                if(pair.first)
                    sum+=v*v;
            }
            for(const auto& pair:mp)
            {
                cout<<"("<<pair.first<<","<<pair.second<<"), ";
            }
            cout<<endl;
            cout << sum << endl;
        }
    }
    return 0;
}