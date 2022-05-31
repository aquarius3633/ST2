#include <iostream>

using namespace std;

class Pair {
    public:
        int *key;//key is a pointer to int in memory from stack
        int *value;

        //initialise Pair constructor
        Pair(int k, int v) {
            this->key = new int;// dynamically create a int (4bytes) of memory from heap and assign to "this->key"((*this).key)
            this->value = new int;

            *this->key = k;//sign variable k value to this newly created memory which "key" pointer(from stack) points to
            *this->value = v;
        }

        //copy constructor initiated
        Pair(const Pair& p){//p is the reference variable to Pair(class/type) Object
            //dynamically allocate new memory address holds int variable to "key"
            key = new int(*p.key);//return "key" pointer value (which is the memory address) then assign to "key" pointer
            
            value = new int(*p.value);
        }
};

int main(){

    Pair pair1(1,5);//calling constructor
    Pair pair2 = pair1;//calling copy constructor which copy the value (which is the reference of objects) => address

    *pair2.key = 10;//deference pair2 then assign 10 (the value) to "key" pointer points

    cout << "Pair 1: " << *pair1.key  << " " << *pair1.value << endl;
    cout << "Pair 2: " << *pair2.key  << " " << *pair2.value << endl;
    cout << "Pair 1 Address: " << pair1.key  << " " << pair1.value << endl;
    cout << "Pair 2 Address: " << pair2.key  << " " << pair2.value << endl;
}