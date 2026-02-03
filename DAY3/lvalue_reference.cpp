#include<iostream>
using namespace std;

int& transform(int& n){
	n*=n;
	return n;
}

int add(int a, int b){
	return a+b;
}

void print(int& x){
	cout<<"print(int&)"<<endl;
}

void print(const int& x){
	cout<<"print(const int&)"<<endl;
}

void print(int&& x){
	cout<<"print(int &&)"<<endl;
	cout<<"& of rvalur: "<<&x<<endl;
}

int main()
{
	int x=10;
	int &ref=x;
	const int &ref1=100;
	int &ref2=transform(x);
	print(x);

	int &&rv=8;

	int &&rv2=add(3,5);

	print(3);
	print(500);

}


