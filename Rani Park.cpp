#include <iostream>
#include <fstream>

using namespace std;

void chart(char[][8]);
void down(char, int&, short, char[][8]);
void up(char, int&, short, char[][8]);
void right(char, int&, short, char[][8]);
void left(char, int&, short, char[][8]);
void status(char, int&, int&, char[][8]);
void move(char, char, short, int&, int&, char[][8]);

int main()
{
	char field[8][8] = { ' ' };
	short numbers = 0;
	char direction = ' ', car = ' ';
	int I = 0, J = 0;

	ifstream map1("map 1.txt");
	if (!map1)
	{
		cout << "Wrong!!!";
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map1 >> field[i][j];
			if (field[i][j] == '0') field[i][j] = ' ';
		}
	}
	chart(field);
	move(car, direction, numbers, I, J, field);

	ifstream map2("map 2.txt");
	if (!map2)
	{
		cout << "Wrong!!!";
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map2 >> field[i][j];
			if (field[i][j] == '0') field[i][j] = ' ';
		}
	}
	chart(field);
	move(car, direction, numbers, I, J, field);

	ifstream map3("map 3.txt");
	if (!map3)
	{
		cout << "Wrong!!!";
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map3 >> field[i][j];
			if (field[i][j] == '0') field[i][j] = ' ';
		}
	}
	chart(field);
	move(car, direction, numbers, I, J, field);

	ifstream map4("map 4.txt");
	if (!map4)
	{
		cout << "Wrong!!!";
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map4 >> field[i][j];
			if (field[i][j] == '0') field[i][j] = ' ';
		}
	}
	chart(field);
	move(car, direction, numbers, I, J, field);
}

void move(char car, char direction, short numbers, int& I, int& J, char field[][8])
{
while(1){
		static short counter = 0;
		cout << "Please select the desired car: ";
		cin >> car;
		cout << "Please enter the direction to move: ";
		cin >> direction;
		cout << "Please enter the number of moves in the entered Direction: ";
		cin >> numbers;

		I = 0;
		J = 0;
		status(car, I, J, field);
		if (direction == 'S')
		{
			down(car, J, numbers, field);
			counter++;
		}
		else if (direction == 'W')
		{
			up(car, J, numbers, field);
			counter++;
		}
		else if (direction == 'D')
		{
			right(car, I, numbers, field);
			counter++;
		}
		else if (direction == 'A')
		{
			left(car, I, numbers, field);
			counter++;
		}
		else cout << "The direction entered is false";
		chart(field);
		cout << "The number of moves you have: " << counter << endl;
		if (field[3][6] == '#')
		{
			cout << "Car unblocked in " << counter << " moves , you win :)" << endl << endl << "Let's start the next step" << endl << endl;
			break;
		}
}
}


void chart(char field[][8])
{
	cout << "--" << "--" << "--" << "--" << "--" << "--" << "--" << "-" << endl;
	cout << "|" << " " << field[1][1] << " " << field[1][2] << " " << field[1][3] << " " << field[1][4] << " " << field[1][5] << " " << field[1][6] << " " << "|" << endl;
	cout << "|" << " " << field[2][1] << " " << field[2][2] << " " << field[2][3] << " " << field[2][4] << " " << field[2][5] << " " << field[2][6] << " " << "|" << endl;
	cout << "|" << " " << field[3][1] << " " << field[3][2] << " " << field[3][3] << " " << field[3][4] << " " << field[3][5] << " " << field[3][6] << " " << " " << endl;
	cout << "|" << " " << field[4][1] << " " << field[4][2] << " " << field[4][3] << " " << field[4][4] << " " << field[4][5] << " " << field[4][6] << " " << "|" << endl;
	cout << "|" << " " << field[5][1] << " " << field[5][2] << " " << field[5][3] << " " << field[5][4] << " " << field[5][5] << " " << field[5][6] << " " << "|" << endl;
	cout << "|" << " " << field[6][1] << " " << field[6][2] << " " << field[6][3] << " " << field[6][4] << " " << field[6][5] << " " << field[6][6] << " " << "|" << endl;
	cout << "--" << "--" << "--" << "--" << "--" << "--" << "--" << "-" << endl;
}


void status(char car, int& I, int& J, char field[][8])
{
	int a = 0, b = 0, c = 0;

	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (field[i][j] == car)
			{
				a++;
				b++;
			}
			if (a > 1)
			{
				c = 1;
				I = i;
				break;
			}
			if (b > 1)
			{
				c = 2;
				J = j;
				break;
			}
		}
		a = 0;
		if (c != 0) break;
	}
	if (c == 0) cout << "The selected car was not found";
}


void down(char car, int& J, short numbers, char field[][8])
{
	for (int r = 0; r < numbers; r++)
	{
		for (int i = 6; i > 0; i--)
		{
			if (field[i][J] == car)
			{
				if (field[i + 1][J] == ' ' && (i + 1) > 0 && (i + 1) < 7)
				{
					field[i + 1][J] = car;
					field[i][J] = ' ';
				}
				else break;
			}
		}
	}
}


void up(char car, int& J, short numbers, char field[][8])
{
	for (int r = 0; r < numbers; r++)
	{
		for (int i = 1; i < 7; i++)
		{
			if (field[i][J] == car)
			{
				if (field[i - 1][J] == ' ' && (i - 1) > 0 && (i - 1) < 7)
				{
					field[i - 1][J] = car;
					field[i][J] = ' ';
				}
				else break;
			}
		}
	}
}


void right(char car, int& I, short numbers, char field[][8])
{
	for (int r = 0; r < numbers; r++)
	{
		for (int j = 6; j > 0; j--)
		{
			if (field[I][j] == '#')
			{
				if (field[I][j + 1] == ' ' && (j + 1) > 0)
				{
					field[I][j + 1] = car;
					field[I][j] = ' ';
				}
				else break;
			}
			if (field[I][j] == car)
			{
				if (field[I][j + 1] == ' ' && (j + 1) > 0 && (j + 1) < 7)
				{
					field[I][j + 1] = car;
					field[I][j] = ' ';
				}
				else break;
			}
		}
	}
}


void left(char car, int& I, short numbers, char field[][8])
{
	for (int r = 0; r < numbers; r++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (field[I][j] == car)
			{
				if (field[I][j - 1] == ' ' && (j - 1) > 0 && (j - 1) < 7)
				{
					field[I][j - 1] = car;
					field[I][j] = ' ';
				}
				else break;
			}
		}
	}
}
