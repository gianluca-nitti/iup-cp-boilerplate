# IUP cross platform boilerplate [![Build Status](https://travis-ci.org/gianluca-nitti/iup-cp-boilerplate.svg?branch=master)](https://travis-ci.org/gianluca-nitti/iup-cp-boilerplate)

> IUP is a multi-platform toolkit for building graphical user interfaces.

(from http://webserver2.tecgraf.puc-rio.br/iup/)

This repository is meant to be an (unofficial) starter kit for cross-platform GUI applications based on the IUP library, using the C language for programming and IUP's LED language for user interface definition.

Out-of-the-box it allows you to build lightweight applications for Windows (32 bits) and Linux (32 and 64 bits) using a 64 bit Linux machine (at the moment, the installation of the necessary development packages is automated for Debian based distributions using the APT package manager, and has been tested on Ubuntu). The shell scripts *get-packages.sh* and *get.tools.sh* will set up your development environment by installing the required packages (Mingw-w64 Linux to Windows cross compiler, GTK developement libraries,...) and downloading the IUP libraries and tools (actually the LED language compiler); the Makefile will compile to the targets you pass to ```make``` from the command line, which are linux64, linux32 and win32.

## Features
- Simple to use and customize: run the setup scripts and you will be able to compile for the supported target platform with make. LED files will be automatically translated to C code files, which will then be compiled together with your C source files. By editing the Makefile you can add targets and/or customize the build process.
- For lightweight and standalone applications: your users won't need to install particular runtime environment since on IUP uses the Win32 API on Windows (which is part of the OS) and GTK on Linux (which is included in the majority of desktop distributions). IUP.so or IUP.dll (~1 MB) can be shipped with the application.
- Continuos integration ready: built to work with [Travis-CI](https://travis-ci.org/).

## Tutorial
Here is a simple step-by-step guide to set up an IUP-based application using this boilerplate. This assumes you are working on an x86_64 Linux system with the APT package manager available.

- Put the files from this repository into an empty directory. If you are seting up a new application you probably don't want to push your files back to this repository, so you may just download and extract a tarball or clone the repository and the delete the .git folder.
- From your terminal run in that directory:
    ```
    sudo ./get-packages.sh
    ```
    sudo is required to install packages to your machine with APT. This will probably take a while since these development packages aren't exactly lightweight.
- Then, run
    ```
    ./get-libs.sh
    ```
    this will download and extract IUP libraries and tools to the ```lib/``` and ```tools/``` subfolders.
- You can now compile to all the target platforms by typing
    ```
    make
    ```
    the built binaries can be found in the ```build/linux64/```, ```build/linux32```, ```build/win32/``` subfolders, together with the IUP library, which is necessary at runtime.
    
## Customization
The main files you probably want to customize with metadata about your application are the Makefile, the Windows manifest file (```res/app.manifest```) and the Windows icon (```res/icon.ico```).

- ```Makefile```: in the first line, which actually contains ```APPNAME=test```, you can replace ```test``` with the name of your application. The produced binary files will be named with this text.
- ```res/app.manifest```: at line 6, you can replace ```TestApp``` with the name of your application (this is for the Windows manifest).
- ```icon.ico```: just replace this file with the icon you want your application's .exe file to have on Windows.

## Directory structure
- ```/```: The makefile is actually designed to compile C source files that are at the root of the project, so if you don't change the Makefile you should put your sources in the project's root folder.
- ```res/```: this directory should contain resources for the application. In particuar,
  - ```res/gui/``` should contain LED files that define the application's user interface. You can find more information about the LED language at the official IUP documentation (see http://webserver2.tecgraf.puc-rio.br/iup/en/led.html and browse the documentation at http://webserver2.tecgraf.puc-rio.br/iup/)
- ```lib/``` (created by the ```get-libs.sh``` script): contains the downloaded binaries and headers of the IUP library for the supported platforms.
- ```tools/``` (created by the ```get-libs.sh``` script): contains the ```ledc``` tool, which is used from the makefile to compile LED (GUI definition) files into C files (which then are compiled together with the other C source files from GCC)
- ```build/``` (created by the ```Makefile``` at compile time): contains subdirectories with the compiled binaries for the different platforms.

## License
Open source MIT license (see the LICENSE file).

## Credits
Official site of the IUP library: http://webserver2.tecgraf.puc-rio.br/iup/

The example icon (res/icon.ico) is from https://www.iconfinder.com/iconsets/function_icon_set .
