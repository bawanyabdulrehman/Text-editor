#include<iostream>
using namespace std;

void menu(){
	cout<<" >new <filename>    - to create new file \n";
	cout<<" >open <filename>   - to open an existing file\n";
	cout<<" >delete <filename> - to delete\n";
	cout<<" >list              - to view the list of files\n";
	cout<<" >Type #save        - to save the file \n";
	cout<<" >Press escape      - to close the file\n";
}
void edit_menu(){
	cout<<" >To exit                  - type 0\n";
    cout<<" >To edit any line         - type e <n>\n";
    cout<<" >Undo                     - type u\n";
    cout<<" >Redo                     - type r\n";
    cout<<" >Add Text                 - type a\n";
    cout<<" >Delete Line n            - type d <n>\n";
    cout<<" >Insert on line n         - type i <n>\n";
    cout<<" >Copy line m to n         - type c <m><n>\n";
    cout<<" >Move line m to n         - type m <m><n>\n";
}
void view_menu(){
	cout<<" >To exit                  - type 0\n";
	cout<<" >complete file            - type p <0>\n";
	cout<<" >line n                   - type p <n>\n";
    cout<<" >line m to n              - type t <m><n>\n";
}
