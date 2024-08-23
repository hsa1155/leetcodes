#include"bits/stdc++.h"
using namespace std;

class MyLinkedList {
private:
int val=-69;
MyLinkedList* next=nullptr;
MyLinkedList* prev=nullptr;

public:

    

    MyLinkedList() {
        //cout<<"create node"<<this->val<<endl;
        
    }
    MyLinkedList(int val,MyLinkedList* next,MyLinkedList* prev) {
        this->val=val;
        this->next=next;
        this->prev=prev;
        //cout<<"create node"<<this->val<<endl;
    }
    
    void travel()
    {
        /*
        MyLinkedList* current_ptr=this;
        while(1)
        {
            cout<<current_ptr->val<<" ";
            if(current_ptr->next!=nullptr)
            {
                current_ptr=current_ptr->next;
            }
            else
            {
                break;
            }
        }


        cout<<endl;

        cout<<"prevs"<<endl;
        current_ptr=this;
        while(1)
        {
            if(current_ptr->prev!=nullptr)   cout<<current_ptr->prev->val<<" ";
            if(current_ptr->next!=nullptr)
            {
                current_ptr=current_ptr->next;
            }
            else
            {
                break;
            }
        }
        cout<<endl;
        */
        
    }


    int get(int index) {
        MyLinkedList* current_ptr=this;

        cout<<"start get, cur="<<current_ptr->val<<endl;
        if(this->val==-69)
        {
            cout<<"end get and get nothing"<<endl;
            return -1;
        }
        for(int i=0;i<index;i++)
        {
            if(current_ptr->next!=nullptr)
            {
                cout<<current_ptr->val<<" ";
                current_ptr=current_ptr->next;
                
            }
            else
            {
                cout<<"end get and get nothing"<<endl;
                travel();
                return -1;
            }
        }
        cout<<endl;

        cout<<"end get"<<endl;
        travel();
        return current_ptr->val;
        
    }
    
    void addAtHead(int val) {

//note very bad behavoir
        if(this->val==-69)
        {
            this->val=val;
            cout<<"end head"<<endl;
            travel();
            return;
        }


        MyLinkedList* oldhead=new MyLinkedList(this->val,this->next,this);

        this->next=oldhead;
        this->val=val;
        this->prev=nullptr;
        if(this->next->next!=nullptr)   
        {
            this->next->next->prev=oldhead;
        }     

        cout<<"end head"<<endl;
        travel();
    }
    
    void addAtTail(int val) {
        MyLinkedList* current_ptr=this;

        if(this->val==-69)
        {
            addAtHead(val);
            cout<<"end tail"<<endl;
            travel();
            return;
        }

        while(1)
        {
            if(current_ptr->next!=nullptr)
            {
                current_ptr=current_ptr->next;
            }
            else
            {
                break;
            }
        }
        //cout<<endl;
        MyLinkedList* newnode=new MyLinkedList(val,nullptr,current_ptr);
        current_ptr->next=newnode;

        cout<<"end tail"<<endl;
        travel();
        
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* current_ptr=this;
        //cout<<"start of addat"<<endl;

        if(index==0)
        {
            addAtHead(val);
            cout<<"end addat"<<endl;
        }

        for(int i=0;i<index;i++)
        {

            if(current_ptr->next!=nullptr)
            {
                 //cout<<current_ptr->val<<" ";
                current_ptr=current_ptr->next;
            }
            else if(i==index-1)
            {
                MyLinkedList* newnode=new MyLinkedList(val,nullptr,current_ptr);
                current_ptr->next=newnode;
                cout<<"end addat"<<endl;
                travel();

                return;//very very bad
            }
            else
            {
                cout<<"end addat"<<"i="<<i<<endl;
        travel();
                return ;
            }
        }
        //cout<<"current"<<current_ptr->val<<endl;
        MyLinkedList* newnode=new MyLinkedList(val,current_ptr,current_ptr->prev);
        if(current_ptr->prev!=nullptr)
        {
            current_ptr->prev->next=newnode;
        }
        current_ptr->prev=newnode;

        current_ptr=this;
        ////cout<<"test add at"<<endl;


        cout<<"end addat"<<endl;
        travel();
        
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList* current_ptr=this;
        if(index==0)
        {
            if(this->next!=nullptr)
            {
                this->val=this->next->val;
                this->prev=nullptr;
                this->next=this->next->next;
                cout<<"end delete"<<endl;
                travel();
                return ;
            }
            else
            {
                this->next=nullptr;
                this->val=-69;
                this->prev=nullptr;
                cout<<"delete everything!!! nothing left"<<endl;
                return ;
            }
        }

        for(int i=0;i<index;i++)
        {
            if(current_ptr->next!=nullptr)
            {
                current_ptr=current_ptr->next;
            }
            else
            {

                cout<<"end delete"<<endl;
                travel();
                return ;
            }
        }

        if(current_ptr->prev!=nullptr)
        {
        cout<<"deleting"<<current_ptr->val<<endl;
        travel();
        cout<<"prev="<<current_ptr->prev->val<<endl;
        current_ptr->prev->next=current_ptr->next;
        }
        if(current_ptr->next!=nullptr)
        {
            current_ptr->next->prev=current_ptr->prev;
        }
        cout<<"end delete"<<endl;
        travel();
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */