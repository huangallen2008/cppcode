// #define GU getchar_unlocked()
// #define PU putchar_unlocked
#define GU _getchar_nolock()
#define PU _putchar_nolock
int in() {
    int x=0;
    char ch=GU;
    while(ch==' '||ch=='\n') ch=GU;
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=GU;
    return x;
}
void out(int x) {
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PU(*it);
    PU(' ');
}
////////////////////////////////////////////////////////////////////
inline char readchar(){
	const int S = 1<<16;
	static char buf[S], *p = buf, *q = buf;
	return p == q and (q = (p = buf) + fread(buf, 1, S, stdin)) == buf ? EOF : *p++;
}
inline int R(){
	int ans = 0; char c = readchar(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = readchar();
	if(c == '-') minus = true, c = readchar();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = readchar();
	return minus ? -ans : ans;
}
inline int R(int &a){
	static char c;
	while(((c = readchar()) < '0' or c > '9') and c != '-' and c != EOF);
	if(c == '-'){
		a = 0;
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a -= c ^ '0';
	} else {
		a = c ^ '0';
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a += c ^ '0';
	}
}
////////////////////////////////////////////////////////////////////
#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
// 請斟酌使用下面兩行，這只能在特定的時候使用
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65516)write(1,OB,OP),OP=0;}
 
inline int RI(){static char c;int a;while(((c=RC())<'0'||c>'9')&&c!='-'&&c!=-1);if(c=='-'){a=0;while((c=RC())>='0'&&c<='9')a*=10,a-=c^'0';}else{a=c^'0';while((c=RC())>='0'&&c<='9')a*=10,a+=c^'0';}return a;}
inline int RU(){static char c;int a;while(((c=RC())<'0'||c>'9')&&c!=-1);a=c^'0';while((c=RC())>='0'&&c<='9')a*=10,a+=c^'0';return a;}
inline void WI(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;if(n<0){OB[OP++]='-';while(n)buf[p++]='0'-(n%10),n/=10;}else{while(n)buf[p++]='0'+(n%10),n/=10;}for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>S-12)write(1,OB,OP),OP=0;}
inline void WU(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65524)write(1,OB,OP),OP=0;}
////////////////////////////////////////////////////////////////////
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

/////////////////////////
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}//快读，不理解的同学用cin代替即可
//re int a;
////////////////////////
#define GC getchar()
#define PC putchar
int in() {
    int x=0;
    char ch=GC;
    while(ch==' '||ch=='\n') ch=GC;
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=GC;
    return x;
}
void out(int x) {
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC(' ');
}
////////////////////
#define GC getchar()
#define PC putchar
inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=(~x)+1;
    return x;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=~(x-1);
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC(' ');
}