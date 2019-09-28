/*
ID: anirudh54
TASK: ride
LANG: C++
*/

#include <fstream>
#include <string>

int main()
{
    std::ifstream input("ride.in");
    std::ofstream output("ride.out");

    int comet = 1, group = 1;
    char c;

    while (input.getline(&c, 1))
    {
        comet *= c - 'A' + 1;
    }
    comet %= 47;
    while (input.getline(&c, 1))
    {
        group *= c - 'A' + 1;
    }
    group %= 47;

    if (comet == group)
    {
        output << "GO" << std::endl;
    } else {
        output << "STAY" << std::endl;
    }

    return 0;
}