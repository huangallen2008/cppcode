pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
int sign(int x) { if(x>0) return 1;else if(x<0) return -1;else return 0; }
bool onl(pii l1,pii l2,pii p) {return cros(to(l1,l2),to(l1,p))==0&&dot(to(l1,l2),to(l1,p))>=0&&dot(to(l2,l1),to(l2,p))>=0;}
bool dif_side(pii a,pii b,pii c,pii d) {return sign(cros(to(a,b),to(a,c)))*sign(cros(to(a,b),to(a,d)))<0;}
bool inters(pii a,pii b,pii c,pii d) { return !onl(a,b,c)&&!onl(a,b,d)&&!onl(c,d,a)&&!onl(c,d,b)&&dif_side(a,b,c,d)&&dif_side(c,d,a,b); }
pii operator-(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
pii operator+(pii a,pii b) { return {b.f+a.f,b.s+a.s}; }

struct po{
    int x,y;
    po(){}
    po(pii p) { x=p.f,y=p.s; }
    po(int f,int s) { x=f,y=s; }
    po operator-(po b) {
        return {x-b.x,y-b.y};
    }
};
istream& operator>>(istream& os,po &p) { return os>>p.x>>p.y; }
ostream& operator<<(ostream& os,po p) { return os<<"{"<<p.x<<","<<p.y<<"}"; }
po to(po a,po b) { return b-a; }
int sig(int x) { if(x<0) return -1;if(x>0) return 1; return 0; }
int dot(po a,po b) { return a.x*b.x+a.y*b.y; }
int cro(po a,po b) { return a.x*b.y-a.y*b.x; }