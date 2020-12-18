#include <iostream>

using namespace std;

string a;
string b;

void LCS(int **lk)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                lk[i + 1][j + 1] = 1 + lk[i][j];
            }
            else
            {
                lk[i + 1][j + 1] = max(lk[i][j + 1], lk[i + 1][j]);
            }
        }
    }
}

int **make_matrix()
{
    int **arr = new int *[a.length() + 1];
    for (int i = 0; i < a.length() + 1; i++)
    {
        arr[i] = new int[b.length() + 1];
    }

    for (int i = 0; i < a.length() + 1; i++)
    {
        for (int j = 0; j < b.length() + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    return arr;
}

void print_LCS(int **lk)
{
    int i = a.length();
    int j = b.length();
    string str = "";

    while (lk[i][j] != 0)
    {
        if (lk[i][j] == lk[i - 1][j - 1])
        {
            i--;
            continue;
        }

        if (lk[i - 1][j] == lk[i][j] or lk[i][j - 1] == lk[i][j])
        {
            cout << i << " : " << j << endl;
            j--;
        }
        else if (lk[i - 1][j - 1] + 1 == lk[i][j])
        {
            cout << a[i - 1] << " " << b[j - 1] << endl;
            str = a[i - 1] + str;
            i--;
            j--;
        }
    }

    cout << "LCS word: " << str << endl;
}

int main()
{
    //a = "stone";
    //b = "longest";
    b = "gerosh";
    a = "george";

    int **lookup = make_matrix();

    LCS(lookup);

    cout << a << " " << b << endl;

    cout << "LCS count: " << lookup[a.length()][b.size()] << endl;
    print_LCS(lookup);

    cout << endl
         << "Lookup table contents: " << endl;
    for (int i = 0; i < a.size() + 1; i++)
    {
        for (int j = 0; j < b.size() + 1; j++)
        {
            cout << lookup[i][j] << " ";
        }
        cout << endl;
    }
}