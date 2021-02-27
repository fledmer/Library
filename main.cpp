
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
    int cout_command = 0;
    UI->controlCenter = &UI;
    start:UI->print_interface();
    int command = 0;
    while(true)
    {
        if(_kbhit())
        {            
            command = _getch();
            system("cls");
            if(command == 13)
               goto start;
            if(command == 224 || command == 0)
            {
                if(kbhit())
                {
                    UI->request(_getch());
                    UI->print_interface();
                }
                else
                {
                    UI->request(224);
                    UI->print_interface();
                }
            }
            else
            {
                UI->request(command);
                UI->print_interface();
            }
            library.save();
        }
    }
}


//Нужно добавить окно проверки согласия пользователя на действие, допустим удаление и код проверить.
