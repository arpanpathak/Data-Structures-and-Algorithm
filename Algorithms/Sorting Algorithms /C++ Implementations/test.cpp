#include <bits/stdc++.h>
using namespace std;
int main() {
	srand(time(0));
	ofstream f("input.txt");
	f<<"1000"<<endl;
	for(int i=1;i<=1000;i++)
		f<<rand()%99999<<" ";
	f.close();
	return 0;

}
