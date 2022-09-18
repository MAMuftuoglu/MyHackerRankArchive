#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person 
{
protected:
    int age;
    string name;

public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
private:
    static int nextID;
    int cur_id, publications;

public:
    Professor()
    {
        cur_id = nextID;
        nextID++;
    }
    
    virtual void getdata() override
    {
        cin >> name >> age >> publications;
    }
    
    virtual void putdata() override
    {
        cout << name << " " << age <<  " " << publications << " " << cur_id << endl;
    }
};

int Professor::nextID = 1;

class Student : public Person
{
private:
    static int nextID;
    int cur_id, marks[6];

public:
    Student()
    {
        cur_id = nextID;
        nextID++;
    }
    
    virtual void getdata() override
    {
        cin >> name >> age;
        for(int index = 0; index < 6; index++)
        {
            cin >> marks[index];
        }
    }
    
    virtual void putdata() override
    {
        int sum = 0;
        
        for(int index = 0; index < 6; index++)
        {
            sum += marks[index];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl; 
    }
};

int Student::nextID = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
