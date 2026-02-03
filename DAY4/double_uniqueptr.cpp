#include<iostream>
using namespace std;
#include<memory>

void alterResource(unique_ptr<int>* ptr){
	cout<<"ptr: "<<**ptr<<endl;
	cout<<"address of ptr: "<<ptr<<endl;
	cout << "address of *ptr: " << (*ptr).get() <<endl;
	**ptr=100;
}

int main()
{
	unique_ptr<int>uptr = make_unique<int>(20);
	cout << "address of uptr: " << &uptr << endl;
	alterResource(&uptr);
	cout << "value uptr after function call: " << *uptr << endl;
}

