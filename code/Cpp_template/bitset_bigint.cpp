#include<bits/stdc++.h>
using namespace std;


template<size_t n> 
bitset<n> operator+(const bitset<n> a,const bitset<n> b) {
    bitset<n> c;
    for(int i=0;i<n-1;i++) {
        c[i+1]=(c[i]&a[i])|(c[i]&b[i])|(a[i]&b[i]);
        c[i]=c[i]^a[i]^b[i];
    } 
    c[n-1]=c[n-1]^a[n-1]^b[n-1];
    return c;
}

template<size_t n> 
bitset<n> operator-(bitset<n> a) {
    a=~a;
    for(int i=0;i<n;i++) {
        if(a[i]) a[i]=0; 
        else { 
            a[i]=1;
            break;
        }
    }
    return a;
}

template<size_t n> 
bitset<n>& operator+=(const bitset<n> &a,const bitset<n> b) {
    bitset<n> c=a;
    for(int i=0;i<n-1;i++) {
        c[i+1]=(c[i]&a[i])|(c[i]&b[i])|(a[i]&b[i]);
        c[i]=c[i]^a[i]^b[i];
    }
    c[n-1]=c[n-1]^a[n-1]^b[n-1];
    return c;
}

template<size_t n> 
bitset<n> operator*(bitset<n> a,bitset<n> b) {
    bitset<n> c;
    while(b!=0) {
        if(b[0]) {
            c=c+a;
        }
        a=a<<1;
        b=b>>1;
    }
    return c;
}