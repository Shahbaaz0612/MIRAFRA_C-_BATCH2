#include<iostream>
using namespace std;

class sensor
{
	int value;
	mutable int read_count; //can modify the data present in const member function.
	public:
	sensor(int v):value(v),read_count(0){}

	int read()const{ 
		read_count++;
		return value;
	}

	int get_read_count()const{
		 return read_count;
	 }

	int write(int v) {
		value=v;
		return value;
	}
};

int main()
{
	sensor obj(100);
	cout<<"reading sensor data: "<<obj.read()<<endl;
	cout<<"reading sensor data: "<<obj.read()<<endl;
	cout<<"obj Read count: "<<obj.get_read_count()<<endl;

	const sensor cobj(200); //const object can evoke only constant member function
	cout<<"cobj Read_count: "<<cobj.get_read_count()<<endl;
	cout<<"reading sensor data: "<<endl<<cobj.read()<<endl;
	cout<<"cobj Read_count: "<<cobj.get_read_count()<<endl;	
	//cout<<cobj.write(300)<<endl;//throws error..
}

