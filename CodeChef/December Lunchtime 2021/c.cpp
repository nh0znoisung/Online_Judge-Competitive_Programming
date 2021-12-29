#include<bits/stdc++.h>

using namespace std;

void init_code(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif
}
int n;
vector<int> v;
void testcase(){
    int a=1e6+1,b=0,c=0,idx=0;
    for(int i=0;i<n;i++){
        a = min(a,v[i]);
        if(b<v[i]){
            b=v[i];
            idx=i;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=idx&&c<v[i]){
            c=v[i];
        }
    }
    cout<<(long long)c*(b-a)<<endl;
}
int main(){
	init_code();
	int t;
	cin>>t;
	while(t--){
        cin>>n;
        v = vector<int>(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        testcase();
	}
	return 0;
}