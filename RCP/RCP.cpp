#include <iostream>     /*THIS CONSOLE APP IS DEVLOPED USING C++ Only     */
#include <random>       /*VERSION : Official : V1.0.1 IDE : VS community  */
#include <vector>       /*DEVLOPPER : [INSTA : mdelhajaji2000]            */
#include <string>       /*This Code Is Open Source No Copyright !!!       */
using namespace std;

/*--Colors Define--*/ 
/*ASCL COLORS VALUES*/
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define DARK_GRAY "\033[90m"
struct stPoints
{
    int TotalePoints = 0;
    int TotaleWin = 0;
    int Choice = 0;// 
    int Draw = 0; // Just For Initialisation (not Important!)
};
stPoints Computer, user;
vector<string> GameChoice = { "rock", "paper", "scissors" }; //Translate int userChoice to string using .at

// Used to generate a Random from 1 to 3 to used in Computer Choice
int RandomGenerator(int x = 1, int y = 3)
{
	mt19937 gen(random_device{}());
	uniform_int_distribution<int> distribution(x, y);
	return distribution(gen);
}

void Rules()
{
	cout << RED << "=======================" << RESET << endl;
	cout << MAGENTA << "--Rock-Paper-Scissors--" << RESET << endl;
	cout << GREEN << "--Welcome to RPC Game--" << endl;
	cout << "---------RULES---------" << endl;
	cout << "------WIN  = 3pts------" << endl;
	cout << "------LOSE = 0pts------" << endl;
	cout << "------DRAW = 1pts------" << RESET << endl;
	cout << RED <<"=======================" << RESET << endl;
	cout << "\n";
}

int GameRoundes()  //function to choise the number of the rules
{
    int choice;
    cout << GREEN << "=================================" << endl;
    cout << "choise the number of the rounds : " << endl;
    cout << "type : [1] : for [3 roundes]" << endl;
    cout << "type : [2] : for [5 roundes]" << endl;
    cout << "type : [3] : for [7 roundes]" << endl;
    cout << "== > ";
    cin >> choice;
    cout << "=================================" << RESET << endl;
    switch (choice)
    {
    case 1:
        return 3;
        break;
    case 2:
        return 5;
        break;
    case 3:
        return 7;
        break;
    default:
        cout << "unvalid input...!" << endl;
        GameRoundes();
        break;
    }
    return 0;
}

string Rounderesult(int user_choice, int computer_choice)
{
    if (user_choice == 1 && computer_choice == 2)
    {
        return "computer-win";
    }
    else if (user_choice == 1 && computer_choice == 3)
    {
        return "user-win";
    }
    else if (user_choice == 2 && computer_choice == 1)
    {
        return "user-win";
    }
    else if (user_choice == 2 && computer_choice == 3)
    {
        return "computer-win";
    }
    else if (user_choice == 3 && computer_choice == 1)
    {
        return "computer-win";
    }
    else if (user_choice == 3 && computer_choice == 2)
    {
        return "user-win";
    }
    else if (user_choice == computer_choice)
    {
        return "Draw";
    }
    return "\0";
}



void FinalREsult(int Roundes)
{
    cout << MAGENTA << "************GAME--OVER*************" << RESET << endl;
    cout << YELLOW << "you win : [" << user.TotaleWin << " / " << Roundes << "] Totale points : " << user.TotalePoints << " pts" << endl;
    cout << "Computer win : [" << Computer.TotaleWin << " / " << Roundes << "] Totale points : " << Computer.TotalePoints << " pts" << endl;
    cout << "Draw : [" << Roundes - (user.TotaleWin + Computer.TotaleWin) << " / " << Roundes << "]" << RESET << endl;
    cout << MAGENTA << "***********************************" << RESET << endl;
    if (user.TotalePoints > Computer.TotalePoints)
    {
        cout << GREEN << "The Winer Is : User (You Win)" << RESET << endl;
    }
    else if (user.TotalePoints < Computer.TotalePoints)
    {
        cout << RED << "The Winer Is : COMPUTER (you lose!)" << RESET << endl;
    }
    else
    {
        cout << "--Draw--" << endl;
    }
    cout << MAGENTA "***********************************" << RESET << endl;
}   


void game(int Roundes)
{
     
    for (int i = 0; i < Roundes; i++)
    {
        
        Computer.Choice = RandomGenerator();
        cout << YELLOW << endl;
        cout << "===========Rounde[" << i + 1 << " / " << Roundes << "]===========" << endl;
        cout << "type : [1] : To Choice : Rock" << endl;
        cout << "Type : [2] : To Choice : Paper" << endl;
        cout << "Type : [3] : To Choice : Scissors" << endl;
        cout << GREEN << "==> ";
        cin >>  user.Choice;
        cout << BLUE;
        cout << "***Rounde " << i + 1 << " result : " << "[+++" << Rounderesult(user.Choice, Computer.Choice) << "+++]" << "***" << endl;
        if (Rounderesult(user.Choice, Computer.Choice) == "computer-win")
        {
            Computer.TotalePoints += 3;
            Computer.TotaleWin++;
        }
        else if (Rounderesult(user.Choice, Computer.Choice) == "user-win")
        {
            user.TotalePoints += 3;
            user.TotaleWin++;
        }
        else
        {
            Computer.TotalePoints++;
            user.TotalePoints++;
            Computer.Draw++;
            user.Draw++;
        }
        cout << GREEN << "Your Choise : " << GameChoice.at(user.Choice - 1) << endl;
        cout << RED << "Computer Choise : " << GameChoice.at(Computer.Choice - 1) << endl;
        cout << "===================================" << endl; cout << RESET;
        cout << endl;
    }
    FinalREsult(Roundes);
}




int GameMain()
{
    cout << CYAN;
    cout <<"\n==============================\n"
        << "Lets get Started!\n"
        << "==type[ENTER] to Start\n"
        << "==============================\n\n"; cout << RESET;
    string s;
    getline(cin, s);
    game(GameRoundes());
    return 0;
}

void startupAndRules()
{
    cout << MAGENTA;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "+++  ROCK-PAPER-SCISSORS  +++" << endl;
    cout << "+++        V 1.0.1        +++" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "******By mdelhajaji2000******" << endl;
    cout << "\n"; cout << RESET;
    Rules();
}

void close()
{
    string C; // C = Close
    cout << "Press Any Key To Close : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, C); /* Simple close systeme to Open the exe file without closing whene there is no input from user */
    return;
}
void FREEPALSTINE();
int main()
{
	startupAndRules();
    GameMain();
    close();
    FREEPALSTINE();
	return 0;
}

void FREEPALSTINE()
{
    cout << RED << "*" << DARK_GRAY << "********************************" << endl;
    cout << RED << "****" << DARK_GRAY << "*****************************" << endl;
    cout << RED << "******" << DARK_GRAY << "***************************" << endl;
    cout << RED << "*********" << WHITE << "************************" << endl;
    cout << RED << "***********" << WHITE << "**********************" << endl;
    cout << RED << "*********" << WHITE << "************************" << endl;
    cout << RED << "*******" << GREEN << "**************************" << endl;
    cout << RED << "****" << GREEN << "*****************************" << endl;
    cout << RED << "*" << GREEN << "********************************" << endl;
    cout << RESET << endl;
    cout << "# FREE PALASTINE " << endl;
}
// Finished The 20/12/2023 at 00:55 (One Day of Worck!!)