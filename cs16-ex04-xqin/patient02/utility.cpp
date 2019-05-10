
bool isOdd(int x) { 
	return (x%2);
}
bool isEven(int x) 
{
	return !(x%2);	
}
bool isPrime(int x) {
    bool primeNumber = false;
	if(x == 0 || x == 1)
		primeNumber = false;

    int counter;

    for(int i = 2; i < x; i++)
    {
        if(x%i == 0)
		{
			counter++;
		}
        
        if(counter > 0)
            primeNumber = false;
    }	
    return primeNumber;
}
