#ifndef CHOUSEMENU_H
#define CHOUSEMENU_H
#include <controller.h>


class ChouseMenu:public Controller
{
public:
    Book *book;
    int &get_ptr() override;
    void set_ptr(int x) override;
    ChouseMenu(Lib &lib,Controller **ControlCenter,Book *book);
    void print_interface() override;
    void request(int command) override;
};

#endif // CHOUSEMENU_H
