#include<iostream>
#include<string>
using namespace std;

template<class T>
class node{
    template<typename U>
    friend class queue;
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
template<class Q>
class queue{
    private:
        node<Q>* front;
        node<Q>* rear;
        node<Q>* current;
        int count;
    public:
        queue(){
            front=NULL;
            rear=NULL;
        }
        void Enqueue(Q value){
            node<Q>* temp=new node<Q>;
            temp->SetData(value);
            if(front==NULL){
                temp->SetNext(NULL);
                front=temp;
                rear=temp;
            }
            else{
                rear->SetNext(temp);
                rear=temp;
            }
            count++;
        }
        void Dequeue(){
            if(!IsEmpty()){
                current=front->GetNext();
                delete front;
                front=current;
                count--;
            }
            else{
                cout<<endl<<"The Queue is empty."<<endl;
            }
        }
        bool IsEmpty(){
            if(front==NULL)
                return true;
            else
                return false;
        }
        int size(){
            return count;
        }        
        void print(){
            cout<<endl<<"\t[";
            current=front;
            while(current!=rear){
                cout<<current->GetData()<<",";
                current=current->next;
            }
            cout<<current->GetData()<<"]"<<endl<<"\t ^"<<endl;
        }
};