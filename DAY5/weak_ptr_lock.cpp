#include<iostream>
using namespace std;
#include<memory>

class Resource{
	public:
		Resource(){
			cout<<"Resource allocated"<<endl;
		}
		~Resource(){
			cout<<"resource released"<<endl;
		}
		void use(){
			cout<<"using resource"<<endl;
		}
};

int main(){
	weak_ptr<Resource>wp;
	{
		auto sp=make_shared<Resource>();
		wp=sp;
	}

	if(auto locked=wp.lock()){
		locked->use();
	}
	else{
		cout<<"resource destroyed"<<endl;
	}
	
}



