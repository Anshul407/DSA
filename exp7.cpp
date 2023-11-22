#include<iostream>
using namespace std;
class CQueue{
    public:
    int *arr;
    
    int size;
    int front;
    int rear;
    CQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
    bool enqueue(int value){
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1))){
            return 0;
        }
        else if(front ==-1){
            front=rear=0;
            arr[front]=value;
        }
        else if(rear==size-1&&front!=0){
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
        return 1;
    }
    int dequeue()
    {
        if(front==-1){
           return -1;
        }
        int ans=arr[front];
        if(front==rear){
            front =rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front ++;
        }
        return ans;
    }

};
int main(int argc, char const *argv[])
{
    /* code */
    CQueue *c=new CQueue(10);
    c->enqueue(10387);
    c->enqueue(10);
    c->enqueue(10);
    c->enqueue(13890);
    int x=c->dequeue();
    cout<<x;
    return 0;
}

