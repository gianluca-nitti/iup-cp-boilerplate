APPNAME=test

SRC=*.c
GUIS=./res/gui/*.led

CC_LINUX=gcc
CC_WIN=i686-w64-mingw32-gcc
WINDRES=i686-w64-mingw32-windres

CFLAGS= -Os -fdata-sections -ffunction-sections -Wall -Werror -Wl,--gc-sections,-rpath,'$${ORIGIN}'

INCS_WIN32=-Ilib/win32/iup/include
INCS_LINUX32=-Ilib/linux32/iup/include
INCS_LINUX64=-Ilib/linux64/iup/include

LIBS_WIN32=-liup -Llib/win32/iup
LIBS_LINUX32=-liup -Llib/linux32/iup
LIBS_LINUX64=-liup -Llib/linux64/iup

all: win32 linux32 linux64

.PHONY: dir
dir:
	mkdir -p build

.PHONY: ledc
ledc:
	./tools/ledc -o ./gui_compiled.c $(GUIS)

.PHONY: win32
win32: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	cp lib/$@/iup/iup.dll build/$@
	$(WINDRES) res/res.rc -O coff -o res/resources.res
	$(CC_WIN) $(SRC) res/resources.res $(INCS_WIN32) $(LIBS_WIN32) $(CFLAGS) -Wl,-subsystem,windows -o build/$@/$(APPNAME).exe

.PHONY: linux32
linux32: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	cp lib/$@/iup/libiup.so build/$@
	$(CC_LINUX) -m32 $(SRC) $(INCS_LINUX32) $(LIBS_LINUX32) $(CFLAGS) -o build/$@/$(APPNAME)
 
.PHONY: linux64
linux64: dir ledc
	rm -rf build/$@
	mkdir -p build/$@
	cp lib/$@/iup/libiup.so build/$@
	$(CC_LINUX) $(SRC) $(INCS_LINUX64) $(LIBS_LINUX64) $(CFLAGS) -o build/$@/$(APPNAME)

.PHONY: clean
clean:
	rm -rf build/
