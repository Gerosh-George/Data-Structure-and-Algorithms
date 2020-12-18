#include <iostream>

using namespace std;

string a;
string b;

int LCS(int i, int j)
{
    if (a[i] == '\0' || b[j] == '\0')
        return 0;

    if (a[i] == b[j])
    {
        return 1 + LCS(i + 1, j + 1);
    }

    return max(LCS(i + 1, j), LCS(i, j + 1));
}

int main()
{

    a = "Gerosh";
    b = "George";

    cout << a << " " + b << endl;

    cout << "LCS count: " << LCS(0, 0) << endl;
}
