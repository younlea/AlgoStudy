class Solution {
           
    // 1 <= n <= 105
    // 1 <= primes.length <= 100
    // 2 <= primes[i] <= 1000
    // primes[i] is guaranteed to be a prime number.
    // All the values of primes are unique and sorted in ascending order.
    
    // 각 primes number의 배수를 이용해서 다음 max값을 저장해 놓고 n 증가할때마다 다음 최대값을 처리 한다.
    // heap을 이용해서 처리한다. 
    // 값을 뽑고 heap에 다시 넣고를 반복.. 
    // heap에 넣을때는 ori primes number와 몇번 곱했는지와 현재 값을 저장.
    // heap은 최소값을 빼는걸로 정한다. 
    
public:
    
    //init heap
    struct myPrimes{
        int primesOriginalValue;
        int primesCurrentValue;
        int count;
    };

    struct compare {
        bool operator()(const myPrimes& p1, const myPrimes& p2) {
            return p1.primesCurrentValue > p2.primesCurrentValue;
        }
    };

    priority_queue<myPrimes, vector<myPrimes>, compare> mq;
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int ret = 0;
        
        vector <myPrimes> usePrimes;

        for(int i = 0; i < primes.size(); i++)
        {
            myPrimes tmp;
            tmp.primesOriginalValue = primes[i];
            tmp.primesCurrentValue = primes[i];
            tmp.count = 1;
            usePrimes.push_back(tmp);
            
            mq.push(usePrimes[i]);
        }

        int backup;
        for(int cnt = 0; cnt < n; )
        {
            // top
            myPrimes tmp = mq.top();
            ret = tmp.primesCurrentValue;
            if(backup != ret)
            {
                cnt++;
                cout << tmp.primesCurrentValue << endl;
            }

            // pop
            mq.pop();
            //calc
            tmp.primesCurrentValue = tmp.primesCurrentValue * tmp.primesOriginalValue;
            tmp.count++;
            // push
            mq.push(tmp);
            
            backup = ret;
        }
        
        return ret;
    }
};