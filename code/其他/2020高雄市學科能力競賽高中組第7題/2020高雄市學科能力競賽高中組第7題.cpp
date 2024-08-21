#include<bits/stdc++.h>
using namespace std;
int h[10000]={1};
int sti(string s) { stringstream ss;    int n; ss<<s; ss>>n; return n; }
string its(int n) { stringstream ss; string s; ss<<n; ss>>s; return s; }
void p(string l) {
	if(h[sti(l)]>9) return;
	cout<<h[sti(l)]++;
	p(l.substr(1,3)+its(h[sti(l)]-1));
}
main() {
	h[9000]=1; h[9900]=1; h[9990]=1; h[9999]=1;
	cout<<"0000"; p("0000"); cout<<"0000";
    return 0; 
}
