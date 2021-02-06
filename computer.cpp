#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
class student
{ char name[20];
  int  id;
  public:
  void enter()
  {cout<<"enter name"<<endl;
   gets(name);
   cout<<"enter id"<<endl;
   cin>>id;
  }
  void disp()
  {cout<<"name :"<<name<<endl;
   cout<<"id   :"<<id<<endl;
  }
  int ids()
  {return id;}
};
void adds()
{ int z=0;
  fstream ob("pro.DAT",ios::binary|ios::in|ios::app);
  student ob1;
  do{
     ob1.enter();
     ob.write((char*)&ob1,sizeof(ob1));
     cout<<"press 9: to add another student"<<endl;
     cout<<"press 0: if you are done       "<<endl;
     cin>>z;
    }while(z!=0);
   ob.close();
}
void tosee()
{ fstream ob("pro.DAT",ios::binary|ios::out|ios::in);
  student ob1;
  ob.seekg(0);
  ob.seekp(0);
  while(ob.read((char*)&ob1,sizeof(ob1)))
       {ob1.disp();
       cout<<endl;
       }
  ob.close();
}
void tosearch()
{ int l,k=0;
  fstream ob("pro.DAT",ios::binary|ios::in);
  student ob1;
  cout<<"enter id of student you wish to search"<<endl;
  cin>>l;
  while(ob.read((char*)&ob1,sizeof(ob1)))
       {
	 if(l==ob1.ids())
	   {k++;
	    ob1.disp();
	   }
	}
  if(k==0)
  {cout<<"student not found"<<endl;}
  ob.close();
}
void todelete()
{ int l=0,k=0;
  fstream ob("pro.DAT",ios::binary|ios::in|ios::out);
  student ob1;

  ofstream ob2("temp.DAT",ios::binary|ios::out);
  cout<<"enter id of student to be removed"<<endl;
  cin>>l;
  while(ob.read((char*)&ob1,sizeof(ob1)))
       { if(l!=ob1.ids())
	   {ob2.write((char*)&ob1,sizeof(ob1));
	    k++;
	   }
       }
  ob.close();
  ob2.close();
  remove("pro.DAT");
  rename("temp.DAT","pro.DAT");
  if(k==0)
  {cout<<"student not found"<<endl;}

}




void main()
{ int cho=0,k=0;
 do{
 clrscr();
 cout<<"                  STUDENT MANAGEMENT"<<endl<<endl<<endl;
 textcolor(GREEN);
 cputs("                press 1: to add");
 cout<<endl;
 cputs("                press 2: to read");
 cout<<endl;
 cputs("                press 3: to exit");
 cout<<endl;
 cputs("                press 4: to search");
 cout<<endl;
 cputs("                press 5: to delete");
 cout<<endl;
 cin>>cho;
 switch(cho)
 { case 1:  adds();break;
   case 2:  tosee();break;
   case 3:  exit(0);
   case 4:  tosearch();break;
   case 5:  todelete();break;

 }
 cout<<"press 1: to return to options"<<endl;
 cin>>k;
 }while(k!=0);
 getch();
 }