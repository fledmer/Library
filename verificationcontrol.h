#ifndef VERIFICATIONCONTROL_H
#define VERIFICATIONCONTROL_H
#include "controller.h"


class VerificationControl: public Controller
{
public:
    int ptr;
    Controller *oldControl;
    Controller **controlCenter;
    string text;
    Book *book;
    void (*func)(Controller** ,Lib&,Book*,Controller *);
    int &get_ptr() override;
    void set_ptr(int x) override;
    VerificationControl(Lib &lib,void (*func)(Controller** ,Lib&,Book*,Controller *),Controller **ControlCenter,
                        Controller *OldController,Book *book,string text);
    void print_interface() override;
    void request(char command) override;
};

#endif // VERIFICATIONCONTROL_H
