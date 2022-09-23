#include "movement.h"

int movecount = 23;

/* int die()
   {
    if (movecount == 0)
   {
    die function goes here. When die funcation is called upon it will reset all the locations of objects, and set int movecount to equal 23 again or whatever number it was originally.
   }

/* Checks if character on pos can move to new pos
 * @param new_pos is a pointer to the position that can be walked to,
 *    only filled if "not-NULL"
 */
bool
checkIfWalkable(struct Position pos, struct Position *new_pos, enum WalkDirection direction, enum FieldPieces cur_piece)
{
  struct Position target = pos;
  // In case something unexpected happens, assume it won't work
  enum FieldPieces piece = eWall;
  switch(direction) {
    case eWalkUp:
      if (pos.y > 0)
        target.y--;
      else
        return false;
      break;
    case eWalkDown:
      if (pos.y+1 < Y_SIZE)
        target.y++;
      else
        return false;
      break;
    case eWalkLeft:
      if (pos.x > 0)
        target.x--;
      else
        return false;
      break;
    case eWalkRight:
      if (pos.x+1 < X_SIZE)
        target.x++;
      else
        return false;
      break;
  }
  
  piece = field.pieces[target.y][target.x];
  
  bool isWalkable = false;
  switch(piece) {
    case eGround:
      isWalkable = true;
	  if(cur_piece == ePlayer)
		  movecount--;
      break;
    case eEnemy:
      // Kick the enemy but stand in place
      isWalkable = false;
      struct Position enemy_pos_new;
      if (!checkIfWalkable(target, &enemy_pos_new, direction, eEnemy)) {
          field.pieces[target.y][target.x] = eGround;
      } else {
        // Clear old location
        field.pieces[target.y][target.x] = eGround;
        // Set enemy to new pos
        field.pieces[enemy_pos_new.y][enemy_pos_new.x] = eEnemy;
      }
	  if(cur_piece == ePlayer)
		  movecount--;
      break;
    // TODO: Do something similar with the rock
    case eRock:
      isWalkable = false;
      struct Position rock_pos;
      if (checkIfWalkable(target, &rock_pos, direction, eRock)) {
        field.pieces[target.y][target.x] = eGround;
        field.pieces[rock_pos.y][rock_pos.x] = eRock;
      }
	  if(cur_piece == ePlayer)
		  movecount--;
      break;
    default:
      isWalkable = false;
      break;
  }
  
  // Save new position if walkable and asked to
  if (isWalkable && new_pos) {
    *new_pos = target;
  }
  
  return isWalkable;
}

void
tryWalk(enum WalkDirection direction)
{
  struct Position target_pos;
  if (checkIfWalkable(player, &target_pos, direction, ePlayer)) {
    player = target_pos;
  }
}

