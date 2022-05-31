// LinkedList2.cpp : This file contains the 'main' function. Program execution 
// begins and ends there.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class NameAndNumber
{
public:
    std::string number;
    std::string name;
    NameAndNumber();//default
    NameAndNumber(std::string nam, std::string num);//overload function
    
    void show();
};

NameAndNumber::NameAndNumber(string num, string nam)
{
    name = nam;
    number = num;
}

NameAndNumber::NameAndNumber() // default constructor
{
    name = "";
    number = "";
}
void NameAndNumber::show()
{
    cout << setw(7) << number << " " << setw(20) << name << " ";
}
// ------------------------ Linked List Class -----------------------------
class NameAndNumberListNode
{
public:
    NameAndNumber *data;
    NameAndNumberListNode* nxt; // the next elemet in the linked list
};
class NameAndNumberList
{
public:
    NameAndNumberListNode* root=nullptr; // the first
    void add(NameAndNumber* nanp);
    void del(NameAndNumberListNode* oneTodelete);
    void del(string number);
    NameAndNumberListNode* find(string number);
    NameAndNumberListNode* find(string number,NameAndNumberListNode* startHere);
    NameAndNumberListNode* findPrecursor(NameAndNumberListNode* oneToFind, NameAndNumberListNode* startHere);
    int delAll();
    // iterator below
    NameAndNumberListNode* curr = nullptr; // the iterator pointer
    void setStart();
    
