#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;

template<typename T>
struct FreeDeleter
{
    void operator()(T* p) const
    {
        free(p);
        cout << "memory freed using free()" << endl;
    }
};

int main()
{
    unique_ptr<int, FreeDeleter> ptr1{
        (int*) (malloc(sizeof(int)))
    };
    *ptr1 = 100;
    cout << *ptr1 << endl;
}

