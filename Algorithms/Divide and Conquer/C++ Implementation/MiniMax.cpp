#include <iostream>
using namespace std;
struct Data
{
    int min,max;
    friend ostream& operator <<(ostream &out,Data &obj)
    {
        out<<"Maximam ="<<obj.max<<"\nMinimum="<<obj.min;
        return out;
    }
};
Data MiniMax(int *A,int i,int j)
{
    Data minimax;
    if(i==j)
    {
        minimax.min=A[i];
        minimax.max=A[i];
    }
    else if(i==j-1)
    {
       minimax.min=std::min(A[i],A[j]);
       minimax.max=std::max(A[i],A[j]);
    }
    else
    {
        int mid=(i+j-1)/2;
        Data left=MiniMax(A,i,mid);
        Data right=MiniMax(A,mid+1,j);
        minimax.min=std::min(left.min,right.min);
        minimax.max=std::max(left.max,right.max);
    }
    return minimax;
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,10,9,108,-4,55};
    Data result=MiniMax(A,0,12);
    cout<<result;
}
