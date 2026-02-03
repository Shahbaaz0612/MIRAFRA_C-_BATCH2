#include<iostream>
using namespace std;

class LED{
	int *gpioPin;
	bool ison;
	LED(int *p):gpioPin(p){}

	void turnOn(){
		if(gpioPin){
			ison=true;
			cout<<"LED on GPIO pin"<<endl;
		}
	}




