#include <iostream>

// TODO 
#include <vector>
#include <list> 
#include <stack> 
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

void vector_ex();
void list_ex(); 
void print_list(list<string> *demo); 
void stack_ex(); 
void queue_ex(); 
void setdiff_ex(); 
void map_ex(); 

int main () 
{
    cout << "* Example of vector" << endl; 
    vector_ex(); 
    cout << endl << endl;

    cout << "* Example of list" << endl; 
    list_ex(); 
    cout << endl << endl;

    cout << "* Example of stack" << endl; 
    stack_ex(); 
    cout << endl << endl;

    cout << "* Example of queue" << endl; 
    queue_ex(); 
    cout << endl << endl;

    cout << "* Example of set difference" << endl; 
    setdiff_ex(); 
    cout << endl << endl;

    cout << "* Example of map" << endl; 
    map_ex(); 
    cout << endl << endl;
    
    return 0;
}

// TODO: p.28 
void vector_ex() 
{
    vector<char> myvector(3, 'A'); // A AA
    vector<char>::iterator it;     // vector iterator
    
    it = myvector.begin();
    it = myvector.insert(it, 'B'); // B A AA
    myvector.insert(it, 2, 'C');   // C CB A AA
    
    it = myvector.begin(); // "it" no longer valid, get a new one:
    
    vector<char> anothervector(2, 'D'); // D D
    myvector.insert(it+2, anothervector.begin(), anothervector.end()); // C CD DB A AA
    
    char myarray[] = {'E', 'F', 'G'};
    myvector.insert(myvector.begin(), myarray, myarray+3); // E F G C CD DB A AA
    
    cout<< "myvectorcontains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        cout<< ' ' << *it;
    cout<< endl;
}


// TODO: p.32 
void print_list(list<string> *demo) 
{
    // Create a forward iterator
    list<string>::iterator place;
    cout<< "List contents from beginning to end: " << endl;
    
    // Traverse list in forward direction
    for (place = demo->begin(); place != demo->end(); place++)
        cout<< *place << " ";
    cout<< endl;
}


// TODO: p.33-34
void list_ex() 
{ 
    list<string> demo; // Create an empty list 
    string word; 
    list<string>::iterator place;
    cout<< "Enter a line with six words:" << endl; 
    for (int i= 1; i<= 6; i++) {
        cin>> word;
        demo.push_back(word); // Insert elements at back
    } 
    
    // Access front, back, and size
    cout<< "Front element: " << demo.front() << endl
        << "Back element: " << demo.back() << endl
        << "Size of list: " << demo.size() << endl;
    print_list(&demo);

    cout<< "Enter a word to insert after the first:";
    cin>> word;
    place = demo.begin(); // Point forward iterator to front 
    ++place; // Advance one place 
    demo.insert(place, word); // Insert an element 
    
    place = demo.end();   // Point forward iterator past end
    --place;              // Move back to last element 
    --place;              // Move back one more place 
    demo.erase(place);    // Delete element 
    
    cout<< "Next to last word has been erased." << endl; 
    cout<< "Enter a word to add at the front: "; 
    cin>> word; 
    demo.push_front(word); // Insert at front 
    print_list(&demo);
    
    string init[] = {"AA", "BB", "CC"}; 
    list<string> demo2(init, init+sizeof(init)/sizeof(string)); 
    demo.merge(demo2);     // merge for two sorted list
    print_list(&demo);
}


// TODO: p.39
void stack_ex() 
{
    stack<string> strStack; 
    string word; 
    
    for (int i=1; i<=6; i++) {
        cin>> word; 
        strStack.push(word);
    }
    
    cout<< "Top: " << strStack.top() << endl
        << "Size " << strStack.size() << endl; 
        
    while (!strStack.empty()) {
        cout<< strStack.top() << endl; 
        strStack.pop(); 
    }
}


// TODO: p.43
void queue_ex() 
{
    queue<string> strQ;
    string word;
    
    for (int i=1; i<=6; i++) {
        cin>> word;strQ.push(word);
    }
    
    cout<< "Front: " << strQ.front() << endl
        << "Back: " << strQ.back() << endl;
    
    while (!strQ.empty()){
        cout<< strQ.front() << endl;
        strQ.pop();
    }
}


// TODO: p.50 
void setdiff_ex()
{
    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10};
    vector<int> v(10);           // 0  0  0  0  0  0  0  0  0  0
    vector<int>::iterator it;
    sort (first,first+5);     //  5 10 15 20 25
    sort (second,second+5);   // 10 20 30 40 50
    it = set_difference(first, first+5, second, second+5, v.begin());//  5 15 25  0  0  0  0  0  0  0
    v.resize(it-v.begin());       //  5 15 25
    
    cout<< "The difference has " << (v.size()) << " elements:\n";
    
    for (it=v.begin(); it!=v.end(); ++it)
        cout<< ' ' << *it;
    cout<< endl;
}


// TODO: p.56
void map_ex()
{
    map<string,int> my_map;
    map<string,int>::iterator it;
    my_map.insert(make_pair("abc",1));
    my_map["bbc"] = 2;
    my_map["cnn"] = 3;
    my_map.erase("hgu");
    
    for (it = my_map.begin(); it != my_map.end(); it++)
        cout<< it->first << ' ' << it->second << endl;
    
    if (my_map.find("cnn") != my_map.end()) cout<< "Exist" << endl;
    else cout<< "Not exist." << endl;
}
