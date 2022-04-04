#include <pspctrl.h>
#include <stdio.h>

#include "controls.h"
#include "movement.h"
#include "field.h"

// Only used once inside controls.cpp, so it's safe to make it static
// (will make it invisible for other files)
static SceCtrlData pad, pad_old;

bool
buttonRecentlyPressed(int bitmask)
{
    if (!(pad_old.Buttons & bitmask) && (pad.Buttons & bitmask)) {
        return true;
    }
    return false;
}

void
execControls()
{
    sceCtrlReadBufferPositive(&pad, 1);
    //TO DO: If movecount = 0 die()

    if (pad.Buttons != 0) {
      if (buttonRecentlyPressed(PSP_CTRL_SQUARE)) {
        printf("Square pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_TRIANGLE)) {
        printf("Triangle pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_CIRCLE)) {
        printf("Cicle pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_CROSS)) {
        printf("Cross pressed \n");
      }

      if (buttonRecentlyPressed(PSP_CTRL_UP)) {
        tryWalk(eWalkUp);
        printf("Up pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_DOWN)) {
        tryWalk(eWalkDown);
        printf("Down pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_LEFT)) {
        tryWalk(eWalkLeft);
        printf("Left pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_RIGHT)) {
        tryWalk(eWalkRight);
        printf("Right pressed \n");
      }

      if (buttonRecentlyPressed(PSP_CTRL_START)) {
        printf("Start pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_START)) {
        printf("Select pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_START)) {
        printf("L-trigger pressed \n");
      }
      if (buttonRecentlyPressed(PSP_CTRL_START)) {
        printf("R-trigger pressed \n");
      }
    }
    pad_old = pad;
}

