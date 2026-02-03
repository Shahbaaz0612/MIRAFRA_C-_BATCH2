#include<iostream>
using namespace std;
#include<vector>

class Vector{
	int *ptr;
	public:
	Vector(int *p):ptr(p){
		cout<<"vector initialised"<<endl;
	
	}

	Vector(Vector&& other){
		cout<<"vector copied"<<endl;
		ptr=other.ptr;
		other.ptr=nullptr;
	}

	Vector(const Vector& other){
		cout<<"vector moved"<<endl;
		ptr=new int(*other.ptr);
	}

	~Vector(){
		cout<<"Vector released"<<endl;
		delete ptr;
	}

};

int main()
{
	vector<Vector>vptr;
	vptr.push_back(new int(2));
	vptr.push_back(new int(3));
}

