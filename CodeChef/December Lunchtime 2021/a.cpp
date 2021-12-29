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
int x,y,z;
void testcase(){
	// cout<<x<<y<<z<<endl;
	if(x+y < z){
		cout<<"PLANEBUS"<<endl;
	}else if(z < x+y){
		cout<<"TRAIN"<<endl;
	}else{
		cout<<"EQUAL"<<endl;
	}
}
int main(){
	init_code();
	int t;
	cin>>t;
	while(t--){
		cin>>x>>y>>z;
		testcase();
	}
	return 0;
}