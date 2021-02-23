#include "readcontroller.h"
#include <iostream>
#include <chousemenu.h>

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8

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
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| Book Name: " << book->name << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
    cout <<book->text << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void ReadController::request(char command)
{
    if(command == Left)
    {
        *controlCenter = new ChouseMenu(library,controlCenter,book);
        delete this;
    }

}
