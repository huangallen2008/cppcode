#include<bits/stdc++.h>
using namespace std;
#define int long long
template<int T> int c=(T<=1?T:0ll)+c<max(T-1,0ll)>+c<max(T-3,0ll)>;
main() {
    cout<<c<3>;
    cout<<c<1><<endl;
    cout<<c<20>;
}