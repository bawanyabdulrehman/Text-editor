#include <iostream>
#include <conio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <queue>
#include "Stack.h"
#include "linkedlist.h"
#include "menu.h"
#include "util-functions.h"
using namespace std;

int main(){
	string command,fileName;
	fstream commands;
	while(true){
		system("cls");
		menu();
		commands.open("commandlist.txt",ios::in);
		commands.seekg(0,ios::beg);
		while(getline(commands,command))
			cout<<"\n   "<<command;
		commands.close();
		cout<<"\n  $:";
		commands.open("commandlist.txt",ios::out | ios::app);
		cin.sync();
		getline(cin,command);
		commands<<command+"\n";
		commands.close();
		if(command.substr(0,4)=="new "){
			fileName=command.substr(4,command.length())+".txt";
			system("cls");
			newFile(fileName);
		}
		else if(command.substr(0,5)=="open "){
			fileName=command.substr(5,command.length())+".txt";
			system("cls");
			openFile(fileName);
		}
		else if (command.substr(0,7)=="delete "){
			fileName=command.substr(7,command.length())+".txt";
			system("cls");
			deleteFile(fileName);
		}
		else if (command=="list"){
			listFiles();
		}
		else{
			system("cls");
			menu();
			cout<<"\n\n\n\n\n\tINVALID COMMAND\n";
			sleep(1);
		}
	}
	return 0;
}
