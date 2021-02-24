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
#define Enter 13
#define Backspace 8
#define PgDn 81
#define PgUp 73

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
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| ";
    cout << "Book Name: " << book->name << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| ";
    if(ptr == 0)
        cout << '>';
    cout << "Read Book" << endl;
    cout << "|| ";
    if(ptr == 1)
        cout << '>';
    cout << "Change Name" << endl;
    cout << "|| ";
    if(ptr == 2)
        cout << '>';
    cout << "Change Text" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void ChouseMenu::request(int command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == PgDn)
    {
        if(ptr == 0)
        {
            *controlCenter = new ReadController(library,controlCenter,book);
        }
        else if(ptr == 1)
        {
            *controlCenter = new ChangeControllerName(library,controlCenter,book);
        }
        else if(ptr == 2)
        {
            *controlCenter = new ChangeControllerText(library,controlCenter,book);
        }
        delete this;
    }
    if(command == PgUp)
    {
        *controlCenter =new MainMenu(library,controlCenter);
        delete this;
    }
}
