#include<iostream>
using namespace std;
#include<memory>

void modify(int *ptr){
	cout<<"modifying the unique ptr resource in fun"<<endl;
	*ptr=200;	
};

int main(){
	unique_ptr<int> uptr = make_unique<int>(10);
	cout<<"resource of unique ptr before fun call "<<*uptr<<endl;
	cout<<"address of uptr: "<<uptr.get()<<endl;
	modify(uptr.get());
	cout<<"after modifying the resource in fun uptr = "<<*uptr<<endl;
	cout<<"address of uptr after fun call: "<<uptr.get()<<endl;




}


