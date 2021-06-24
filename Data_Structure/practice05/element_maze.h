#include <iostream> 
#include <cstring>

using namespace std; 

// Definition of Element structure for maze problem
typedef struct {
    short int row;
    short int col;
    short int dir;
} Element;

typedef struct {
    short int vert;
    short int horiz; 
} offsets; 
