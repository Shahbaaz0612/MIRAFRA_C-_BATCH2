#include<iostream>
using namespace std;
#include<memory>

class GPIO
{
	unique_ptr<int> pin;
	public:
	GPIO(int p):pin(make_unique<int>(p)){
		cout<<"GPOI pin: "<<*pin<<" initialised"<<endl;
	}

	void show(){
		cout<<"GPIO pin value: "<<*pin<<endl;
	}

};

int main()
{
	GPIO g1(10);
	cout<<"g1.."<<endl;
	g1.show();

	GPIO g2=move(g1);
	cout<<"g1 resources moved to g2.."<<endl;
	cout<<"g2.."<<endl;
	g2.show();

//	GPIO g3=g1;
//	g3.show();  //error
}
