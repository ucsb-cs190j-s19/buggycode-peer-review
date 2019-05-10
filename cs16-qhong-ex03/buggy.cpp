#include <iostream>
using namespace std;

int main(){
  int n;
  double pi = 0;
  while(1){
    cout << "Enter the value of the parameter 'n' in the Leibniz formula (or -1 to quit):\n";
    cin >> n;
    if (n<0)
      break;
    for (int i=0;i<=n;i++)
      {if ((i%2)==0)
	  pi=pi+4*1.0/(2*i+1);
	if ((i%2)==1)
	  pi=pi-4*1.0/(2*i+1);
	    
      }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    if (n==0)
      cout <<"The approximate value of pi using 1 term is: " << pi << endl;
    if (n>=1)
      cout << "The approximate value of pi using "<< n+1 << " terms is: "<< pi<< endl;
  }
    
    

  return 0;
}
