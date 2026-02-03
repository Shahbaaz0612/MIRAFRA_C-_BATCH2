#include<iostream>
using namespace std;
#include<memory>

class sensor{
	int* value;
	public:
	sensor(int v):value(new int(v)){ 
		cout<<"sensor value initialised"<<endl;       
	}
	
	~sensor(){
		cout<<"destructor called"<<endl;
		delete value;
	}

	int get()const{
		return *value;
	}
};

void logger(shared_ptr<sensor> lptr){
	cout<<"inside logger API - sensor value: "<<lptr->get()<<endl;
}

void modules(shared_ptr<sensor>mptr){
	cout<<"inside modules API - sensor value: "<<mptr->get()<<endl;
}


int main()
{
	shared_ptr<sensor> sptr=make_shared<sensor>(20);
	cout<<"sptr: "<<sptr.get()<<endl;


}
