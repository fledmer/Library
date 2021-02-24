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
#define PgDn 81
#define PgUp 73

ChangeControllerName::ChangeControllerName(Lib &lib,Controller **controlCenter,Book *book)
    :Controller(lib,controlCenter),book(book),new_name(book->name)
{
        horizontal_ptr = new_name.size();
}

void ChangeControllerName::pushChar(int x)
{
    if(horizontal_ptr == new_name.size())
        new_name.push_back(x);
    else
    {
        string first = "";
        string second = "";
        for(int x = 0; x < horizontal_ptr;x++)
            first += new_name[x];
        first += x;
        for(int x = horizontal_ptr;x < new_name.size();x++)
            second += new_name[x];
        new_name = first + second;
    }
}


void back_name(Controller **controlCenter,Lib &library,Book *book,Controller *oldControl)
{
    *controlCenter = new ChouseMenu(library,controlCenter,book);
}

void ChangeControllerName::pushChar(const char *_char)
{
    if(horizontal_ptr == new_name.size())
        new_name.push_back(*_char);
    else
        new_name.insert(horizontal_ptr,_char);
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

void ChangeControllerName::set_horizontal_ptr(int x)
{
    if(x < 0)
        horizontal_ptr = new_name.size();
    else if(x > new_name.size())
        horizontal_ptr = 0;
    else
        horizontal_ptr = x;
}

void ChangeControllerName::print_interface()
{
    cout << endl << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| New Name: >"<<new_name << "_<" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}

void ChangeControllerName::request(int command)
{
    if(command == Backspace)
    {
        if(new_name.size() > 0)
        {
            if(horizontal_ptr == new_name.size())
                new_name.pop_back();
            else
                new_name.erase(horizontal_ptr-1,1);
            set_horizontal_ptr(horizontal_ptr-1);
        }
    }
    else if(command == Left)
    {
        set_horizontal_ptr(horizontal_ptr-1);
    }
    else if(command == Right)
    {
        set_horizontal_ptr(horizontal_ptr+1);
    }
    else if(command == PgDn)
    {
        new_name.pop_back();
        book->name = new_name;
       *controlCenter = new ChouseMenu(library,controlCenter,book);
    }
    else if(command == PgUp)
    {
        if(new_name.size() > 0)
            new_name.pop_back();
        if(new_name != book->name)
            *controlCenter = new VerificationControl(library,back_name,controlCenter,this,book,"Are you sure what you don't want to save it ?");
        else
        {
            *controlCenter = new ChouseMenu(library,controlCenter,book);
            delete this;
        }
    }
    else
    {
        pushChar(command);
        set_horizontal_ptr(horizontal_ptr+1);

    }

}
