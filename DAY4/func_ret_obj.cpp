#include<iostream>
using namespace std;

class Demo{
	public:
		Demo(){
			cout<<"inside default constructor"<<endl;
		}
		Demo(const Demo &other){
			cout<<"copy constructor"<<endl;
		}
		Demo(Demo &&other){
			cout<<"move constructor"<<endl;
		}
		~Demo(){
			cout<<"destructor called"<<endl;
		}
};

Demo create(){
	Demo d;
	return d;
}

int main()
{
	Demo d = create();
	Demo d1 = move(d);
}
