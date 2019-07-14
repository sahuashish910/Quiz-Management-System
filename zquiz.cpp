#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<iomanip>
using namespace std;

char name[50];
void front();
void intro()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t  -----------------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(h,6|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t\t                                    C++ PROJECT \n\n";
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t                                     A  SIMPLE  QUIZ  SYSTEM \n";
    SetConsoleTextAttribute(h,3|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t\t\t                                       Made By ASHISH SAHU \n\n";
    SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t\t  -----------------------------------------------------------------------------";

	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);	
    cout<<"\n\n\t\t\t\t\t\t  Press any key to continue...";
    getch();
}

void heading()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t                                     A SIMPLE QUIZ SYSTEM \n";
    SetConsoleTextAttribute(h,3|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t                                      Made By ASHISH SAHU \n\n";
    SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t  -----------------------------------------------------------------------------";

    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

void headname()
{
	cout<<"\n\n\n";
    HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l,6|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t             WELCOME TO SIMPLE QUIZ\n";
	cout<<"\t\t\t\t\t\t\t\t                    "<<name;
	cout<<"\n\t\t\t\t\t\t\t\t	    ------------------------\n\n";
	SetConsoleTextAttribute(l,5|FOREGROUND_INTENSITY);
}
class Questions
{
	public:
		char str[1000];
		char opt[4][25];
		char ch;
		char answer;
		void show_ques()
		{
			ch='a';
			cout<<"\t\t\t\t\t\t\t"<<str<<"\n\n";
			cout<<"\t\t\t\t\t\t\tAvailable Answers : \n";
			for(int j=0;j<4;j++)
			{
				cout<<"\t\t\t\t\t\t\t"<<ch<<'.';	
				cout<<opt[j]<<endl;
				ch+=1;
			}
		}
};


void start()
{
	int cat_marks[10]={0},total=0;
	for(int z=1;z<=10;z++)
	{
		system("cls");
		heading();
		headname();
		Questions que;
		if(z==1)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Data Types\n";
			cout<<"\t\t\t\t\t\t\t\t            -------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("datatype.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Data Types\n";
				cout<<"\t\t\t\t\t\t\t\t            -------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Data Types\n";
			cout<<"\t\t\t\t\t\t\t\t            -----------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Data Types' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}	
		if(z==2)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Control Flow\n";
			cout<<"\t\t\t\t\t\t\t\t            ---------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("controlflow.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Control Flow\n";
				cout<<"\t\t\t\t\t\t\t\t            ---------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Control Flow\n";
			cout<<"\t\t\t\t\t\t\t\t            -------------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Control Flow' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==3)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Functions\n";
			cout<<"\t\t\t\t\t\t\t\t            ------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("functions.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Functions\n";
				cout<<"\t\t\t\t\t\t\t\t            ------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Functions\n";
			cout<<"\t\t\t\t\t\t\t\t            ----------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Functions' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==4)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Pointers & Arrays\n";
			cout<<"\t\t\t\t\t\t\t\t            -------------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("pointers.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Pointers & Arrays\n";
				cout<<"\t\t\t\t\t\t\t\t            -------------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Pointers & Arrays\n";
			cout<<"\t\t\t\t\t\t\t\t            ------------------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Pointers & Arrays' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==5)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Structure\n";
			cout<<"\t\t\t\t\t\t\t\t            -----------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("structure.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Structure\n";
				cout<<"\t\t\t\t\t\t\t\t            -----------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Structure\n";
			cout<<"\t\t\t\t\t\t\t\t            ----------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Structure' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==6)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Unions\n";
			cout<<"\t\t\t\t\t\t\t\t            --------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("union.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Unions\n";
				cout<<"\t\t\t\t\t\t\t\t            --------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Unions\n";
			cout<<"\t\t\t\t\t\t\t\t            -------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Unions' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==7)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : In/Out\n";
			cout<<"\t\t\t\t\t\t\t\t            --------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("input.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : In/Out\n";
				cout<<"\t\t\t\t\t\t\t\t            --------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : In/Out\n";
			cout<<"\t\t\t\t\t\t\t\t            -------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'In/Out' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==8)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Error Handling\n";
			cout<<"\t\t\t\t\t\t\t\t            ----------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("error.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Error Handling\n";
				cout<<"\t\t\t\t\t\t\t\t            ----------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Error Handling\n";
			cout<<"\t\t\t\t\t\t\t\t            ---------------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Error Handling' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==9)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Enum\n";
			cout<<"\t\t\t\t\t\t\t\t            ------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("enum.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Enum\n";
				cout<<"\t\t\t\t\t\t\t\t            ------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Enum\n";
			cout<<"\t\t\t\t\t\t\t\t            -----------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Enum' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z==10)
		{
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Miscellaneous\n";
			cout<<"\t\t\t\t\t\t\t\t            ---------------------------\n";
			HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			ifstream cpp_file("mis.txt",ios::binary|ios::in);
			cpp_file.seekg(0,ios::end);
			int size=cpp_file.tellg()/sizeof(que);
			char ans[size]={'T'};
			int marks=0,award[size]={0};
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				system("cls");
				heading();
				headname();
				cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Miscellaneous\n";
				cout<<"\t\t\t\t\t\t\t\t            ---------------------------\n\n";
				HANDLE m= GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(m,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
				cout<<"\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\t\t           Marks Allotted : 1\n";
				cout<<"\t\t\t\t\t\t\t\t        Enter your answer : ";
				cin>>ans[i];
				if(ans[i]==que.answer)
				{
					marks+=1;
					award[i]=1;
				}
		 	}
		 	cat_marks[z]=marks;
		 	total+=marks;
			system("cls");
			heading();
			cout<<"\n\n\n";
			headname();
			cout<<"\t\t\t\t\t\t\t\t             CATEGORY : Miscellaneous\n";
			cout<<"\t\t\t\t\t\t\t\t            --------------------------\n\n";
			HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t\t\t\t             CONGRATULATIONS "<<name<<"\n";
			cout<<"\t\t\t\t\t\t\t\tYou have successfully completed 'Miscellaneous' category quiz\n";
			cout<<"\t\t\t\t\t\t\t\t       You have scored "<<marks<<" out of 10\n"; 
			cout<<"\t\t\t\t\t\t\t\t       Here are your answers(ENTER) : \n";   
			getch();                    
			cpp_file.seekg(0,ios::beg);
			for(int i=0;i<size;i++)
			{
				cout<<"\n\t\t\t\t\t\t\tQuestion "<<i+1<<endl;
				cpp_file.read((char*)&que,sizeof(Questions));
				que.show_ques();
				cout<<"\n\t\t\t\t\t\t\tCorrect Answer : "<<que.answer;
				cout<<"\n\t\t\t\t\t\t\tYour Answer    : "<<ans[i];
				cout<<"\n\t\t\t\t\t\t\tMarks Awarded  : "<<award[i];
				cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			}
		}
		if(z!=10)
		cout<<"\n\t\t\t\t\t\t\tPress any key to begin with next category quiz.....";
		if(z==10)
		cout<<"\n\t\t\t\t\t\t\tPress any key to see category wise results.....";
		getch();
	}
	system("cls");
	heading();
	cout<<"\n";
	headname();
	cout<<"\t\t\t\t\t\t\t\t               CATEGORY WISE MARKS\n";
	cout<<"\t\t\t\t\t\t\t\t              ----------------------\n\n";
	HANDLE k= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout<<"\n\t\t\t\t\t\t\t     1. Data Type                          "<<setw(5)<<cat_marks[1]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     2. Control Flow                       "<<setw(5)<<cat_marks[2]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     3. Functions                          "<<setw(5)<<cat_marks[3]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     4. Pointers & Arrays                  "<<setw(5)<<cat_marks[4]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     5. Structure                          "<<setw(5)<<cat_marks[5]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     6. Unions                             "<<setw(5)<<cat_marks[6]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     7. In/Out                             "<<setw(5)<<cat_marks[7]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     8. Error Handling                     "<<setw(5)<<cat_marks[8]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t     9. Enum                               "<<setw(5)<<cat_marks[9]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t    10. Miscellaneous                      "<<setw(5)<<cat_marks[10]<<"/10";
	cout<<"\n\t\t\t\t\t\t\t                                       --------------";
	cout<<"\n\t\t\t\t\t\t\t                                       TOTAL : "<<total<<"/100";
	SetConsoleTextAttribute(k,2|FOREGROUND_INTENSITY);
	cout<<"\n\n\t\t\t\t\t\t\t\t  Your final total score "<<total<<" out of 100";
	SetConsoleTextAttribute(k,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	if(total<30)
	cout<<"\n\t\t\t\t\t\t\t\t                You FAILED";
	else
	cout<<"\n\t\t\t\t\t\t\t\t                You PASSED";
	SetConsoleTextAttribute(k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

void category()
{
	system("cls");
	heading();
	int ch;
	char hc;
    cout<<"\n\n\n\n\n";
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t             WELCOME TO SIMPLE QUIZ\n";
	cout<<"\t\t\t\t\t\t\t\t	    ------------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t\t\t              Enter Name : ";
    cin.ignore();
	cin.getline(name,50);
    system("cls");
	heading();
	cout<<"\n\n\n";
    HANDLE l= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l,6|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t             WELCOME TO SIMPLE QUIZ\n";
	cout<<"\t\t\t\t\t\t\t\t                    "<<name;
	cout<<"\n\t\t\t\t\t\t\t\t	    ------------------------\n\n";
	SetConsoleTextAttribute(l,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                   CATEGORIES\n";
	cout<<"\t\t\t\t\t\t\t\t                  ------------\n";
	SetConsoleTextAttribute(l,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                 1. Data Types\n";
	cout<<"\t\t\t\t\t\t\t\t                 2. Control Flow\n";
	cout<<"\t\t\t\t\t\t\t\t                 3. Functions\n";
	cout<<"\t\t\t\t\t\t\t\t                 4. Pointers & Arrays\n";
	cout<<"\t\t\t\t\t\t\t\t                 5. Structure\n";
	cout<<"\t\t\t\t\t\t\t\t                 6. Unions\n";
	cout<<"\t\t\t\t\t\t\t\t                 7. In/Out\n";
	cout<<"\t\t\t\t\t\t\t\t                 8. Error Handling\n";
	cout<<"\t\t\t\t\t\t\t\t                 9. Enum\n";
	cout<<"\t\t\t\t\t\t\t\t                10. Miscellaneous\n";
	cout<<"\n\n\t\t\t\t\t\t              Want to start (y/Y) :  ";
    cin>>hc;
    if(hc=='y' || hc=='Y')
    start();
    else
    front();
}

void front()
{
	system("cls");
	heading();
	int ch;
    cout<<"\n\n\n\n\n";
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t             WELCOME TO SIMPLE QUIZ\n";
	cout<<"\t\t\t\t\t\t\t\t	    ------------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t\t\t                 1. START QUIZ\n\n";
    cout<<"\t\t\t\t\t\t\t\t                 2. EXIT\n\n";
    cout<<"\t\t\t\t\t\t\t\t    Your choice : ";
    cin>>ch;
    switch(ch)
    {
    	case 1: category();
    	        break;
        case 2: exit(0);
        		break;
		default: front();         
	}
}		

int main()
{
	intro();
    front();
}
