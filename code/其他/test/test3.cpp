#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e6,NIL=-1;

int cnt;
map<int,int>lg;
struct vEB{
	int u,summary;
	vector<int>cluster;
	int min,max;
}vEB[MAXN];


inline void Tree_Build(int p,int size){//u=2^size
	vEB[p].summary=vEB[p].min=vEB[p].max=NIL;
	if(size<=1){
		vEB[p].u=2;return;
	}
	vEB[p].u=1<<size;
	int cluster_size=(size>>1)+(size&1);//即ceil(log(u)/2)
	vEB[p].summary=++cnt;
	Tree_Build(vEB[p].summary,cluster_size);
	vEB[p].cluster.resize(1<<cluster_size);	//节省空间用的
	for(int i=0;i<1<<cluster_size;++i){
		vEB[p].cluster[i]=++cnt;
		Tree_Build(vEB[p].cluster[i],size>>1);
	}
	
	return;
}

void init(){
	for(int i=0;i<32;++i)lg[1<<i]=i;
}
inline int high(int p,int x){
	int u=1<<(lg[vEB[p].u]>>1);
	return x/u;
}
inline int low(int p,int x){
	int u=1<<(lg[vEB[p].u]>>1);
	return x%u;
}
inline int index(int p,int x,int y){
	int u=1<<(lg[vEB[p].u]>>1);
	return x*u+y;
}

inline int Tree_Minimum(int p){
	return vEB[p].min;
}
inline int Tree_Maximum(int p){
	return vEB[p].max;
}
bool Tree_Member(int p,int x){
	if(x==vEB[p].min||x==vEB[p].max)return true;
	if(vEB[p].u==2)return false;
	return Tree_Member(vEB[p].cluster[high(p,x)],low(p,x));
}
int Tree_Successor(int p,int x){
	if(vEB[p].u==2){
		if(x==0&&vEB[p].max==1)return 1;
		return NIL;
	}
	if(vEB[p].min!=NIL&&x<vEB[p].min)return vEB[p].min;
	int offset,max_low=Tree_Maximum(vEB[p].cluster[high(p,x)]);
	if(max_low!=NIL&&low(p,x)<max_low){
		offset=Tree_Successor(vEB[p].cluster[high(p,x)],low(p,x));
		return index(p,high(p,x),offset);
	}
	int succ_cluster=Tree_Successor(vEB[p].summary,high(p,x));
	if(succ_cluster==NIL)return NIL;
	offset=Tree_Minimum(vEB[p].cluster[succ_cluster]);
	return index(p,succ_cluster,offset);
}
int Tree_Predecessor(int p,int x){
	if(vEB[p].u==2){
		if(x==1&&vEB[p].min==0)return 0;
		return NIL;
	}
	if(vEB[p].max!=NIL&&x>vEB[p].max)return vEB[p].max;
	int offset,min_low=Tree_Minimum(vEB[p].cluster[high(p,x)]);
	if(min_low!=NIL&&low(p,x)>min_low){
		offset=Tree_Predecessor(vEB[p].cluster[high(p,x)],low(p,x));
		return index(p,high(p,x),offset);
	}
	int pred_cluster=Tree_Predecessor(vEB[p].summary,high(p,x));
	if(pred_cluster==NIL){
		if(vEB[p].min!=NIL&&x>vEB[p].min)return vEB[p].min;
		return NIL;
	}
	offset=Tree_Maximum(vEB[p].cluster[pred_cluster]);
	return index(p,pred_cluster,offset);
}
inline void Empty_Tree_Insert(int p,int x){
	vEB[p].max=vEB[p].min=x;
}
void Tree_Insert(int p,int x){
	if(vEB[p].min==NIL){
		Empty_Tree_Insert(p,x);
		return;
	}
	if(x<vEB[p].min)swap(x,vEB[p].min);
	if(vEB[p].u>2){
		if(Tree_Minimum(vEB[p].cluster[high(p,x)])==NIL){
			Tree_Insert(vEB[p].summary,high(p,x));
			Empty_Tree_Insert(vEB[p].cluster[high(p,x)],low(p,x));
		}else Tree_Insert(vEB[p].cluster[high(p,x)],low(p,x));
	}
	if(x>vEB[p].max)vEB[p].max=x;
	return;
}
void Tree_Delete(int p,int x){
	if(vEB[p].min==vEB[p].max){
		vEB[p].min=vEB[p].max=NIL;
		return;
	}
	if(vEB[p].u==2){
		vEB[p].max=vEB[p].min=!x;
		return;
	}
	if(x==vEB[p].min){
		int first_cluster=Tree_Minimum(vEB[p].summary);
		x=index(p,first_cluster,Tree_Minimum(vEB[p].cluster[first_cluster]));
		vEB[p].min=x;
	}
	Tree_Delete(vEB[p].cluster[high(p,x)],low(p,x));
	if(Tree_Minimum(vEB[p].cluster[high(p,x)])==NIL){
		Tree_Delete(vEB[p].summary,high(p,x));
		if(x==vEB[p].max){
			int summary_max=Tree_Maximum(vEB[p].summary);
			if(summary_max==NIL)vEB[p].max=vEB[p].min;
			else vEB[p].max=index(p,summary_max,Tree_Maximum(vEB[p].cluster[summary_max]));
		}
	}else if(x==vEB[p].max)vEB[p].max=index(p,high(p,x),Tree_Maximum(vEB[p].cluster[high(p,x)]));
	return;
}

int n,m,rt;
int main(){
	init();
//	freopen("std.in","r",stdin);
//  freopen("my.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u=0;for(--n;n;n>>=1,++u);
	Tree_Build(rt,u);
	while(m--){
		int op,x;scanf("%d",&op);
		if(op==1){
			scanf("%d",&x);
			if(!Tree_Member(rt,x))Tree_Insert(rt,x);
		}else if(op==2){
			scanf("%d",&x);
			if(Tree_Member(rt,x))Tree_Delete(rt,x);
		}else if(op==3){
			printf("%d\n",Tree_Minimum(rt));
		}else if(op==4){
			printf("%d\n",Tree_Maximum(rt));
		}else if(op==5){
			scanf("%d",&x);
			printf("%d\n",Tree_Predecessor(rt,x));
		}else if(op==6){
			scanf("%d",&x);
			printf("%d\n",Tree_Successor(rt,x));
		}else if(op==7){
			scanf("%d",&x);
			printf("%d\n",Tree_Member(rt,x)?1:-1);
		}
	}
	return 0;
}