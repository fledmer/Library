#include <mainmenu.h>
#include <controller.h>
#include <chousemenu.h>
#include <iostream>

using namespace std;

#define Down 80
#define Up 72
#define Right 77
#define Backspace 8

MainMenu::MainMenu(Lib &lib,Controller **controlCenter):Controller(lib,controlCenter){}

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
    if(ptr == 0)
        cout << '>';
    cout << "..NEW" << endl << endl;
    for(int x = 0; x < library.size();x++)
    {
        if(x+1 == ptr)
            cout << '>';
        cout << library[x]->name << endl;
    }

}

void MainMenu::request(char command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == Backspace)
    {
        if(ptr > 0)
        {
            library[ptr-1]->_delete();
            for(int x = ptr;x < library.books_vector.size()-1;x++)
            {
                *(library[x]) = *(library[x+1]);
            }
            library.books_vector.pop_back();
        }
    }
    if(command == Right)
    {
       if(ptr == 0)
       {
            *controlcenter = new ChouseMenu(library,controlcenter,library.add());
       }
       else
       {
           *controlcenter = new ChouseMenu(library,controlcenter,library.books_vector[ptr-1]);
       }
    }

}
