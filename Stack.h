#include<iostream>
using namespace std;

class Stack{
	private:
		string *str;
		int top;
		int size;
	public:
		Stack(int n=0){
			top=-1;
			size=n;
			str=new string[n]();
		}
		int push(string s){
			if(top==size)return 0;	
			else{
				top++;
				str[top]=s;
			}
		}
		string pop(){
			string s;
			if(top==-1)return "NULL";
			else{
				s=str[top];
				top--;
			}
			return s;
		}
		string peek(){
			if(top==-1)return "NULL";
			return str[top];
		}
};
