#include<bits/stdc++.h>
using namespace std;
template<int T> int c=(T<=1?T:0)+c<max(T-1,0)>+c<max(T-2,0)>;
main() {
    cout<<c<3>;
    cout<<c<1><<endl;
    cout<<c<50>;
}