#include <iostream>
#include <windows.h>
#include <conio.h>
#include <lib.h>
#include <controller.h>
#include <mainmenu.h>

using namespace std;

int main()
{
    Lib library;
    Controller *UI;
    UI = new MainMenu(library,UI);
    UI->print_interface();
    char command = ' ';
    while(true)
    {
        if(_kbhit())
        {
               system("cls");
               command = _getch();
               UI->request(command);
               UI->print_interface();
        }
    }
}
