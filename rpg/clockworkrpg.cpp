#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

int GoblinHealth = 9;

int SpiderHealth = 11;

int DragonHealth = 50;

int PlayerHealth = 10;

string PlayerWeapon = "sword";
string FleeMessage;


int PlayerMana = 10;

bool GameComplete = false;

void Information() //Displays the info of the enemy
{
    cout << "Welcome adventurer. Prepare for your journey\n";
    cout << endl;
    cout << "You must defeat a few enemies before I can call you a true\n";
    cout << endl;
    cout << "adventurer and you can get to the City of Smog\n";
    cout << endl;
}

bool PlayGame() //Tells whether or not playing game
{
    

    string name;
    cout << "First, what is your name adventurer?\n";
    cin >> name; //Input name
    cout << endl;
    cout << "Why hello there "<< name << endl;
    cout << endl;
    cout << "Your first task will be to cross this bridge to lead you to the city of smog\n";
    cout << endl;

    cout << "You make it to the bridge. You are greeted by a goblin, the nastiest of sorts.\n";
    cout << endl;
    cout << "'No one is allowed across my bridge' the goblin tells you.\n";
    cout << endl;
    cout << "Do you kill him? Or do you try to bargain\n";
    cout << endl;

    string PlayerGoblinResponse;
    int GoblinDamage = 1;

    cin >> PlayerGoblinResponse;
    if (PlayerGoblinResponse == "Kill him" || PlayerGoblinResponse == "Kill" || PlayerGoblinResponse == "kill")
    {
        while (GoblinHealth > 0)
        {
            int SwordDamage = rand() % 4 + 1;
            int FireballDamage = rand() % 5 + 2;

            if (PlayerHealth <= 0)
            {
                cout << "You have died. Press A to exit the window.";

            }
            cout << "Would you like to use your " << PlayerWeapon <<", magic or flee.\n";
            string PlayerGoblinResponse2;
            cin >> PlayerGoblinResponse2;
            if (PlayerGoblinResponse2 == "Sword" || PlayerGoblinResponse2 == "sword")
            {
                cout << "You attack with your sword. You deal " << SwordDamage << " damage \n";
                GoblinHealth = GoblinHealth - SwordDamage; //Determines the health of the goblin
                cout << "The goblin has " << GoblinHealth << " health" << endl;
                cout << endl;
                if (GoblinHealth > 0)
                {
                    cout << "The goblin attacks you with their club and deals " << GoblinDamage << " damage.\n";
                    PlayerHealth = PlayerHealth - GoblinDamage; //Determines the player health after combat
                    cout << endl;
                    cout << "You have " << PlayerHealth << " health.\n";
                    cout << endl;
                }
                else if (GoblinHealth <= 0)
                {
                    cout << "You kill the goblin.\n";
                    cout << endl;
                }
            }
            else if (PlayerGoblinResponse2 == "Magic" || PlayerGoblinResponse2 == "magic")
            {
                cout << "You shoot your fireball at the goblin. You deal " << FireballDamage << " damage \n";
                GoblinHealth = GoblinHealth - FireballDamage; //Determines the health of the goblin
                PlayerMana -= 5;
                cout << "The goblin has " << GoblinHealth << " health" << endl;
                cout << endl;
                cout << "You have " << PlayerMana << " mana.\n";
                cout << endl;
                if (GoblinHealth > 0)
                {
                    cout << "The goblin attacks you with their club and deals " << GoblinDamage << " damage.\n";
                    PlayerHealth = PlayerHealth - GoblinDamage; //Determines the player health after combat
                    cout << endl;
                    cout << "You have " << PlayerHealth << " health.\n";
                    cout << endl;
                }
            }
            else if (PlayerGoblinResponse2 == "Flee" || PlayerGoblinResponse2 == "flee")
            {
                cout << "You coward. Why would you flee. Well, don't turn back now. You are a laughing stock to the goblin.\n";
                cout << endl;
                cout << "Please press A to close out of the window.\n";
                cout << endl;
                GoblinHealth = 0;
                cin >> FleeMessage;
                if (FleeMessage == "a" || FleeMessage == "A")
                {
                    GameComplete = true;
                }
            }

        }
    }
    else if (PlayerGoblinResponse == "Bargain" || PlayerGoblinResponse == "bargain")
    {
        cout << endl;
        cout << "You bargain with the goblin.\n";
        cout << endl;
        cout << "'Maybe I can let you through if you don't tell anyone' the goblin tells you\n";
        cout << endl;
        cout << "They let you through\n";
        cout << endl;
    }

    cout << "Congratulation " << name << ".";
    cout << endl;
    cout << "You are just outside the City of Smog. You think you are in the safe, but you encounter a stray golem";
    cout << endl;
    cout << "You can try to avoid it or attack it.";
    cout << endl;






    GameComplete = true; //Sets the game to be done
    return true;
}

int main()
{
    srand((unsigned) time(0)); //Create new random sequence based on time of day
    Information();
    PlayGame();
    if (GameComplete == true) //Checks to see if game is done
    {
        return 0;
    }
    
}