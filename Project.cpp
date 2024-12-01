#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



class Player
{ 
    public:
        enum Dir {LEFT, RIGHT, UP, DOWN, STOP}; // This is the direction state

        Player(){
            playerPos.pos->x = 10;
            playerPos.pos->y = 5;
            playerPos.symbol = '*';
        };
        ~Player();

        objPos getPlayerPos() const {
            return playerPos;
        }; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        objPos playerPos; // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
};

Player* player;


int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    player = new Player();
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == player->getPlayerPos().pos->x && j == player->getPlayerPos().pos->y) {
                MacUILib_printf("%c", player->getPlayerPos().symbol);
            }
            else if (i == 0 || i == 10 - 1 || j == 0 || j == 10 - 1) {
                MacUILib_printf("#");
            } else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");  // Move to the next row
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
