#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","w",stdout);
	int n=200000;
    int q=n;
    cout<<n<<" "<<q<<endl;
    int t=200000;
    for(int i=1;i<=n;i++){
        cout<<t;
        if(i!=n) cout<<" ";
    }
    int up = 904;
    cout<<endl;
    for(int i=1;i<=q;i++){
        cout<<n<<" "<<up<<endl;
    }
}