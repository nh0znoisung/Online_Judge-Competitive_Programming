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
string s;
void testcase(){
    int a=0,b=0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') a++;
        else b++;
    }
    cout<<max(min(a,b)-1,0)<<endl;
}
int main(){
	init_code();
	int t;
	cin>>t;
	while(t--){
        cin>>n>>s;
        testcase();
	}
	return 0;
}