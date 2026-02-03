#include<iostream>
using namespace std;
#include<vector>
class car{
	vector<int>vehicleNumbers;
	public:
	car(int count) : vehicleNumbers(count,0){}

	void setVehicle(int index, int number){
		if(index < vehicleNumbers.size())
			vehicleNumbers[index]= number;
	}

	void print()const{
		cout<<"Total cars: "<<vehicleNumbers.size()<<endl;
		for(auto i=0; i<vehicleNumbers.size(); i++){
			cout<<"car:"<<i+1<<", VehicleNumber:"<<vehicleNumbers[i]<<endl;
		}
	}
};

int main()
{
	car garage1(2);
	garage1.setVehicle(0,1000);
	garage1.setVehicle(1,2000);
	cout<<"Garage1:--------- "<<endl;
	garage1.print();

	car garage2(3);
	garage2.setVehicle(0,0000);
	garage2.setVehicle(1,1111);
	garage2.setVehicle(2,2222);
	cout<<"Garage2:--------- "<<endl;
	garage2.print();

	car garage3=garage1;
	cout<<"Garage3:--------- "<<endl;
	garage3.print();

	garage1 = garage2;
	cout<<"after copy assignment garage1=garage2"<<endl;
	cout<<"Garage1:--------- "<<endl;
	garage1.print();

	
}


