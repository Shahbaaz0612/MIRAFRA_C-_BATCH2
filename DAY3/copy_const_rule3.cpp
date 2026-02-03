#include<iostream>
using namespace std;

class student
{
	string name;
	int *roll;
	public:
	student(string s="",int *r=nullptr){
		cout<<"constructor allocating resources"<<endl;
		name=s;
		roll=r;
	}
	
	void display()const{
	cout<<"name: "<<name<<endl;
	cout<<"roll: "<<*roll<<endl;
	}

	student(const student& other){     //copy constructor..
		name=other.name;
		roll=new int (*other.roll);
		cout<<"in copy constructor"<<endl;
	}

	void operator()(const student& other){
		name=other.name;
		if(roll) delete roll;
		roll=new int (*other.roll);
		cout<<"in copy ovl constructor"<<endl;
	}

	student& operator = (const student& other){  //copy assignment..
		if(this != &other){
			name=other.name;
			delete roll;
			roll=new int (*other.roll);
		}
		cout<<"in copy assignment operator"<<endl;
		return *this;
	}

	student(student&& other):name(other.name),roll(other.roll){
		other.name="";
		other.roll=nullptr;
		cout<<"resources moved - move constructor called"<<endl;
	}

	student& operator = (student&& other)noexcept{
		if(this != &other){
			delete roll;
			name=other.name;
			roll=other.roll;
			other.name="";
			other.roll=nullptr;
		}
		return *this;
	}	

	~student(){
		cout<<"destructor deallocating resources"<<endl;
		delete roll;
	};

};
int main()
{
	student s1("shahbaaz",new int(1));
	student s2("manohar",new int(2));
	student s3=s1; 
	cout<<"displaying using s3 object--> copy assign s3=s1(shahbaaz)"<<endl;
	s3.display(); 
	//s2=s1;
	cout<<"displaying using s2 object--> copy assign. s2=s1(shahbaaz)"<<endl;
	s2.display();
	student s4(s2);
	s4(s2);
	cout<<"displaying using s4 object--> operator ovl s4(s2) s2-->manohar"<<endl;
	s4.display();
	student s5;
	s5=s1;
	cout<<"displaying using s5 object--> copy assign. s5=s1(shahbaaz)"<<endl;
	s5.display();
	student s6=move(s4);
	cout<<"displaying using s6 object--> move ctor s6=move(s4)"<<endl;
	s6.display();

}
	

