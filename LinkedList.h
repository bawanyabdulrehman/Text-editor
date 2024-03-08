#include<iostream>
using namespace std;

struct Node{
	string data;
	Node *next;
	Node *prev;
};
class linkedList{
	private:
		Node *head;
	public:
		linkedList(){head = NULL;}
		Node* createNode(string data){
			Node* n= new Node; 
			n->data=data; 
			n->next=n->prev=NULL; 
			return n;
		}
		void push(Node** head,Node* n){
			if(*(head)==NULL) *head=n;
			else{
				Node* ptr=*head;
				while(ptr->next!=NULL) ptr=ptr->next;
				ptr->next=n;
				n->prev=ptr;
			} 
		}
		void push(Node** head,Node* n,int pos){
			if(*(head)==NULL) *head=n;
			else{
				Node* ptr=*head;
				int i=1;
				while(ptr->next!=NULL && (i<pos-1||pos==0)){
					++i;
					ptr=ptr->next;
				}
				if(ptr==*head){
					n->next=*head;
					(*head)->prev=n;
					*head=n;
					return;
				}
				if(ptr->next==NULL){
					ptr->next=n;
					n->prev=ptr;
					return;
				}
				n->next=ptr->next;
				ptr->next->prev=n;
				ptr->next=n;
				n->prev=ptr;
			} 
		}
		void display(){
			Node* temp;
			temp=head;
			while(temp!=NULL){ 
				cout<<temp->data<<" "; 
				temp=temp->next; 
			}
		}
		string display(int n){
			Node *temp=head;
			int i=1;
			while(temp!=NULL&&i<n){
				i++;
				temp=temp->next;
			}
			return temp->data;
		}
		void insert(string s){
			push(&head,createNode(s)); 
		}
		void insert(string s,int pos){
			push(&head,createNode(s),pos); 
		}
		bool search(string s){
			Node* temp=head;
			while(temp!=NULL){
				if(s.compare(temp->data)==0)return true;
				temp=temp->next;
		}
			return false;
		}
		void replace(string s,string s1){
			Node* temp=head;
			while(temp!=NULL){
			if(s.compare(temp->data)==0){
				temp->data=s1;
				break;
			}
			temp=temp->next;
			}
		}
		void recreate(string fileName){
			fstream file;
			Node* temp;
			temp=head;
			file.open(fileName.c_str(),ios::in);
			remove(fileName.c_str());
			file.open(fileName.c_str(),ios::in);
			file.close();
			file.open(fileName.c_str(),ios::out);
			while(temp!=NULL){
				file<<temp->data+"\n";
				temp=temp->next;
			}
			file.close();
			return;
		}
		void del(int n){
			Node *temp=head;
			int i=1;
			while(temp!=NULL&&i<n){
				i++;
				temp=temp->next;
			}
			cout<<temp->data;
			if(head==temp)
				head=temp->next;
			if(temp->prev!=NULL)
				temp->prev->next=temp->next;
			if(temp->next!=NULL)
				temp->next->prev=temp->prev;
		}
		string copy(int n){
			Node *temp=head;
			int i=1;
			while(temp!=NULL&&i<n){
				i++;
				temp=temp->next;
			}
			return temp->data;
		}
};
