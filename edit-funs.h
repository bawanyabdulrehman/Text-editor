#include<iostream>
using namespace std;

void editLine(string fileName,int i){
	fstream file;
	char ch;
	string w,y="",z="";
	int nline=1;
	cout<<"\n(Type in the whole line)(you can insert or delete)\n\n";
	file.open(fileName.c_str(),ios::in);
	if(i==1){
		bool f=true;
		while(file.get(ch)){
			if(ch=='\n')f=false;
			if(f)cout<<ch;
			else z+=ch;
		}
	cout<<"\r";
	cin.sync();
	getline(cin,w);
	}
	else{
		int f=-1;
		while(file.get(ch)){
			if(f==0 && ch=='\n'){
				++nline;
				if(nline==i)f=0;
				else if(nline>i)f=1;
			}
			switch(f){
				case -1:
					y+=ch;
					break;
				case 1:
					z+=ch;
					break;
				case 0:
					cout<<ch;
					break;
			}
			if(ch=='\n'){
				++nline;
				if(nline==i) f=0;
				else if (nline>i)f=1;
			}
		}
		cout<<"\r";
		cin.sync();
		getline(cin,w);
	}
	file.close();
	file.open(fileName.c_str(),ios::out);
	file<<y;
	file<<w;
	file<<z;
	file.close();
}
void undo(string fileName,Stack *undoBuffer,Stack *redoBuffer){
	fstream file;
	string Y;
	if(undoBuffer->peek()!="NULL"){
		Y=undoBuffer->pop();
		redoBuffer->push(Y);
		Y=undoBuffer->peek();
		if (Y!="NULL"){
			file.open(fileName.c_str(),ios::out);
			file<<Y;
			file.close();
		}
	}
}
void redo(string fileName,Stack *undoBuffer,Stack *redoBuffer){
	fstream file;
	string Y;   
	if(redoBuffer->peek()!="NULL"){
		Y=redoBuffer->pop();
		undoBuffer->push(Y);
		file.open(fileName.c_str(),ios::out);
		file<<Y;
		file.close();
	}
}
void addText(string fileName){
	fstream file;
	int lineno=1;
	string str;
	file.open(fileName.c_str(),ios::app);
    cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
    cout<<lineno<<". ";
    cin>>str;
    queue<string> input;
    while(str!="#save"){
        input.push(str);
        if(cin.peek()=='\n'){
        	cout<<++lineno<<". ";
            file<<str+"\n";
        }
        else if(cin.peek()==' ')
            file<<str+' ';
        cin>>str;
    }
        file.close();
        system("cls");
        menu();
        cout<<"\n\n   "<<fileName<<" is saved";
        sleep(1);
}
void deleteLine(string fileName,int i){
	fstream file;
	linkedList list;
	string str;
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str))
		list.insert(str);
	list.del(i);
	list.recreate(fileName);
}
void insertatLine(string fileName,int i){
	fstream file;
	linkedList list;
	string str;
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str))
		list.insert(str);
	cout<<"Enter text to be inserted:";
	cin.sync();
	getline(cin,str);
	list.insert(str,i);
	list.recreate(fileName);
}
void copy(string fileName,int src,int dest){
	fstream file;
	linkedList list;
	string str;
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str))
		list.insert(str);
	str=list.copy(src);
	list.insert(str,dest);
	list.recreate(fileName);
}
void move(string fileName,int src,int dest){
	fstream file;
	linkedList list;
	string str;
	file.open(fileName.c_str(),ios::in);
	while(getline(file,str))
		list.insert(str);
	str=list.copy(src);
	list.insert(str,dest+1);
	list.recreate(fileName);
	deleteLine(fileName,src);
}
