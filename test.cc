/*
ID: anirudh54
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout("test.out");
    ifstream fin("test.in");
    int a = 0, b = 0;
    fin >> a >> b;
    fout << a + b << endl;
    return 0;
}