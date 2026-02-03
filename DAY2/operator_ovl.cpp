#include<iostream>
using namespace std;

class ABC
{
	public:
		int var=10;
		ABC(){}

		int operator + (const ABC& obj)
		{
			return var + obj.var;
		}
};

int main()
{
	ABC obj1;
	ABC obj2;
	int value = obj1 + obj2;
	cout<<"value: "<<value<<endl;
}
