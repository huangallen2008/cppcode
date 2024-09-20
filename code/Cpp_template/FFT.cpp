namespace FFT{
	struct comp{
		db x,y;
		comp(const db x_=0,const db y_=0){x=x_;y=y_;}
	}A[MAXN],B[MAXN],C[MAXN],D[MAXN];
	int N;
	comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
	comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
	comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	comp conj(comp a){return comp(a.x,-a.y);}
	db si[MAXN],cs[MAXN];
	
	void prepare(){
		fo(i,0,maxn){
			si[i]=sin(pi*2/maxn*i);
			cs[i]=cos(pi*2/maxn*i);
		}
	}
	
	void DFT(comp *a){
		for(int i=0,j=0;i<N;i++){
			if (i<j)swap(a[i],a[j]);
			int x=N>>1;
			for(;(j^x)<j;x>>=1)j^=x;
			j^=x;
		}
		for(int i=1,d=1;i<N;i<<=1,d++)
			for(int j=0;j<N;j+=(i<<1))
				for(int k=0;k<i;k++){
					comp l=a[j+k],r=a[i+j+k]*comp(cs[(maxn>>d)*k],si[(maxn>>d)*k]);
					a[i+j+k]=l-r;
					a[j+k]=l+r;
				}
	}
	
	void IDFT(comp *a){
		DFT(a);
		reverse(a+1,a+N);
		fo(i,0,N-1)a[i].x/=N,a[i].y/=N;
	}
	
	void multi(LL *a,LL *b,LL *c,int n,int m,bool sig=1){
		if (sig){
			N=1;
			while(N<=n+m)N<<=1;
		}
		fo(i,0,N-1)A[i]=B[i]=comp(0,0);
		fo(i,0,n)A[i]=comp(a[i]>>15,a[i]&32767);
		fo(i,0,m)B[i]=comp(b[i]>>15,b[i]&32767);
		DFT(A),DFT(B);
		fo(i,0,N-1){
			comp x=A[i],y=A[i==0?0:N-i];
			comp a0=(x+conj(y))*comp(0.5,0),a1=(x-conj(y))*comp(0,-0.5);
			x=B[i],y=B[i==0?0:N-i];
			comp b0=(x+conj(y))*comp(0.5,0),b1=(x-conj(y))*comp(0,-0.5);
			C[i]=a0*b0+a1*b0*comp(0,1);
			D[i]=a0*b1+a1*b1*comp(0,1);
		}
		IDFT(C),IDFT(D);
		LL cv=32768ll*32768%mo;
		fo(i,0,n+m){
			LL v1=C[i].x+0.3,v2=C[i].y+0.3,v3=D[i].x+0.3,v4=D[i].y+0.3;
			v1=v1%mo,v2=v2%mo,v3=v3%mo,v4=v4%mo;
			LL v=(v1*cv+v2*32768+v3*32768+v4)%mo;
			c[i]=v;
		}
	}
}