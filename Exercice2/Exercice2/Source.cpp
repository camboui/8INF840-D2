#include <fstream>
#include <sstream>
#include "Lego.h"
#include "Tree234.h"

using namespace std;

vector<vector<string>> readLegoFile(string fileName)
{
	vector<vector<string>> data;
	ifstream infile(fileName);
	string headerLine;
	getline(infile, headerLine);
	getline(infile, headerLine);

	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;

		istringstream ss(s);
		vector <string> record;

		string line;
		while (getline(ss, line))
		{
			int prev(0);
			int pos;
			char delimiter(',');
			while ((pos = line.find_first_of(delimiter, prev)) != string::npos)
			{
				if (pos > prev) {
					record.push_back(line.substr(prev, pos - prev));
				}
				if (line[pos + 1] == '"' || prev == pos) {
					delimiter = '"';
				}
				else {
					delimiter = ',';
				}
				prev = pos + 1;
			}
			if (prev < line.length()) {
				record.push_back(line.substr(prev, string::npos));
			}
		}
		if (!record.empty()) {
			data.push_back(record);
		}
	}
	return data;
}

int main()
{
	string file = "pieces.txt";
	vector<vector<string>> data = readLegoFile(file);
	vector<Lego> legos;

	Tree234<Lego> tree;

	for (int i = 0; i < data.size(); i++)
	{
		Lego lego = Lego(data[i][0], data[i][1], data[i][2]);
		legos.push_back(lego);
		tree.addKey(lego);
	}

	system("pause");
	return 0;
}