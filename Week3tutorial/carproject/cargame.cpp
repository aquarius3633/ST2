// Simple C++ program to display Play car game
// Header file for input output functions 
#include<iostream>  
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
// function prototypes
int getOption();
void currentSituation();
void straightRoad();
void corner(string direction, bool sharp);
// global variables
int score = 0;
int speed = 50;
bool endGame = false;
string status = "alive";
int maxScore = 0;
int gameTurn=0;
int corners = 0;
// 0 std::cout << "(a) - accelerate " << endl;
// 1 std::cout << "(b) - decelerate (apply brakes) (d) " << endl;
// 2 std::cout << "Gun it (g) - go fast" << endl;
// 3 std::cout << "Steady keep speed (s)"
int main()
{
    char ch;
    time_t t;
    /* Intialise the random number generator with current time */
    srand((unsigned)time(&t));
    std::cout << "Car game ";
    std::cout << "You can safely take a gentle corner at speed 80" << endl;
    std::cout << "You can safely take a sharp corner at speed 50" << endl;
    currentSituation(); straightRoad(); 
    if (!endGame) { currentSituation(); corner("left", false); }
    if (!endGame) { currentSituation(); straightRoad(); }
    if (!endGame) { currentSituation(); corner("right", false); }
    if (!endGame) { currentSituation(); straightRoad(); }
    if (!endGame) { currentSituation(); corner("left", true); }
    if (!endGame) { currentSituation(); corner("left", false); }
    std::cout << endl << "-------------- End Game Summary --------------- " << 
    endl;
    std::cout << "You are        : " << (endGame?"Dead":"Alive") << endl;
    std::cout << "Final game turn: " << gameTurn << endl;
    std::cout << "Final speed    : " << speed << endl;
    std::cout << "Final Score    : " << score << endl;
    std::cout << endl << "Press any key to continue";
        cin >> ch;
        return 0;
}
int random100()
{
    return rand() % 100 + 1;
}
void currentSituation()
{
    gameTurn++;
    sleep(1);
    std::cout << ".. .. .." << endl;
    std::cout << endl;
    std::cout << "game turn " << gameTurn << endl;
    std::cout << "you are travelling at a speed of " << speed << endl;
    std::cout << "------------------------------------" << endl;
}
void straightRoad()
{
    std::cout << "Ahead you see straight road " << endl;
    getOption();
    std::cout <<"Driving ..";
    sleep(3);
    std::cout <<".. ..";
    sleep(1);
    std::cout << ".. ..";
    sleep(1);
    std::cout << ".. .." << endl;
    std::cout << "All clear straight road " << endl;
    if (speed >= 110) std::cout << "You might consider slowing down! " << endl;
}
void corner(string direction, bool sharp)
{
    std::cout << "Ahead you see a " << direction << " corner that is ";
    std::cout << (sharp ? "sharp" : "gentle") << endl;
    getOption();
    std::cout << "Driving ..";
    sleep(3);
    std::cout << ".. ..";
    sleep(1);
    std::cout << ".. ..";
    sleep(2);
    std::cout << ".. .." << endl;
    if (sharp)
    {
        // sharp
        if (speed > 90)
        {
            if (random100() < 60)
            {
                std::cout <<"Your car spins helplessly out of control.\n"<<
                endl;
                std::cout <<"there is a grinding of metal as you blackout.\
                n"<< endl;
                std::cout <<"As life fades from your body you vaguely hear emergency crews trying to pull your"
                " mangled body from the wreck."<< endl;
                endGame = true;
            }
            else
            {
                std::cout<<"Your car slips but you keep control\n"<<endl;
                std::cout<<"Sweat pours from your body as you see the road ahead, the next corner\n"
                "already looming; rapidly aproaching through the windshield.\n"<<endl;
                score = score + 5;
            }
        }
        else if (speed > 50)
        {
            if (random100() < 30)
            {
                std::cout << "Your car spins helplessly out of control.\n" 
                << endl;
                std::cout << "There is a huge tree aproaching. You blackout, "
                "the glass from the broken windscreen ripping at your face.\n"<<endl;
                std::cout <<"You lay bleedoing in the wreck , you hear how do we get it out of the tree"
                "\n then you haer and see no more" << endl;
                endGame = true;
            }
        else
            {
            std::cout << "Your car slips but you seem to control\n" << endl;
            std::cout << "You survive the near miss. \n The next corner already "
            "rapidly aproaching as the car lurches unsteadily still swaying from the close call.\n" << endl;
            score = score + 5;
            }
        }
        else
        {
            std::cout <<"You easily take the curve; you see the road ahead"
            "inviting the prospect of a long safe journey.\n" << endl;
            score++;
        }
    }
    else
    {
        // gentle
        if (speed > 80)
        {
        if (random100() < 40)
            {
                std::cout << "Your car skids out of control.\n" << endl;
                std::cout << "The ditch no one told yo abot the ditch You blackout, " << endl;
                std::cout << "You lay bleedoing in the wreck , slowly the vehicl fills with muddy brown ware you cant breath"
                "\n then you haer and see no more" << endl;
                endGame = true;
            }
        else
            {
                std::cout << "Your car skids round the corner\n" << endl;
                std::cout << "Adrenaline pumps through your system. The" " next corner already rapidly aproaching\n as the car lurches unsteadily YEEHA.\n";
                score = score + 5;
            }
        }
        else
        {
        std::cout << "Boring Boring boring the curve is easy; you see the road ahead"
        "inviting the prospect of a long safe journey.\n" << endl;
        score++;
        }
    }
}
// no protype needed
void adjustSpeed(int copt)
{
    switch (copt)
    {
    case 0:
        speed = speed + 10;
        break;
    case 1:
        speed = speed - 10;
        break;
    case 3:
        break;
    default:
        std::cout << "Not Good Not Good at all !  " << endl;
    }
}
int getOption()
{
    string inp;
    int copt=4;
    std::cout << "Your Options are:" << endl;
    std::cout << "(A) - accelerate " << endl;
    std::cout << "(B) - decelerate (apply brakes) " << endl;
    std::cout << "(S) Steady keep speed " << endl;
    std::cout << "Enter selection:";
    cin >> inp;
    //Short solution using C++11 and toupper().
    char opt = inp[0];
    //std::cout << "selected " << inp << " " << opt << endl;
    if (opt == 'A') copt = 0; // accelerate +10
    if (opt == 'B') copt = 1; // decelerate 
    if (opt == 'S') copt = 3; // steady
    adjustSpeed(copt);
    return 0;
}