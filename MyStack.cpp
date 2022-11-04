#include<iostream>
#include<string>
using namespace std;

template<class T>
class node{
    template<typename U>
    friend class stack;
    private:
        node* next;
        T data;
    public:
        node<T> *GetNext(){
            return next;
        }
        T GetData(){
            return data;
        }
        void SetNext(node<T> *a){
            next=a;
        }
        void SetData(T a){
            data=a;
        }
};

template<typename A>
class stack{
    private:
        node<A>* top;
        node<A>* current;
        int count;
    public:
        stack<A>(){
            top=NULL;
            current=NULL;
            count=0;
        }
        void insert(A value){
            node<A>* temp=new node<A>;
            temp->SetData(value);
            if(top==NULL){
                temp->SetNext(NULL);
                top=temp;
            }
            else{
                temp->SetNext(top);
                top=temp;
            }
            count++;
        }
        void del(){
            current=top->next;
            delete top;
            top=current;
            count--;
        }
        bool IsEmpty(){
            if(top==NULL)
                return true;
            else
                return false;
        }
        void print(){
            if(IsEmpty())
                cout<<"";
            else{
                current=top;
                cout<<"|";
                while(current->next!=NULL){
                    cout<<current->data<<"|"<<endl<<"|";
                    current=current->next;
                }
                cout<<current->data<<"|"<<endl;
            }
        }
        int size(){
            return count;
        }
        A gettop(){
            return top->GetData();
        }
        void Display_Options(){
            abc:
            cout<<"Select from the following options:\n1) Insert data.\n2) Print Stack\n3) Delete Data\n4) Quit"<<endl;
            int option;
            cin>>option;
            while(option!=4){
                switch (option){
                case 1:{
                    A num;
                    char op='y';
                    while(true){
                        cout<<"Enter Data into the Stack:\n";
                        cin>>num;
                        insert(num);
                        print();
                        cout<<"\n:";
                        cout<<endl<<"Continue?(Y/N)?: ";
                        cin>>op;
                        if(op=='N'||op=='n')
                            break;
                    }
                };
                    break;
                case 2:
                    if(!IsEmpty()){
                        cout<<"-----------"<<endl;
                        print();
                        cout<<"-----------"<<endl;
                    }
                    else
                        cout<<"The Stack is Empty Broooooooo!"<<endl;
                    break;
                case 3:
                    if(!IsEmpty())
                        del();
                    else
                        cout<<"The Stack is Empty Brooooooo!"<<endl;
                    break;
                default:
                    cout<< "Your selection must be between 1 and 4!\n";
                }
                goto abc;
            }
        }
};


