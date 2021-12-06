#include<iostream>  
   
 using namespace std;  
   
 struct node{  
        
      int PRN;  
      char Name[10];  
      node *next;  
 };  
   
 node *nnode,*npre;  
 char ch;  
 int prn,total=0,choice;  
   
 class Pinnacle_Club{  
        
      public:  
             
           node *President,*Secretary;  
             
           Pinnacle_Club(){  
             
           President=Secretary=NULL;  
      }  
        
      void create();  
      void display();  
      void newpresident();  
      void DelPresident();  
      void DelSecretary();  
      void DelMember();  
      void Total();  
 };  
   
 void Pinnacle_Club::create()  
 {  
      do{  
           nnode=new node;  
           nnode->next=NULL;  
           cout<<"Enter PRN NO. of Student : "<<endl;  
           cin>>nnode->PRN;  
           cout<<"Enter Name of Student : "<<endl;  
           cin>>nnode->Name;  
             
           if (President==NULL || Secretary==NULL)  
           {  
           President=Secretary=nnode;  
           }  
           else  
           {  
           Secretary->next=nnode;  
           Secretary=nnode;  
           }  
           cout<<"Do you want to Add more Students to Club (Y or N) ";  
           cin>>ch;  
      }while(ch=='Y');       
 }  
   
   
 void Pinnacle_Club::display()  
 {    
   cout<<" List of Members in Club "<<endl;  
   cout<<"PRN NO."<<" "<<"Name"<<endl;  
   node *temp;  
   temp=President;  
   while(temp!=NULL)  
      {  
      cout<<" "<<temp->PRN<<"   ";  
      cout<<temp->Name<<endl;  
      temp=temp->next;  
  }  
 }  
   
 void Pinnacle_Club::newpresident()  
 {   
   npre=new node;  
   npre->next=NULL;  
   cout<<"Enter PRN NO. of New President : "<<endl;  
   cin>>npre->PRN;  
   cout<<"Enter Name of New President : "<<endl;  
   cin>>npre->Name;  
   npre->next=President;  
   President=npre;  
   cout<<"Name of New President : "<<President->Name<<endl;  
   cout<<"PRN NO. of New President : "<<President->PRN<<endl;  
 }  
   
 void Pinnacle_Club::DelPresident()  
 {  
      node *temp;  
      temp=President;  
      President=President->next;  
      delete temp;  
      cout<<"Name of New President : "<<President->Name<<endl;  
      cout<<"PRN NO. of New President : "<<President->PRN<<endl;  
 }  
   
 void Pinnacle_Club::DelSecretary()  
 {  
      node *temp;  
      temp=President;  
      while(temp->next!=Secretary){  
      temp=temp->next;  
      }  
   Secretary=temp;  
   delete temp->next;  
   cout<<"Name of New Secretary : "<<Secretary->Name<<endl;  
   cout<<"PRN NO. of New Secretary : "<<Secretary->PRN<<endl;  
 }  
   
 void Pinnacle_Club::DelMember()  
 {  
      cout<<"Enter PRN no. Member to be deleted"<<endl;  
      cin>>prn;  
      node *temp,*temp1;  
      temp=President;  
      while((temp->next)->PRN!=prn){  
      temp=temp->next;  
      }  
      temp1=temp->next;  
      temp->next=temp1->next;  
       delete temp1;  
 }  
   
 void Pinnacle_Club::Total()  
 {  
   node *temp;  
   temp=President;  
   while(temp!=NULL)  
      {  
           total=total+1;  
           temp=temp->next;       
      }  
      cout<<"Total No. of Elements Are :"<<total<<endl;  
 }  
   
   
 int main(){  
        
      Pinnacle_Club M1,M2;  
      M1.create();  
      M1.display();  
        
      cout<<"\nPresident Name : "<<M1.President->Name<<endl;  
      cout<<"Secretary Name : "<<M1.Secretary->Name<<endl;  
        
   do  
      {  
   cout<<"\n1.Insert New President\n2.Delete President\n3.Delete Secretary\n4.Delete Member\n5.Display\n6.Find total No. of members\n7.Concatenate two list\n0. Exit";  
   cout<<"\nEnter your choice: ";  
   cin>>choice;  
   switch(choice)  
           {  
                case 0:   
                     break;   
                case 1:   
                  M1.newpresident();  
                     break;  
                case 2:       
                  M1.DelPresident();  
                     break;  
                case 3:   
                  M1.DelSecretary();  
                     break;  
                case 4:   
                  M1.DelMember();  
                     break;  
                case 5:   
                  M1.display();  
                  break;  
                case 6:  
                     M1.Total();  
                     break;  
                case 7:  
                     cout<<"Enter the Details of new Club"<<endl;  
                     M2.create();  
                     M2.display();  
                     M1.Secretary->next=M2.President;  
                     M1.Secretary=M2.Secretary;  
                     M1.display();  
                     break;  
                default:  
                     cout<<"Wrong choice";  
           }  
      }while(choice!=0);  
      return 0;  
 } 