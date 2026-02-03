#include<iostream>
using namespace std;

class LED
{
	bool status;
	public:
	LED(bool state):status(state){}
	
	void operator= (bool state){
		if(status==state){
			cout<<"invalid state"<<endl;
		}
		else {
			cout<<"valid state"<<endl;
			status=~status;
		}
	}
};


int main()
{
	bool on=true;
	bool off=false;
	LED obj(off);
	obj = on;
	obj = on;
}

