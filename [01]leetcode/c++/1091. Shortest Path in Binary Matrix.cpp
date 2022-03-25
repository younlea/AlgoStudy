class Solution {
public:
    #define Q_SIZE 10000
    
    struct Queue{
        int x;
        int y;
        int count;
    }myQueue[Q_SIZE];
    
    int front = 0;
    int tail = 0;
    
    void initQueue(void) {
        front = tail = 0;
    }
    
    bool isQueuIsFull(void) {
        return ((tail+1)%Q_SIZE) == front;
    }
    
    int enqueue(Queue input) {
        if(isQueuIsFull())
        {
            cout<<"queue is full" << endl; 
            return -1;
        }
        
        myQueue[(tail++)%Q_SIZE]= input;
        return 1;
    }
    
    bool isQueueIsEmpty() {
        return tail == front;
    }
    
    Queue deQueue(void) {
        struct Queue tmp;
        tmp.x = 0;
        tmp.y = 0;
        tmp.count = -1;
        
        if(isQueueIsEmpty())
        {
            cout << "queue is emtpy";    
        }
        return myQueue[(front++)%Q_SIZE];        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        initQueue();
        
        struct Queue tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.count = 1;
        enQueue
        return 1;
    }
};