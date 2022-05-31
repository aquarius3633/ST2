#include <iostream>
#include<string>

using namespace std;

class Bug{
public: 
    string zData;
    Bug* nextBug;
    //void addBug(Bug*, string);
    void AddBug(){};
};

//listRoot* Bug = nullptr;
Bug* listRoot = nullptr;
//------add the front
// void Bug::addBug(Bug* itemToAdd, string data){
//     Bug* itemToAdd = new Bug();
//     itemToAdd->zDate = data;
//     listRoot->next = nullptr;
// }
//

void Bug::addBug(Bug* itemToAdd)
{
    Bug* itemToAdd = new Bug();
    itemToAdd->nextBug = nullptr;
    listRoot = itemToAdd;
}


int main(){};