//making a queue
typedef struct {
    int data[100];
    int front; //index of front
    int rear;  //index of back
    int size;  //not technically necessary, but added for the sake of some stack operations
} Queue;

//initializes
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear] = x; //puts data on rear index
    q->rear = (q->rear + 1); //moves rear index up one
    q->size++; //size up
}
// removes from front
int dequeue(Queue* q) {
    if (q->size == 0)
        return -1; // underflow
    int x = q->data[q->front];
    q->front = (q->front + 1);
    q->size--;
    return x;
}

// returns front
int frontQueue(Queue* q) {
    return q->data[q->front]; //returns front
}


typedef struct {
    Queue q1; //important queue
    Queue q2; //temporary queue
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    //Stores in q1
    enqueue(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
    //move everything except last object to q2
    while (obj->q1.size > 1) {
        //remove from q1
        int temp = dequeue(&obj->q1);
        //put in q2
        enqueue(&obj->q2, temp);
    }
    //last element in q1 is the top of the stack so you can get rid of it
    int popped = dequeue(&obj->q1);
    //switch q1 and q2
    Queue tempq = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tempq;
    //q1 now has its last element (top of stack) removed
    return popped;
}

int myStackTop(MyStack* obj) {
    //exactly the same as pop just not removing
    while (obj->q1.size > 1) {
        int temp = dequeue(&obj->q1);
        enqueue(&obj->q2, temp);
    }
    int topElement = frontQueue(&obj->q1);
    enqueue(&obj->q2, dequeue(&obj->q1));
    Queue tempq = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tempq;
    return topElement;
}

bool myStackEmpty(MyStack* obj) {
    //there's never anything in q2 so you don't have to check it
    return (obj->q1.size == 0);
}

void myStackFree(MyStack* obj) {
    //uh huh
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
