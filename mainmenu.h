#ifndef MAINMENU_H
#define MAINMENU_H
#include <controller.h>

class MainMenu:public Controller
{
public:
    int &get_ptr() override;
    void set_ptr(int x) override;
    MainMenu(Lib &lib,Controller **ControlCenter);
    void print_interface() override;
    void request(char command) override;
};

#endif // MAINMENU_H
