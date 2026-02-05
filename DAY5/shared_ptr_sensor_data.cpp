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
        cout<<"enter sensor values"<<endl;

        for(int i=0;i<10;i++){
                cin>>sptr[i];
        }

        cout<<"sensor values are:"<<endl;
        for(int i=0;i<10;i++){
                cout<<"Sensor "<<i<<": "<<sptr[i]<<endl;
        }
}

