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
#define PgDn 81
#define PgUp 73

string convert_to_string(vector<string> vector)     //Нужно для преобразования вектора строк в 1 строку.
{
    string text = "";
    for(auto x : vector)
    {
        text += x + '\n';
    }
    return text;
}


ChangeControllerText::ChangeControllerText(Lib &lib,Controller **controlCenter,Book *book)
    :Controller(lib,controlCenter),book(book)
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
    horizontal_ptr = new_text[0].size();
}

void back_text(Controller **controlCenter,Lib &library,Book *book,Controller *oldControl)
{
    *controlCenter = new ChouseMenu(library,controlCenter,book);
}

void ChangeControllerText::pushChar(int x)
{
    if(horizontal_ptr == new_text[ptr].size())
        new_text[ptr].push_back(x);
    else
    {
        string first = "";
        string second = "";
        for(int x = 0; x < horizontal_ptr;x++)
            first += new_text[ptr][x];
        first += x;
        for(int x = horizontal_ptr;x < new_text[ptr].size();x++)
            second += new_text[ptr][x];
        new_text[ptr] = first + second;
    }
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

void ChangeControllerText::set_horizontal_ptr(int x)
{
    if(x < 0)
        horizontal_ptr = new_text[ptr].size();
    else if(x > new_text[ptr].size())
        horizontal_ptr = 0;
    else
        horizontal_ptr = x;
}

void ChangeControllerText::print_interface()
{
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| Book Name: " << book->name << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    for(int x = 0; x < new_text.size();x++)
    {
        cout << "|| ";
        if(x == ptr)
            cout << ">";
        for(int y = 0; y < new_text[x].size();y++)
        {
            if(y == horizontal_ptr && x == ptr)
                cout << "_";
            cout << new_text[x][y];
        }
        if(horizontal_ptr == new_text[x].size() && x == ptr)
            cout << "_";
        if(x == ptr)
            cout << "<";
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void ChangeControllerText::request(int command)
{
    if(command == Backspace)
    {
        if(new_text[ptr].size() > 0 && horizontal_ptr > 0)
        {
            if(horizontal_ptr == new_text[ptr].size())
                new_text[ptr].pop_back();
            else
                new_text[ptr].erase(horizontal_ptr-1,1);
            set_horizontal_ptr(horizontal_ptr-1);
        }
        else if(new_text.size()>1)
        {
            horizontal_ptr = new_text[ptr-1].size();
            new_text[ptr-1] += new_text[ptr];
            for(int x = ptr;x < new_text.size()-1;x++)
            {
                new_text[x] = new_text[x+1];
            }
            new_text.pop_back();
            set_ptr(ptr-1);
        }
    }
    else if(command == '\\')
    {
        new_text.push_back("");
        for(int x = new_text.size()-1;x > ptr;x--)
        {
            new_text[x] = new_text[x-1];
        }
        new_text[ptr+1] = "";
        for(int x = new_text[ptr].size()-1;x != horizontal_ptr-1;x--)
        {
            new_text[ptr+1] += new_text[ptr][x];
            new_text[ptr].pop_back();
        }
        reverse(new_text[ptr+1].begin(),new_text[ptr+1].end());
    }
    else if(command == Down)
    {
        set_ptr(ptr+1);
        horizontal_ptr = new_text[ptr].size();
    }
    else if(command == Up)
    {
        set_ptr(ptr-1);
        horizontal_ptr = new_text[ptr].size();
    }
    else if(command == Left)
    {
        set_horizontal_ptr(horizontal_ptr-1);
    }
    else if(command == Right)
    {
        set_horizontal_ptr(horizontal_ptr+1);
    }
    else if(command == PgUp)
    {
        if(convert_to_string(new_text) != book->text)
            *controlCenter = new VerificationControl(library,back_text,controlCenter,this,book,"Are you sure what you don't want to save it ?");
        else
            *controlCenter = new ChouseMenu(library,controlCenter,book);
    }
    else if(command == PgDn)
    {
        string text = "";
        for(auto x : new_text)
            text += x + "\n";
        book->text = text;
       *controlCenter = new ChouseMenu(library,controlCenter,book);
        delete this;
    }
    else
    {
        pushChar(command);
        set_horizontal_ptr(horizontal_ptr+1);
    }
}
