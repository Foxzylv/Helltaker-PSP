/*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * main.c - Basic Input demo -- reads from control pad and indicates button
 *          presses.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 * Copyright (c) 2005 Donour Sizemore <donour@uchicago.edu>
 *
 * $Id: main.c 1095 2005-09-27 21:02:16Z jim $
 */
#include <pspctrl.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>


#include "controls.h"
#include "field.h"
#include "movement.h"

/* Define the module info section */
PSP_MODULE_INFO("CONTROLTEST", 0, 1, 1);

/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

/* Define printf, just to make typing easier */
//#define printf pspDebugScreenPrintf

void
dump_threadstatus(void);

int done = 0;

/* Exit callback */
int
exit_callback(int arg1, int arg2, void* common)
{
  done = 1;
  return 0;
}

/* Callback thread */
int
CallbackThread(SceSize args, void* argp)
{
  int cbid;

  cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
  sceKernelRegisterExitCallback(cbid);
  sceKernelSleepThreadCB();

  return 0;
}

/* Sets up the callback thread and returns its thread id */
int
SetupCallbacks(void)
{
  int thid = 0;

  thid =
    sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
  if (thid >= 0) {
    sceKernelStartThread(thid, 0, 0);
  }

  return thid;
}

int
main(void)
{
  pspDebugScreenInit();
  SetupCallbacks();

  sceCtrlSetSamplingCycle(0);
  sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

  while (!done) {
    pspDebugScreenSetXY(0, 2);

    printField();

    pspDebugScreenSetXY(0, 3);

    execControls();

  }

  sceKernelExitGame();
  return 0;
}
