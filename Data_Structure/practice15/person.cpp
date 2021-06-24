#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// TODO: p.60~61

class Person{
    string name;
    int age;
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        bool operator <(const Person &a) const {
            return this->age < a.age;
        }
        string get_name() {return name;} 
        int get_age(){return age;}
};

int main() {
    vector<Person> v;
    v.push_back(Person("MinJi", 22));
    v.push_back(Person("Kangho", 28));
    v.push_back(Person("Minho", 26));
    v.push_back(Person("Strange Yun", 15));
    v.push_back(Person("JunEun", 13));
    sort(v.begin(), v.end());
    
    // sort(v.begin(), v.end(), less<Person>());
    // sort(v.begin(), v.end(), greater<Person>());
    
    for (int i= 0; i< v.size(); i++)
        cout<< v[i].get_age() << ", " << v[i].get_name() << endl;
}