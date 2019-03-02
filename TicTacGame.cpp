#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
char value[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};       //Character value initialization
    int i = 1;                                                        // i variable for change the number of player. It's either 1 or 2
      char b = 'X';                                                   // b is used for postion Sign respectively('X' or 'Y')
        int row,col;
        string player1;                                                //To take players name
        string player2;
        bool draw = false;                                            //To draw the game
  //gotoxy Function Goes here
void gotoxy(int x,int y)
      {
      COORD coord;
      coord.X = x;
      coord.Y  =y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      }
      void clear()                                          //To clear the previous screen
          {
            system("cls");
            gotoxy(15,1);
            cout<<" T I C   T A C   T O E   G A M E\n\n";
            cout<<"Player 1 : "<<player1<<" \t\tPlayer 2 : "<<player2<<endl<<endl;
            cout<<"Player 1 Sign : [X] \t\tPlayer 2 Sign : [Y] "<<endl<<endl;
          }
void DisplayFun()                                    //game interface
    {
      clear();
      cout<<"\t\t     |     |     "<<endl;
      cout<<"\t\t"<<"  "<<value[0][0]<<"  |  "<<value[0][1]<<"  |  "<<value[0][2]<<"  "<<endl;
      cout<<"\t\t     |     |     "<<endl;
      cout<<"\t\t_____|_____|_____"<<endl;
      cout<<"\t\t     |     |     "<<endl;
      cout<<"\t\t"<<"  "<<value[1][0]<<"  |  "<<value[1][1]<<"  |  "<<value[1][2]<<"  "<<endl;
      cout<<"\t\t     |     |     "<<endl;
      cout<<"\t\t_____|_____|_____"<<endl;
      cout<<"\t\t     |     |     "<<endl;
      cout<<"\t\t"<<"  "<<value[2][0]<<"  |  "<<value[2][1]<<"  |  "<<value[2][2]<<"  "<<endl;
      cout<<"\t\t     |     |     "<<endl;
    }
    bool GameEnd()                             //To end the game condition
    {
      for(int i=0;i<3;i++)
      if(value[i][0]==value[i][1] && value[i][0] == value[i][2])
      return false;
      for(int j=0;j<3;j++)
     if(value[0][j]==value[1][j] && value[0][j] == value[2][j])
      return false;
      if(value[0][0]==value[1][1] && value[0][0]==value[2][2] || value[0][2]==value[1][1] && value[0][2]==value[2][0])
      return false;
      for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
      if(value[i][j]!='X' && value[i][j]!='Y')
      return true;
      draw = true;
      return false;
    }
    void PlayerTurn()                                 //When player gives the input
    {
      int choice;
    if(b=='X')
      cout<<"\tPlayer1 [X] turn : ";
    if(b=='Y')
      cout<<"\tPlayer2 [Y] turn : ";
      cin>>choice;
      cout<<endl;
    switch(choice)
    {
      case 1:row=0,col=0;
      break;
      case 2:row=0,col=1;
      break;
      case 3:row=0,col=2;
      break;
      case 4:row=1,col=0;
      break;
      case 5:row=1,col=1;
      break;
      case 6:row=1,col=2;
      break;
      case 7:row=2,col=0;
      break;
      case 8:row=2,col=1;
      break;
      case 9:row=2,col=2;
    break;
    default:cout<<"Worng choice"<<endl;
    break;
    }
    if(b =='X' && value[row][col]!='X' && value[row][col]!='Y')
    {
      value[row][col]='X';
      b = 'Y';
      i = 2;
    }
    else if(b == 'Y' && value[row][col]!='X' && value[row][col]!='Y')
  {
    value[row][col]='Y';
    b = 'X';
    i = 1;
  }
  else{
  cout<<"Position is all ready filled!\nPlease try again!\n\n";
  PlayerTurn();
}
DisplayFun();
}
void Interface()
        {
          cout<<"Enter the two player name: "<<endl;
          cout<<"Player1: ";
          getline(cin, player1);
          cout<<"Player2: ";
          getline(cin, player2);
        }
int main()
{
  int n;
  gotoxy(15,1);
cout<<" T I C   T A C   T O E   G A M E\n\n";
Interface();
while(GameEnd())
{
  DisplayFun();
  PlayerTurn();
  GameEnd();
}
if(draw == false&&value[0][0]=='X'&& value[0][1]=='X'&&  value[0][2]=='X' //First row
|| value[1][0]=='X'&& value[1][1]=='X'&& value[1][2]=='X'  //Second row
|| value[2][0]=='X'&& value[2][1]=='X'&& value[2][2]=='X'  //Third row
|| value[0][0]=='X'&& value[1][0]=='X'&& value[2][0]=='X'  //First column
|| value[0][1]=='X'&& value[1][1]=='X'&& value[2][1]=='X'  //Second column
|| value[0][2]=='X'&& value[1][2]=='X'&& value[2][2]=='X'  //Third column
|| value[0][0]=='X'&& value[1][1]=='X'&& value[2][2]=='X'  //forword diagonal
|| value[0][2]=='X'&& value[1][1]=='X'&& value[2][0]=='X')  //Backword diagonal
cout<<player1<<" Win!  congratulation!"<<endl;
if(value[0][0]=='Y'&& value[0][1]=='Y'&&  value[0][2]=='Y' && draw == false //First row
|| value[1][0]=='Y'&& value[1][1]=='Y'&& value[1][2]=='Y'  //Second row
|| value[2][0]=='Y'&& value[2][1]=='Y'&& value[2][2]=='Y'  //Third row
|| value[0][0]=='Y'&& value[1][0]=='Y'&& value[2][0]=='Y'  //First column
|| value[0][1]=='Y'&& value[1][1]=='Y'&& value[2][1]=='Y'  //Second column
|| value[0][2]=='Y'&& value[1][2]=='Y'&& value[2][2]=='Y'  //Third column
|| value[0][0]=='Y'&& value[1][1]=='Y'&& value[2][2]=='Y'   //forword diagonal
|| value[0][2]=='Y'&& value[1][1]=='Y'&& value[2][0]=='Y')  //Backword diagonal
cout<<player2<<" Win!   congratulation!"<<endl;
else
cout<<"Game is over!";
  return 0;
}
