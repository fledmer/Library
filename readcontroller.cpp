#include "readcontroller.h"
#include <iostream>
#include <chousemenu.h>

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8
#define PgDn 81
#define PgUp 73

ReadController::ReadController(Lib &lib,Controller **controlCenter,Book *book):Controller(lib,controlCenter),book(book){}

int& ReadController::get_ptr()
{
   return ptr;
}

void ReadController::set_ptr(int x)
{
}


void ReadController::print_interface()
{
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| Book Name: " << book->name << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
    cout << "  ";
    for(int x = 0; x < book->text.size();x++)
    {
        if(book->text[x] == '\n')
            cout << endl << "  ";
        else
            cout << book->text[x];
    }
    cout <<endl<< "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void ReadController::request(int command)
{
    if(command == PgUp)
    {
        *controlCenter = new ChouseMenu(library,controlCenter,book);
        delete this;
    }

}
