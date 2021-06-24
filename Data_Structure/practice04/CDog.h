#include <iostream>	    // DO NOT CHANGE this line 
#include <cstring>      // DO NOT CHANGE this line 
using namespace std;    // DO NOT CHANGE this line 

class CDog {	// CDog.h
    // TODO: Implement the program referring to p.67 of lecture PDF 
    private:
        bool rabid;
        int weight;
        char name[20];

    public:
        CDog(int x, const char *y);

        bool getRabid() {return rabid;}
        void setRabid(bool x) {rabid = x;}
        char *getName() {return name;}
        void setName(char *z) {strcpy(name, z);}
        int getWeight() {return weight;}
        void setWeight(int x) {weight = x;}
        void eat();
        void growl();
        void jump();
};