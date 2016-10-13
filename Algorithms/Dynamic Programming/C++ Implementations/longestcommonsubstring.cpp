/** Longest Common substring using dynamic programming, implemented by Arpan Pathak, Time Complexity O(MxN) **/
#include <bits/stdc++.h>
#define ninf INT_MIN
using namespace std;
int M[5000][5000],x,y;
int length_common_substring(string s1,string s2)
{
    int max_length=ninf,p,q;
    for(int i=1;i<=s1.length();i++)
    {
        for(int j=1;j<=s2.length();j++)
        {
                M[i][j]=(s1.at(i-1)==s2.at(j-1))? M[i-1][j-1]+1 : 0;
                if(M[i][j]>max_length) { x=i; y=j; }
                max_length=max(max_length,M[i][j]);
        }
    }
    return max_length;
}
void print(string s1,string s2,int i,int j)
{
    if(M[i][j]==0 ) return;
    print(s1,s2,i-1,j-1);
    cout<<s1.at(i-1);
}
int main()
{
    cout<<length_common_substring("abcdef","xyz")<<endl;
    print("abcdef","xyz",x,y);
}
