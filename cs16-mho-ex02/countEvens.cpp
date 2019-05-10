#include <iostream>

using namespace std;

bool isEven(int x){
	return !(x % 2)
}

int countEven(int arr[]){
	int num_of_evens = 0;	
	for(int i = arr[1]; i <= arr[6]; i++){
		num_of_evens += 1;
		return num_of_evens;
	}
}

int main(){
	int arr[6] = {1, 2, 3, 4, 5, 1};
	cout << countEven(arr) << endl;
}
