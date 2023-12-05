#include <fstream>
#include <cstring>
#define LGMAX 100002
#define LGMIN 12
#define NRLITERE 26
using namespace std;
int main()
{
	ifstream f("degrade.in");
	char s[LGMAX];
	f.getline(s, LGMIN);
	int poz[NRLITERE], i;
	memset(poz, -1, sizeof(poz));
	for (i = 0; s[i]; i++) poz[s[i]-'a'] = i;
	f.get(s, LGMAX);
	f.close();
	int p = -1, lg = 0, nr = 0, lgmax = 0;
	for (i = 0; s[i]; i++)
	{
		int c = s[i]-'a';
		if (poz[c] >= p) lg++;
		else
		{
			if (lg > lgmax) lgmax = lg, nr = 1;
			else if (lg == lgmax) nr++;
			lg = 1;
		}
		p = poz[c];
	}
	if (lg > lgmax) lgmax = lg, nr = 1;
	else if (lg == lgmax) nr++;
	ofstream g("degrade.out");
	g << lgmax << ' ' << nr;
	g.close();
	return 0;
}

