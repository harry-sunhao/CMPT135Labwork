#include <iostream>

using namespace std;

struct Point
{
	double x, y;
};

struct Line
{
	Point start, end;
};

Line readLine()
{
	Line line;
	cout << "Enter x and y coordinate of the start point" << endl;
	cin>>line.start.x>>line.start.y;
	cout << "Enter x and y coordinate of the end point" << endl;
	cin>>line.end.x>>line.end.y;
	return line;
}

void printLine(const Line &line)
{
	cout << "(" << line.start.x << ", " << line.start.y << ") --- ("<< line.end.x << ", " << line.end.y << ")"<<endl;
	return;
}
double getSlope(const Line *line)
{
	double y_diff = line->end.y - line->start.y;
	double x_diff = line->end.x - line->start.x;

	if(x_diff==0)
		return 1e100;
	else
		return y_diff / x_diff;
}

int main()
{
	int size;
	cout << "Enter the array size ";
	cin >> size;
	cout << endl;
	Line *L = new Line[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Reading Line " << i+1 << endl;
		L[i] = readLine();
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Line " << i+1 << " = ";
		printLine(L[i]);
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			double s1 = getSlope(&L[i]);
			double s2 = getSlope(&L[j]);
			if (s1 == s2)
				cout << "Line " << i+1 << " is parallel to Line " << j+1 << endl;
		}
	}
	cout << endl;
	system("Pause");
	return 0;
}
