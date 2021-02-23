
#include <windows.h>
#include <conio.h>
#include <lib.h>
#include <controller.h>
#include <mainmenu.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);
    Lib library;
    Controller *UI;
    UI = new MainMenu(library,&UI);
    UI->controlCenter = &UI;
    start:UI->print_interface();
    char command = ' ';
    while(true)
    {
        if(_kbhit())
        {
               //cout << UI << endl;
               command = _getch();
               system("cls");
               if(command == 13)
                   goto start;
               try {
               UI->request(command);
               UI->print_interface();
               }  catch (...) {

               }
               library.save();
        }
    }
}


//Нужно добавить окно проверки согласия пользователя на действие, допустим удаление и код проверить.
