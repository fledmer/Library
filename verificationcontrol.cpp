#include "verificationcontrol.h"
#include <iostream>

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8

VerificationControl::VerificationControl(Lib &lib,void (*func)(Controller**,Lib&,Book*,Controller *oldControl)
    ,Controller **controlCenter,Controller *OldController,Book *book,string text):Controller(lib,controlCenter),controlCenter(controlCenter),
    oldControl(OldController),func(func),book(book),text(text),ptr(0)
{
}

int& VerificationControl::get_ptr()
{
   return ptr;
}

void VerificationControl::set_ptr(int x)
{
    if(x < 0)
        ptr = 1;
    else if(x > 1)
        ptr = 0;
    else
        ptr = x;
}


void VerificationControl::print_interface()
{
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| " <<text << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| ";
    if(ptr == 0)
        cout << ">";
    cout << " Yes." <<endl;
    cout << "|| ";
    if(ptr == 1)
        cout << ">";
    cout << " No." << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}

void VerificationControl::request(char command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == Right)
    {
        if(ptr == 0)
        {
            func(controlCenter,library,book,oldControl);
        }
        else if(ptr == 1)
        {
            *controlCenter = oldControl;
            //(*controlCenter)->request(8);
        }
        delete this;
    }
}
