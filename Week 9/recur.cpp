#include <iostream>
using namespace std;

class ReCursion
{
private:
    /* data */
public:
    ReCursion(/* args */);
    ~ReCursion();
    void countFunction(int, int);
    int addFunction(int, int);
    int powerFunction(int, int);
    long factorialFunction(long int);
    int sum(int);
};

ReCursion::ReCursion(/* args */)
{
}

ReCursion::~ReCursion()
{
}
// =============================add from 1 to any number====================
int ReCursion::sum(int num){
    if(num == 1) 
        return 1;
    else
        return num + sum(num - 1);
}
//=============================count from any number to any number============
void ReCursion::countFunction(int startNum, int endNum){
    cout <<"Counting " << startNum << endl;
    if(startNum == endNum) return;
    countFunction(startNum + 1, endNum);
}
//=============================add from any number to any number============
// assume startNum <= endNum
int ReCursion::addFunction(int startNum, int endNum){
    
    if(startNum == endNum)
         return 2*startNum;
    else
        return endNum + addFunction(startNum, endNum - 1);
}
//===========================pow any number ==============================
int ReCursion::powerFunction(int base, int pow){
    if (pow == 0) return 1;
    return base * powerFunction(base, pow - 1);
}
//==========================factorial recursion===========================
long ReCursion::factorialFunction(long int number){
    if (number == 0) return 1;
    else
        return number * factorialFunction(number - 1);
}
//==========================add even number===============================
// assume numberStart < numberEnd
int ReCursion::addEvenNumber(int numberStart, int numberEnd){
    if(numberStart % 2 == 0 && numberEnd % 2 == 0)
    {
        return numberEnd + addEvenNumber(numberStart, numberEnd - 1)
    }
}
int main(int argc, char const *argv[])
{
    ReCursion c;
    //c.countFunction(1,100);
    //cout << c.addFunction(0,100) << endl;
    //cout << c.powerFunction(2, 3) << endl;
    //cout << c.factorialFunction(5) << endl;
    cout << c.sum(100) << endl;
    return 0;
}
