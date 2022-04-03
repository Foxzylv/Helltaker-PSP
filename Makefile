TARGET = template
OBJS = src/main.o src/field.o src/movement.o src/controls.o
DEPENDS = $(OBJS:.o=.d)

BUILD_PRX=1

INCDIR = 
CFLAGS = -O2 -G0 -Wall -MMD
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Helltaker
PSP_EBOOT_ICON = ICON0.Png
PSP_EBOOT_PIC1 = PIC1.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

-include $(DEPENDS)
