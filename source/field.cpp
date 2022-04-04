#include <pspdebug.h>
#include <cstddef>
#include <sstream>

#include "field.h"
#include "movement.h"

struct Position player = { .x = 5, .y = 0 };

struct Field field = { .pieces = {
    {eGround,    eWall,    eWall,    eWall,    eGround,   eGround},
    {eWall,    eGround,    eGround,    eEnemy,  eGround,     eGround},
    {eWall,  eGround,    eEnemy,    eGround,    eEnemy,     eWall},
    
    {eGround,   eGround,    eWall,  eWall,   eWall,     eWall},
    {eGround,  eRock,    eGround,   eGround,  eRock,   eGround},
    {eGround,  eRock,    eGround,    eRock,  eGround,     eGround},
    {eWall,  eWall,  eWall,  eWall,  eWall,     eWall} 
  }
};

const char* ground_symbol = " ";
const char* rock_symbol = "o";
const char* player_symbol = "1";
const char* goal_symbol = "4";
const char* key_symbol = "5";
const char* wall_symbol = "#";
const char* lock_symbol = "L";
const char* enemy_symbol = "E";

const char*
look_up_symbol(enum FieldPieces piece)
{
  const char* return_value = ground_symbol;
  switch (piece) {
    case eGround:
      return_value = ground_symbol;
      break;
    case eRock:
      return_value = rock_symbol;
      break;
    case eKey:
      return_value = key_symbol;
      break;
    case eGoal:
      return_value = goal_symbol;
      break;
    case eLock:
      return_value = lock_symbol;
      break;
    case eEnemy:
      return_value = enemy_symbol;
      break;
    case eWall:
      return_value = wall_symbol;
      break;
  }
  return return_value;
}

/** Prints the content of the field to screen */
void
printField()
{
  pspDebugScreenSetXY(X_OFFSET - 1, Y_OFFSET - 1);
  for (size_t x = 0; x < X_SIZE + 2; x++) {
    pspDebugScreenPuts("-");
  }

  for (size_t y = 0; y < Y_SIZE; y++) {
    pspDebugScreenSetXY(X_OFFSET - 1, Y_OFFSET + y);
    pspDebugScreenPuts("|");
    for (size_t x = 0; x < X_SIZE; x++) {
      const char* symbol = look_up_symbol(field.pieces[y][x]);
      pspDebugScreenPuts(symbol);
    }
    pspDebugScreenPuts("|");
  }

  pspDebugScreenSetXY(X_OFFSET - 1, Y_OFFSET + Y_SIZE);
  for (size_t x = 0; x < X_SIZE + 2; x++) {
    pspDebugScreenPuts("-");
  }

  pspDebugScreenSetXY(X_OFFSET + player.x, Y_OFFSET + player.y);
  pspDebugScreenPuts(player_symbol);
 
  std::ostringstream ss;
  ss << movecount;
  pspDebugScreenSetXY(X_OFFSET - 1, Y_OFFSET + Y_SIZE + 2); // Move 2 below the max size of the field
  pspDebugScreenPuts(ss.str().c_str());
} 
