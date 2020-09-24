#include "CManip.h"
#include "FIELD.h"
#include "CSnake.h"
#include "CObject.h"
#include "CInterface.h"
#include <conio.h>

std::vector<size_t> records;

int main()
{
    InvisibleCursor();
    CenrtreConsole();
    PrintGreeting(records);

    field CSystem = GenerateField(25);

    Snake Player(CSystem);
    Food foodForSnake;
    Obstacle obstacleForSnake;

    char dflvl;
    while (!_kbhit()) {};
    system("cls");
    while (_kbhit()) dflvl = _getch();

    foodForSnake.Spawn(CSystem);
    obstacleForSnake.SpawnObs(CSystem, dflvl);

    while (true)
    {
        PrintInterface(Player, dflvl, records);
        char chr;
        if (_kbhit())
        {
            while (_kbhit()) chr = _getch();
            CatchCommand(Player, chr);
        }

        PrintGameField(CSystem);
        PrintInstriuction();
        SetCursor(0, 0);

        Player.MoveSnake(CSystem);
        if (Player.isDead())
        {
            RestartGame(records, CSystem, Player.GetCount());
        }

        if (Player.isEat())
        {
            foodForSnake.Spawn(CSystem);
        }
        ChooseDifficulty(dflvl);
    }
    return 0;
}

