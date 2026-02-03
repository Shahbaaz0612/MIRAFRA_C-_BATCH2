#include<iostream>
using namespace std;
#include<memory>
class ex
{
	public:
	void fun(){
		cout<<"inside ex fun"<<endl;
	}
};


int main()
{
	unique_ptr <ex> ptr = make_unique <ex> ();
	ptr->fun();
	unique_ptr <ex> ptr1 = move(ptr);
	ptr1->fun();
	ptr1.swap(ptr);
	unique_ptr<int> p = make_unique<int>(10);
	int* raw = p.get();
       cout<<*raw<<endl;	


}
