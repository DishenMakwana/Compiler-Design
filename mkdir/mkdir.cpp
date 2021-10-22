#include <bits/stdc++.h>
#include <io.h>
using namespace std;

int32_t main(int argc, char *argv[])
{
    if (argv[1] == "mkdir")
    {
        int x = mkdir(argv[2]);
        cout << x << endl;
        if (x == -1)
        {
            cout << "Directory created" << endl;
            return 0;
        }
        else
        {
            cout << "Error" << endl;
            return 0;
        }
    }
    else if (argv[1] == "rmdir")
    {
        int x = rmdir(argv[2]);
        cout << x << endl;
        if (x == -1)
        {
            cout << "Directory deleted" << endl;
            return 0;
        }
        else
        {
            cout << "Error" << endl;
            return 0;
        }
    }
    return 0;
}