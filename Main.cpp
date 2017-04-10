#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;
//ïðîâåðêà ðàáîòû ÷åðåç òåðìèíàë äîìà // поправьте 

int MainMenu()
{
	setlocale(0, "");
	srand(unsigned(time(NULL)));
	int N, M;
	char P;
	//cout << "Введите размер матрицы: ";
	N = 20;
	M = 10;
	char ** A = new char *[N];
	for (int i = 0; i < N; i++)
		A[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = 256;

	A[N / 9][M / 9] = '1';
	A[N / 9][M / 9 + 1] = '.';
	A[N / 9][M / 9 + 2] = 83;
	A[N / 9][M / 9 + 3] = 'T';
	A[N / 9][M / 9 + 4] = 'A';
	A[N / 9][M / 9 + 5] = 'R';
	A[N / 9][M / 9 + 6] = 'T';
	A[N / 9 + 4][M / 9] = '0';
	A[N / 9 + 4][M / 9 + 1] = '.';
	A[N / 9 + 4][M / 9 + 2] = 'E';
	A[N / 9 + 4][M / 9 + 3] = 'X';
	A[N / 9 + 4][M / 9 + 4] = 'I';
	A[N / 9 + 4][M / 9 + 5] = 'T';
	A[N / 9 + 2][M / 9] = '2';
	A[N / 9 + 2][M / 9 + 1] = '.';
	A[N / 9 + 2][M / 9 + 2] = 'S';
	A[N / 9 + 2][M / 9 + 3] = 'P';
	A[N / 9 + 2][M / 9 + 4] = 'E';
	A[N / 9 + 2][M / 9 + 5] = 'E';
	A[N / 9 + 2][M / 9 + 6] = 'D';

	//вывод матрицы
	//cout << "Вот Ваша матрица:" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;
	//getch();
	bool G = true;

	do
	{
		P = _getch();
		if (P == '1')
		{
			return 1;
			G = false;
		}
		if (P == '0')
		{
			return 0;
			G = false;
		}

		//Вставить сюда функцию меню сложности
	
	} 
	while (G==true);
	
}


void setMap(char **k, int *h, int *w,int x,int y)
{
 
    for(int i=0;i<*h;i++){
        for(int j=0;j<*w;j++){
            if(i==0 || i==*h-1){k[i][j] = 'w';}
            else if(j==0 || j==*w-1){k[i][j] = 'w';}
            else {k[i][j] = ' ';}
        }
    }
 
    k[x][y]='*';
    k[x+1][y]='*';
    k[x+2][y]='*';
    k[x+1][y-1]='*';
    k[x+1][y+1]='*';
    k[x+3][y-1]='*';
    k[x+3][y+1]='*';
}
 
void printMap(char **m, int* h, int *w){
    for(int i=0;i<*h;i++){
        for(int j=0;j<*w;j++){
            cout<<m[i][j];
        }
    cout<<endl;
    } 
}
    
void clearscreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
//Маин полностью не работоспособен
int main(){
    int height, width;
    cout<<"Enter height and width of a map"<<endl;
    cin>>height>>width;
    int x=8,y=6;
    char** map = new char* [height];
    for(int i=0;i<height;i++){
        map[i] = new char[width];
    }
    setMap(map, &height, &width, x, y);
    char move;
    while(true)
        {
        clearscreen();
        printMap(map,&height, &width);
        move=getch();
        if(move == 'w'  && x>1)
        {
            map[x+1][y+2]=' ';
            map[x+1][y+1]=' ';
            map[x][y]=' ';
            map[x+2][y-2]=' ';
            map[x+2][y-1]=' ';
            map[x+2][y+2]=' ';
            map[x+2][y+1]=' ';
            map[x+1][y]=' ';
            map[x+2][y]=' ';
            map[x+1][y-1]=' ';
            map[x+3][y]=' ';
            map[x+4][y]=' ';
            map[x+1][y+1]=' ';
            map[x+3][y-1]=' ';
            map[x+3][y+1]=' ';
            map[--x][y]='*';
            map[x+1][y]='*';
            map[x+2][y]='*';
            map[x+1][y-1]='*';
            map[x+1][y+1]='*';
            map[x+3][y-1]='*';
            map[x+3][y+1]='*';
        }
        if(move=='s' && x<height-6)
{
    map[x][y]=' ';
    map[x+2][y-2]=' ';
    map[x+2][y-1]=' ';
    map[x+2][y+2]=' ';
    map[x+2][y+1]=' ';
    map[x+1][y+2]=' ';
    map[x+1][y+1]=' ';
    map[x+1][y]=' ';
    map[x+2][y]=' ';
    map[x+1][y-1]=' ';
    map[x+1][y+1]=' ';
    map[x+3][y-1]=' ';
    map[x+3][y+1]=' ';
    map[++x][y]=' ';
    map[x+3][y]='*';
    map[x+4][y]='*';
    map[x+2][y]='*';
    map[x+1][y-1]='*';
    map[x+1][y+1]='*';
    map[x+3][y-1]='*';
    map[x+3][y+1]='*';
        }
        if(move=='d' && y<width-5)
{
    map[x+1][y+2]=' ';
    map[x+1][y+1]=' ';
    map[x][y]=' ';
    map[x+2][y-2]=' ';
    map[x+2][y-1]=' ';
    map[x+1][y]=' ';
    map[x+2][y]=' ';
    map[x+1][y-1]=' ';
    map[x+3][y]=' ';
    map[x+4][y]=' ';
    map[x+1][y+1]=' ';
    map[x+3][y-1]=' ';
    map[x+3][y+1]=' ';
    map[x][++y]=' ';
    map[x+1][y]=' ';
    map[x+2][y+2]='*';
    map[x+2][y+1]='*';
    map[x+2][y]='*';
    map[x+1][y-1]='*';
    map[x+1][y+1]='*';
    map[x+3][y-1]='*';
    map[x+3][y+1]='*';
        }
 
        if(move=='a' && y>3)
        {
            map[x+1][y+2]=' ';
            map[x+1][y+1]=' ';
            map[x][y]=' ';
            map[x+1][y]=' ';
            map[x+2][y]=' ';
            map[x+1][y-1]=' ';
            map[x+3][y]=' ';
            map[x+4][y]=' ';
            map[x+1][y+1]=' ';
            map[x+3][y-1]=' ';
            map[x+3][y+1]=' ';
            map[x][--y]=' ';
            map[x+1][y]=' ';
            map[x+2][y-2]='*';
            map[x+2][y-1]='*';
            map[x+2][y]='*';
            map[x+1][y-1]='*';
            map[x+1][y+1]='*';
            map[x+3][y-1]='*';
            map[x+3][y+1]='*';
        }
   }
   return 0;
}
