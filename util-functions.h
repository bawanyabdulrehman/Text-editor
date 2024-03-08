#include<iostream>
#include "edit-funs.h"
#include "view-funs.h"
using namespace std;

void newFile(string fileName){
    int lineno=1;
    fstream file;
    string str;
    file.open(fileName.c_str(),ios::in);
    if(file){
        cout<<"\n\n\n\n   The file already exists";
        sleep(1);
        file.close();
        return;
    }
    file.close();
    cout<<"\n\n\n\n\n   Creating a new file -- "<<fileName<<endl;
    file.open(fileName.c_str(),ios::out);
    system("cls");
    menu();
    cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
    cout<<lineno<<". ";
    cin>>str;
    queue<string> input;
    while(str!="#save"){
        input.push(str);                            //inserting every word you type into a queue
        if(cin.peek()=='\n'){
        	cout<<++lineno<<". ";
            file<<str+"\n";
        }
        else if(cin.peek()==' '){
            file<<str+' ';
        }
        cin>>str;
    }
        file.close();
        system("cls");
        menu();
        cout<<"\n\n   "<<fileName<<" is saved";
        sleep(1);
}
void deleteFile(string fileName){
	fstream file;
	menu();
	file.open(fileName.c_str(),ios::in);
	if(!file){
		cout<<"\n\n   The file "<<fileName<<" doesn't exist";
		sleep(1);
		return;
	}
	file.close();
	if(!remove(fileName.c_str()))
		cout<<"\n\n\n\n\n\tThe file --"<<fileName<<"-- is deleted"<<endl;
	sleep(1);
}
void viewFile(string fileName){
	fstream file;
	view_menu();
	char c;
l1:	cout<<"\nEnter your viewing mode: ";
	cin>>c;
	int i,j;
	switch(c){
		case '0':
			break;
		case 'p':
			cin>>i;
			system("cls");
			if(i!=0)printLine(fileName,i);
			else printFile(fileName);
			getch();
			return;
		case 't':
			cin>>i>>j;
			system("cls");
			printLine(fileName,i,j);
			getch();
			return;
		default:
			cout<<"\n\n\tINVALID COMMAND\n";
			sleep(1);
			goto l1;
	}
}
void edit(string fileName,Stack *undoBuffer,Stack *redoBuffer){
	fstream file;
	edit_menu();
	int i;
	int src,dest;
	char c;
l1:	cout<<"\nEnter your editing mode: ";
	cin>>c;
	switch(c){
		case '0':
			break;
		case 'e':
			cin>>i;
			editLine(fileName,i);
			return;
		case 'u':
			undo(fileName,undoBuffer,redoBuffer);
			return;
		case 'r':
			redo(fileName,undoBuffer,redoBuffer);	
			return;
		case 'a':
			addText(fileName);
			return;
		case 'd':
			cin>>i;
			deleteLine(fileName,i);
			return;
		case 'i':
			cin>>i;
			insertatLine(fileName,i);
			return;
		case 'c':
			cin>>src>>dest;
			copy(fileName,src,dest);
			return;
		case 'm':
			cin>>src>>dest;
			move(fileName,src,dest);
			return;
		default:
			cout<<"\n\n\tINVALID COMMAND\n";
			sleep(1);
			goto l1;
	}
}
void openFile(string fileName){
	fstream file;
	system("cls");
	menu();
	char ch;
	string X,Y;
	Stack undoBuffer(50);
	Stack redoBuffer(50);
	file.open(fileName.c_str(),ios::in);
	if(!file){
		cout<<"\n\n   The file "<<fileName<<" doesn't exist";
		sleep(1);
		return;
	}
	cout<<"\n\n\n\n\n\tOpening the file --"<<fileName<<"\n\n";
	sleep(1);
	file.close();
l3:	int lineno=1;
	file.open(fileName.c_str(),ios::in);
   	X="";
	system("cls");
	menu();
	printFile(fileName);
	while(file.get(ch))
		X+=ch;
	file.close();
	undoBuffer.push(X);
	cout<<"\n\n\n\n(Press any key to edit,escape key to exit,space bar for file viewing options)\n\n";
	ch=getch();
	if(ch==27)return;
	else if(ch==32){
		viewFile(fileName);
		goto l3;
	}
	else{
		edit(fileName,&undoBuffer,&redoBuffer);
		goto l3;
	}
}
void listFiles(){
	fstream file;
	string command;
	file.open("commandlist.txt",ios::in);
	file.seekg(0,ios::beg);
	system("cls");
	menu();
	int i=0;
	cout<<"List of files:(press any key to exit)\n\n\n\n";
	while(getline(file,command)){
		if(command.substr(0,4)=="new "){
			if (i==4){
				cout<<"\n\n";
				i=0;
			}
		cout<<"\t"<<command.substr(4,command.length())<<"\t\t";
		++i;
		}
	}
	file.close();
	getch();
}
