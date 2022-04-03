#pragma once
#include "field.h"

enum WalkDirection
{
  eWalkUp,
  eWalkDown,
  eWalkLeft,
  eWalkRight
};

bool
checkIfWalkable(struct Position pos, struct Position *new_pos, enum WalkDirection direction, enum FieldPieces cur_piece);

void
tryWalk(enum WalkDirection direction);
