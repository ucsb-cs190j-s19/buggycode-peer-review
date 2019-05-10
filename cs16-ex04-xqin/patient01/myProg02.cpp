#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }

	ifstream animalsFile(argv[1]);
	
	if(!animalsFile)
	{
		cerr << "File DNE";
		exit(0);
	}

	int duckCounter = 0;
	int notDuckCounter = 0;
	string line = "";
	
	while(animalsFile)
	{
		if(line == "duck")
		{
			duckCounter++;
		}
		else
		{
			notDuckCounter++;
		}

		getline(animalsFile,line);
	}
    
	cout << "Report for " << argv[1] << ":" << endl;
	cout << "   Animal count:    " << duckCounter + notDuckCounter << endl;
	cout << "   Duck count:      " << duckCounter << endl;
        cout << "   Non duck count:  " << notDuckCounter << endl;	
	
	return 0;
}
