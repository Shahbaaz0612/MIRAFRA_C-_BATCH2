#include<iostream>
using namespace std;

template<class T>

class myunique
{
	T *ptr;
	public:
	myunique(){}

	myunique(T *p = nullptr){
		ptr=p;
	}

	T* operator ->(){
		return ptr;
	}

	T& operator *(){
		return *ptr;
	}

	myunique(const myunique&)=delete;

   	myunique& operator=(const myunique&)=delete;

    	myunique(myunique&& other) {
        	ptr=other.ptr;
        	other.ptr=nullptr;
    	}

    	myunique& operator=(myunique&& other) {
        		if (this!=&other) {
            			delete ptr;
            			ptr=other.ptr;
            			other.ptr=nullptr;
        		}
        		return *this;
    	}

	T* release(){
		T* temp=ptr;
		ptr=nullptr;
		return temp;
	}

	void reset(T* newptr = nullptr){
		delete ptr;
		ptr=newptr;
	}

	T* operator() (const myunique& obj){
		ptr = obj.ptr;
		return ptr;
	}

	~myunique(){
		delete ptr;
	}

};

class example
{
	public:
	void fun(){
		cout<<"inside class example"<<endl;
	}
};

class test
{
	public:
		void api(){
			cout<<"inside class test"<<endl;
		}
};

int main()
{
	myunique<example>eobj(new example());
	eobj->fun();
	//eobj.reset();
	myunique<example>tobj(new example());
	tobj->fun();
	eobj(tobj);
}
	

	



