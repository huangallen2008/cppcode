#define pii pair<int,int>
#define f first
#define s second
class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        for(int i=1;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]) a[i][j]=a[i-1][j]+1;
        int val=0,an=0;
        vector<pair<int,int>> stk;
        for(int i=0;i<n;i++) {
            stk={{0,0}};
            for(int j=0;j<m;j++) {
                while(stk.back()>a[i][j]) {
                    val-=stk.back().f*(stk.back().s-stk[stk.size()-2].s);
                    stk.pop_back();
                }
                val+=(j-stk.back().s)*a[i][j];
                stk.push_back({a[i][j],j});
                an+=val;
            }
        }
        return an;
    }
};