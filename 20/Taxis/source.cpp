#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long a[500000];
vector<long long> b;

int main(){
	long long m,d;
	int n,i;
	scanf("%lld %lld %d",&m,&d,&n);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	if(a[n-1]>=m+d){
		puts("1");
		return 0;
	}
	int p=lower_bound(a,a+n,m-d)-a;
	if(p==n){
		puts("0");
		return 0;
	}
	for(i=n-1;i>p;i--)b.push_back(a[i]);
	for(i=p-1;i>=0;i--)b.push_back(a[i]);
	long long pr=0;
	for(i=0;i<n-1;i++){
		if(b[i]<=d-pr){
			puts("0");
			return 0;
		}
		pr=b[i]-(d-pr)+pr;
		if(pr>=d||(d-pr)*2+(m-d)<=a[p])break;
	}
	if(i==n-1)puts("0");
	else if(pr>=m)printf("%d\n",i+1);
	else printf("%d\n",i+2);
	return 0;
}
