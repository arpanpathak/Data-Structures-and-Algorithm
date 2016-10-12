#include <bits/stdc++.h>
#define ULL unsigned long long int
using namespace std;
int c=0;
ULL _pow(ULL a,int b)
{
    if(b==0) return 1;
    c++;
    return a*_pow(a,b-1);
}
ULL _pow2(ULL a,int b)
{
    if(b==0) return 1;
    ULL x=_pow2(a,b/2);
    c++;
    if(b%2==0)
        return x*x;
    else
        return a*x*x;
}
int main()
{
    cout<<_pow(2,63)<<endl;
    cout<<"No of operations in general recursive algorithm="<<c<<endl;
    c=0;
    cout<<_pow2(2,63)<<endl;
    cout<<"No of operations in divide and conquer algorithm="<<c<<endl;
}
