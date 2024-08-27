#include<bits/stdc++.h>
using namespace std;
int T;
int main() {
    string ans="";
    cin>>T;
    while(T--) {
        string n;
        cin>>n;
        for(int i=0;i<n.size();i++) {
            if(n[i]=='0') {
                n[i]='9';
                break;
            }
            else if(n[i]=='1') {
                continue;
            }
            else if(n[i]=='2') {
                n[i]='3';
                break;
            }
            else if(n[i]=='3') {
                bool b=true;
                for(int j=i+1;j<n.size();j++) {
                    if(n[j]=='8') {
                        n[i]='9';
                        n[j]='9';
                        b=false;
                        break;
                    }
                }
                if(b) {
                    for(int j=n.size()-1;j>i;j--) {
                        if(n[j]=='6') {
                            n[i]='9';
                            n[j]='5';
                            b=false;
                            break;
                        }
                        if(n[j]=='9') {
                            n[i]='9';
                            n[j]='5';
                            b=false;
                            break;
                        }
                    }
                }
                if(b) {
                    n[i]='5';
                }
                break;
            }
            else if(n[i]=='4') {
                n[i]='7';
                break;
            }
            else if(n[i]=='5') {
                bool b=true;
                for(int j=i+1;j<n.size();j++) {
                    if(n[j]=='8') {
                        n[i]='9';
                        n[j]='9';
                        b=false;
                        break;
                    }
                }
                if(b) {
                    for(int j=n.size()-1;j>i;j--) {
                        if(n[j]=='6') {
                            n[i]='9';
                            n[j]='5';
                            b=false;
                            break;
                        }
                        if(n[j]=='9') {
                            n[i]='9';
                            n[j]='5';
                            b=false;
                            break;
                        }
                    }
                }
                if(b) continue;
                else  break;
            }
            else if(n[i]=='6') {
                n[i]='9';
                break;
            }
            else if(n[i]=='7') {
                continue;
            }
            else if(n[i]=='8') {
                bool b=true;
                for(int j=i+1;j<n.size();j++) {
                    if(n[j]=='0') {
                        n[i]='9';
                        n[j]='8';
                        b=false;
                        break;
                    }
                    if(n[j]=='3') {
                        n[i]='9';
                        n[j]='9';
                        b=false;
                        break;
                    }
                    if(n[j]=='5') {
                        n[i]='9';
                        n[j]='9';
                        b=false;
                        break;
                    }
                    if(n[j]=='6') {
                        n[i]='9';
                        n[j]='8';
                        b=false;
                        break;
                    }
                }
                if(b) {
                    for(int j=n.size()-1;j>i;j--) {
                        if(n[j]=='9') {
                            n[i]='9';
                            n[j]='8';
                            b=false;
                            break;
                        }
                    }
                }
                if(b) continue;
                else  break;
            }
            else if(n[i]=='9') {
                continue;
            }
        }
        ans+=n+"\n";
    }
    cout<<ans;
    return 0;
}
