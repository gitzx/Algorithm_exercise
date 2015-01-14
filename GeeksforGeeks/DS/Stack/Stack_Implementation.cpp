//basic operations:
//push:add an item in the stack;
//pop:remove an item from the stack;
//peek:get the topmost item

#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

//using array to implement a stack
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

class Solution1{
public:
    Stack* createStack(unsigned capacity){
        Stack* stack=(Stack*)malloc(sizeof(Stack));
        stack->capacity=capacity;
        stack->top=-1;
        stack->array=(int*)malloc(stack->capacity*sizeof(int));
        return stack;
    }
    bool isFull(Stack* stack){
        return stack->top==stack->capacity-1;
    }
    bool isEmpty(Stack* stack){
        return stack->top==-1;
    }
    void push(Stack* stack, int item){
        if(isFull(stack)){
            return;
        }
        stack->array[++stack->top]=item;
        cout<<"pushed:"<<item<<endl;
    }
    int pop(Stack* stack){
        if(isEmpty(stack)){
            return INT_MIN;
        }
        return stack->array[stack->top--];
    }
    int peek(Stack* stack){
        if(isEmpty(stack)){
            return INT_MIN;
        }
        return stack->array[stack->top];
    }
};

//using linked list to implement a stack
struct StackNode{
    int data;
    StackNode* next;
};

class Solution2{
public:
    StackNode* newNode(int data){
        StackNode* stackNode=(StackNode*)malloc(sizeof(StackNode));
        stackNode->data=data;
        stackNode->next=NULL;
        return stackNode;
    }
    bool isEmpty(StackNode *root){
        return !root;
    }
    void push(StackNode **root,int data){
        StackNode* stackNode=newNode(data);
        stackNode->next=*root;
        *root=stackNode;
        cout<<"Pushed:"<<data<<endl;
    }
    int pop(StackNode** root){
        if(isEmpty(*root)){
            return INT_MIN;
        }
        StackNode* temp=*root;
        *root=(*root)->next;
        int popped=temp->data;
        free(temp);
        return popped;
    }
    int peek(StackNode *root){
        if(isEmpty(root)){
            return INT_MIN;
        }
        return root->data;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    Stack *stack=solution1.createStack(100);
    solution1.push(stack,10);
    solution1.push(stack,20);
    solution1.push(stack,30);
    cout<<solution1.pop(stack)<<endl;
    cout<<solution1.peek(stack)<<endl;

    StackNode* root=NULL;
    solution2.push(&root,10);
    solution2.push(&root,20);
    solution2.push(&root,30);
    cout<<solution2.pop(&root)<<endl;
    cout<<solution2.peek(root)<<endl;
    return 0;
}
/*
pushed:10
pushed:20
pushed:30
30
20
Pushed:10
Pushed:20
Pushed:30
30
20
*/
