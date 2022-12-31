#include<iostream>
using namespace std;
class node{
    friend class list;
    private:
        node* back;
        node* next;
        int data;
    public:
        void setdata(int a){
            data=a;
        }
        int getdata(){
            return this->data;
        }
};
class list{
    private:
        node* head;
        node* tail;
        node*current;
        node*currrrr; //To store the actual previous state of the current pointer.
        int index;    //To store the position of where the counter was in an arry form.
        int counter;  //To store the size of the List. Used in back function to make index=counter
        int space;    //To store the spaces required to print out '^'
    public:
        list(){
            head=NULL;
            index=0;
            counter=0;
            space=0;
        }
        void insert (int a){
            node* temp= new node;
            if (head==NULL){
                temp->setdata(a);
                this->head=temp;
                this->tail=temp;
                temp->back=this->head;
                temp->next=this->tail;
                counter++;
            }
            else{
                temp->setdata(a);
                tail->next=temp;
                temp->back=tail;
                tail=temp;
                tail->next=head;
                head->back=tail;
                counter++;
            }
        }
        void print(){
            current=head;
            cout<<"[";
            while(current!=tail){
                cout<<current->data<<",";
                current=current->next;
            }
            cout<<current->data<<"]";
        }
        //The following functions are only used for calculating the spaces required
        //to print out ^ character to the selected number.
        int Length_Of_Number(int num){//This calculates the length of a number
            int count=0;
            while(num>=10){
                num=num/10;
                ++count;
            }
            return ++count;
        }
        int spaces(){//This calculates the number of spaces required.
            current=head;
            while(current!=currrrr){
                space=space+Length_Of_Number(current->data);
                current=current->next;
            }
            return space+index;
        }
        void print_position(){//This Prints out the '^' to point out to the currently selected number
            currrrr=current;
            print();
            cout<<endl;
            int comeone= spaces();
            for(int i=0;i<=comeone;i++){
                cout<<" ";
            }
            cout<<"^\n-----------------------"<<endl;
            current=currrrr;
            space=0;
        }
        //End of Calculating spaces Function
        void forward(){
            if(current==tail){
                index=0;
                current=current->next;
                cout<<"----------------------\nPosition: "<<index;
                cout<<"\nData: "<<current->getdata()<<endl;
            }
            else{
                current=current->next;
                index=index+1;
                cout<<"----------------------\nPosition: "<<index;
                cout<<"\nData: "<<current->getdata()<<endl;
            }
            print_position();
        }
        void back(){
            if(current==head){
                index=counter;
                current=head->back;
                index=index-1;
                cout<<"----------------------\nPosition: "<<index;
                cout<<"\nData: "<<current->getdata()<<endl;
            }
            else{
                current=current->back;
                index=index-1;
                cout<<"----------------------\nPosition: "<<index;
                cout<<"\nData: "<<current->getdata()<<endl;
            }
            print_position();
        }
        void del(){
            if(tail==current){
                tail=current->back;
                index=0;
            }
            if(head==current)
                head=current->next;
            current->next->back=current->back;
            current->back->next=current->next;
            currrrr=current->next;
            delete current;
            current=currrrr;
        }
        void del(int pos){
            current=head;
            for(int i=1;i<=pos;i++)
                current=current->next;
            del();
        }
        bool isempty(){
            if (head==NULL)
                return true;
            else
                return false;
        }
        void Display_List_Options(){
            abc:
            cout<<"Select from the following options:\n1) Insert data.\n2) Change Currently Selected Data(Forward/Backwards)?\n3) Print the list\n4) Delete item\n5) Quit"<<endl;
            int option;
            cin>>option;
            while(option!=5){
                switch (option){
                case 1:{
                    int num;
                    string str;
                    cout<<"Enter Numbers into the List. Type a character to stop:\n";
                    while(cin>>num){
                        insert(num);
                        cout<<"Printing The New List:\n";
                        print();
                        cout<<" +-->";
                    }
                    cin.clear();
                    getline(cin, str);
                };
                    break;
                case 2:{
                    if(isempty()){
                        cout<<"The List is Empty Broooooooo!"<<endl;
                        break;
                    }
                    cout<<"\nF = Forward\nB = Backwards.\nAny other character = exit\n";
                    char op='o';
                    while (op!='n'){
                        cin>>op;
                        if(op=='F'||op=='f')
                            forward();
                        else if(op=='B'||op=='b')
                            back();
                    }
                    break;
                }
                case 3:
                    if(!isempty())
                        print_position();
                    else
                        cout<<"The List is Empty Broooooooo!"<<endl;
                    break;
                case 4:
                    if(isempty()){
                        cout<<"The List is Empty Broooooooo!"<<endl;
                        break;
                    }
                    char op;
                    cout<<"Delete from currently selected data(D) or from an index(I)?: ";
                    cin>>op;
                    if(op=='D'||op=='d')
                        del();
                    else if(op=='I'||op=='i'){
                        cout<<"Enter Index";
                        int i;
                        cin>>i;
                        del(i);
                    }
                    else
                        cout<<"Incorrent option. Try Again."<<endl;
                    break;
                default:
                    cout<< "Your selection must be between 1 and 5!\n";
                }
                goto abc;
            }
        }

};
int main(){
    list L;
    cout<<"This is a circular list."<<endl;
    L.Display_List_Options();
    return 0;
}
