#include "bits/stdc++.h"
using namespace std;

int32_t main()
{
    string source, dest, line;
    cin >> source >> dest;

    ifstream in(source, ios::in);
    ofstream out(dest, ios::out);

    if (!in.is_open())
    {
        cout << "file not found";
    }
    else
    {
        out << in.rdbuf();
    }

    string words;
    fstream file;

    file.open(dest);
    while (file >> words)
    {
        cout << words << " ";
    }

    // if (in && out)
    // {
    //     while (getline(in, line))
    //     {
    //         out << line << "\n";
    //     }
    // }
    // else
    // {
    //     cout << "Cannot read File." << endl;
    // }

    in.close();
    out.close();
    return 0;
}