#include <iostream>
using namespace std;

#define HEAPSIZE 1500

struct pq{
     int heapCnt = 0;
     int heap[HEAPSIZE] = {0, };

     /*
               [1]           자식 -> 부모 n/2 
          [2]      [3]       (2n, 2n+1)
          [4]  [5] [6]   [7]

     */
     void myswap(int * a, int *b)
     {
          int tmp = *a;
          *a = *b;
          *b = tmp;
     }

     void push(int data)
     {
          int cur = heapCnt;
          heap[heapCnt++] = data;
          while(cur > 0)
          {
               int parent = (cur -1) / 2;
               if(heap[parent] > heap[cur])
               {
                    myswap(&heap[parent], &heap[cur]);
               }else
               {
                    break;
               }
               cur = parent;
          }
     }

     int pop(void)
     {
          int ret = heap[0];
          heap[0] = heap[--heapCnt];
          
          int cur = 0;
          while(2*cur + 2 <=heapCnt)
          {
               int l = 2*cur +1;
               int r = 2*cur +2;
               int nxt = heap[l] < heap[r]? l: r;

               if(heap[nxt] < heap [cur])
               {
                    myswap(&heap[nxt], &heap[cur]);
                    cur = nxt;
               }
               else
               {
                    break;
               }
          }

          return ret;
     }
};



int main()
{
     pq test;
     for(int i = 100; i > 0; i--)
       test.push(i);

     for(int i = 0; i < 100; i++)
          cout << test.pop() << endl;
     
     return 0;
}
