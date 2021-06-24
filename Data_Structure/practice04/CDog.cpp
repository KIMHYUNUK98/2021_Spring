#include "CDog.h"    // DO NOT CHANGE this line 

// TODO: Implement the program referring to p.68 of lecture PDF 
CDog::CDog (int x, const char *y) {
    rabid = false;
    weight = x;
    strcpy(name,y);
}
void CDog::eat() {
        cout << name << ": eating" << endl;
        weight++;
    }
    void CDog::growl() {
        cout << name << ": Grrr" << endl;
    }
    void CDog::jump() {
        cout << "Jump!" << endl;
        weight--;
    }