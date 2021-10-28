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

// There is a special keyboard with all keys in a single row.
// Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25), initially your finger is at index 0. To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index i to index j is |i – j|.

class Solution {
    public:
    int calculateTime(string keyboard, string word){
        vector<int>a(26);
        for(int i = 0; i<keyboard.size(); i++){
            a[keyboard[i] - 'a'] = i;
        }
        int res = a[word[0] - 'a'];
        for(int i = 0; i<word.size()-1; i++){
            res += abs(a[word[i] - 'a'] - a[word[i+1] - 'a']);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution ob;
    string keyboard = "pqrstuvwxyzabcdefghijklmno";
    string word = "leetcode";
    cout<<(ob.calculateTime(keyboard, word))<<endl; 
    // keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode" -> 73
    // keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba" -> 4
    return 0;
}