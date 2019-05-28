#include "vector.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	Vector <int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.pop_back();
	A.erase(1);
	for (int i=0; i<A.size(); i++)
		cout<<A[i]<<endl;
}
