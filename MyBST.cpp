//EveryThing In A BST Tree!!!!!!!!
#include<iostream>
#include<stack>

template<class T>
class Node{
    private:
        T Data;
        Node *Left,*Right;   
        int height;  
    public:
        Node(T data){
            Data=data;
            Left=NULL;
            Right=NULL;
            height=0;
        }
        Node* GetLeft() {return Left; }
        Node* GetRight() {return Right; }
        T Get_Data() {return Data; }

        void SetLeft(Node*L) {Left=L; }
        void SetRight(Node*R) {Right=R; }

        void SetValue(T data) {Data=data; }
};

template<class U>
class bst{
    private:
        Node<U>* Root,*Current;//The Current Pointer is only used for searching and displaying.
        std::stack<int>s;      
        Node<U>* add(U data,Node<U>* SubRoot){//SubRoot Pointer exists only to insert the values.
            if(Root==NULL){     //This will only run 1st time......     
                return Root = new Node<U>(data);//.....
            }                   //just to make Root pointer = first node.
            if(SubRoot==NULL){     //This Will Make a node whenever the currently selected node's                                     
                return new Node<U>(data);//Left Or Right Side becomes Empty.
            }
            else if(data<SubRoot->Get_Data()){   //This will move our SubRoot Pointer to the left if 
                SubRoot->SetLeft(add(data,SubRoot->GetLeft()));//The Value inserted is less then the subroot.
            }
            else if(data>SubRoot->Get_Data()){//if The Value inserted is more then the subroot.
                SubRoot->SetRight(add(data,SubRoot->GetRight()));//This will move our SubRoot Pointer to the right
            }              //This Function will return the left or right side of the pointer's value
            else{
                // std::cout<<"Value Already Added!   ID: "<<id<<std::endl;
                return SubRoot;
            }                                                 
            int BF=Get_Balance_Factor(SubRoot);
            // std::cout<<"Balance Factor Of "<<SubRoot->Get_Data()<<": "<<BF<<std::endl;
            if(BF>1&&SubRoot->GetLeft()->Get_Data()>data){ //LL ImBalance
                // std::cout<<"LL"<<std::endl;
                return RightRotation(SubRoot);
            }
            if(BF<-1&&SubRoot->GetRight()->Get_Data()<data){ //RR ImBalance
                // std::cout<<"RR"<<std::endl;
                return LeftRotation(SubRoot);
            }
            if(BF>1&&SubRoot->GetLeft()->Get_Data()<data){ //LR ImBalance
                SubRoot->SetLeft(LeftRotation(SubRoot->GetLeft()));
                // std::cout<<"LR"<<std::endl;
                return RightRotation(SubRoot);
            }
            if(BF<-1&&SubRoot->GetRight()->Get_Data()>data){//RL ImBalance
                SubRoot->SetRight(RightRotation(SubRoot->GetRight()));
                // std::cout<<"RL"<<std::endl;
                return LeftRotation(SubRoot);
            }
            return SubRoot;
        }

        Node<U>* RightRotation(Node<U>* SubRoot){
            Node<U>* Temp=SubRoot->GetLeft();
            SubRoot->SetLeft(SubRoot->GetLeft()->GetRight());
            Temp->SetRight(SubRoot);
            if(SubRoot==Root)
                Root=Temp;
            return Temp;
        }

