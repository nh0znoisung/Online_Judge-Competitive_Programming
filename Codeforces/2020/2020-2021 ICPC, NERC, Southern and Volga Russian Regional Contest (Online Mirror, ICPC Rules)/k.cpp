#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

void move(int&x, int&y, char d){
    if(d == 'U'){
        y++;
    }else if(d == 'D'){
        y--;
    }else if(d == 'R'){
        x++;
    }else if(d == 'L'){
        x--;
    }
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    //brute force
    for(int i =0 ;i<n; i++){
        int x = 0;
        int y = 0;
        for(int j = 0; j<= i; j++){
            move(x,y,s[j]);
        }
        int xs = x;
        int ys = y;
        x =y = 0;
        int x1, y1;
        for(int j = 0; j<n;j++){
            x1 = x;
            y1 = y;
            move(x1, y1, s[j]);
            if(!(x1 == xs && y1 == ys)){
                x = x1;
                y = y1;
            }
        }
        if(x == 0 && y == 0){
            cout<<xs<<" "<<ys<<endl;
            return;
        }
    }
    cout<<0<<" "<<0<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
