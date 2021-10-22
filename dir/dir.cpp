#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <iomanip>
#include <pwd.h>
using namespace std;

//Print file permissions
void printPriority(struct stat statinfo)
{
    mode_t mode = statinfo.st_mode;
    //Judging the file type
    cout << (S_ISDIR(mode) ? 'd' : '-');

    //Determine USR permissions
    cout << (mode & S_IRUSR ? 'r' : '-');
    cout << (mode & S_IWUSR ? 'w' : '-');
    cout << (mode & S_IXUSR ? 'x' : '-');

    //Determine GRP permissions
    cout << (mode & S_IRGRP ? 'r' : '-');
    cout << (mode & S_IWGRP ? 'w' : '-');
    cout << (mode & S_IXGRP ? 'x' : '-');

    //Judgment of OTH authority
    cout << (mode & S_IROTH ? 'r' : '-');
    cout << (mode & S_IWOTH ? 'w' : '-');
    cout << (mode & S_IXOTH ? 'x' : '-');

    cout << " ";
}

//Print owner and group
void printOwner(struct stat statinfo)
{
    struct passwd *passwdinfo = getpwuid(statinfo.st_uid);
    cout << passwdinfo->pw_name << " ";
    passwdinfo = getpwuid(statinfo.st_gid);
    cout << passwdinfo->pw_name << " ";
}

//Print file size
void printSize(struct stat statinfo)
{
    cout << setw(6) << statinfo.st_size << " ";
}

//Print Time
void printTime(struct stat statinfo)
{
    time_t rawtime = statinfo.st_mtime;
    struct tm *timeinfo = localtime(&rawtime);
    cout << timeinfo->tm_mon + 1 << "Month" << timeinfo->tm_mday << "Day";
    if (timeinfo->tm_hour < 9)
        cout << "0" << timeinfo->tm_hour << ":";
    else
        cout << timeinfo->tm_hour << ":";

    if (timeinfo->tm_min < 9)
        cout << "0" << timeinfo->tm_min << " ";
    else
        cout << timeinfo->tm_min << " ";
}

void printName(const char *name)
{
    cout << name << " ";
}

void ls_l(const char *path)
{
    chdir(path);
    DIR *dir = opendir(".");
    struct dirent *dirinfo;
    while (dirinfo = readdir(dir))
    {
        if (!strcmp(dirinfo->d_name, ".") || !strcmp(dirinfo->d_name, ".."))
            continue;
        struct stat statinfo;
        stat(dirinfo->d_name, &statinfo);
        //begin
        printPriority(statinfo);
        printOwner(statinfo);
        printSize(statinfo);
        printTime(statinfo);
        printName(dirinfo->d_name);
        //end
        cout << endl;
    }
}

int main()
{
    ls_l("/home/wwx/Linux/Day04/fileSystem");
    return 0;
}
