/** N Queen Problem using backtracking, implemented by Arpan Pathak,
** Worst Case Time Complexity O(N^N) **/
#include <bits/stdc++.h>
using namespace std;
int placed[100];
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(placed[i]==j)
                cout<<"Q ";
            else
                cout<<". ";
        }
        cout<<endl;
    }
}
bool isSafe(int k,int i)
{
    if(k<0 || i<0) return false;
    if(k==0) return true;
    for(int j=0;j<=k-1;j++)
    {
        if((placed[j]==i) || (abs(j-k)==abs(placed[j]-i)))
            return false;
    }
    return true;
}

void nqueen(int initial,int k,int n)
{
    bool flag=false;
    if(k<0 || k>=n ) return;
    for(int j=initial;j<n;j++)
    {
        if(isSafe(k,j))
        {
            placed[k]=j;
            flag=true;
            break;
        }
    }
    if(flag) nqueen(0,k+1,n);
    else
        nqueen(placed[k-1]+1,k-1,n);
}

int main()
{
    for(int i=0;i<100;i++) placed[i]=-1;
    int n;
    cout<<"Enter the value of n=";
    cin>>n;
    nqueen(0,0,n);
    print(n);
    return 0;
}
