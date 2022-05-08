class Solution {
public:

    int nthSuperUglyNumber(int n, vector<int>& primes) {
    //n번째까지 모두 구해야 답을 구할수 있음. 
    //1. primes 값들을 최대값까지 모두 나열한다.       
    //2. n번째 값을 찾아 낸다. 
    
    //     1 <= n <= 105
    // 1 <= primes.length <= 100
    // 2 <= primes[i] <= 1000
    // primes[i] is guaranteed to be a prime number.
    // All the values of primes are unique and sorted in ascending order.
    
    // 각 primes number의 배수를 이용해서 다음 max값을 저장해 놓고 n 증가할때마다 다음 최대값을 처리 한다.
    // heap을 이용해서 처리한다. 
    // 값을 뽑고 heap에 다시 넣고를 반복.. 
    // heap에 넣을때는 ori primes number와 몇번 곱했는지와 현재 값을 저장.
    // heap은 최소값을 빼는걸로 정한다. 


    }
};