#include<iostream>
using namespace std;
class Student
{
    private:
    int roll;
    string name;
    int mks;
    float cgpa;
    public:
    void getdata()
    {
        cout<<"Enter roll number: ";
        cin>>roll;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter marks: ";
        cin>>mks;
        cout<<"enter CGPA:";
        cin>>cgpa;
    }
    void showdata()
    {
        cout<<roll<<" ";
        cout<<name<<"  ";
        cout<<mks<<" ";
        cout<<cgpa<<" ";
    }
};
int main()
{
    
    Student s;
    s.getdata();
    s.showdata();
    return 0;
}

