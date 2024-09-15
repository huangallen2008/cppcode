#include<vector>
#include<map>
using namespace std;
main() {
	vector<pair<int,int> > v;
    map<int,int> m;
    int n,p=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b,c;
    	scanf("%d%d%d",&a,&b,&c);
    	m[b]+=(-a*2+3)*((a-1)*n+1);
    	m[c]-=(-a*2+3)*((a-1)*n+1);
	}
    for(auto &t : m) {
    	if(p>0 && p+t.second<=0)
    	    v[v.size()-1].second=t.first;
    	else if(p<=0 && p+t.second>0)
    	    v.push_back({t.first,0});
    	p+=t.second;
    }
    printf("%d\n",v.size());
    for(auto i : v)
    	printf("%d %d\n",i.first,i.second);
    return 0;
}
