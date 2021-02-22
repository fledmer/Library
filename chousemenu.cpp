#include "chousemenu.h"
#include "mainmenu.h"
#include <lib.h>
#include <control.h>
#include <iostream>
#include <changecontrollername.h>
#include <changecontrollertext.h>
#include <readcontroller.h>

using namespace std;

#define Down 80
#define Up 72
#define Right 77
#define Left 75

ChouseMenu::ChouseMenu(Lib &lib,Controller **controlCenter,Book *book):Controller(lib,controlCenter),book(book){}

int& ChouseMenu::get_ptr()
{
   return ptr;
}

void ChouseMenu::set_ptr(int x)
{
    if(x < 0)
        ptr = 2;
    else if(x > 2)
        ptr = 0;
    else
        ptr = x;
}


void ChouseMenu::print_interface()
{
    cout << "Book Name:" << book->name << endl << endl;
    if(ptr == 0)
        cout << '>';
    cout << "Read Book" << endl;
    if(ptr == 1)
        cout << '>';
    cout << "Change Name" << endl;
    if(ptr == 2)
        cout << '>';
    cout << "Change Text" << endl;
}

void ChouseMenu::request(char command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == Right)
    {
        if(ptr == 0)
        {
            *controlcenter = new ReadController(library,controlcenter,book);
        }
        else if(ptr == 1)
        {
            *controlcenter = new ChangeControllerName(library,controlcenter,book);
        }
        else if(ptr == 2)
        {
            *controlcenter = new ChangeControllerText(library,controlcenter,book);
        }
    }
    if(command == Left)
    {
        *controlcenter =new MainMenu(library,controlcenter);
    }
}
