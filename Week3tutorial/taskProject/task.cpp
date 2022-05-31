// code for class cat

#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

int task1_time = 0;
int task2_time = 0;
int task3_time = 0;
int task4_time = 0;
#define TIMESTODO1 100
#define TIMESTODO2 1000
int timestodo = TIMESTODO1;
int task1_timeb = 0;
int task2_timeb = 0;
int task3_timeb = 0;
int task4_timeb = 0;
void showTime(const char s[], int timein)
{
    cout << s << " " << timein << " seconds " << endl;
    cout << endl;
}
void task(int& timeCount)
{
    timeCount++;
}
void task1(int& i) // do it once
{
    task(i);
}
void task2(int& t) // do it 100
{
    for (int i=0; i< timestodo; i++) task(t);
}
void task3(int& t) // do it 100 times once (but check each one against all others) // check for fraud
{
    for (int i = 0; i < timestodo; i++)
    {
        for (int j=0; j< timestodo; j++) task(t);
    }
}
void task4(int& t) // do it 100 times once (but check each one against all others) // check for duplicates
{
    for (int i = 0; i < timestodo; i++)
    {
        for (int j = 0; j < i; j++) task(t);
    }
}
int main()
{
    task1(task1_time);
    showTime(" task 1 time = ", task1_time);
    task2(task2_time);
    showTime(" task 2 time = ", task2_time);
    task3(task3_time);
    showTime(" task 3 time = ", task3_time);
    task4(task4_time);
    showTime(" task 4 time = ", task4_time);
    timestodo = TIMESTODO2;
    cout << endl << "***************************" << endl << endl;
    task1(task1_timeb);
    showTime(" task 1 timeb = ", task1_timeb);
    task2(task2_timeb);
    showTime(" task 2 timeb = ", task2_timeb);
    task3(task3_timeb);
    showTime(" task 3 timeb = ", task3_timeb);
    task4(task4_timeb);
    showTime(" task 4 timeb = ", task4_timeb);
    cout << endl << "***************************" << endl << endl;
    cout << "task1 factor " << (double)task1_timeb / task1_time << 
    setprecision(2) << fixed << endl;
    cout << "task1 factor " << (double)task2_timeb / task2_time << 
    setprecision(2) << fixed << endl;
    cout << "task1 factor " << (double)task3_timeb / task3_time << 
    setprecision(2) << fixed << endl;
    cout << "task1 factor " << (double)task4_timeb / task4_time << 
    setprecision(2) << fixed << endl;
    return 0;
}