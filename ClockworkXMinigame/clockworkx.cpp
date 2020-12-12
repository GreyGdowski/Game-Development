#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "\nYou hear the Clockwork X is going to be heading through the City of Smog\n";
    cout << "You task yourself with killing them, becoming the next Clockwork X ";
    cout << "You approach the Geared Palace, and come upon the lock. You know the following about the code for the lock: \n\n";
}

bool PlayGame(int Difficulty)
{
    srand(time(NULL));
    //Print messages to terminal
    if (Difficulty == 1)
    {
        PrintIntroduction(Difficulty);
    }
    

    //Declare 3 number code
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    cout << endl;
    cout << "(Level " << Difficulty << ")\n";
    cout << "+ There are 3 numbers for the code." << endl;
    cout << "+ The codes add up to: " << CodeSum << endl;
    cout << "+ The codes multiply to: " << CodeProduct << endl;


    //Store player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if player guess is right
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "You make it in. You are greated with another door\n" << endl;
        return true;
    }
    else
    {
        cout << "You get the code wrong. A guard finds you and sets you up for execution. You will never become the Clockwork X.\n";
        return false;
    }
}



int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 1000;

    while (LevelDifficulty <= MaxLevel || LevelDifficulty < 0) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //Clears any errors
        cin.ignore();

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
        else if (!bLevelComplete)
        {
            LevelDifficulty = -1;
            return 0;
        }
        if (LevelDifficulty == 1000)
        {
            cout << "\nYou are the Clockwork X\n";
        }
    }
    

}