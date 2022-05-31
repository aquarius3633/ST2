#include <iostream>

using namespace std;

class Calculate
{
private:
    int x;
    int y;
    //vector<int*> v1;
    vector<int>* v2;
public:
    Calculate(int, int);
    ~Calculate();
    void doCal();
    void doPrimeCal();
};

Calculate::Calculate(int x, int y)
{
    this->x = x;
    this->y = y;
}

Calculate::~Calculate()
{
    
}
void Calculate::doCal(){
    cout<< x + y << endl;
}

void Calculate::doPrimeCal()
{

    for (size_t i = x; i < y; i++)
    {
        bool prime = true;
        for (size_t j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime == true)
        {
            cout << i << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    Calculate cal(2, 100);
    cal.doCal();
    cal.doPrimeCal();
    Calculate *c = new Calculate(10, 100);
    //pointer to class instance
    c->doCal();
    c->doPrimeCal();
    delete c;
    cin.ignore();
    cin.get();
    return 0;
}
