// &&&&&&&     COMPUTER SCIENCE PROJECT WORK      &&&&&&&&&&   //
//	           SOFTWARE FOR THE USE IN SMARTPHONE OUTLET      //                                 
//							                                 //
//		 *******INTRODUCTION*******                         //
//		    NAME:- PIYUSH KUMAR                            //
//		    CLASS:- XII A                                 //
//		    ROLL NO:- '24'                               //
//	     SCHOOL: - THE LAWRENCE PUBLIC SCHOOL           //
//		 *******-----------*********                   //
//	     Password (if required) :-  MyShowroom 	      //
//                                                   //

/*        HEADER FILES        */

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

/*        STRUCTURE DEFINITIONS       */

/* STRUCTURE FOR CUSTOMER DETAILS */
struct customer       
{ int c_no;
  char name[30];
  char AADHAR_No[13];
  char ContactNo[11];
  int prodimei;
  int d;        //date of purchase
  int m;        //month number
  int y;        //year
  int VCNM;     //vide cash memo number
};

/* CLASS CONTAINING FUNC. FOR PHONE */

class SmartPhone      
{ char nameph[30];
  char Model[10];
  int IMEI;
  int Warranty;

public :
   float price;

  void getdata()
  { 
   cout<<"\nEnter the name of phone - ";
    gets(nameph);
    cout<<"Enter the model number - ";
    gets(Model);
    cout<<"Enter IMEI number of phone - ";
    cin>>IMEI;
    cin.ignore(1000,'\n');
    cout<<"Enter warranty period(in yrs) - ";
    cin>>Warranty;
    cin.ignore(1000,'\n');
    cout<<"Enter price of phone(in Rs) - ";
    cin>>price;
    cin.ignore(1000,'\n');
  }
 void dispdata()
 { 
   cout<<"\nName of phone - "<<nameph;
    cout<<"\nModel - "<<Model;
   cout<<"\nIMEI number - "<<IMEI;
   cout<<"\nWarranty - "<<Warranty;
   cout<<"\nPrice - Rs."<<price;
 }
 int retimei()
 {
 return IMEI;
}
 char *retmodel()
 {
 return Model;
}
};

/*        FUNCTIONS FOR SMARTPHONE      */
void addrec();
void displayrec();
void modifyrec(int r);        //r,i,z
void searchrec(int i);        //are entered by
void delrec(int z);           //user(IMEI no.)

/*        FUNCTION TO CHECK THE VALIDITY OF DATE     */
void valid_date(int m,int d,int y)
{
 if(m<=12&&m>0)
    { if(m%2!=0)
      {  if(d>=1&&d<=31)
	 cout<<"\nValid date\n";
	 else
	 cout<<"\nInvalid date\n";
      }
      else if(m==2)
      {   if(y%4==0)
		{ if (d>=1&&d<=29)
		  cout<<"\nValid date\n";
		  else
		  cout<<"\nInvalid date\n";
		}
	  else if(y%4!=0)
		{ if (d>=1&&d>=28)
		   cout<<"\nValid date\n";
		  else
		   cout<<"\nInvalid date\n";
		}
      }

     else if(m%2==0)
     {   if(d>=1&&d<=30)
		cout<<"\nValid date\n";
	 else
		cout<<"\nInvaild date\n";
     }
    }
 else cout<<"\nInvalid Month\n";
}


class Custmr          /* CLASS CONTAINING FUNC. FOR CUSTOMER */
{ customer c;
 public :
  void gtdat()
  { cout<<"Enter Customer number - ";
    cin>>c.c_no;
    cin.ignore(1000,'\n');
    cout<<"Enter Name of the customer - ";
    cin.getline(c.name,30);
    cout<<"Enter the AADHAR number - ";
    cin.getline(c.AADHAR_No,13);
    cin.ignore(1000,'\n');
    cout<<"Enter contact number - ";
    cin.getline(c.ContactNo,11);
    cin.ignore(1000,'\n');
    cout<<"Enter IMEI number of product purchased - ";
    cin>>c.prodimei;
    cin.ignore(1000,'\n');
    cout<<"Enter date of purchase(in nos.and must be valid) - ";
    cin>>c.d>>c.m>>c.y;
    cout<<"Checking whether date is valid.........";
    valid_date(c.m,c.d,c.y);
    cout<<"Enter the cash memo number - ";
    cin>>c.VCNM;
    cin.ignore(1000,'\n');
  }
  void putdat()
  { cout<<"\nCustomer number - "<<c.c_no;
    cout<<"\nName of the customer - "<<c.name;
    cout<<"\nAADHAR number - "<<c.AADHAR_No;
    cout<<"\nContact number - "<<c.ContactNo;
    cout<<"\nIMEI Number of Product Purchased - "<<c.prodimei;
    cout<<"\nDate of Purchase - "<<c.d<<"."<<c.m<<"."<<c.y;
    cout<<"\nCash memo number - "<<c.VCNM;
  }
  int retcno()
  { return c.c_no;}
};

