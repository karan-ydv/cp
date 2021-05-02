#include <iostream>
using namespace std;

int main()
{
	string str = "";
	char ch;
	cout << "Cipher Text:" << endl;
	while ((ch = std::cin.get()) != 27) {
		str += ch;
	}
	int k;	cin >> k;
	for(char c: str)
	{
		if(isalpha(c))
		{
			if(islower(c))	ch = 'a' + (c - 'a' + k) % 26;
			else			ch = 'A' + (c - 'A' + k) % 26;
		}
		else	ch = c;
		cout << ch;
	}
	return 0;
}