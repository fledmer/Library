#include "changecontrollertext.h"
#include <iostream>
#include <chousemenu.h>
#include <verificationcontrol.h>

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8

string convert_to_string(vector<string> vector)
{
    string text = "";
    for(auto x : vector)
    {
        text += x + '\n';
    }
    return text;
}


ChangeControllerText::ChangeControllerText(Lib &lib,Controller **controlCenter,Book *book):Controller(lib,controlCenter),book(book)
{
    string text = "";
    for(auto x : book->text)
    {
        if(x == '\n')
        {
            new_text.push_back(text);
            text = "";
        }
        else
            text += x;
    }
    if(new_text.size() == 0)
        new_text.push_back(text);
}

void back_text(Controller **controlCenter,Lib &library,Book *book,Controller *oldControl)
{
    *controlCenter = new ChouseMenu(library,controlCenter,book);
}



int& ChangeControllerText::get_ptr()
{
   return ptr;
}

void ChangeControllerText::set_ptr(int x)
{
    if(x < 0)
        ptr = new_text.size()-1;
    else if(x >= new_text.size())
        ptr = 0;
    else
        ptr = x;
}

void ChangeControllerText::print_interface()
{
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| Book Name: " << book->name << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    for(int x = 0; x < new_text.size();x++)
    {
        cout << "|| ";
        if(x == ptr)
            cout << ">";
        cout << new_text[x];
        if(x == ptr)
            cout << "_<";
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void ChangeControllerText::request(char command)
{
    if(command == Right)
    {
        string text = "";
        new_text[ptr].pop_back();
        for(auto x : new_text)
            text += x + "\n";
        book->text = text;
       *controlCenter = new ChouseMenu(library,controlCenter,book);
       delete this;
    }
    else if(command == Backspace)
    {
        if(new_text[ptr].size() > 0)
        {
            new_text[ptr].pop_back();
        }
        else if(new_text.size()>1)
        {
            for(int x = ptr;x < new_text.size()-1;x++)
            {
                new_text[x] = new_text[x+1];
            }
            new_text.pop_back();
            set_ptr(ptr-1);
        }
    }
    else if(command == Left)
    {
        if(new_text[ptr].size() > 0)
            new_text[ptr].pop_back();
        if(convert_to_string(new_text) != book->text)
            *controlCenter = new VerificationControl(library,back_text,controlCenter,this,book,"Are you sure what you don't want to save it ?");
        else
            *controlCenter = new ChouseMenu(library,controlCenter,book);
        delete this;
    }
    else if(command == '\\')
    {
        new_text.push_back("");
        for(int x = new_text.size()-1;x > ptr;x--)
        {
            new_text[x] = new_text[x-1];
        }
        new_text[ptr+1] = "";
    }
    else if(command == Up)
    {
        if(new_text[ptr].size()>0)
            new_text[ptr].pop_back();
        set_ptr(ptr-1);
    }
    else if(command == Down)
    {
        if(new_text[ptr].size()>0)
            new_text[ptr].pop_back();
        set_ptr(ptr+1);
    }
    else
    {
        if(command != Down && command != Right && command != Left && command != Up)
        {
            new_text[ptr] += command;
        }
    }

}
