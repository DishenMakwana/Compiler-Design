#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

void mapping(string s)
{
    istringstream ss(s);

    string word;
    while (ss >> word)
    {
        mp[word]++;
    }
}

void reducer()
{
    for (auto x : mp)
    {
        cout << x.first << " : " << x.second << endl;
    }
}

int32_t main(int argc, char *argv[])
{
    string line, file;
    cin >> file;
    ifstream myfile(file);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            mapping(line);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
        return 0;
    }

    reducer();
    return 0;
}