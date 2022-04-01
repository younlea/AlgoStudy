class Solution {
public:
    #define Q_SIZE 1000
    
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
        // cout << "isQueueIsFull" <<endl;
        return ((tail+1)%Q_SIZE) == front;
    }
    
    int enQueue(Queue input) {
        // cout << "enQueue" <<endl;
        // cout << "input.x, input,y "<< "(" <<input.x << ","<<input.y <<")" ;
        // cout << " count   " << input.count <<endl;
        // cout << "" << endl;
        
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
        
        // cout << "deQueue" <<endl;
        
        if(isQueueIsEmpty())
        {
            cout << "queue is emtpy";    
            return tmp;
        }
        return myQueue[(front++)%Q_SIZE];        
    }
    
void myEnQueue(int x, int y, int cnt, vector<vector<int>>& grid)
{
    struct Queue temp;
    temp.x = x;
    temp.y = y;
    temp.count = cnt;
    grid[temp.x][temp.y] = 1;
    enQueue(temp);
}
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int xSize = grid.size();
        int ySize = grid[grid.size()-1].size();
        
        // cout << "xsize " << xSize << endl;
        // cout << "ysize " << ySize <<endl;
        
        initQueue();
        //start 0,0
        if(grid[0][0] == 1 || grid[xSize - 1][ySize -1] == 1 )
            return -1;
        
        //enqueue start point
        
        struct Queue tmp;
        tmp.x = 0;
        tmp.y = 0;
        tmp.count = 1;
        grid[0][0] = 1; // visited
        
        enQueue(tmp);
        int flag = 1;
        while(flag)
        {
            tmp = deQueue();
            if(tmp.count == -1 )
            {
                flag = 0;
                return -1;
            }
            int cnt = tmp.count + 1;
            
            if(tmp.x == xSize -1 && tmp.y == ySize -1)
                return tmp.count; 
            
            //check 8 direction
            if(tmp.x -1 >=0 && tmp.y-1 >=0 && grid[tmp.x-1][tmp.y-1]== 0)
                myEnQueue(tmp.x-1, tmp.y-1, tmp.count+1, grid);
            
            if(tmp.y-1 >=0 && grid[tmp.x][tmp.y-1]== 0)
                myEnQueue(tmp.x, tmp.y-1, tmp.count+1, grid);
            
            if(tmp.x+1 < xSize && tmp.y-1 >=0 && grid[tmp.x + 1][tmp.y - 1]== 0)
                myEnQueue(tmp.x+1, tmp.y-1, tmp.count+1, grid);
            
            if(tmp.x -1 >=0 && grid[tmp.x-1][tmp.y]== 0)
                myEnQueue(tmp.x-1, tmp.y, tmp.count+1, grid);
            
            if(tmp.x +1 < xSize && grid[tmp.x+1][tmp.y]== 0)
                myEnQueue(tmp.x+1, tmp.y, tmp.count+1, grid);
            
            if(tmp.x -1 >= 0 && tmp.y+1 < ySize && grid[tmp.x-1][tmp.y+1]== 0)
                myEnQueue(tmp.x-1, tmp.y+1, tmp.count+1, grid);
            
            if(tmp.y+1 < ySize && grid[tmp.x][tmp.y+1]== 0)
                myEnQueue(tmp.x, tmp.y+1, tmp.count+1, grid);
            
            if(tmp.x +1 < xSize && tmp.y+1 < ySize && grid[tmp.x+1][tmp.y+1]== 0)
                myEnQueue(tmp.x+1, tmp.y+1, tmp.count+1, grid);
 
        }
        return -1;
    }
};