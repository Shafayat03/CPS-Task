/// windows.h --> for operating system use 
#include<windows.h>

#include <stdio.h>
/// conio.h ----> for _kbhit and getch() function 
#include<conio.h>
/// MMsystem.h header file----> for starting game sound playing audio sound 

///pacman moves using four arrow keys only
/// Goal : to collect 250 foods means --> '.' using  arrow keys only
// % holo pacman k jete bara dibe % er sathe cross hole game over

/// structure for pacman and ghost 

#include<MMsystem.h>
#define H 30
#define W 60
#define gho1 5

struct coord
{
   int x;
   int y;
};

struct PacMan
{
   struct coord position;
   int vx;
   int vy;
   int food_coll;
};


struct Ghost
{
   struct coord position;
   int vx;
   int vy;
};


struct Ghost allGhosts[gho1];
struct Ghost allGhosts2[gho1];
/// ending the structure of ghost and pacman here 

/// structure for . and designed initialing

struct PacMan myPacMan = {
                           {
                              .x = 1,
                              .y = 5,
                           },
                           .vx = 0,
                           .vy = 0,
                           .food_coll = 0,
                         };

/// for paly_field using 2D array from here 
                         
char playfield[H][W] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "#   ##################     ######    ###################   #" },
   { "#                  ####      ##     ####                   #" },
   { "#    ####   ###    ####      ##     ####    ###    ####    #" },
   { "#    ####   ###    ####    ######   ####    ###    ####    #" },
   { "#    ####                                          ####    #" },
   { "#     ##################     ##     ##################     #" },
   { "#                            ##                            #" },
   { "#   ###############   ###    ##    ###   ###############   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###  ###   ##########  ##  ##  ##########  ###   ###   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###############   ###  ##  ##  ###   ###############   #" },
   { "#                                                          #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###       ###   ####   ###       ###    ####   #" },
   { "#   ####                    ####                    ####   #" },
   { "#   ####     ############          ############     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ##################################     ####   #" },
   { "#   ####                                            ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####        ####         ##          ####       ####   #" },
   { "#               ####     ##########      ####              #" },
   { "#       ####             ##########             ####       #" },
   { "############################################################" }
};
void display();
void SetColor(int ForgC);
/// initialize function ---> initialize all emply field here 
void initialize()
{
   /// 1. replace each empty field in the playfield with a food field
   int i;

   for(i = 0; i < H; i++)
   {
       int j;
      for( j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }

   /// 2. initialize all ghosts

   for ( i = 0; i <gho1; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
     /// try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      playfield[y][x] = '%';

   }
     for ( i = 0; i < gho1; i++)
   {
      allGhosts2[i].vx = 0;
      allGhosts2[i].vy = 0;
      /// try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts2[i].position.x = x;
      allGhosts2[i].position.y = y;
      playfield[y][x] = '%';

   }



}

///
void user_input()
{
    /// initialize the function using inpuut from keyboard ---> _kbhit()
    
   if (_kbhit())
   {
      char c1 = _getch();

      /// if  c1 == -32 it only declare the press key is a arraow key
      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;
         int i;
         for(i=0;i<gho1;i++)
        {
             allGhosts[i].vx=0;
             allGhosts[i].vy=0;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=0;

        }

        /// switch case for respected arrow keys 
        
         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right
         }
         for(i=0;i<gho1;i++)
         {
             allGhosts[i].vx=+1;
             allGhosts[i].vy=+1;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=+1;
         }
      }




   }

}
/// Display the pacman and setcolor in BLUE
void display()
{
    SetColor(1);
printf("                                        _______   ______    _____   ___      ___   ______   ___       \n");
printf("                                       ||     || ||    ||  ||      ||  |    |  || ||    || ||  |    ||\n");
printf("                                       ||     || ||    ||  ||      ||   |  |   || ||    || ||   |   ||\n");
printf("                                       ||_____|| ||____||  ||      ||    ||    || ||____|| ||    |  ||\n");
printf("                                       ||        ||    ||  ||      ||          || ||    || ||     | ||\n");
printf("                                       ||        ||    ||  ||____  ||          || ||    || ||      |||\n");
SetColor(15);
}

