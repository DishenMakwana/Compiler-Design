#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dir.h>

int main(int args, char *argv[])
{
    int my;
    my = mkdir(argv[1]);

    if (!my)
    {
        printf("directory created");
    }
    else
    {
        printf("Unable to create");
        exit(1);
    }
    getch();
}