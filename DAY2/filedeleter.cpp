#include<iostream>
using namespace std;
#include<memory>
class FileDeleter
{
	public:
		void operator () (FILE *file)const{
			if(file){
				cout<<"closing file in custom deleter"<<endl;
				fclose(file);
			}
		}
};

struct DeleteArray{
	template<typename T>
	void operator() (T* p)const{
		cout<<"array deleted"<<endl;
		delete[] p;
	}
};

int main()
{
	unique_ptr<FILE, FileDeleter> fptr(fopen("data.txt","w"));
	if(fptr){
		cout<<"file opened successfully"<<endl;
	}

	unique_ptr<int[], DeleteArray> arr_ptr(new int[10]);
}
