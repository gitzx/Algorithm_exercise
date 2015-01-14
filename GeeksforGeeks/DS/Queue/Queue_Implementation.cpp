/*
(1)enQueue()
(2)deQueue()
*/

#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

//using array to implement queue
struct Queue{
    int front,rear,size;
    int capacity;
    int* array;
};
class Solution1{
public:
    Queue* createQueue(unsigned capacity){
        Queue* queue=(Queue*)malloc(sizeof(Queue));
        queue->capacity=capacity;
        queue->front=queue->size=0;
        queue->rear=capacity-1;
        queue->array=(int*)malloc(queue->capacity*sizeof(int));
        return queue;
    }
    bool isFull(Queue* queue){
        return queue->size==queue->capacity;
    }
    bool isEmpty(Queue* queue){
        return queue->size==0;
    }
    void enqueue(Queue* queue,int item){
        if(isFull(queue)){
            return;
        }
        queue->rear=(queue->rear+1)%queue->capacity;
        queue->array[queue->rear]=item;
        queue->size=queue->size+1;
        cout<<"enqueued:"<<item<<endl;
    }
    int dequeue(Queue* queue){
        if(isEmpty(queue)){
            return INT_MIN;
        }
        int item=queue->array[queue->front];
        queue->front=(queue->front+1)%queue->capacity;
        queue->size=queue->size-1;
        return item;
    }
    int front(Queue* queue){
        if(isEmpty(queue)){
            return INT_MIN;
        }
        return queue->array[queue->front];
    }
    int rear(Queue* queue){
        if(isEmpty(queue)){
            return INT_MIN;
        }
        return queue->array[queue->rear];
    }
};

//using linked list to impelement queue
struct QNode{
    int val;
    QNode *next;
};
struct Queue_L{
    QNode *front,*rear;
};

class Solution2{
public:
    QNode* newNode(int data){
        QNode *node=(QNode*)malloc(sizeof(QNode));
        node->val=data;
        node->next=NULL;
        return node;
    }
    Queue_L* createQueue(){
        Queue_L* queue=(Queue_L*)malloc(sizeof(Queue));
        queue->front=queue->rear=NULL;
        return queue;
    }
    void enQueue(Queue_L* queue, int k){
        QNode *node=newNode(k);
        if(queue->rear==NULL){
            queue->front=queue->rear=node;
            return;
        }
        queue->rear->next=node;
        queue->rear=node;
    }

    QNode *deQueue(Queue_L *queue){
        if(queue->front==NULL){
            return NULL;
        }
        QNode *node=queue->front;
        queue->front=queue->front->next;
        if(queue->front==NULL){
            queue->rear=NULL;
        }
        return node;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    Queue *queue=solution1.createQueue(100);
    solution1.enqueue(queue,10);
    solution1.enqueue(queue,20);
    solution1.enqueue(queue,30);
    solution1.enqueue(queue,40);
    cout<<"dequeued:"<<solution1.dequeue(queue)<<endl;
    cout<<solution1.front(queue)<<endl;
    cout<<solution1.rear(queue)<<endl;

    Queue_L *queue_l=solution2.createQueue();
    solution2.enQueue(queue_l,10);
    solution2.enQueue(queue_l,20);
    solution2.deQueue(queue_l);
    solution2.deQueue(queue_l);
    solution2.enQueue(queue_l,30);
    solution2.enQueue(queue_l,40);
    solution2.enQueue(queue_l,50);
    QNode *node=solution2.deQueue(queue_l);
    cout<<"solution2 dequeued:"<<node->val<<endl;
    return 0;
}

/*
enqueued:10
enqueued:20
enqueued:30
enqueued:40
dequeued:10
20
40
solution2 dequeued:30
*/
