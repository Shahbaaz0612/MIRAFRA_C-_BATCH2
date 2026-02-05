#include<iostream>
#include<memory>
using namespace std;

class FreeDeleter{
	public:
		void operator () (int arr[]){
			cout<<"custom deleter releasing resources"<<endl;
			delete[] arr;
		}
};

int main()
{
	shared_ptr <int[]>sptr(new int[10], FreeDeleter{});
	int sum=0;
	cout<<"enter the elements"<<endl;
	for(int i=0;i<10;i++){
		cin>>sptr[i];
		sum=sum+sptr[i];
	}
	cout<<"average of elements: "<<sum/10<<endl;
}

