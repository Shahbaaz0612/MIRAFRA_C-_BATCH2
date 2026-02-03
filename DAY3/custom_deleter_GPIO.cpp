#include<iostream>
#include<memory>
using namespace std;

class Disable_Gpio
{
	//bool status;
	public:
	void operator()(int* pin)const{
		if(pin) {
			cout << *pin << " GPIO pin disabled "<<endl;
			delete pin;
		}
	}
};

int main()
{
	unique_ptr<int, Disable_Gpio> uptr(new int (2));
	cout<<"GPIO pin in use "<<*uptr<<endl;
}
