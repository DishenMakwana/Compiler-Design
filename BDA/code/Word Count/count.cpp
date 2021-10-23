#include "bits/stdc++.h"
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
    string s = "Hello I am JohnDoe. Hello I am an Intern";
    mapping(s);
    reducer();
    return 0;
}