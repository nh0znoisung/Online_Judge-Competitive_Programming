#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    queue<int>two;
    priority_queue<pair<int,int>>three;
    vector<bool>vis(n+1, false);
    int id = 1;
    while(n--){
        int type;
        cin>>type;
        if(type == 1){
            int m;
            cin>>m;
            two.push(id);
            three.push(make_pair(m, -id));
            id++;
        }else if(type == 2){
            while(vis[two.front()]){
                two.pop();
            }
            cout<<two.front()<<" ";
            vis[two.front()] = true;
            two.pop();

        }else if(type == 3){
            while(vis[-three.top().second]){
                three.pop();
            }
            cout<<-three.top().second <<" ";
            vis[-three.top().second] = true;
            three.pop();
        }
    }
    cout<<"\n";

    return 0;
}
