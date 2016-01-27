#! /bin/bash
# This script will download the IUP libraries to the lib/ directory.

set -e
mkdir -p lib
getLibFiles(){
	printf "Setting up IUP library for $2.\n\nStarting download...\n\n"
	# wget -O lib/iup-$1.tar.gz http://sourceforge.net/projects/iup/files/3.15/$1%20Libraries/iup-3.15_Linux319_64_lib.tar.gz
	wget -O lib/iup-temp http://sourceforge.net/projects/iup/files/$1
	printf "Extracting archive...\n\n"
	mkdir -p lib/$2/iup
	# tar -C lib/$2/iup -xf lib/iup-temp.tar.gz
	atool -X lib/$2/iup lib/iup-temp
	rm lib/iup-temp
	printf "Done.\n\n"
}
getLibFiles "3.15/Linux%20Libraries/iup-3.15_Linux32_64_lib.tar.gz/download" linux64
getLibFiles "3.15/Linux%20Libraries/iup-3.15_Linux32_lib.tar.gz/download" linux32
getLibFiles "3.15/Windows%20Libraries/Static/iup-3.15_Win32_mingw4_lib.zip/download" win32

# This will download the IUP tools, including the necessary LEDC compiler for LED files, to the tools/ directory.

mkdir -p tools
echo "Downloading IUP tools..."
wget -O tools/iuptools.tar.gz http://sourceforge.net/projects/iup/files/3.15/Tools%20Executables/iup-3.15_Linux319_64_bin.tar.gz
echo "Extrcting ledc..."
tar -C tools -zxvf tools/iuptools.tar.gz ledc iupview
rm tools/iuptools.tar.gz
echo "Done."