    NameAndNumber* retreiveCurrent();
    NameAndNumberListNode* advanceCurrent();
    // for testing show
    void show(NameAndNumberListNode* item);// show just this item
    void showAll(NameAndNumberListNode* item); // show from this item on
};
void NameAndNumberList::show(NameAndNumberListNode* item)
{
    item->data->show();
    cout << " \n";
}
void NameAndNumberList::showAll(NameAndNumberListNode* item)
{
    if (item == nullptr) return;
    NameAndNumberListNode* temp = item;
    show(temp);
    temp = temp->nxt;
    showAll(temp);//recursive call showAll()
    // -----------------------------------------while loop version-------------------------
    // while(temp != nullptr){
    //     show(temp);
    //     temp = temp->nxt;
    // }
}
void NameAndNumberList::add(NameAndNumber* nanp)
{
    NameAndNumberListNode* temp = new NameAndNumberListNode();//initialise a temp pointer to a new List Node
    temp->data = nanp;                                        //assign data value to the newly created Node
    NameAndNumberListNode* hold = root;              //create a new pointer "hold" points to root pointer points to (head of the list)
    root = temp;                                              //root pointer points to temp pointer points to (the newly created Node)
    temp->nxt = hold;//access next pointer from this Node and make it points to hold points to (which is the original root points to nullptr)
}
void NameAndNumberList::del(string number)
{
    NameAndNumberListNode* temp = find(number);
        if (temp == nullptr) return;
        del(temp);
}
void NameAndNumberList::del(NameAndNumberListNode* oneTodelete)
{
    if (oneTodelete == root)
    {
        NameAndNumberListNode* hold = root;
        root = root->nxt;
        delete hold;
    }
    NameAndNumberListNode* temp = findPrecursor(oneTodelete, root);
    if (temp == nullptr) return;
    NameAndNumberListNode* hold = temp; // hold-temp is the precursor
    temp->nxt = oneTodelete->nxt;
    delete oneTodelete;
}
NameAndNumberListNode* NameAndNumberList::find(string number)
{
    return find(number, root);
}
NameAndNumberListNode* NameAndNumberList::find(string number, 
NameAndNumberListNode* startHere)
{
    if (startHere == nullptr) return startHere; // No did find 
    if (startHere->data->number == number) return startHere; // found it
    return find(number, startHere->nxt);//recursion to find the matching data to the number
}
NameAndNumberListNode* NameAndNumberList::findPrecursor(NameAndNumberListNode* 
oneToFind, NameAndNumberListNode* startHere)
{
    if (startHere == nullptr) return nullptr;
    if (startHere->nxt == oneToFind)
    {
        return startHere;
    }
    return findPrecursor(oneToFind, startHere->nxt);
}
int NameAndNumberList::delAll()
// returns the count of items deleted more for checking than any practicalnecessity
{
    int retv = 0;
    if (root != nullptr)
    {
        NameAndNumberListNode* hold = root;
        root = root->nxt;
        delete hold;
        retv++;
        int cnt = delAll();
        retv=retv+cnt; // update counter
    }
    return retv;
}
void NameAndNumberList::setStart()
{
    curr = root;
}
NameAndNumber* NameAndNumberList::retreiveCurrent()
{
    return curr->data;
}
NameAndNumberListNode* NameAndNumberList::advanceCurrent()
{
    curr = curr->nxt;
    return curr;
}
void test1()
{
    // test add
    std::cout << "Test add \n";
    NameAndNumber nn5 = { "2112","Tony" };
    NameAndNumber nn6 = { "21010","Jamison" };
    NameAndNumber nn7 = { "1112","OneOneOneTwo" };
    NameAndNumber nn8 = { "20010","Kevin Jamison" };
    NameAndNumber nn9 = { "1013","Luke Skywalker" };
    NameAndNumberList nanl;
    nanl.add(&nn5);
    nanl.add(&nn6);
    nanl.add(&nn7);
    nanl.add(&nn8);
    nanl.add(&nn9);
    std::cout << "\n";
    nanl.show(nanl.root);
    std::cout << "\n";
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
}
void test2()
{
    // test find
    std::cout << "Test find \n";
    NameAndNumber nn5 = { "2112","Tony" };
    NameAndNumber nn6 = { "21010","Jamison" };
    NameAndNumber nn7 = { "1112","OneOneOneTwo" };
    NameAndNumber nn8 = { "20010","Kevin Jamison" };
    NameAndNumber nn9 = { "1013","Luke Skywalker" };
    NameAndNumberList nanl;
    nanl.add(&nn5);
    nanl.add(&nn6);
    nanl.add(&nn7);
    nanl.add(&nn8);
    nanl.add(&nn9);
    auto p = nanl.find("2112");
    std::cout << "\n";
    nanl.show(p);
    std::cout << "\n\n";
    p = nanl.find("1112");
    std::cout << "\n";
    nanl.show(p);
    std::cout << "\n\n";
    p = nanl.find("1013");
    std::cout << "\n";
    nanl.show(p);
    std::cout << "\n\n";
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
}
void test3()
{
    // test iterator
    std::cout << "Test iterator \n";
    NameAndNumber nn5 = { "2112","Tony" };
    NameAndNumber nn6 = { "21010","Jamison" };
    NameAndNumber nn7 = { "1112","OneOneOneTwo" };
    NameAndNumber nn8 = { "20010","Kevin Jamison" };
    NameAndNumber nn9 = { "1013","Luke Skywalker" };
    NameAndNumber nn2 = { "230","Owen" };
    NameAndNumber nn3 = { "2310","Akmed" };
    NameAndNumberList nanl;
    nanl.add(&nn5);
    nanl.add(&nn6);
    nanl.add(&nn7);
    nanl.add(&nn8);
    nanl.add(&nn9);
    nanl.setStart();
    std::cout << "\n";
    while (true)
    {
        auto p = nanl.retreiveCurrent();
        p->show();
        std::cout << "\n";
        auto d = nanl.advanceCurrent();
        if (d == nullptr) break;
    }
}
void test4()
{
    // test delete
    std::cout << "Test delete \n";
    NameAndNumber nn2 = { "230","Owen" };
    NameAndNumber nn3 = { "2310","Akmed" };    
    NameAndNumber nn5 = { "2112","Tony" };
    NameAndNumber nn6 = { "21010","Jamison" };
    NameAndNumber nn7 = { "1112","OneOneOneTwo" };
    NameAndNumber nn8 = { "20010","Kevin Jamison" };
    NameAndNumber nn9 = { "1013","Luke Skywalker" };
    NameAndNumberList nanl;
    nanl.add(&nn2);
    nanl.add(&nn3);
    nanl.add(&nn5);
    nanl.add(&nn6);
    nanl.add(&nn7);
    nanl.add(&nn8);
    nanl.add(&nn9);
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
    // now delete 1st last and a mid one
    nanl.del("230");
    nanl.del("2112");
    nanl.del("1013");
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
}
void test5()
{
    // test deleteAll
    std::cout << "Test deleteAll \n";
    NameAndNumber nn2 = { "230","Owen" };
    NameAndNumber nn3 = { "2310","Akmed" };
    NameAndNumber nn5 = { "2112","Tony" };
    NameAndNumber nn6 = { "21010","Jamison" };
    NameAndNumber nn7 = { "1112","OneOneOneTwo" };
    NameAndNumber nn8 = { "20010","Kevin Jamison" };
    NameAndNumber nn9 = { "1013","Luke Skywalker" };
    NameAndNumberList nanl;
    nanl.add(&nn2);
    nanl.add(&nn3);
    nanl.add(&nn5);
    nanl.add(&nn6);
    nanl.add(&nn7);
    nanl.add(&nn8);
    nanl.add(&nn9);
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
    // now delete 
    int cnt = nanl.delAll();
     std::cout << "count of deleted is:" << cnt << "\n";
    std::cout << "\n";
    nanl.showAll(nanl.root);
    std::cout << "\n\n";
}
int main()
{
    std::cout << "Our Own Linked List!\n";
    //test1();
    test2();
    //test3();
    //test4();
    //test5();
    std::cout << "End Our Own Linked List!\n";
}
