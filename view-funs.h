#include<iostream>
using namespace std;

void printLine(string fileName,int pos){
	fstream file;
	linkedList list;
	string str;
	int length=0;
	system("cls");
	cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str)){
		list.insert(str);
		length++;
	}
	if(pos<=length) cout<<"\n"<<pos<<"."<<list.display(pos);
}
void printLine(string fileName,int s_pos,int e_pos){
	fstream file;
	linkedList list;
	string str;
	int length=0;
	cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str)){
		list.insert(str);
		length++;
	}
	while(s_pos<=e_pos&&s_pos<=length)
		cout<<"\n"<<s_pos++<<"."<<list.display(s_pos);
}
void printFile(string fileName){
	fstream file;
	char ch;
	int lineno=1;
	cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
	printf("\n%d. ",lineno);
	file.open(fileName.c_str(),ios::in);
	while(file.get(ch)){
		cout<<ch;
		if(ch=='\n'){
			if(file.get(ch)){
				cout<<++lineno<<". ";
				cout<<ch;
			}
		}
	} 	
}
