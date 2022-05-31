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
int ReCursion::sum(int num){
    if(num == 1) return 1;
    else
        return num + sum(num - 1);
}
void ReCursion::countFunction(int startNum, int endNum){
    cout <<"Counting " << startNum << endl;
    if(startNum == endNum) return;
    countFunction(startNum + 1, endNum);
}

int ReCursion::addFunction(int startNum, int endNum){
    if(startNum == endNum)  
        return startNum;
    else
        return endNum + addFunction(startNum, endNum - 1);
}

int ReCursion::powerFunction(int base, int pow){
    if (pow == 0) return 1;
    else
        return base * powerFunction(base, pow - 1);
}

long ReCursion::factorialFunction(long int number){
    if (number == 0) return 1;
    else
        return number * factorialFunction(number - 1);
}

int main(int argc, char const *argv[])
{
    ReCursion c;
    //c.countFunction(1,100);
    cout << c.addFunction(0,100) << endl;
    //cout << c.powerFunction(2, 3) << endl;
    //cout << c.factorialFunction(5) << endl;
    cout << c.sum(100);
    return 0;
}
