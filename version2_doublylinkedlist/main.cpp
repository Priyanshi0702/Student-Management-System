#include<iostream>
#include<utility>
using namespace std;
class Node
{
    public:
    int roll;
    int mks;
    string name;
    Node *next;
    Node *prev;
    node(int n, int m,string x)
    {
        roll=n;
        mks=m;
        name=x;
        next=NULL;
        prev=NULL;
    }
};
Node *head=NULL;
void Addstudent(int n,int m,string x)
{
     Node *t=new Node(n,m,x);
     if(head==NULL)
     {
        head=t;
     }
     else
     {
        Node *c=head;
        while(c->next!=NULL)
        {
            c=c->next;
        }
        c->next=t;
        t->prev=c;
     }
}
void displaystudent()
{
   if(head==NULL)
    {
        cout<< "list is Empty"<<endl;
    }
    else
    {
         Node *c=head;
         while(c!=NULL)
         {
            cout<<c->roll<<"\t"<<"\t"<<c->mks<<"\t"<<c->name<<endl;
            c=c->next;
         }
    }
}
int countstudent()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return 0;
    }
        
    else
    {
        Node *c=head;
        int count =0;
        while(c!=NULL)
        {
            count++;
            c=c->next;
        }
        cout<<"Total number of student = "<<count<<endl;
        return count;
    }
}
void searchbyroll()
{
    int r;
    cout<<"enter the roll number to search"<<endl;;
    cin>>r;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        Node *c=head;
        int f=0;
        while(c!=NULL)
        {
            if(c->roll==r)
            {
                cout<<c->roll<<"\t"<<c->mks<<"\t"<<c->name<<endl;
                f=1;
                return;
            }
            c=c->next;
        }
        if(f==0)
        {
            cout<<"Roll number not found"<<endl;
        }
    }
}
void deletebyroll()
{
    int r;
    cout<<"enter the roll number to delete";
    cin>>r;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        Node *c=head;
        int f=0;
        while(c!=NULL)
        {
            if(c->roll==r)
            {
                c->prev->next=c->next;
                c->next->prev=c->prev;
                delete(c);
                f=1;
                cout<<"student deleted successfully"<<endl;
                return;
            }
            c=c->next;
        }
        if(f==0)
        {
            cout<<"invalid roll number";
        }
    }
}
void sortbymarks()
{
    int i,j;
    int c1=countstudent();
    Node*c=head;
    Node *p=head;
    for(i=1;i<c1;i++)
    {   c=p->next;
        for(j=i;j<c1;j++)
        {
            
            if(p->mks>c->mks)
            {
                swap(p->roll,c->roll);
                swap(p->mks,c->mks);
                swap(p->name,c->name);
            }
            c=c->next;
        }
        p=p->next;
        
    
}
}
int main()
{   cout<<" STUDENT MANAGEMENT SYSTEM MENU "<<endl;
    cout<<"Press 1 to Add student"<<endl;
    cout<<"Press 2 to display students"<<endl;
    cout<<"Press 3 to Search Student By Roll Number"<<endl;
    cout<<"Press 4 to delete student by roll number"<<endl;
    cout<<"Press 5 to count number of students"<<endl;
    cout<<"press 6 to sort student by marks"<<endl;
    int n;
    do
    {
    cout<<"Enter Your Choice From Above"<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            int r;
            int m;
            string y;
            cout<<"enter roll number"<<endl;
            cin>>r;
            cout<<"enter marks"<<endl;
            cin>>m;
            cout<<"enter name of student"<<endl;
            cin>>y;
            Addstudent(r,m,y);
            cout<<"student added successfully"<<endl;
            break;
        }
        case 2:
        {
            cout<<"ROLL NO."<<"\t"<<"MARKS"<<"\t"<<"NAME"<<endl;
            displaystudent();
            break;
        }
        case 3:
        {
            searchbyroll();
            break;
        }
        case 4:
        {
              deletebyroll();
              break;
        }
        case 5:
        {
            countstudent();
            break;
        }
        case 6:
        {
            sortbymarks();
            displaystudent();
            break;
        }
        case 7:
        {
            cout<<"Thank you for using student management system"<<endl;
        }
    }
}
while(n!=7);
return 0;
}
