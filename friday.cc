/*
ID: anirudh54
TASK: friday
LANG: C++
*/

#include <fstream>
#include <array>

/* allows us to write std::array in the expected output format */
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& stream, const std::array<T, N>& array)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            stream << " ";
        stream << array[i];
    }
    return stream;
}

/* Lookup the number of days in a month given the year and month */
int lookup_days_in_month(int month, int year)
{
    /* century years are only leap years if divisible by 400 */
    bool is_leap = year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
    if (month == 1)
        return is_leap ? 29 : 28;
    /* feb empty since handled above */
    int lookup[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return lookup[month];
}

/**
 * Get the number of "X the thirteenth" for each weekday
 * spanning from January 1, 1900 to December 31, 1900+N-1.
 */
std::array<int, 7> get_thirteenths(int N)
{
    std::array<int, 7> thirteenths {};
    /* 0 = january, 1 = february, ... */
    int month = 0;
    int day = 1;
    /* 0 = saturday, 1 = sunday, ... */
    int weekday = 2;
    int year = 1900;
    int target_year = 1900+N-1;
    while (year <= target_year)
    {
        if (day == 13)
        {
            thirteenths[weekday]++;
        }
        day++;
        weekday++;
        int days_in_month = lookup_days_in_month(month, year);
        if (day > days_in_month)
        {
            day = 1;
            month++;
        }
        if (weekday > 6)
        {
            weekday = 0;
        }
        if (month > 11)
        {
            month = 0;
            year++;
        }
    }
    return thirteenths;
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