#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

int main(){

	list<int> l = {7,5,2,10};
	l.push_front(10);
	l.push_back(30);

	auto it = find(l.begin(), l.end(), 2);
	if(it != l.end()){
		l.insert(it, 40);
	}

	cout<<"l = { ";
	for(auto n: l){
		cout<<n<<", ";
	}cout<<"};"<<endl;

	return 0;
}

