#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class Link_Stack
{
private:
    Node* topnode;
public:
    Link_Stack():topnode{nullptr}
    {}
    ~Link_Stack()
    {
        while(topnode!=nullptr)
        {
            Node* temp=topnode;
            topnode=topnode->next;
            delete temp;
        }
    }
    void push(int &num,int &x)
    {
        Node* newnode=new Node;
        newnode->data=num;
        x=newnode->data;
        newnode->next=topnode;
        topnode=newnode;
    }
    bool gettop(int &x)
    {
        if(topnode==nullptr)
        {
            return false;
        }
        x=topnode->data;
        return true;
    }
    bool pop(int &x)
    {
        if(topnode==nullptr)
        {
            return false;
        }
        Node* temp=topnode;
        x=topnode->data;
        topnode=topnode->next;
        delete temp;
        return true;
    }
    bool isEmpty()
    {
        if(topnode==nullptr)
        {
            return true;
        }
    }
};
int main()
{
    Link_Stack stack;
    int num=0,x=0,m=0,count=0,k=0;
    cout<<"请输入一串数据(输入114514终止)";
    while(cin>>num&&num!=114514)
    {
        stack.push(num,k);
        cout<<k<<" ";
        count++;
    }
    cout<<endl<<"栈顶";
    stack.gettop(x);
    cout<<stack.gettop(x)<<" "<<x<<endl;
    cout<<"弹出"<<endl;
    for(int i=0;i<count;i++)
    {
        stack.pop(m);
        cout<<m<<endl;
    }
    return 0;
}
