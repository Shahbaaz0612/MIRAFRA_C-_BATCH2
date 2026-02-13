#include<iostream>
using namespace std;
#include<memory>
class list{

	struct ll{
		int data;
		shared_ptr<ll> next;
		weak_ptr<ll> prev;
		ll(int value) : data(value), next(nullptr){}
	};
	
	shared_ptr<ll> head;
	shared_ptr<ll> tail;

	
	public:
	list() : head(nullptr), tail(nullptr){ }
	
	list(const list& other) : head(nullptr), tail(nullptr) {
    		if (!other.head) return;

		head = make_shared<ll>(other.head->data);
		tail = head;
    		auto temp = other.head->next;
   		while (temp) {
        		auto Nn = make_shared<ll> (temp->data);
        		tail->next = Nn;
        		Nn->prev = tail;
        		tail = Nn;
        		temp = temp  ->next;
		}
	}

	list(list&& other){
		head = other.head;
		tail = other.tail;
		other.head = nullptr;
		other.tail = nullptr;

	}
	
	void push_front(int value) {
		shared_ptr<ll> Nn = make_shared<ll>(value);
		if(head == nullptr){
			head=Nn;
			tail=Nn;
		}
		else{
			Nn->next = head;
			head->prev = Nn;
			head = Nn;
		}
	}
	
	void push_back(int value) {
		shared_ptr<ll> Nn = make_shared<ll> (value);
		if(head == nullptr){
			head=Nn;
			tail=Nn;
		}
		else{
			tail->next=Nn;
			Nn->prev=tail;
			tail=Nn;
		}
	}

	void pop_back() {
		tail = tail->prev.lock();
		tail->next = nullptr;
	}

	void pop_front() {
		shared_ptr<ll>temp = head;
		head = head->next;
		temp->next=nullptr;
		temp=nullptr;
	}

	void print() const {
		ll* temp = head.get();
		while(temp){
			cout<<temp->data<<"->";
			temp=temp->next.get();
		} cout<<endl;
	}
	
};



int main(){
	list l;
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(20);
	l.push_back(100);
	l.pop_back();
	l.pop_front();

	cout<<"l:"<<endl;
	l.print();

	list l1 = l;
	cout<<"l1:"<<endl;
	l1.print();

	list l2 = move(l);
	cout<<"l2:"<<endl;
	l2.print();


}

