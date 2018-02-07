#include "Header.h"

int main()
{
	std::string filename = comdlg();
	std::ifstream text1(filename);

	filename = comdlg();
	std::ifstream text2(filename);

	std::string str1, str2;
	int x = 1;
	while (true)
	{
		std::getline(text1, str1);
		std::getline(text2, str2);

		if (str1 != str2)
		{
			break;
		}
		x++;

	}

	int y = 0;
	while (true)
	{
		if (str1.substr(y,1) != str2.substr(y,1))
		{
			break;
		}
		y++;
	}

	std::string out1 = str1.substr(y);
	std::string out2 = str2.substr(y);

	std::string temp = "\\";
	std::string str(filename);
	std::size_t found = str.rfind(temp);
	std::string outloc = str.substr(0, found+1);
	outloc = outloc + "output.txt";
	std::ofstream output(outloc);	

	output << "Line " << x << " character " << y << " on document one is different than document two.\n";
	output << "Document 1, line " << x << " char " << y << ":\n";
	output << out1;
	output << "\nDocument 1, line " << x << " char " << y << ":\n";
	output << out2;

	return 0;
}