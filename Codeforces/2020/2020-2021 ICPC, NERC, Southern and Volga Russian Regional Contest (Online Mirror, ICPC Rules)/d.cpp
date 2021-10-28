#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int>s;
    for(int i = 0; i<m;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    sort(s.begin(), s.end(),greater<int>());
    int A = abs(a-b) - 1; //max time that we can stand stable
    int B = A + (a<b ? a : n+1 - a); //max time after we are caught
    int ans = 0;
    for(int i = 1, t = 1; i<= m && t<=A; t++){
        while(i<=m && t+s[i-1] >B) i++;
        if(i<=m){
            //we can put the boom
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    cout<<"\n";

    return 0;
}

