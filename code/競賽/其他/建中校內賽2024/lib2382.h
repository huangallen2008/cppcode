#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

namespace GRADER{
    const int lim = 140000;
    vector<int> v;
    int cnt = 0;
    int n;
    void Init(){
        assert(1 == scanf("%d", &n));
        v = vector<int>(n);
        for(int i = 0;i<n;i++)assert(1 == scanf("%d",&v[i]));
    }
    int Ask(int a,int b,int c){
        if(a<0||a>=n||b<0||b>=n||c<0||c>=n){
            puts("Out of Range!\n");
            exit(0);
        }
        cnt++;
        if(cnt>lim){
            puts("Too Many Queries!\n");
            exit(0);
        }
        if(v[a]>=max(v[b],v[c]))return v[b]^v[c];
        else if(v[b]>=max(v[a],v[c]))return v[a]^v[c];
        else return v[a]^v[b];
    }
}

int Ask(int a,int b,int c){return GRADER::Ask(a,b,c);}
int Init(){GRADER::Init();return GRADER::n;}
void Answer(vector<int> v){
    printf("%d\n",(int)v.size());
    for(auto &i:v)printf("%d ",i);
    printf("\n%d",GRADER::cnt);
}