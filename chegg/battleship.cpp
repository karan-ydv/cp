#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream infile;

const int widthGameBoard = 25;
const int heightGameBoard = 25;

void Fire(const int widthGameBoard, const int heightGameBoard, int X, int Y, char gameBoard[][25]);
void FleetSunk(const int widthGameBoard, const int heightGameBoard, int X, int Y, char gameBoard[][25], bool& GameOver);

int main()
{
   //Takes Input File
   infile.open("BattleShip_Board.txt");

   //Vairables
   char gameBoard[widthGameBoard][heightGameBoard];
   int X;
   int Y;
   bool GameOver;

   for (int i = 0; i < 25; i++)
   {
       for (int j = 0; j < 25; j++)
           infile>> gameBoard[i][j];
   }

   for (int i = 0; i < 25; i++)
   {
       for (int j = 0; j < 25; j++)
           infile >>gameBoard[i][j];
   }

   GameOver = false;
   while (!GameOver)

   {
       cout << endl;
       cout << " To attack enter X coordinate from 0 to 25" << endl << endl;
       cin >> X;
       cout << endl;
       cout << "To attack enter Y coordinate from 0 to 25" << endl << endl;
       cin >> Y;
       cout << endl;

       Fire(heightGameBoard, widthGameBoard, X, Y, gameBoard);
       FleetSunk(heightGameBoard, widthGameBoard, X, Y, gameBoard, GameOver);
   }

   //Closing Program Statements
   infile.close();
   system("pause");
   return 0;

}

//function declarations
void Fire(const int widthGameBoard, const int heightGameBoard, int X, int Y, char gameBoard[][25])

{
   if (gameBoard[X][Y] == '#')
   {
       cout << "HIT" << endl;
       gameBoard[X][Y] = 'H';
   }

   else if (gameBoard[X][Y] == 'H')
   {
       cout << "HIT AGAIN" << endl;
   }

   else
   {
       cout << "MISS" << endl;
   }
}

void FleetSunk(const int widthGameBoard, const int heightGameBoard, int X, int Y, char gameBoard[][25], bool& GameOver)

{
bool NoPound;
NoPound = false;

for (int i = 0; i < 25; i++)
{
   for (int j = 0; j < 25; i++)
       if (gameBoard[i][j] == '~' || gameBoard[i][j] == 'H')
           NoPound = true;
       else
       {
           NoPound = false;
           break;
       }
   if (NoPound == false)
       break;
}

if (NoPound == true)

{
   GameOver = true;
   cout << "Enemey Fleet Destroyed!" << endl;
   cout << "Game Over" << endl << endl;
}
}