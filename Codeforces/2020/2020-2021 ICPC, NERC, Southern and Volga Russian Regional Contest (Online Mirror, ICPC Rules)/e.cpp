#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        vector<int>a(4);
        for(int i =0 ;i<4;i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        sort(a.begin(), a.end());
        cout<<a[0]*a[2]<<endl;
    }

    return 0;
}
