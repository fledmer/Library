#include <mainmenu.h>
#include <controller.h>
#include <chousemenu.h>
#include <iostream>
#include <verificationcontrol.h>
using namespace std;

#define Down 80
#define Up 72
#define Right 77
#define Left 75
#define Enter 13
#define Backspace 8
#define PgDn 81
#define PgUp 73

MainMenu::MainMenu(Lib &lib,Controller **controlCenter):Controller(lib,controlCenter){}

void _delete(Controller **controlCenter,Lib &library,Book *book,Controller *oldControl)
{
    int ptr = library.find(book);
    library[ptr]->_delete();
    for(int x = ptr;x < library.books_vector.size()-1;x++)
    {
        *(library[x]) = *(library[x+1]);
    }
    library.books_vector.pop_back();
    *controlCenter = oldControl;
}

int& MainMenu::get_ptr()
{
   return ptr;
}

void MainMenu::set_ptr(int x)
{
    if(x < 0)
        ptr = library.size();
    else if(x > library.size())
        ptr = 0;
    else
        ptr = x;
}

void MainMenu::print_interface()
{
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|| ";
    if(ptr == 0)
        cout << '>';
    cout << "Create new Book" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    for(int x = 0; x < library.size();x++)
    {
        cout << "|| ";
        if(x+1 == ptr)
            cout << '>';
        cout << to_string(x+1) << "." << library[x]->name << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}

void MainMenu::request(int command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == Backspace)
    {
        if(ptr > 0)
        {
            *controlCenter = new VerificationControl(library,_delete,controlCenter,this,library[ptr-1],"Are you sure you want to delete this book ?");
        }
    }
    if(command == PgDn)
    {
       if(ptr == 0)
       {
            *controlCenter = new ChouseMenu(library,controlCenter,library.add());
       }
       else
       {
           *controlCenter = new ChouseMenu(library,controlCenter,library.books_vector[ptr-1]);
       }
       delete this;
    }

}
