#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>
#include <numeric>
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
const int M=998244353;
const int N=1000005,E=524288;


void init_code(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif
}

const int INF = numeric_limits<int>::max(); // Đặt giá trị vô hạn

void bfs(int start, const vector<vector<int> >& graph, vector<int>& distances) {
    queue<int> q;
    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (distances[v] == INF) { // Nếu chưa được cập nhật
                distances[v] = distances[u] + 1; // Cập nhật khoảng cách
                q.push(v);
            }
        }
    }
}

void solveLinearEquations(int n, const vector<vector<int> >& A, const vector<int>& b, vector<double>& x) {
    for (int i = 0; i < n; ++i) {
        x[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                x[i] += A[i][j] * x[j];
            }
        }
        x[i] = (double) (b[i] / (1 - x[i]));
    }
}

// bool gaussianElimination(vector<vector<int> >& A, vector<int>& b) {
//     int n = A.size();

//     for (int i = 0; i < n; ++i) {
//         // Search for maximum in this column
//         double maxEl = abs(A[i][i]);
//         int maxRow = i;
//         for (int k = i + 1; k < n; ++k) {
//             if (abs(A[k][i]) > maxEl) {
//                 maxEl = abs(A[k][i]);
//                 maxRow = k;
//             }
//         }

//         // Swap maximum row with current row (pivoting)
//         swap(A[maxRow], A[i]);
//         swap(b[maxRow], b[i]);

//         // Make all rows below this one 0 in current column
//         for (int k = i + 1; k < n; ++k) {
//             double c = -A[k][i] / A[i][i];
//             for (int j = i; j < n; ++j) {
//                 if (i == j) {
//                     A[k][j] = 0; // This will be 0
//                 } else {
//                     A[k][j] += c * A[i][j];
//                 }
//             }
//             b[k] += c * b[i];
//         }
//     }

//     // Solve equation Ax=b for an upper triangular matrix A
//     vector<double> x(n);
//     for (int i = n - 1; i >= 0; --i) {
//         x[i] = b[i];
//         for (int j = i + 1; j < n; ++j) {
//             x[i] -= A[i][j] * x[j];
//         }
//         x[i] /= A[i][i];
//     }

//     // Output solution
//     cout << "Solution:\n";
//     for (int i = 0; i < n; ++i) {
//         cout << "x" << i + 1 << " = " << x[i] << endl;
//     }

//     return true;
// }

int forwardElim(vector<vector<double> >& mat, vector<double>& b);

// Function to calculate the values of the unknowns
void backSub(vector<vector<double> >& mat, vector<double>& b, vector<double>& x);

// Function to perform Gaussian Elimination
void gaussianElimination(vector<vector<double> >& mat, vector<double>& b, vector<double>& x) {
    // Reduction into r.e.f.
    int singular_flag = forwardElim(mat, b);

    // If matrix is singular
    if (singular_flag != -1) {
        cout << "Singular Matrix.\n";
        if (b[singular_flag] != 0)
            cout << "Inconsistent System." << endl;
        else
            cout << "May have infinitely many solutions." << endl;
        return;
    }

    // Get solution to system and print it using backward substitution
    backSub(mat, b, x);
}

// Function for elementary operation of swapping two rows
void swap_row(vector<vector<double> >& mat, int i, int j) {
    for (int k = 0; k < mat[0].size(); k++) {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// Function to reduce matrix to r.e.f.
int forwardElim(vector<vector<double> >& mat, vector<double>& b) {
    int N = mat.size();
    for (int k = 0; k < N; k++) {
        // Initialize maximum value and index for pivot
        int i_max = k;
        double v_max = abs(mat[i_max][k]);

        // Find greater amplitude for pivot if any
        for (int i = k + 1; i < N; i++) {
            if (abs(mat[i][k]) > v_max) {
                v_max = abs(mat[i][k]);
                i_max = i;
            }
        }

        // If a principal diagonal element is zero, matrix is singular
        if (mat[k][i_max] == 0)
            return k; // Matrix is singular

        // Swap the greatest value row with current row
        if (i_max != k)
            swap_row(mat, k, i_max);

        for (int i = k + 1; i < N; i++) {
            // Factor to set current row kth element to 0
            double f = mat[i][k] / mat[k][k];

            // Subtract fth multiple of the corresponding kth row
            for (int j = k + 1; j < mat[0].size(); j++) {
                mat[i][j] -= mat[k][j] * f;
            }
            b[i] -= b[k] * f; // Update b vector
            mat[i][k] = 0; // Filling lower triangular matrix with zeros
        }
    }
    return -1;
}

// Function to calculate the values of the unknowns
void backSub(vector<vector<double> >& mat, vector<double>& b, vector<double>& x) {
    int N = mat.size();
    // Start calculating from the last equation up to the first
    for (int i = N - 1; i >= 0; i--) {
        x[i] = b[i]; // Start with the RHS of the equation
        for (int j = i + 1; j < N; j++) {
            x[i] -= mat[i][j] * x[j]; // Subtract all the lhs values
        }
        x[i] /= mat[i][i]; // Divide the RHS by the coefficient of the variable
    }

    cout << "\nSolution for the system:\n";
    for (int i = 0; i < N; i++)
        cout << x[i] << endl;
}


//TODO: make sure all variables get reset
// g++ 4.\ Counting\ Divisors.cpp -o a && ./a
void run_case(){
    ll n, x, y;
    cin >> n;
    vector<double> a(n);
    vector<vector<int> > graph(n);
    vector<vector<double> > distanceMatrix(n, vector<double>(n, INF));
    
    // statement
    for (int i = 0; i < n; i++)  {
        cin >> a[i];
    }
    // edges
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }

    for (int i = 0; i < n; ++i) {
        vector<int> distances(n, INF);
        bfs(i, graph, distances);
        for (int j = 0; j < n; ++j) {
            distanceMatrix[i][j] = distances[j];
        }
    }

    // DEBUG
    cout << "DISTANCE MATRXI" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distanceMatrix[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distanceMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    // DEBUG
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }

    vector<double> X(n);
    // solveLinearEquations(n, distanceMatrix, a, X);

    
    // cout << "Nghiem x:" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << "x[" << i << "] = " << X[i] << endl;
    // }
    gaussianElimination(distanceMatrix, a, X);
    


    
}

int main() {
    init_code();
    int t;
    cin>>t;
    while(t--){
    	run_case();
    }
    return 0;
}