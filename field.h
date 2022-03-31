#pragma once

#include "position.h"

enum FieldPieces
{
  eGround,
  eRock,
  eKey,
  eGoal,
  eLock,
  eEnemy,
  eWall
};

// Offset of the board in characters
#define X_OFFSET 10
#define Y_OFFSET 10

#define X_SIZE 6
#define Y_SIZE 7

// Structure of a field only
struct Field
{
  enum FieldPieces pieces[Y_SIZE][X_SIZE];
};

// Variables implemented in field.cpp
extern Field field;

extern struct Position player;

// Functions implemented in field.cpp
const char*
look_up_symbol(enum FieldPieces piece);

void
printField();
