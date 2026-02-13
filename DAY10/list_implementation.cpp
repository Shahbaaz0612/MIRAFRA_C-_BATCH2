#include <iostream>
using namespace std;

class MyList
{
private:
    struct Node
    {
        int data;
        Node* prev;
        Node* next;

        Node(int d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;

public:
    MyList() : head(nullptr) {}

    ~MyList()
    {
        while (head)
        {
            pop_front();
        }
    }

    void push_front(int value)
    {
        Node* nn = new Node(value);

        if (head == nullptr)
        {
            head = nn;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    void push_back(int value)
    {
        Node* nn = new Node(value);

        if (head == nullptr)
        {
            head = nn;
        }
        else
        {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;

            temp->next = nn;
            nn->prev = temp;
        }
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    
    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* temp = head;
            while (temp->next->next)
                temp = temp->next;

            delete temp->next;
            temp->next = nullptr;
        }
    }

    void insert(int pos, int value)//insert();
    {
        if (pos <= 1)
        {
            push_front(value);
            return;
        }
        Node* temp = head;
        int cnt = 1;
        while (temp && cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp == nullptr)
        {
            push_back(value);
            return;
        }
        Node* nn = new Node(value);
        nn->next = temp->next;
        nn->prev = temp;
        if (temp->next)
            temp->next->prev = nn;
        temp->next = nn;
    }

    void reverse()//reverse
    {
        Node* temp = head;
        Node* temp1 = nullptr;

        while (temp)
        {
            temp1 = temp->prev;
            temp->prev = temp->next;
            temp->next = temp1;
            head = temp;
            temp = temp->prev;
        }
    }

    ///print()
    void print() const
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyList lst;

    lst.push_front(10);
    lst.push_back(20);
    lst.push_back(30);

    lst.insert(2, 15);
    lst.print();

    lst.reverse();
    lst.print();
}