/*        FUNCTIONS FOR CUSTOMERS' RECORD      */
void addcust();
void dispcust();
void modifycust(int j);
void searchcust(int k);
void delcust(int l);
/*        MAIN FUNCTION      */
void main()
{clrscr();
 int choice,a,b,r,i,z,g,h,t;
 char ch[15];
cout<<"\n";
cout<<"\t*       *  * * *  *       * * *   * * * *   *       *  * * *\n";
cout<<"\t*       *  *      *      *       *       *  * *   * *  *\n";
cout<<"\t*   *   *  * * *  *      *       *       *  *   *   *  * *\n";
cout<<"\t* *   * *  *      *      *       *       *  *       *  *\n";
cout<<"\t*       *  * * *  * * *   * * *   * * * *   *       *  * *  *\n";
cout<<"\n\n\t\tSoftware developed by     -      PIYUSH KUMAR    \n \n";
do
 {
 cout<<"\t\t\t____________MAIN MENU____________\n";
 cout<<"1.To access CUSTOMER information";
 cout<<"\n2.To access SMARTPHONE information";
 cout<<"\n3.To EXIT\n";

 cin>>choice;

 if(choice==1)
 {cout<<"You have entered 1...";
  cout<<"\nEnter showroom password to access customer details = ";
  gets(ch);
  if(strcmp(ch,"MyShowroom")==0)
  {do
   {
    cout<<"\n\t\t\t______CUSTOMER_MENU_______\n";
    cout<<"1.TO ADD RECORD";
    cout<<"\n2.TO DISPLAY CUSTOMER RECORD";
    cout<<"\n3.TO MODIFY CUSTOMER RECORD";
    cout<<"\n4.TO SEARCH CUSTOMER RECORD";
    cout<<"\n5.TO DELETE CUSTOMER RECORD";
    cout<<"\n6.TO EXIT\n";
    cin>>a;

    switch(a)
    {case 1:cout<<"You have entered 1...\n";
	   addcust();
	   break;
     case 2:cout<<"You have entered 2...\n";
	   dispcust();
	   break;
     case 3:cout<<"You have enterded 3...";
	    cout<<"\nEnter the customer number - ";
	    cin>>g;
	    modifycust(g);
	    break;
     case 4:cout<<"You have entered 4...";
	    cout<<"\nEnter customer no. to be searched - ";
	    cin>>h;
	    searchcust(h);
	    break;
     case 5:cout<<"You have entered 5...";
	    cout<<"\nEnter customer no. to be deleted - ";
	    cin>>t;
	    delcust(t);
	    break;
    }
   }while(a<=5);
  }
  else
  cout<<"\n***************ACCESS DENIED**************\n";

 }
 else if(choice==2)
 {cout<<"You have entered 2...";
  do
  {
   cout<<"\n\t\t\t__________PHONE MENU________\n";
   cout<<"1.TO ADD PHONE RECORD";
   cout<<"\n2.TO DISPLAY PHONE RECORD";
   cout<<"\n3.TO MODIFY PHONE RECORD";
   cout<<"\n4.TO SEARCH PHONE RECORD";
   cout<<"\n5.TO DELETE PHONE RECORD";
   cout<<"\n6.TO EXIT\n";
   cin>>b;

   switch(b)
   {case 1:cout<<"You have entered 1...\n";
	   addrec();
	   break;
    case 2:cout<<"You have entered 2...\n";
	   displayrec();
	   break;
    case 3:cout<<"You have entered 3....";
	   cout<<"\nEnter IMEI number - ";
	   cin>>r;
	   modifyrec(r);
	   break;
    case 4:cout<<"You have entered 4...";
	   cout<<"\nEnter IMEI number - ";
	   cin>>i;
	   searchrec(i);
	   break;
    case 5:cout<<"You have entered 5...";
	   cout<<"\nEnter IMEI number - ";
	   cin>>z;
	   delrec(z);
	   break;
    case 6:break;

    }
  }while(b<=5);
 }

  else if(choice==3)
      exit(0);
}while(choice<3);
getch();
}

/*  **************FUNCTION DEFINITIONS*****************     */

