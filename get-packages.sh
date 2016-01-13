#! /bin/bash
# This script is written for distributions based on .deb packages, and it requires the apt-get package manager.
# Run this script to install the cross-compilers for Windows and the compiler libraries to compile for x86 linux from x86_64 linux.
# This script needs to be run as superuser (use sudo ./get-packages.sh)

dpkg --add-architecture i386
apt-get update
apt-get install -y atool            # Tool to automate extraction of tar and zip archives, required the library download script.
apt-get install -y mingw-w64        # To cross compile for Windows
apt-get install -y libc6-dev-i386   # To cross compile for Linux x86 from linux x86_64.
apt-get install -y libgtk2.0-dev    # Gtk dev library.
apt-get install -y libgtk2.0-0:i386 # Required for Gtk cross compilation.

#These links are necessary for the cross-compilation from x86_64 Linux to x86 Linux to link the code with the GTK driver and it's dependencies (credit: http://stackoverflow.com/a/20845987)
ln -s /lib/i386-linux-gnu/libglib-2.0.so.0 /usr/lib32/libglib-2.0.so
ln -s /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0 /usr/lib32/libgtk-x11-2.0.so
ln -s /usr/lib/i386-linux-gnu/libgdk-x11-2.0.so.0 /usr/lib32/libgdk-x11-2.0.so
ln -s /usr/lib/i386-linux-gnu/libatk-1.0.so.0 /usr/lib32/libatk-1.0.so
ln -s /usr/lib/i386-linux-gnu/libpangox-1.0.so.0 /usr/lib32/libpangox-1.0.so
ln -s /usr/lib/i386-linux-gnu/libpango-1.0.so.0 /usr/lib32/libpango-1.0.so
ln -s /usr/lib/i386-linux-gnu/libgmodule-2.0.so.0 /usr/lib32/libgmodule-2.0.so
ln -s /usr/lib/i386-linux-gnu/libgobject-2.0.so.0 /usr/lib32/libgobject-2.0.so
ln -s /usr/lib/i386-linux-gnu/libgdk_pixbuf-2.0.so.0 /usr/lib32/libgdk_pixbuf-2.0.so
ln -s /usr/lib/i386-linux-gnu/libXext.so.6 /usr/lib32/libXext.so
ln -s /usr/lib/i386-linux-gnu/libX11.so.6 /usr/lib32/libX11.so
