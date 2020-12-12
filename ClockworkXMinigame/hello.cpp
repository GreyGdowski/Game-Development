#include <iostream>
#include <ctime>
void PlayGameAtDifficulty(int difficulty)
{

}

int main()
{
    int difficulty = 2;
    int maxDifficulty = 10;
    while (difficulty <= maxDifficulty)
    {
        PlayGameAtDifficulty(difficulty);
        std::cin.clear();
        std::cin.ignore();
        difficulty++;
    }

    std::cout << "You have taken over the city and become the master clockwork\n";
    return 0;
}