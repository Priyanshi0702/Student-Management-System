#include<iostream>
#include<fstream>
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
        cin.ignore();
        cout<<"Enter name:";
        getline(cin,name);
        cout<<"Enter marks: ";
        cin>>mks;
        cout<<"enter CGPA:";
        cin>>cgpa;
        
    }
    void showdata()
    {   
        cout<<roll<<" "; 
        cout<<name<<" ";
        cout<<mks<<" ";
        cout<<cgpa<<" "<<"\n";
        
    }
    void setroll(int r)
    {
        roll = r;
    }
    void setname(string n)
    {
        name = n;
    }
    void setmarks(int m)
    {
        mks = m;
    }
    void setcgpa(float c)
    {
        cgpa = c;
    }
    int getroll()
{
    return roll;
}

string getname()
{
    return name;
}

int getmarks()
{
    return mks;
}

float getcgpa()
{
    return cgpa;
}
};
class StudentManagement
{
    public:
    void addstudent();
    void searchstudent();
    void updatestudent();
    void deletestudent();
};
void StudentManagement::addstudent()
{
    Student s;
    cout<<"Enter student details: "<<endl;
    s.getdata();
    ofstream fout ("student.txt",ios::app);
    if (!fout)
{
    cout << "Error opening file!\n";
    return;
}
    fout<<s.getroll()<<" "<<s.getname()<<" "<<s.getmarks()<<" "<<s.getcgpa()<<" "<<"\n";
    fout.close();
    cout<<"New student added successfully, \n";
    
}

int main()
{   
    cout<<"enter the number of students you want to add: ";
    int n;
    cin>>n;
    StudentManagement obj1;
    for(int i=1; i<=n; i++)
    {
        obj1.addstudent();
    }
    return 0;
}

