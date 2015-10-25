#! /bin/bash
# This script is written for distributions based on .deb packages, and it requires the apt-get package manager.
# Run this script to install the cross-compilers for Windows and the compiler libraries to compile for x86 linux from x86_64 linux.
# This script needs to be run as superuser (use sudo ./get-packages)

apt-get update
apt-get install -y atool            # Tool to automate extraction of tar and zip archives, required the library download script.
apt-get install -y mingw-w64        # To cross compile for Windows
apt-get install -y libc6-dev-i386   # To cross compile for Linux x86 from linux x86_64.
apt-get install -y libgtk2.0-dev    # Gtk dev library.
apt-get install -y libgtk2.0-0:i386 # Required for Gtk cross compilation.