/*        FUNCTION DEFINITION FOR SMARTPHONES      */
void addrec()                          //To add phone records
{ SmartPhone s;
  ofstream fout("Outlet.txt");
  if(!fout)
    cout<<"\nFile not exist!!!";
  else
  { char ch;
    do
    {  s.getdata();
       fout.write((char*)&s,sizeof(s));
       cout<<"\nWant to enter more records ???(Y/N)";
       cin>>ch;
    }while(ch=='Y'||ch=='y');
  }
  fout.close();
}
void displayrec()                      //To display phone records
{ SmartPhone s1;
  ifstream fin;
  fin.open("Outlet.txt");
  if(!fin)
     cout<<"\nFile not exist!!!";
  else
  { while(!fin.eof())
       {  fin.read((char*)&s1,sizeof(s1));
	  s1.dispdata();
       }
  }
  fin.close();
}
void searchrec(int r)                  //To search a phone's record
{ SmartPhone S;
  int found=0;
  ifstream fin;
  fin.open("Outlet.txt",ios::binary);
  if(!fin)
     cout<<"\nFile not EXIST!!!";
  else
  {  while(!fin.eof())
       { fin.read((char*)&S,sizeof(S));
	 if(S.retimei()==r)
	 { cout<<"\nRecord FOUND:)...:";
	   S.dispdata();
	   found=1;
	 }
       }
     if(found==0)
	 cout<<"\nRecord not FOUND!!!";
  }
  fin.close();
}
void modifyrec(int z)                      //To modify a phone's record
{ SmartPhone s;
  ifstream fin("Outlet.txt",ios::binary);
  if(!fin)
    cout<<"\nFile not exist!!!";
  else
  { ofstream fout("Temp.txt");
    while(!fin.eof())
     {  fin.read((char*)&s,sizeof(s));
	if(s.retimei()==z)
	{ s.getdata();
	  fout.write((char*)&s,sizeof(s));
	}
	else
	  fout.write((char*)&s,sizeof(s));
     }
    fout.close();
  }
  fin.close();
  remove("Outlet.txt");
  rename("Temp.txt","Outlet.txt");
}
void delrec(int a)                        //To delete a phone's record
{ SmartPhone s1;
  ifstream fin("Outlet.txt");
  if(!fin)
      cout<<"\nFile not exist!!!";
  else
  {  ofstream fout("Temp.txt");
     while(!fin.eof())
     {  fin.read((char*)&s1,sizeof(s1));
	if(s1.retimei()!=a)
	     fout.write((char*)&s1,sizeof(s1));
     }
     fout.close();
  }
  fin.close();
  remove("Outlet.txt");
  rename("Temp.txt","Outlet.txt");
}

/*        FUNCTION DEFINITION FOR CUSTOMER   */
void addcust()                                 //To add customer's record
{ Custmr c1;
  ofstream fout("CUSTOMER.txt",ios::binary);
  if(!fout)
    cout<<"\nfile not exist!!!";
  else
  { char ch;
    do
    {  c1.gtdat();
       fout.write((char*)&c1,sizeof(c1));
       cout<<"\nWant to enter more records ???(Y/N)";
       cin>>ch;
    }while(ch=='Y'||ch=='y');
  }
  fout.close();
}
void dispcust()                           //To display customer's records
{ Custmr c2;
  ifstream fin;
  fin.open("Customer.txt");
  if(!fin)
     cout<<"\nFile not exist!!!";
  else
  {
       while(fin.read((char*) &c2, sizeof(c2)) )
	c2.putdat();
  }
  fin.close();
}
void searchcust(int r)                     //To search a customer's record
{ Custmr c3;
  int found=0;
  ifstream fin;
  fin.open("Customer.txt",ios::binary);
  if(!fin)
     cout<<"\nFile not EXIST!!!";
  else
  {  while(!fin.eof())
       { fin.read((char*)&c3,sizeof(c3));
	 if(c3.retcno()==r)
	 { cout<<"\nRecord FOUND:)...:";
	   c3.putdat();
	   found=1;
	 }
       }
     if(found==0)
	 cout<<"\nRecord not FOUND!!!";
  }
  fin.close();
}
void modifycust(int z)                        //To modify a customer's record
{ Custmr c4;
  ifstream fin("Customer.txt",ios::binary);
  if(!fin)
    cout<<"\nFile not exist!!!";
  else
  { ofstream fout("Temp.txt");
    while(!fin.eof())
     {  fin.read((char*)&c4,sizeof(c4));
	if(c4.retcno()==z)
	{ c4.gtdat();
	  fout.write((char*)&c4,sizeof(c4));
	}
	else
	  fout.write((char*)&c4,sizeof(c4));
     }
    fout.close();
  }
  fin.close();
  remove("Customer.txt");
  rename("Temp.txt","Customer.txt");
}
void delcust(int a)                  //To delete a customer's record
{ Custmr c5;
  ifstream fin("Customer.txt");
  if(!fin)
      cout<<"\nFile not exist!!!";
  else
  {
     ofstream fout("Temp.txt");
     while(!fin.eof())
     {  fin.read((char*)&c5,sizeof(c5));
	if(c5.retcno()!=a)
	     fout.write((char*)&c5,sizeof(c5));
     }
     fout.close();
  }
  fin.close();
  remove("Customer.txt");
  rename("Temp.txt","Customer.txt");
}

