#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void init_code(){
    ios_base::sync_with_stdio(false);
    #ifndef NEAL_DEBUG
        cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// 199711L (C++98 or C++03)
// 201103L (C++11)
// 201402L (C++14)
// 201703L (C++17)
// 202002L (C++20)

// g++ -std=c++17 -o a a.cpp && ./a  



void solve(vector<int>& v){
    int n = v.size();
    int write_idx = 0, read_idx = 0;
    // write_idx >= read_idx. == iff the v[0]..v[read_idx] not exist any 0-value.
    while(write_idx <= n-1){
        if (v[read_idx] == 0) {
            write_idx++;
        }
        write_idx++;
        read_idx++;
    }

    if (write_idx == n + 1){
        v[n-1] = 0;
        write_idx = n - 2;
        read_idx -= 2; // sure v[read_idx] = 0
    }else if (write_idx == n) {
        if(v[read_idx] == 0) {
            v[n-1] = 0;
            v[n-2] = 0;
            read_idx -= 2;
            write_idx -= 3;
        }else { // !=0
            read_idx -= 1;
            write_idx -= 1;
        }
    }

    while (read_idx >= 0) {
        if (v[read_idx] == 0) {
            v[write_idx] = 0;
            v[write_idx - 1] = 0;
            write_idx -= 2;
        }else{
            v[write_idx] = v[read_idx];
            write_idx -= 1;
        }
        read_idx --;
    }
}

int main() {
    init_code();
    vector<int> v {1, 0, 0, 2, 1, 3};
    solve(v);
    
    for (int x : v){
        cout<< x << " ";
    }
    return 0;
}