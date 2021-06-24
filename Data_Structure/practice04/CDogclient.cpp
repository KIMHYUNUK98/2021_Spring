#include "CDog.h"   // DO NOT CHANGE this line 
#include <string>

int main ( ) 
{
    // TODO: Implement the program referring to p.66 of lecture PDF and the expected results 
    CDog* c1;
    c1 = new CDog(14, "Bob");
    CDog c2 (7, "Ethel");
    c2.eat();
    c1->growl();
    
    cout << c1->getName() << "'s weight : " << c1->getWeight() << endl;
    cout << c2.getName() << "'s weight : " << c2.getWeight() << endl;
} 

