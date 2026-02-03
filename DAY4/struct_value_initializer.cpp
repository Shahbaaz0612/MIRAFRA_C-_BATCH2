#include<iostream>
#include<memory>
using namespace std;

/*struct test{
	int x;
	
	test(){
		//x=100;
	}

	void fun(){
	cout<<"value of x: "<<x<<endl;
	}
}; */

class GPIO{
	int *ptr;
	public:
	GPIO(int n) : ptr(new int(n)){
		cout<<"GPIO pin: "<<*ptr<<" initialised"<<endl;
	}
};

class GPIODeleter{
	public:
	void operator()(GPIO *p){
		cout << "gpio pin released" << endl;
		delete p;
	}
};



int main()
{
	//test t{};
	//t.fun();
	
	GPIODeleter d{};
	
	unique_ptr<GPIO,GPIODeleter> g ( new GPIO(13), d );
}
