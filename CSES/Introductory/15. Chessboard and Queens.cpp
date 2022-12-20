#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool **board;

void init_board(int n);
void free_board(int n);
int nqueens(int n);
int nqueens_core(int index, int n);
bool canbeplaced(int i, int j, int n);

int main()
{
    int n = 8;
    board=new bool*[n];
    for(int i=0; i<n; i++)
    {
        board[i]=new bool[n];
        for(int j=0; j<n; j++)
        {
            char s;
            cin>>s;
            if(s == '.') board[i][j]=false;
            else board[i][j]=true;
        }
    }
    cout<<nqueens(n)<<endl;
    free_board(n);

    return 0;
}

//void init_board(int n)
//{
//    board=new bool*[n];
//    for(int i=0; i<n; i++)
//    {
//        board[i]=new bool[n];
//        for(int j=0; j<n; j++)
//        {
//            string s;
//            cin>>s;
//            if(s == ".") board[i][j]=false;
//            else if(s == "*") board[i][j]=true;
//        }
//    }
//}

void free_board(int n)
{
    for(int i=0; i<n; i++)
        delete[] board[i];

    delete[] board;
}
int nqueens(int n)
{
    cout<<"asdfad"<<endl;
    return nqueens_core(0, n);
}

int nqueens_core(int index, int n)
{
    if(index==n)
    {
        cout<<"asdfad"<<endl;
//        for(int i=0; i<n; i++)
//        {
//            for(int k=0; k<n; k++)
//            {
//                if(board[i][k])
//                    cout<<"Q";
//                else
//                    cout<<".";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        return 1;
    }

    int ans=0;
    for(int j=0; j<n; j++)
    {
        if(canbeplaced(index, j, n))
        {
            if(!board[index][j]){
                board[index][j]=true;
                ans=ans+nqueens_core(index+1, n);
                board[index][j]=false;
            }
        }
    }

    return ans;
}

bool canbeplaced(int i, int j, int n)
{
    int k, l;
    //UP
    for(k=i-1; k>=0; k--)
    {
        if(board[k][j]==true)
        {
            return false;
        }
    }

    //DOWN
    for(k=i+1; k<n; k++)
    {
        if(board[k][j]==true)
        {
            return false;
        }
    }

    //RIGHT
    for(l=j+1; l<n; l++)
    {
        if(board[i][l]==true)
        {
            return false;
        }
    }

    //LEFT
    for(l=j-1; l>=0; l--)
    {
        if(board[i][l]==true)
        {
            return false;
        }
    }

    //UP RIGHT
    for(k=i-1, l=j+1; k>=0 && l<n; k--, l++)
    {
        if(board[k][l]==true)
        {
            return false;
        }
    }

    //DOWN RIGHT
    for(k=i+1, l=j+1; k<n && l<n; k++, l++)
    {
        if(board[k][l]==true)
        {
            return false;
        }
    }

    //DOWN LEFT
    for(k=i+1, l=j-1; k<n && l>=0; k++, l--)
    {
        if(board[k][l]==true)
        {
            return false;
        }
    }

    //UP LEFT
    for(k=i-1, l=j-1; k>=0 && l>=0; k--, l--)
    {
        if(board[k][l]==true)
        {
            return false;
        }
    }

    return true;
}
