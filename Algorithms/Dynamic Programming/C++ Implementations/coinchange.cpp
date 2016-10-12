/** Coin Change problem using both bottomUp and topDown dynamic programming, implemented by Arpan Pathak **/
#include <bits/stdc++.h>
#define inf 9223372036854775808
#define ULL unsigned long long int
using namespace std;
ULL M[50000];
ULL S[50000];
ULL change_coin(int *d,int n,ULL amount)
{
    if(amount==0) return 0;
    if(M[amount]!=0) return M[amount];
    ULL q=inf;
    for(int i=0;i<n && d[i]<=amount ;i++)
    {
        int k=change_coin(d,n,amount-d[i]);
        if(k<q)
        {
            q=k;
            S[amount]=d[i];
        }
    }
    M[amount]=q+1;
    return q+1;
}
ULL coin_change_bottomUp(int *d,int n,ULL amount)
{
    for(int i=1;i<=amount;i++)
    {
        M[i]=inf;
        for(int j=0;j<n && d[j]<=i;j++)
        {
            int k=M[i-d[j]]+1;
            if(k<M[i])
            {
                S[i]=d[j];
                M[i]=k;
            }
        }
    }
    return M[amount];
}
void print_coins(int amount)
{
    while(amount>0)
    {
        cout<<S[amount]<<" ";
        amount=amount-S[amount];
    }
}
int main()
{
    int d[]={1,2,5,10,20,50,100,500,1000};
    cout<<coin_change_bottomUp(d,9,10783)<<endl;
    print_coins(10783);
}
