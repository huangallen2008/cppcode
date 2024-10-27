#include <iostream>
#include <vector>
#define lli long long int
using namespace std;

vector<lli> T;

lli gcd(lli a, lli b) {
    if(b == 0) 
        return a;
    return gcd(b, a%b);
}

lli gcd_vector(vector<lli>& a, lli b) {
    lli ma = 1;
    for(int i=0; i<T.size(); i++)
        ma = ma*T[i]%b;
    return gcd(b, ma);
}

int main() {
    int n;
    cin>>n;
    T=vector<lli>(n);
    for(int i=0;i<n;i++) cin>>T[i];
    lli answer = 1;
    for(int i=1; i<=1000; i++) {
        lli factor = i/gcd_vector(T, i); 
        T.push_back(factor);
        answer = (answer*factor)%1000000007;
    }

    cout << answer << endl;
}