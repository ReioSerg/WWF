

#include <iostream>
#include <fstream>
#include <signal.h>
using namespace std;
bool f = true;
void Ctr_c(int sub) {
	cout << "Im done\n";
	f = false;
}

void main(int argc, char* argv[])
{   
	char str[100];
	ofstream file;
	file.open(argv[1]);
	if (file.is_open() == false) {
		cout << "File cant be open";
	}
	else {
		cout << "Enter the data\n";
		while (f) {
			cin.getline(str, 99);
			file << str<<endl;
			signal(SIGINT, Ctr_c);
		}
	}
	file.close();
}
