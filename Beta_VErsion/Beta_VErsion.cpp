#include <iostream>     /*THIS CONSOLE APP IS DEVLOPED USING C++*/
#include <random>       /*VERSION : BETA : V2.0.1                      */
#include <vector>       /*DEVLOPPER : [INSTA : mdelhajaji2000]  */
using namespace std;

int RandomGenerator(int x = 1, int y = 3)
{
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> distribution(x, y);
    return distribution(gen);
}

string result(int user_choice, int computer_choice)
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
        cout << "draw" << endl;
    }
    return "\0";
}

void game(int roundes)
{
    vector<string> game_choice = { "rock", "paper", "scissors" };
    cout << "===Rules===" << endl;
    cout << "win = 3 points" << endl;
    cout << "draw = 1 points" << endl;
    cout << "lose = 0 points" << endl;
    int user_points = 0, computer_points = 0;
    int user_choice, computer_choice = RandomGenerator();
    int user_round_win = 0, computer_rounde_win = 0, draw = 0;
    for (int i = 0; i < roundes; i++)
    {
        cout << "=====Rock-Paper-Scissors=====" << endl;
        cout << "=[ rounde number : [" << i + 1 << " / " << roundes << "] ]=" << endl;
        cout << "type : [1] : for rock" << endl;
        cout << "type : [2] : for paper" << endl;
        cout << "type : [3] : for scissors" << endl;
        cin >> user_choice;
        computer_choice = RandomGenerator();
        cout << "=========================" << endl;
        cout << "your choice is : " << game_choice.at(user_choice - 1) << endl;
        cout << "Computer Choice is : " << game_choice.at(computer_choice - 1) << endl;
        if (result(user_choice, computer_choice) == "computer-win")
        {
            computer_points += 3;
            computer_rounde_win++;
        }
        else if (result(user_choice, computer_choice) == "user-win")
        {
            user_points += 3;
            user_round_win++;
        }
        else
        {
            user_points++;
            computer_points++;
            draw++;
        }
        cout << "round [" << i + 1 << "/" << roundes << "] result : " << result(user_choice, computer_choice) << endl;
        cout << "your points : " << user_points << " pts" << endl;
        cout << "Computer points :  " << computer_points << " pts" << endl;
        cout << "=========================" << endl;

    }
    cout << "the final result is : ";
    cout << (user_points > computer_points ? "YOU WIN" : (user_points < computer_points ? "THE COMPUTER WIN" : "DRAW")); cout << endl;
    cout << "****\n";
    cout << "More details : \n";
    cout << "you win : [" << user_round_win << "/" << roundes << "]" << " || totale points : " << user_points << endl;
    cout << "computer win : [" << computer_rounde_win << "/" << roundes << "]" << " || totale points : " << computer_points << endl;
    cout << "Draw : " << draw << endl;
    int exit;
    cout << "****\n";
    cout << "==enter any character to close==" << endl;
    cin >> exit;
}

void start()
{
    int choice;
    cout << "choise the number of the rounds : " << endl;
    cout << "type : [1] : for [3 roundes]" << endl;
    cout << "type : [2] : for [5 roundes]" << endl;
    cout << "type : [3] : for [7 roundes]" << endl;
    cout << "== > ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        game(3);
        break;
    case 2:
        game(5);
        break;
    case 3:
        game(7);
        break;
    default:
        cout << "unvalid input...!" << endl;
        break;
    }
}


int main()
{
    cout << "welcome to RSP game devloped using cpp " << endl;
    cout << "VERSION : Beta : V2.0.1" << endl;
    start();
    return 0;
}
//FINISHID THE : 12/12/2023 AT 02:19