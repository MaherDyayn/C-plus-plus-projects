#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct student
{
char name[32];
int reg_no;
student*stu;
};

class stack();
{student*top;
 public:
 stack()
 {
 top=NULL;
 }
 void push();
 void pop();
 void display;
 ~stack()
 {}
}

void stack::push()
{
student*p=new student;
cout<<"enter student name=";
gets(p->name);
cout<<"enter student registration number=;
cin>>p->reg_no;
if(top==NULL)
{
top=p;
p->stu=NULL;
}
else
{
p->stu=top;
top=p;
}
}

void stack::pop()
{if(top==NULL)
{
cout<<"underflow"<<endl;"
}
else
{student*temp;
 temp=top;
 top=temp->stu;
 delete(temp);
}
}

void stack::disp()
{
cout<<"displaying stack"<<endl;
if(top==NULL)
{
cout<<"underflow"<<endl;
}
else
{
student*temp;
temp=top;
while(temp!=NULL)
{
cout<<"name="<<temp->name<<endl;
cout<<"registration number="<<temp->reg_no;
temp=temp->stu;
}
}
}

void main()
{clrscr
while(1)
{
cout<<endl;
cout<<"press [1] to push an element"<<endl;
cout<<"press [2] to pop an element"<<endl;
cout<<"press [3] to display all elements"<<endl;
cout<<"press [4] to exit program"<<endl;
}

}