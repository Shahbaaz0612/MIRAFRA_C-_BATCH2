#include<iostream>
#include<memory>
using namespace std;

void modify_resource(unique_ptr<int> p){
	*p=100;
}

int main()
{
	unique_ptr<int> uptr = make_unique<int>(10);
	modify_resource(move(uptr));
	if(!uptr){
		cout<<"resources are moved and uptr is null!!"<<endl;
	}
}
