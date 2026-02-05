#include<iostream>
using namespace std;
template<class T>
class sharedptr{
	T* ptr;
	int* refcount;
	
	void release(){
		if(*refcount){
			(*refcount)--;
			cout << "Release: count = " << (*refcount) <<endl;
		}
		if(*refcount==0){
			delete ptr;
			delete refcount;
			cout<<"shared deleted and refcount: "<<(*refcount)<<endl;
		}
	}

	public:
	sharedptr(T *p=nullptr):ptr(p) {
		refcount=new int(1);
		cout<<"resource allocated refcount: "<<(*refcount)<<endl;
	}

	sharedptr(const sharedptr& other) {
		ptr=other.ptr;
		refcount=other.refcount;
		(*refcount)++;
		cout<<"resources copied refcount: "<< (*refcount) << endl;
	}

	sharedptr& operator = (const sharedptr& other) {
		if(this != &other){
			release();
			ptr=other.ptr;
			refcount=other.refcount;
			(*refcount)++;
		}
		return *this;
	}
	
	sharedptr& operator = (sharedptr&& other)noexcept {
		if(this != &other){
			release();
			ptr=other.ptr;
			refcount=other.refcount;
			(*refcount)--;
			cout<<"resource moved refcount: "<< (*refcount) <<endl;
		}
		return *this;
	}

	sharedptr(sharedptr&& other) noexcept{
		ptr=other.ptr;
		refcount=other.refcount;
		other.ptr=nullptr;
		other.refcount=nullptr;
		cout<<"resource moved refcount: "<<(*refcount)<<endl;
	}

	T& operator * (){
		return *ptr;
	}

	T* operator -> (){
		return ptr;
	}


};

class GPIO{
	int *ptr;
	public:
	GPIO(int p) : ptr(new int(p)) {
		cout<<"resource allocated for GPOI pin"<<endl;
	}
	
	void display() const{
	{
		cout<<"GPIO pin: "<< *ptr <<endl;
	}
};


class GPOIDeleter{
	public:
		void operator () (GPOI* other) {
			cout<<"custom deleter - GPIO pin: "<<other->display()<<endl;
			delete other;
		}
};


int main(){

	sharedptr<int>sptr1(new int(10));
	sharedptr<int>sptr2=sptr1;
	sharedptr<int>sptr3=move(sptr2);
	cout<<"data: "<<*sptr3<<endl;
	sharedptr<GPIO> gsptr(new GPIO());
	//gsptr->display();

	sharedptr<GPIO, GPOIDeleter>sptr ( new GPIO(10), GPOIDeleter{} );
	
}



