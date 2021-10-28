#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

int solution(vector<int> x , vector<int> y){
//    if(x.size() == 1 && y.size() == 1) return 0;
    if(x== y){
        return x.size();
    }
    else{
        x.insert(x.begin(), 0);
        y.insert(y.begin(), 0);
        vector<int> vecX;
        vector<int> vecY;
        vector<int>::iterator pointer1 = x.begin();
        vector<int>::iterator pointer2 = y.begin();
        //auto
        int start = 0;
//        if(a<c) vecX.push_back(1);
        while(pointer1 != x.end() && pointer2!= y.end()){

            if(&pointer1 < &pointer2  ){
                if(pointer2 == y.begin()){
                    while(&pointer1 < &pointer2){
                        pointer1 ++;
                        start ++;
                    }
                    pointer1 --;
                    vecX.push_back(start);
                    start =0;
                }else {
                    if(pointer1 == x.end() ){
                        while(pointer2 != y.end()){
                            pointer2++;
                            start++;
                        }
                    }else{
                        vector<int>::iterator pointer11 = pointer1+1;
                        while(&pointer1 < &pointer2 && &pointer2 < &pointer11 ){
                            start ++;
                            pointer2++;
                        }
                    }
                    vecY.push_back(start);
                    start = 0;
                    pointer2--;
                    pointer1++;
                }
            }



            if(&pointer2 < &pointer1  ){
                if(pointer1 == x.begin()){
                    while(&pointer2 < &pointer1){
                        pointer2 ++;
                        start ++;
                    }
                    pointer2 --;
                    vecX.push_back(start);
                    start =0;
                }else{
                    if(pointer2 == y.end() ){
                        while(pointer1 != x.end()){
                            pointer1++;
                            start++;
                        }
                    }else{
                        vector<int>::iterator pointer22 = pointer2+1;
                        while(&pointer2 < &pointer1 && &pointer1 < &pointer22 ){
                            start ++;
                            pointer1++;
                        }
                    }
                    vecX.push_back(start);
                    start = 0;
                    pointer1--;
                    pointer2++;
                }
            }
        }

//        vecX.resize();
//        vecY.resize();
        int Max= 0;
        int a = x.front();
        int c = y.front();
        if(a<c){
            //x before, y after
            //choose the range of the middle
            //if choose x is the middle
            int rightY;
            for(int i=0; i<vecX.size(); i++){
                int sumX = 0;
                if(i ==0) rightY = 0;
                else if(i>0) rightY += vecY[i-1];
                int midY;

                for(int j=i; j<vecX.size(); j++){
                    sumX += vecX[j];
                    if(j ==i) midY ==0;
                    else midY += vecY[j-1];


                    int leftY = y.size() - midY - rightY;
                    Max = max(Max, 2*min(leftY, rightY)+ sumX);

                }
            }
            rightY =0;



            //if choose y is the middle
            int rightX;
            for(int i=0; i<vecY.size(); i++){
                int sumY = 0;
                rightX += vecX[i];
                int midX;

                for(int j=i; j<vecX.size(); j++){
                    sumY += vecY[j];

                    if(j ==i) midX ==0;
                    else midX += vecX[j];


                    int leftX = x.size() - midX - rightX;
                    Max = max(Max, 2*min(leftX, rightX)+ sumY);

                }
            }

        }else if(a>c){
            //x before, y after
            //choose the range of the middle
            //if choose x is the middle
            int rightY;
            for(int i=0; i<vecX.size(); i++){
                int sumX = 0;
                rightY += vecY[i];
                int midY;

                for(int j=i; j<vecX.size(); j++){
                    sumX += vecX[j];
                    if(j ==i) midY ==0;
                    else midY += vecY[j];


                    int leftY = y.size() - midY - rightY;
                    Max = max(Max, 2*min(leftY, rightY)+ sumX);

                }
            }
            rightY =0;



            //if choose y is the middle
            int rightX;
            for(int i=0; i<vecY.size(); i++){
                int sumY = 0;
                if(i ==0) rightX = 0;
                else if(i>0) rightX += vecX[i-1];
                int midX;

                for(int j=i; j<vecX.size(); j++){
                    sumY += vecY[j];

                    if(j ==i) midX ==0;
                    else midX += vecX[j-1];


                    int leftX = x.size() - midX - rightX;
                    Max = max(Max, 2*min(leftX, rightX)+ sumY);

                }
            }
            rightX =0;

        }

            return Max;
        }
}
int main() {
    ios::sync_with_stdio(false);
//    int t;
//    cin>>t;
//    while(t--){
//        int n;
//        cin>>n;
//        vector<int> vec(n);
//        vector<vector<int> > check(27);
//        for(int i =0 ; i<n ; i++){
//            cin>> vec[i];
//            check[vec[i]].push_back(i);
//        }
//        if(vec.size() <= 1){
//            cout<<1<<"\n";
//            continue;
//        }
//        int Max =0;
//        for(int i =1; i<27; i++ ){
//            if(check[i].size() == 0) continue;
//            else{
//                for(int j =i; j<27; j++){
//                    if(check[j].size() == 0) continue;
//                    else{
////                        Max = max(Max, solution(check[i], check[j]));
//                            Max = 0;
//                    }
//                }
//
//            }
//        }
//        cout<<Max<<"\n";

    vector<int> x ;
    x.push_back(1);
    x.push_back(3);
    vector<int> y;
    y.push_back(2);
    y.push_back(4);
//    y.push_back(5);
    if(x.size() == 1 && y.size() == 1) cout<< 0;
    else{
        int a = x.front();
        int b = x. back();
        int c = y. front();
        int d = y.back();
        if(x== y){
            cout<< x.size();
        }
        else{
            vector<int> vecX;
            vector<int> vecY;
            vector<int>::iterator pointer1 = x.begin();
            vector<int>::iterator pointer2 = y.begin();
            cout<<*(pointer1+1)<<endl;
            cout<<*pointer2<<endl;

            int start = 0;
            while(1){
                if(&pointer1 < &pointer2  ){
                    if(pointer2 == y.begin()){
                        while(*pointer1 < *pointer2){
                            pointer1 ++;
                            start ++;
                        }
                        vecX.push_back(start);
                        start =0;
                    }else {
                        if(pointer1 == x.end() ){
                            while(pointer2-1 != y.end()){
                                pointer2++;
                                start++;
                            }
                            vecY.push_back(start);
                            start =0;
                            break;
                        }else{
                            while(*(pointer2-1) < *pointer1 && *pointer1 < *pointer2 ){
                                start ++;
                                pointer1++;
                            }
                          vecX.push_back(start);
                          start = 0;
                        }

                    }
                }

                if(&pointer2 < &pointer1){
                    if(pointer1 == x.begin()){
                        while(*pointer2 < *pointer1){
                            pointer2 ++;
                            start ++;
                        }
                        vecX.push_back(start);
                        start =0;
                    }else{
                        if(pointer2 == y.end() ){
                            while(pointer1-1 != x.end()){
                                pointer1++;
                                start++;
                            }
                            vecX.push_back(start);
                              start =0;
                              break;
                        }else{

                            while(*(pointer1-1) < *pointer2 && *pointer2 < *pointer1 ){
                                start ++;
                                pointer2++;
                            }
                          vecY.push_back(start);
                          start = 0;
                        }

                    }
                }
            }


            cout<<vecX.size();
            cout<<vecY.size();

            for(int i =0; i<vecX.size(); i++){
                    cout<<vecX[i]<<"\t";
            }
                cout<<endl;
            for(int i =0; i<vecY.size(); i++){
                cout<<vecY[i]<<"\t";
            }

        }


//        int Max= 0;
//        int a = x.front();
//        int c = y.front();
//        if(a<c){
//            //x before, y after
//            //choose the range of the middle
//            //if choose x is the middle
//            int rightY;
//            for(int i=0; i<vecX.size(); i++){
//                int sumX = 0;
//                if(i ==0) rightY = 0;
//                else if(i>0) rightY += vecY[i-1];
//                int midY;
//
//                for(int j=i; j<vecX.size(); j++){
//                    sumX += vecX[j];
//                    if(j ==i) midY ==0;
//                    else midY += vecY[j-1];
//
//
//                    int leftY = y.size() - midY - rightY;
//                    Max = max(Max, 2*min(leftY, rightY)+ sumX);
//
//                }
//            }
//            rightY =0;
//
//
//
//            //if choose y is the middle
//            int rightX;
//            for(int i=0; i<vecY.size(); i++){
//                int sumY = 0;
//                rightX += vecX[i];
//                int midX;
//
//                for(int j=i; j<vecX.size(); j++){
//                    sumY += vecY[j];
//
//                    if(j ==i) midX ==0;
//                    else midX += vecX[j];
//
//
//                    int leftX = x.size() - midX - rightX;
//                    Max = max(Max, 2*min(leftX, rightX)+ sumY);
//
//                }
//            }
//
//        }else if(a>c){
//            //x before, y after
//            //choose the range of the middle
//            //if choose x is the middle
//            int rightY;
//            for(int i=0; i<vecX.size(); i++){
//                int sumX = 0;
//                rightY += vecY[i];
//                int midY;
//
//                for(int j=i; j<vecX.size(); j++){
//                    sumX += vecX[j];
//                    if(j ==i) midY ==0;
//                    else midY += vecY[j];
//
//
//                    int leftY = y.size() - midY - rightY;
//                    Max = max(Max, 2*min(leftY, rightY)+ sumX);
//
//                }
//            }
//            rightY =0;
//
//
//
//            //if choose y is the middle
//            int rightX;
//            for(int i=0; i<vecY.size(); i++){
//                int sumY = 0;
//                if(i ==0) rightX = 0;
//                else if(i>0) rightX += vecX[i-1];
//                int midX;
//
//                for(int j=i; j<vecX.size(); j++){
//                    sumY += vecY[j];
//
//                    if(j ==i) midX ==0;
//                    else midX += vecX[j-1];
//
//
//                    int leftX = x.size() - midX - rightX;
//                    Max = max(Max, 2*min(leftX, rightX)+ sumY);
//
//                }
//            }
//            rightX =0;
//
//        }
//
//
    //'the end of loop

    }
	return 0;
}
