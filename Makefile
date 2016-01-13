APPNAME=test

SRC=*.c
GUIS=./res/gui/*.led

CC_LINUX=gcc
CC_WIN=i686-w64-mingw32-gcc
WINDRES=i686-w64-mingw32-windres
STRIP=strip

CFLAGS= -Os -fdata-sections -ffunction-sections -Wall -Werror -Wl,--gc-sections

GTK_LIBS=-lgtk-x11-2.0 -lgdk-x11-2.0 -lgdk_pixbuf-2.0 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lXext -lX11 -lm

INCS_WIN32=-Ilib/win32/iup/include
INCS_LINUX32=-Ilib/linux32/iup/include
INCS_LINUX64=-Ilib/linux64/iup/include

LIBS_WIN32=lib/win32/iup/libiup.a -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32
LIBS_LINUX32=lib/linux32/iup/libiup.a $(GTK_LIBS)
LIBS_LINUX64=lib/linux64/iup/libiup.a $(GTK_LIBS)

all: win32 linux32 linux64

.PHONY: dir ledc win32 linux32 linux64 clean

dir:
	mkdir -p build

ledc:
	./tools/ledc -o ./gui_compiled.c $(GUIS)

win32: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	$(WINDRES) res/res.rc -O coff -o res/resources.res
	$(CC_WIN) $(SRC) res/resources.res $(INCS_WIN32) $(LIBS_WIN32) $(CFLAGS) -Wl,-subsystem,windows -o build/$@/$(APPNAME).exe
	$(STRIP) build/$@/$(APPNAME).exe

linux32: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	$(CC_LINUX) -m32 $(SRC) $(INCS_LINUX32) $(LIBS_LINUX32) $(CFLAGS) -o build/$@/$(APPNAME)
	$(STRIP) build/$@/$(APPNAME)

linux64: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	$(CC_LINUX) $(SRC) $(INCS_LINUX64) $(LIBS_LINUX64) $(CFLAGS) -o build/$@/$(APPNAME)
	$(STRIP) build/$@/$(APPNAME)

clean:
	rm -rf build/
