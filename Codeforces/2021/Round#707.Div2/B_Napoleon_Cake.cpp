#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1000005,E=524288;
int x[N],y[N],i,mp,c,t,f[N],a[N];
long long n,m,k;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	long long g=exgcd(b,a%b,x,y);
	long long tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			f[i]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			++f[max(i-a[i]+1,1)];
			--f[i+1];
		}
		for(i=1;i<=n;++i)
			f[i]+=f[i-1];
		for(i=1;i<=n;++i)
			printf("%d ",f[i]?1:0);
		printf("\n");
	}
	
}