        Node<U>* LeftRotation(Node<U>* SubRoot){
            Node<U>* Temp=SubRoot->GetRight();
            // std::cout<<"Value Of Temp: "<<Temp->Get_Data()<<std::endl;
            SubRoot->SetRight(SubRoot->GetRight()->GetLeft());
            Temp->SetLeft(SubRoot);
            if(SubRoot==Root)
                Root=Temp;
            return Temp;
        }
        void inorderrr(Node<U>* t){
            if(t==NULL)
                return;
            inorderrr(t->GetLeft());
            std::cout<<t->Get_Data()<<std::endl;
            inorderrr(t->GetRight());
        }
        void prr(Node<U>* t){
            if(t==NULL)
                return;
            prr(t->GetRight());
            std::cout<<t->Get_Data()<<std::endl;
            prr(t->GetLeft());
            
        }
        void post(Node<U>* t){
            if(t==NULL)
                return;
            std::cout<<t->Get_Data()<<std::endl;
            prr(t->GetLeft());
            prr(t->GetRight());
        }
        Node<U>* minn(Node<U>* t){
            if(t==NULL)
                return NULL;
            else if(t->GetLeft()==NULL)
                return t;
            else
                return minn(t->GetLeft());
        }
        Node<U>* maxx(Node<U>* t){
            if(t==NULL)
                return NULL;
            else if(t->GetRight()==NULL)
                return t;
            else
                return maxx(t->GetRight());
        }
        Node<U>* Searchh(Node<U>* SubRoot,U value){
            if(SubRoot==NULL)
                return NULL;
            if(SubRoot->Get_Data()==value)
                return SubRoot;
            if(SubRoot->Get_Data()>value)
                return Searchh(SubRoot->GetLeft(),value);
            return Searchh(SubRoot->GetRight(),value);
        }
        int counter(Node<U>* SubRoot){
            if(SubRoot==NULL)
                return 0;
            return counter(SubRoot->GetLeft())+counter(SubRoot->GetRight())+1;
        }
        int TotalDepth(Node<U>* SubRoot){
            if(SubRoot==NULL)
                return 0;
            int LeftHight=TotalDepth(SubRoot->GetLeft());
            int RightHight=TotalDepth(SubRoot->GetRight());
            return std::max(LeftHight,RightHight)+1;
        }
        int Get_Balance_Factor(Node<U> *SubRoot){
            if(SubRoot==NULL)
                return 0;
            else
                return (TotalDepth(SubRoot->GetLeft())-TotalDepth(SubRoot->GetRight()));
        }
        Node<U>* Khatm(Node<U>*SubRoot,U v){
            if(v<SubRoot->Get_Data())
                SubRoot->SetLeft(Khatm(SubRoot->GetLeft(),v));
            else if(v>SubRoot->Get_Data())
                SubRoot->SetRight(Khatm(SubRoot->GetRight(),v));
            else{
                if(SubRoot->GetLeft()==NULL){//If It has One Child at Left.
                    Node<U>* Temp=SubRoot->GetRight();
                    delete SubRoot;
                    return Temp;
                }
                if(SubRoot->GetRight()==NULL){//If It has One Child at Right.
                    Node<U>* Temp=SubRoot->GetLeft();
                    delete SubRoot;
                    return Temp;
                }
            Node<U>* Temp= minn(SubRoot->GetRight());
            SubRoot->SetValue(Temp->Get_Data());
            SubRoot->SetRight(Khatm(SubRoot->GetRight(),Temp->Get_Data()));
            }
            s.pop();
            return SubRoot;
        }

    public:
        bst(){
            Root=NULL;
        }
        void insert(U data){
            s.push(data);
            add(data,Root);
        }
        void Search(int v){
            if(Searchh(Root,v)==NULL){
                std::cout<<"This Value Doesnot exist."<<std::endl;
            }
            else
                std::cout<<"Value "<<v<<" Found!"<<std::endl;
        }
        void Del(U v){
            Khatm(Root,v);
            std::cout<<"\n.......Data "<<v<< " Deleted......"<<std::endl;
        }
        U LastElement() {return s.top(); }
        void Inorder() {inorderrr(Root); }
        void PreOrder() {prr(Root); }
        void PostOrder() {post(Root); }
        int count() {return counter(Root); }
        U minvalue() {return minn(Root)->Get_Data(); }
        U maxvalue() {return maxx(Root)->Get_Data(); }
        int Depth() {return Get_Balance_Factor(Root); }
        U RootValue() {return Root->Get_Data(); }
};

int main(){
    bst<int>a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.Inorder();
    std::cout<<std::endl;
    a.PreOrder();
    std::cout<<std::endl;
    a.PostOrder();
    std::cout<<std::endl;
    std::cout<<"Root Value: "<<a.RootValue()<<std::endl;
    return 0;
}
