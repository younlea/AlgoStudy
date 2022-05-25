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

        int backup=0;

        if(n == 1)
            return 1;
        
        for(int cnt = 1; cnt < n; )
        {
            // top
            myPrimes tmp = mq.top();
            ret = tmp.primesCurrentValue;
            // cout << "---" << backup << " "<< ret << endl;
            if(backup != ret)
            {
  //              cout << cnt <<'.' <<tmp.primesCurrentValue << '.'<< tmp.primesOriginalValue << endl;
                cnt++;

            }

            // pop
            mq.pop();
            long long number = (long long)tmp.primesCurrentValue;
            long long value = 0;
            for(int i = 0; i < primes.size(); i++)
            {
                //calc
                value = number * primes[i];  // primes 들어온 수들끼리 곱해야 한다. 
                if(value < 2147483647)  // int 최대값을 넘어가는건 없애야 한다. 
                {
                  tmp.primesCurrentValue = (int)value; //곱하기 모든 수.. ㅋㅋㅋ
//                cout << "+++" << tmp.primesCurrentValue << " "<< tmp.primesOriginalValue<<" "<<number << " " << primes[i] <<endl;
                  tmp.count++;
                  // push  
                  //TODO 이전에 넣었던 수들은 넣지 않는다. hash를 써야 하나?
                  mq.push(tmp);
                }
            }

            backup = ret;
        }
        
        return ret;
    }
};