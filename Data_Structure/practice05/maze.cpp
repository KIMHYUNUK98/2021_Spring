#include "element_maze.h"
#include "stack.cpp"

class Maze {
  private:
    Stack* stack;
    int exit_row;
    int exit_col;
    int num_row;
    int num_col; 
    int **map;
    int **mark;  
    bool found;
    offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

  public: 
    Maze(int *e_map, int e_row, int e_col);
    void findPath();
    void printMap();
    void printPath();
};


Maze::Maze(int *e_map, int e_row, int e_col) 
{
    exit_row = e_row; 
    exit_col = e_col;   
    num_row = exit_row + 2;
    num_col = exit_col + 2;

    map = new int*[num_row];
    mark = new int*[num_row];
    for (int i = 0; i < num_row; i++)
    {
        map[i] = new int[exit_col];
        mark[i] = new int[num_col];
        for (int j = 0; j < num_col; j++)
        {
            map[i][j] = *(e_map + (i * num_col) + j);
            mark[i][j] = 0;
        }
    } 

    stack = new Stack(100);

    printMap();
}


void Maze::findPath(void)
{
    short int row, col, next_row, next_col, dir;
    Element *position;
    mark[1][1] = 1;

    position = new Element;
    position->row = 1;
    position->col = 1;
    position->dir = 1;
    stack->Push(position);

    found = false;

    while (!stack->IsEmptyS() && !found)
    {   
        position = stack->Pop();
        row = position->row;
        col = position->col;
        dir = position->dir;

       
        while (dir < 8 && !found)
        {
            // TODO: Complete findPath() by referring to pseudo codes below

            // while (dir < 8 AND Exit is not found) {
            //     <next_row, next_col> = coordinate of next move;      // dir = direction of move;
            next_row= row + move[dir].vert;
            next_col= col + move[dir].horiz;
            
            //     if (<next_row, next_col> == < EXIT_ROW, EXIT_COL> )
            //         success;
            if(next_row == exit_row && next_col == exit_col)
            { 
                found = true;
                position = new Element;
                position->row = row;
                position->col = col;
                stack->Push(position);
            }
            //     if (maze[next_row][next_col] == 0            // the move is legal
            //         && mark[next_row][next_col] == 0))       // and never been here before
            //     {   
            if(map[next_row][next_col] == 0 && mark[next_row][next_col] == 0)
            {
            //         mark[next_row][next_col] = 1;          // save current position and direction
            mark[next_row][next_col] = 1;
            
            //         add <row, col, dir+1> to the top of the stack;   // push
            position = new Element;
            position->row = row;
            position->col = col;
            position->dir = ++dir;
            stack->Push(position);

            //         row = next_row;                        // move to the next position
            //         col = next_col;
            //         dir = north;
            row = next_row;
            col = next_col;
            dir = 0;
            }   
            //     } else
            //         dir++;
            // }
            else{
                dir++;
            }
        }
    }
}

void Maze::printMap()
{
    cout << "Maze: " << endl;
    for (int i = 0; i < exit_row + 2; i++) 
    {
        for (int j = 0; j < exit_col + 2; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl; 
}


void Maze::printPath()
{
    if (found) 
    {
        printf("\nThe path is : \n");
        printf("row col \n");
        int len = stack->Length();
        Element **array = new Element*[len];

        int i = len;
        while (!stack->IsEmptyS())
        {
            Element *element = stack->Pop();
            array[i--] = element;
        }

        for (i = 0; i < len; i++)
        {
            printf("%2d %5d \n", array[i]->row, array[i]->col);
        }
        printf("%2d %5d \n", exit_row, exit_col);
    }
}


int main() 
{   
    int exit_row = 4; 
    int exit_col = 8;
    int map[exit_row+2][exit_col+2] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                                        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
                                        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                                        {1, 0, 0, 1, 0, 0, 0, 0, 1, 1},
                                        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

    // int exit_row = 3;
    // int exit_col = 3;
    // int map[exit_row+2][exit_col+2] = { {1, 1, 1, 1, 1}, 
    //                                     {1, 0, 0, 0, 1}, 
    //                                     {1, 0, 1, 1, 1}, 
    //                                     {1, 0, 0, 0, 1}, 
    //                                     {1, 1, 1, 1, 1} };

    Maze *maze = new Maze((int *)map, exit_row, exit_col);

    maze->findPath();
    
    maze->printPath();

    return 0;
}