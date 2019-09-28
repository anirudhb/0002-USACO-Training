/*
ID: anirudh54
TASK: gift1
LANG: C++
*/

#include <vector>
#include <string>
#include <fstream>
#include <cassert>

template <typename K, typename V>
V* vector_pair_lookup(std::vector<std::pair<K, V>> container, const K& key)
{
    for (std::pair<K, V>& pair : container)
    {
        if (pair.first == key)
        {
            return &pair.second;
        }
    }
    return nullptr;
}

int main()
{
    std::ifstream input("gift1.in");
    std::ofstream output("gift1.out");

    int NP;
    input >> NP;

    std::vector<std::pair<std::string, int>> people;

    for (int i = 0; i < NP; i++)
    {
        std::string name;
        input >> name;

        people.emplace_back(name, 0);
    }

    for (int i = 0; i < NP; i++)
    {
        std::string name;
        input >> name;

        int amt_to_give;
        int* person = vector_pair_lookup(people, name);
        assert(person != nullptr);

        input >> amt_to_give;

        int NG;
        input >> NG;

        if (NG < 1) continue;

        int per_person = amt_to_give / NG;

        for (int j = 0; j < NG; j++)
        {
            std::string to_give;
            input >> to_give;
            int* other = vector_pair_lookup(people, to_give);
            assert(other != nullptr);
            *other += per_person;
            *person -= per_person;
        }
    }

    for (const auto& pair : people)
    {
        output << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}