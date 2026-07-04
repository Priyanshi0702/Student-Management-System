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
        cout<<roll<<"\t"<<"\t"<<name<<"\t"<<mks<<"\t"<<cgpa<<"\n";
        
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
    void displaystudent();
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
void StudentManagement::displaystudent()
{
    ifstream fin("student.txt");
    if (!fin)
{
    cout << "Error opening file!\n";
    return;
}
    Student s;
    cout<<"Displaying all students: "<<endl;
    cout<<"Roll number"<<"\t"<<"Name"<<"\t"<<"Marks"<<"\t"<<"CGPA"<<endl;
    int r;
    string n;
    int m;
    float c;
    while(fin>>r>>n>>m>>c)
    {
        s.setroll(r);
        s.setname(n);
        s.setmarks(m);
        s.setcgpa(c);
        
        s.showdata();
    }
    fin.close();
}
void StudentManagement::searchstudent()
{
    int roll;
    cout<<"Enter roll number of student to search: ";
    cin>>roll;
    ifstream fin("student.txt");
    if (!fin)
{
    cout << "Error opening file!\n";
    return;
}
    Student s;
    bool f=0;
    int r;
    string n;
    int m;
    float c;
    while(fin>>r>>n>>m>>c)
    {
        s.setroll(r);
        s.setname(n);
        s.setmarks(m);
        s.setcgpa(c);
        if(s.getroll()==roll)
        {
            cout<<"Student found: "<<endl;
            cout<<"Roll number"<<"\t"<<"Name"<<"\t"<<"Marks"<<"\t"<<"CGPA"<<endl;
            s.showdata();
            f = 1;
            break;
        }
    }
    if(f==0)
    {
        cout<<"Student not found"<<endl;
    }
    fin.close();
}

int main()
{   
    int choice;
    StudentManagement obj1;
    do
    {
    
    cout<<"please select the number according to the operation you want to perform: "<<endl;
    cout<<"1 for Add student"<<endl;
    cout<<"2 for Display students"<<endl;
    cout<<"3 for Search student"<<endl;
    cout<<"4 for Exit"<<endl;
   
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
        cout<<"enter the number of students you want to add: ";
        int n;
        cin>>n;
            for(int i=1; i<=n; i++)
            {
                obj1.addstudent();
            }
            break;
        }
        case 2:
            obj1.displaystudent();
            break;
        case 3:
            obj1.searchstudent();
            break;
            case 4:
            cout<<"Exiting the program."<<endl;
            cout<<"thankyou for using the Student Management program!"<<endl;
            break;
        default:
            cout<<"Invalid choice!"<<endl;
    }
}
while(choice!=4);
    return 0;
}