///swaroop
/// move figure for  pacman  --> moving according to the users input 
void move_figures()
{
   /// 1. delete PacMan from old position
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';
   int i;
   for(i=0;i<gho1;i++)
   {
       playfield[allGhosts[i].position.y][allGhosts[i].position.x] = ' ';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x] = ' ';
   }

   /// 2. compute new desired coordinate (nx,ny)
   int nx = myPacMan.vx + myPacMan.position.x;
   int ny = myPacMan.vy + myPacMan.position.y;
   int mx[5];
   int my[5];
   int mx1[5];
   int my1[5];
 for(i=0;i<gho1;i++)
   {
        mx[i] = allGhosts[i].vx + allGhosts[i].position.x;
        my[i] = allGhosts[i].vy + allGhosts[i].position.y;
        mx1[i] = allGhosts2[i].vx + allGhosts2[i].position.x;
        my1[i] = allGhosts2[i].vy + allGhosts2[i].position.y;
   }
   // 3. test whether there is a wall at (nx,ny)
   if (playfield[ny][nx] == '#')
   {
      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   for(i=0;i<gho1;i++)
   {

   if(playfield[my[i]][mx[i]]=='#')
      {
          if(allGhosts[i].vx>0 || allGhosts[i].vy>0)
          {

                allGhosts[i].vx=-1;
                allGhosts[i].vy=-1;
            }
            else
            {
                allGhosts[i].vx=+1;
                allGhosts[i].vy=+1;
            }
      }
    if(playfield[my1[i]][mx1[i]]=='#')
    {
        if(allGhosts2[i].vy<0)
          {

                allGhosts2[i].vx=0;
                allGhosts2[i].vy=+1;
            }
            else
            {
                allGhosts2[i].vx=0;
                allGhosts2[i].vy=-1;
            }
    }



}



   /// 4. update PacMan's coordinate

   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;
    for(i=0;i<gho1;i++)
      {
          allGhosts[i].position.x+=allGhosts[i].vx;
          allGhosts[i].position.y+=allGhosts[i].vy;
          allGhosts2[i].position.x+=allGhosts2[i].vx;
          allGhosts2[i].position.y+=allGhosts2[i].vy;

      }

   /// 5. check for a food piece at the new location
   if (playfield[ny][nx] == '.')
   {
      myPacMan.food_coll++;
   }
   for(i=0;i<gho1;i++)

   {

    if(playfield[my[i]][mx[i]] == '.')
    {

            playfield[my[i]-allGhosts[i].vy][mx[i]-allGhosts[i].vx]='.';
    }
    if(playfield[my1[i]][mx1[i]] == '.')
    {

            playfield[my1[i]-allGhosts2[i].vy][mx1[i]-allGhosts2[i].vx]='.';
    }
    }


   /// 6. put PacMan back again to playfield

   playfield[myPacMan.position.y][myPacMan.position.x] = '@';
    for(i=0;i<gho1;i++)
    {
        playfield[allGhosts[i].position.y][allGhosts[i].position.x]='%';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x]='%';
    }

}

void show_playfield()
{
    int i;
   for ( i = 0; i < H; i++)
   {
       printf("                                       ");
       int j;
      for ( j = 0; j < W; j++)
      {
          if(playfield[i][j]=='.')
          {
              SetColor(4);
            printf("%c", playfield[i][j]);
                SetColor(15);
          }
            else if(playfield[i][j]=='%')
            {
                SetColor(9);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else if(playfield[i][j]=='@')
            {
                SetColor(14);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else
            {
                printf("%c", playfield[i][j]);
            }
      }
      printf("\n");
   }

   printf("                                       Score: %d\n", myPacMan.food_coll);
}
/// check_ coll function --> either if the position of pacman and the ghost is same then game over

void check_coll()
{
    int i=0;
     for(i=0;i<gho1;i++)
   {
       /// This is for losing part
       if((allGhosts[i].position.x==myPacMan.position.x && allGhosts[i].position.y==myPacMan.position.y) || (allGhosts2[i].position.x==myPacMan.position.x && allGhosts2[i].position.y==myPacMan.position.y))
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            PlaySound(TEXT("death.wav"),NULL,SND_SYNC);
            getchar();
            exit(0);
        }
        /// This is for wining part 
        if(myPacMan.food_coll>=250)
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            PlaySound(TEXT("fireworks.wav"),NULL,SND_SYNC);
            getchar();
            exit(0);
            }
   }
}

/// set_cursor_position ---> function for set the cursor position in game for x and y cordinates
void set_cursor_position(int x, int y)
{
   ///Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} /// set_cursor_position

/// hide_cursor function ---> for reduce the blingking of the screen 
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

/// for add color the text when it is necesearray
void SetColor(int ForgC)
{
     WORD wColor;
     ///This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

/// and the main function for playsound  function-->  to play the sound usintg
int main()
{
   system("cls");
   hidecursor();
   initialize();
   PlaySound(TEXT("pacman.wav"),NULL,SND_SYNC);

   /// infinite loop for untill breaks the conditions
   while (1)
   {
      user_input();
      move_figures();
      display();
      show_playfield();
      check_coll();
      ///sleep function --> for pause each and every iteration( ensures the character speed here to the specified seconds) 
      Sleep( 10/ 30 );
      /// set the set_cursor_position function at (0,0) position starting the game and set the all operation at the same screen 
      
      set_cursor_position(0,0);
   }

}

