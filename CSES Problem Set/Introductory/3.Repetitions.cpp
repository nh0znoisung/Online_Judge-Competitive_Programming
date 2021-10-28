#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int ans = 0;
    char cur;
    int cnt = 0;
    for(int i = 0; i< s.size(); i++){
       // cout<<cur<<endl;
        if(cur != s[i]){
            cur = s[i];
            ans = max(ans, cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    ans = max(ans, cnt);
    cout<<ans<<endl;
    return 0;

}
