#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1000005,E=524288;
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
// int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int mx = -1;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        if(n == 1){
            cout<<0<<endl;
            return 0;
        }
        vector<int>re(n-1);
        // bool check0 = false;
        // bool checkAll0 = true;
        set<int>s;
        for(int i = 0; i<n-1; i++){
            re[i] = a[i+1] - a[i];
            // if(re[i] == 0){
            //     check0 = true;
            // }else{
            //     checkAll0 = false;
            // }
            s.insert(re[i]);
        }
        if(s.size() == 1){
            //exist 0
            cout<<0<<endl;
        }else{
            set<int>pos;
            set<int>neg;
            for(int i = 0; i<re.size(); i++){
                if(re[i] >= 0) pos.insert(re[i]);
                if(re[i] < 0) neg.insert(re[i]);
            }
            if(pos.size() == 1 && neg.size() == 1){
                if(*pos.begin() - *neg.begin() <= mx){
                    cout<<-1<<endl;
                }else cout<<*pos.begin() - *neg.begin()<<" "<<*pos.begin()<<endl;
            }else{
                cout<<-1<<endl;
            }
        }
        

    }
    return 0;
}