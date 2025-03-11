


typedef struct {
    int stack1[100];// the input stack
    int stack1top; // next free index
    int stack2[100]; //output stack
    int stack2top; //next free index
} MyQueue;


MyQueue* myQueueCreate() {
    //clears memory for queue
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    //sets initial indexes of both stacks to 0
    queue->stack1top = 0;
    queue->stack2top = 0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    //adds object to stack1
    obj->stack1[obj->stack1top++] = x;
}

int myQueuePop(MyQueue* obj) {
    //if stack2 is empty moves all objects to it, this will essentially flip the stack, turning it into a queue
    if (obj->stack2top == 0) {
        while (obj->stack1top > 0) {
            //takes it out of stack1 and puts it in stack2
            obj->stack2[obj->stack2top++] = obj->stack1[--obj->stack1top];
        }
    }
    //pops from stack2
    return obj->stack2[--obj->stack2top];
}

int myQueuePeek(MyQueue* obj) {
    //this is copy pasted from queuepop
    if (obj->stack2top == 0) {
        while (obj->stack1top > 0) {
            obj->stack2[obj->stack2top++] = obj->stack1[--obj->stack1top];
        }
    }
    //returns the object at the top of the stack
    return obj->stack2[obj->stack2top - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    //If the stacks are empty the queue is too
    return (obj->stack1top == 0 && obj->stack2top == 0);
}

void myQueueFree(MyQueue* obj) {
    //take 3 guesses
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
