#ifndef READCONTROLLER_H
#define READCONTROLLER_H
#include <controller.h>

class ReadController:public Controller
{
public:
    ReadController(Lib &lib,Controller **ControlCenter,Book *book);
    Book *book;
    int &get_ptr() override;
    void set_ptr(int x) override;
    void print_interface() override;
    void request(char command) override;
};

#endif // READCONTROLLER_H
