#include <iostream>     // cout
#include <fstream>      // ifstream and ofstream

using namespace std;

int main()
{
	ifstream inp;
	inp.open("savefile");	// put name of your savefile here
	char c = inp.get();
	cout << ">>>Previous advice:" << endl;
	while(inp.good()) {		// Check whether state of stream is good
		cout << c;			// output content of file
		c = inp.get();
	}
	cout << '\n';
	inp.clear();			// clear the previous advice
	inp.close();			// close stream

	ofstream out;			// output stream
	out.open("savefile");	// open file
	cout << ">>>Your advice to the next user. Hit ENTER twice to exit:" << endl;
	c = cin.get();			// Check whether state of stream is good
	while(cin.good()) {
		out.put(c);
		if(c == '\n')
		{
			c = cin.get();
			if(c == '\n')	// double enter to break
				break;
		}
		else c = cin.get();
	}
	out.close();			// close stream
	cout << '\n';
	cout << "Thanks for your advice." << endl;
	return 0;
}