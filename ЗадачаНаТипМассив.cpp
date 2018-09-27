#include<iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class C
{
private:
	int*** A;//инкапсуляция!
	int x, y, z;//размеры
public:
	C(int x,int y,int z) : x(x),y(y),z(z)//конструктор. выполняется при создании объектов класса
	{

		A = new int**[x];
		for (int i = 0; i < x; ++i)
			A[i] = new int*[y];
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				A[i][j] = new int[z];
	}
	~C()//деструктор. выполняется при удалении объектов класса вручную или автоматически
	{
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				delete A[i][j];
		for (int i = 0; i < x; ++i)
			delete A[i];
		delete A;
	}
	void ShowCube();
	void Zapolnenie();
	void MethodTwo();
	void MethodThree();
};

int main(void)
{
	setlocale(LC_ALL, "Russian");
	C r(4,5,4);

	cout << "Первый метод:";
	r.Zapolnenie();
	r.ShowCube();
	r.MethodTwo();
	r.ShowCube();
	r.MethodThree();

	system("pause");
	return 0;
}
void C::Zapolnenie()
{
	int count = 0;
	for (int i = 0; i < x; ++i)
		for (int k = 0; k < z; ++k)
			for (int j = 0; j < y; ++j)
			{
				A[i][j][k] = count;
				count++;
			}
}

void C::MethodTwo()
{
  int o;
cout << "\n\nВторой метод\n\n";

cout << "Каким значением вы хотите заполнить срез?: \n";
cin >> o;
for (int i = 0; i < x; ++i)
    for (int k = 0; k < z; ++k)
        for(int j = 0; j < y; ++j)
        {
        if (i - j ==0 && i+j == 0 + k*2)
              A[i][j][k] = o;
        }
}


void C::MethodThree()
{
int j;
cout << "\n\nТретий метод\n";
       cout << "\r\n\r\n\r\n";
		for (int k = z - 1; k >= 0; k--)
        {
			for (int l = 5 - j; l >= 1; l--)
				cout<<" ";
			for (int i = 0; i < x; i++)
				cout << setprecision(3) << A[i][2][k] << "    ";
			cout << "\r\n";
		}
		cout << "\r\n\r\n\r\n";


}

void C::ShowCube()
{
	cout << "\r\n\r\n\r\n";
	for (int k = z - 1; k >= 0; k--)
	{
		for (int j = 0; j<y; j++)
		{
			for (int l = 5 - j; l >= 1; l--)
				cout<<" ";
			for (int i = 0; i < x; i++)
				cout << setprecision(3) << A[i][j][k] << "    ";
			cout << "\r\n";
		}
		cout << "\r\n\r\n\r\n";
	}
}
