#include<iostream>
using namespace std;
#include<memory>
class B;

class A{
	public:
		shared_ptr<B>Bptr;
		static int acnt;
		A(){
			cout<<"A created"<<endl;
			acnt++;
		}
		~A(){
			cout<<"A released"<<endl;
			--acnt;
		}
};

class B{
	public:
		shared_ptr<A>Aptr;
		static int bcnt;
		B(){
			cout<<"B created"<<endl;
			bcnt++;
		}
		~B(){
			cout<<"B released"<<endl;
			--bcnt;
		}
};

int A :: acnt = 0;
int B :: bcnt = 0;

int main(){
	shared_ptr<A>aptr = make_shared<A>();
	shared_ptr<B>bptr = make_shared<B>();

	aptr->Bptr=bptr;
	bptr->Aptr=aptr;

	cout<<"Acnt: "<<A::acnt<<endl;
	cout<<"Bcnt: "<<B::bcnt<<endl;


}

