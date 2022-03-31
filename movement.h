#pragma once

enum WalkDirection
{
  eWalkUp,
  eWalkDown,
  eWalkLeft,
  eWalkRight
};

bool
checkIfWalkable(struct Position pos, struct Position *new_pos, enum WalkDirection direction);

void
tryWalk(enum WalkDirection direction);
