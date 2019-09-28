/*
ID: anirudh54
TASK: friday
LANG: C++
*/

#include <fstream>
#include <array>

/* allows us to write std::array in the expected output format */
template <typename T, int N>
std::ofstream& operator<<(std::ofstream& stream, const std::array<T, N>& array)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            stream << " ";
        stream << array[i];
    }
    return stream;
}

int main()
{
    std::ifstream input("friday.in");
    std::ofstream output("friday.out");

    int N;
    input >> N;

    std::array<int, 7> likelihood = get_thirteenths(N);
    output << likelihood << std::endl;

    return 0;
}