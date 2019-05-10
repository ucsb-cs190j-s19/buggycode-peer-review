#include "tddFuncs.h"
#include<iostream>
using namespace std;

// should return amount of prime numbers in arr
int countPrimes(int arr[], int size);

int main() {

  int fiveThrees[5]={3,3,3,3,3};
  assertEquals(5,
	       countPrimes(fiveThrees,5),
	       "countPrimes(fiveThrees,5)");
  
  int zeros[3]={0,0,0}; // initializes all elements to 0
  assertEquals(0,
	       countPrimes(zeros,3), 
	       "countPrimes(zeros,3)" );  

  
  int fiveInts[5]={1,2,3,4,5}; 
  assertEquals(3,
	       countPrimes(fiveInts,5), 
	       "countPrimes(fiveInts,5)" ); 

  int empty[] = {};
  assertEquals(0,
	       countPrimes(empty,0), 
	       "countPrimes(empty,0)" ); 

  int primes[] = {2,3,5,7,11,13,17,19,23,29};
  assertEquals(10,
	       countPrimes(primes,10), 
	       "countPrimes(primes,10)" ); 

  int meaning[] = {42};
  assertEquals(0,
	       countPrimes(meaning,1), 
	       "countPrimes(meaning,1)" ); 

  int mix[10]={-10,-3,0,3,4,5,9,10,11,29};
  assertEquals(4,
	       countPrimes(mix,10), 
	       "countPrimes(mix,10)" );

  return 0;
}

// implementation from a CS16 student
int countPrimes(int arr[], int size){
    int count = 0;
    bool isPrime = true;
    for (int i = 0; i < size; i++){
        if (arr[i] < 2){
            count += 0;
        }
        else{
            for (int j = 2; j <= arr[i]/2; j++){
                if (arr[i] % j == 0) {
                    isPrime = false;
                }
                if (isPrime){
                    count++;
                }
            }
        }
    }
    return count;
}
