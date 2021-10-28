#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

// Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

// Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

// We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

// Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

class Solution{
    public:
    vector<int>killProcess(vector<int>&pid, vector<int>&ppid, int kill){
        map<int,vector<int>>m;
        // map<int>vis
        int n = pid.size();
        for(int i = 0 ; i<n ;i++){
            m[ppid[i]].push_back(pid[i]);
        }
        vector<int>ans;
        queue<int>q;
        q.push(kill);
        while(!q.empty()){
            int a = q.front();
            ans.push_back(a);
            q.pop();
            for(int i = 0; i<m[a].size(); i++){
                q.push(m[a][i]);
            }

        }
        return ans;
    }
};

void print(vector<int>a){
    for(int i = 0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution ob;
    int kill = 5;
    vector<int>pid = {1,3,10,5};
    vector<int>ppid = {3,0,5,3};
    // The given kill id is guaranteed to be one of the given PIDs
    //n >=1
    print(ob.killProcess(pid, ppid, kill));
    // => [5,10]
    return 0;
}