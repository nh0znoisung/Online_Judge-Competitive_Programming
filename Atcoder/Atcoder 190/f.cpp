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

ll _mergeSort(int arr[], int temp[],  
                 int left, int right); 
ll merge(int arr[], int temp[], int left,  
                   int mid, int right); 
  
/* This function sorts the  
   input array and returns the  
number of inversions in the array */
long long mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function  
  that sorts the input array and  
returns the number of inversions in the array. */
long long _mergeSort(int arr[], int temp[],  
                 int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp,  
                                left, mid); 
        inv_count += _mergeSort(arr, temp,  
                             mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left,  
                           mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
ll merge(int arr[], int temp[], int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i =0 ;i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    //How to smaller than O(n^3)
    long long cnt = mergeSort(a, n);
    // int cnt = 0;
    // for(int i =0; i<n ;i++){
    //     for(int j =i+1 ;j<n;j++){
    //         if(a[j] < a[i]) cnt++;
    //     }
    // }
    cout<<cnt<<endl;
    for(int i = 0; i<n-1; i++){
        cnt += n-1 - 2*b[i] ;
        cout<<cnt<<endl;
    }
    return 0;
}