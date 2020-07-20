#include <stdio.h>
#include <conio.h>
#include<iostream>
#include <Windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 32

using namespace std;

int Mover(int x, int y)
{
    HANDLE capturar;
    capturar = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(capturar, coordenada);
 return y;   
}

void Ocultar(){
    HANDLE capturar;
    capturar = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;  
    cursor.bVisible=FALSE;
    cursor.dwSize= 1;
    SetConsoleCursorInfo(capturar, &cursor);
}
void Area(){
    for (int i = 2; i < 78; i++)
    {
        Mover(i,3); printf("%c",205);
        Mover(i,28); printf("%c",205);
    }   
    for (int i = 4; i < 28; i++)
    {
        Mover(2,i); printf("%c",186);
        Mover(77,i); printf("%c",186);
    }
    
     Mover(2,3); printf("%c",201);
     Mover(2,28); printf("%c",200);
     Mover(77,3); printf("%c",187);
     Mover(77,28); printf("%c",188);
}
void menu_principal(int opc)
{
    Area();
  Mover(15,10);cout<<" Player vs Machine";
  Mover(15,11);cout<<" Player1 vs Player2";
  Mover(15,12);cout<<" History";
  Mover(15,13);cout<<" Exit";
        
      switch (opc) {
         case 1:
                Mover(15,15);
                cout<<" the mode Player vs Machine was choosen";
            break;
 
         case 2:
            Mover(15,15);
            cout<<" the mode Player1 vs Player2 was choosen";
            break;
 
         case 3:
           Mover(15,15);
           cout<<" History was selected";
            break;
 
           case 4:
            Mover(11,15);
            cout << "Bye bye!" << endl;
            break;
      }
}


int main()
{
    system("cls");
    Ocultar();
    Area();
    int x = 10, y = 10,opc=0;
    bool Exit = false;
    while(!Exit){
        
        if (kbhit()){
        char CapturarTecla = getch();
        Mover(x,y);printf(" ");
        if (CapturarTecla == UP) y--;
        if (CapturarTecla == DOWN) y++;
        if (y>13) y=10;
        if (y<10) y=10;
        Mover(x,y);printf(">");
        if (y==10 && CapturarTecla== ENTER){opc=1; system("cls");}
        if (y==11 && CapturarTecla== ENTER) {opc=2;system("cls");}
        if (y==12 && CapturarTecla== ENTER) {opc=3;system("cls");}
        if (y==13 && CapturarTecla== ENTER) {opc=4;system("cls");}
        menu_principal(opc);
        }
        Sleep(25);
    }
    return 0;
}