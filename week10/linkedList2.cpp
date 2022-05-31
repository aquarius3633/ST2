#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Person
{
private:
    string name;
    string number;
public:
    Person();
    Person(string n, string numb);
    ~Person();

    void show();
};

Person::Person()
{
    name = "";
    number = "";
}
Person::Person(string n, string numb)
{
    name = n;
    number = numb;
}

void Person:: show()
{
    cout << setw(7) << number << setw(20) << name << " ";
}
class PhoneListNode
{
public:
    Person* person;
    PhoneListNode* next;
};

class PhoneList
{
public:
    PhoneListNode* head;//first node
    PhoneListNode* curr;//iterator for the list
    PhoneListNode* temp;//temp node
    int size; //the size of the list

    PhoneList();


//add and del methods
    void add(Person* person);
    void add(PhoneListNode* node);
    void del(PhoneListNode* node);
    void del(Person* person);
//find methods

    /*code here*/

//for testing show
    void show(PhoneListNode* node);// show current node
    void showAll(PhoneListNode* node);//show all nodes from current node to the end
};

PhoneList::PhoneList()//default constructor
{
    head = nullptr;
    curr = nullptr;
    
    size = 0;
}
//add by data
void PhoneList::add(Person* person)
{
    PhoneListNode* newPerson = new PhoneListNode();
    newPerson->person = person;
    temp = head;//perserve head in temp
    head = newPerson;//place new node into head
    newPerson->next = temp;//new node points next node
}
//add by node
void PhoneList::add(PhoneListNode* node)
{
    PhoneListNode* node = new PhoneListNode();
    temp = head;
    head = node;
    node->next = temp;
}

//delete by node
void PhoneList::del(PhoneListNode* node)
{
    PhoneListNode* ToBeDelete = new PhoneListNode();
    
}
//delete by data
void PhoneList::del(Person* person)
{
    
     
}


int main()
{


}