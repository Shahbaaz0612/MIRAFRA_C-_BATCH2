#include<iostream>
#include<memory>
using namespace std;
class B;
class A
{
	public:
	shared_ptr<B>Bptr;
	static int acnt;
	A(){
		cout<<"A allocated"<<endl;
		acnt++;
	}
	~A(){
		cout<<"A released"<<endl;
		--acnt;
	}
};

class B{
	public:
		weak_ptr<A>Aptr;
		static int bcnt;
		B(){
			cout<<"B allocated"<<endl;
			bcnt++;
		}
		~B(){
			cout<<"B released"<<endl;
			--bcnt;
		}
};

int A :: acnt = 0;
int B :: bcnt = 0;

int main()
{
	shared_ptr<A>aptr = make_shared<A> ();
	shared_ptr<B>bptr = make_shared<B> ();

	aptr->Bptr=bptr;
	bptr->Aptr=aptr;

	cout<<"aptr cnt: "<<A::acnt<<endl;
	cout<<"bptr cnt: "<<B::bcnt<<endl;
}


	

