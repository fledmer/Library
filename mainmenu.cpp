#include <mainmenu.h>
#include <controller.h>

#define Down 80
#define Up 72
#define Right 11

MainMenu::MainMenu(Lib &lib,Controller *controlCenter):Controller(lib,controlCenter){}

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
    cout << "..NEW" << endl;
    for(int x = 0; x < library.size();x++)
    {
        if(x+1 == ptr)
            cout << '>';
        cout << library[x].name << endl;
    }
    cout << ptr;

}

void MainMenu::request(char command)
{
    if(command == Down)
        set_ptr(ptr+1);
    if(command == Up)
        set_ptr(ptr-1);
    if(command == Right);
}
