#include "changecontrollername.h"
#include <iostream>
#include <chousemenu.h>
#include <verificationcontrol.h>

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8

ChangeControllerName::ChangeControllerName(Lib &lib,Controller **controlCenter,Book *book):Controller(lib,controlCenter),book(book),new_name(book->name)
{
}

void back_name(Controller **controlCenter,Lib &library,Book *book,Controller *oldControl)
{
    *controlCenter = new ChouseMenu(library,controlCenter,book);
}

int& ChangeControllerName::get_ptr()
{
   return ptr;
}

void ChangeControllerName::set_ptr(int x)
{
    if(x < 0)
        ptr = 1;
    else if(x > 1)
        ptr = 0;
    else
        ptr = x;
}


void ChangeControllerName::print_interface()
{
    cout << endl << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| New Name: >"<<new_name << "_<" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}

void ChangeControllerName::request(char command)
{
    if(command == Right)
    {
        new_name.pop_back();
        book->name = new_name;
       *controlCenter = new ChouseMenu(library,controlCenter,book);
    }
    else if(command == Backspace)
    {
        if(new_name.size() > 0)
            new_name.pop_back();
    }
    else if(command == Left)
    {
        if(new_name.size() > 0)
            new_name.pop_back();
        if(new_name != book->name)
            *controlCenter = new VerificationControl(library,back_name,controlCenter,this,book,"Are you sure what you don't want to save it ?");
        else
            *controlCenter = new ChouseMenu(library,controlCenter,book);
        delete this;
    }
    else if(command == Up)
    {
        new_name.pop_back();
    }
    else if(command == Down)
    {
       new_name.pop_back();
    }
    else
    {
        if(command != Down && command != Right && command != Left && command != Up)
            new_name += command;
    }

}
