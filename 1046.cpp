#include <iostream>
#include <iomanip>
using namespace std;

double shortPath(int m, int n) 
{
	int result = m * n;
	if ( result % 2 == 0)
		return (double) result;
	else
		return  result + 0.41;
}

int main()
{
	int num;
	cin >> num;
	for( int i = 1; i <= num; i++) {
		int m, n;
		cin >> m >> n;
		cout << "Scenario #" << i << ":" << endl;
		cout << fixed << setprecision(2) << shortPath(m, n) << endl << endl;
	}	
}
