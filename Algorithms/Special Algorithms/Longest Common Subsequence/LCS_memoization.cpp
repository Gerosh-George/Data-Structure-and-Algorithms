#include <iostream>
#include <map>
#include <iterator>

using namespace std;

string a;
string b;

map<pair<int, int>, int> mem;
pair<int, int> set;

int LCS(int i, int j)
{
    set = make_pair(i, j);
    if (mem[set])
    {
        //cout << "HIT!" << endl;
        return mem[set];
    }

    int count = 0;

    if (a[i] == '\0' || b[j] == '\0')
        return 0;

    else if (a[i] == b[j])
    {
        count = 1 + LCS(i + 1, j + 1);
    }
    else
    {
        count = max(LCS(i + 1, j), LCS(i, j + 1));
    }

    set = make_pair(i, j);
    mem[set] = count;
    return count;
}

int main()
{

    a = "gerosh";
    b = "george";

    cout << a << " " + b << endl;

    cout << "LCS count: " << LCS(0, 0) << endl;

    cout << endl
         << "mem object contents: " << endl;
    for (auto itr = mem.begin(); itr != mem.end(); ++itr)
    {
        cout << "(" << itr->first.first << "," << itr->first.second << ")"
             << " : " << itr->second << endl;
    }
}
