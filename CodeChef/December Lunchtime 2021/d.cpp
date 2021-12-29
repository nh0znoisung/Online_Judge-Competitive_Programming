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
int n,k;
string s;

void testcase(){
    // O(k^2)
    // char c= s[0];
    // for(int j=k; j>0; j--){
    //     for(int i =0; i<=(j-1)/2; i++){
    //         c = s[i];
    //         s[i] = s[j-i-1];
    //         s[j-i-1] = c;
    //     }
    // }
    string r = s.substr(0,k);
    int curr = 0, tmp = k-1;
    for(int i = k-1; i>=0; i--){
        // cout<<curr<<endl;
        s[i] = r[curr];
        curr += tmp;
        if(tmp < 0) tmp = -tmp-1;
        else tmp = -tmp+1;
    }
    cout<<s<<endl;
}
int main(){
	init_code();
	int t;
	cin>>t;
	while(t--){
        cin>>n>>k>>s;
        testcase();
	}
	return 0;
}