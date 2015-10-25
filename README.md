# IUP cross platform boilerplate

> IUP is a multi-platform toolkit for building graphical user interfaces.

(from http://webserver2.tecgraf.puc-rio.br/iup/)

This repository is meant to be a starter kit for cross-platform GUI applications based on the IUP library, using the C language for programming and IUP's LED language for user interface definition.

Out-of-the-box it allows you to build lightweight applications for Windows (32 bits) and Linux (32 and 64 bits) using a 64 bit Linux machine (at the moment, the installation of the necessary development packages is automated for Debian based distributions using the APT package manager, and has been tested on Ubuntu). The shell scripts *get-packages.sh* and *get.tools.sh* will set up your development environment by installing the required packages (Mingw-w64 Linux to Windows cross compiler, GTK developement libraries,...) and downloading the IUP libraries and tools (actually the LED language compiler); the Makefile will compile to the targets you pass to make, which are linux64, linux32 and win32.

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
    this will download and extract IUP libraries and tools to the lib/ and tools/ subfolders.
- You can now compile to all the target platforms by typing
    ```
    make
    ```
    the built binaries can be found in the build/linux64/, build/linux32, build/win32/ subfolders, together with the IUP library necessary at runtime.
    
## Customization
(documentation under construction)

## Credits

Example icon (res/icon.ico) is form https://www.iconfinder.com/iconsets/function_icon_set .
