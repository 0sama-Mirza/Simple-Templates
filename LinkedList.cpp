//Write and function to find out whether the given data exists or not in the linked list.
#include<iostream>

template<class T>
class Node{
    template<class U>
    friend class List;
    private:
        T data;
        Node *next,*back;
    public:
        void set_data(int value) {this->data=value; }
        T Get_Data() {return this->data; }
};

template<class U>
class List{
    private:
        Node<U> *head,*tail,*current;
        int position;
    public:
        List<U>() {head=NULL;tail=NULL; }
        //Adds Nodes At the End of the List
        void add_link(U value){
            //This is declaring an object of type Node Dynamically.
            Node<U> *temp=new Node<U>;
            temp->set_data(value);
            //As we are only going to create a new node as the question demands the next
            //Pointer will always point to NULL.
            if(head==NULL){
                this->head=temp;
                this->tail=temp;
                this->current=temp;
                temp->next=NULL;
                temp->back=NULL;
            }
            else{
                tail->next=temp;
                temp->back=tail;
                this->tail=temp;
                this->current=temp;
            }
        }
        //Deletes the Nodes at the end of the list. The Function Which the Question Asked.
        void remove_from_tail(){
            std::cout<<"\nRemoving An Element From The Tail........\n";
            tail=tail->back;
            delete tail->next;
            tail->next=NULL;

        }
        bool find(U value){
            current=head;
            position=0;
            while(current!=tail){
                if(current->data==value){
                    return true;
                }
                current=current->next;
                position++;    
            }
            if(current->data==value)
                return true;
            else
                return false;
        }
        int get_position(){
            return position;
        }
        void print(){
            current=head;
            std::cout<<"[";
            while(current->next!=NULL){
                std::cout<<current->data<<",";
                current=current->next;
            }
            std::cout<<current->data<<"]";
        }
        int count(){
            int counter=0;
            this->current=this->head;
            while(current!=tail){
                current=current->next;
                counter++;
            }
            return ++counter;
        }
};

int main(){
    List<int> L;
    int num;
    std::string str;
    std::cout<<"Enter Numbers into the List. Type a character to stop:\n";
    //The problem is that once the stream goes to failure state 
    //it will not accept any further inputs.
    while(std::cin>>num){
        L.add_link(num);
        std::cout<<"Printing The New List:\n";
        L.print();std::cout<<" +-->";
    }
    std::cout<<std::endl<<"Printing the List:"<<std::endl;
    L.print();
    std::cout<<"\nEnter the number you want to search: ";
//To clear the failed state stream I need to do this:
//The cin.clear() clears the error flag on cin (so that future I/O operations will work correctly),
    std::cin.clear();
    std::getline(std::cin, str);
    //And this.
    std::cin>>num;
    if(L.find(num))
        std::cout<<"The Number "<<num<<" does exist at index : "<<L.get_position()<<std::endl;
    else
        std::cout<<"The Number "<<num<<" does not exist.\n";
        
    return 0;
}