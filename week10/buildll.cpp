#include <iostream>

using namespace std;
class LinkerListNode
{
public:
    LinkerListNode* next;
    int number;
};

LinkerListNode* root = nullptr;
LinkerListNode* head = nullptr;
//build list by adding new node to the end of the list
void buildList(){
    LinkerListNode* newNode = new LinkerListNode();
    newNode->number = 10;
    newNode->next = nullptr;
    root = newNode;

    newNode = new LinkerListNode();
    newNode->number = 20;
    newNode->next = nullptr;
    root->next = newNode;
    
    newNode = new LinkerListNode();
    newNode->number = 30;
    newNode->next = nullptr;
    root->next->next = newNode;
}
//better way to build or add new node to the head of the linker list
void buildlist2(int num){
    LinkerListNode* newNode = new LinkerListNode();
    newNode->number = num;
    newNode->next = head;
    head = newNode;
}

void showlist(LinkerListNode* node){
    while(node != nullptr)
    {
        cout << node->number << endl;
        node = node->next;
    }
}
void addNode(){

}
int main()
{
    buildList();
    showlist(root);
    buildlist2(2);
    buildlist2(5);
    buildlist2(6);
    showlist(head);
}