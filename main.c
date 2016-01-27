#include <stdlib.h>
#include <iup.h>
#include "tools.h"
#include "about.h"

Ihandle *mainDlg, *aboutDlg;

void main_about(){ //Callback for the about button of the main dialog
	IupPopup(aboutDlg, IUP_CENTERPARENT, IUP_CENTERPARENT); //Shows the "about" window
}

int main(int argc, char **argv){
	IupOpen(&argc, &argv);
	#ifdef LINUX
	Ihandle *mainIcon = load_image_icon_ico(); //Loads the main dialog's icon (only for Linux, on Windows this is automatic since the icon is included as a resource)...
	IupSetHandle("MAINICON", mainIcon); //and associates it with the "MAINICON" name, so it's recognized by the GUI definition in the res/gui/main.led file.
	#endif
	led_load(); //Loads the GUI compiled from LED files.
	mainDlg = IupGetHandle("mainDlg"); //Get the window named "mainDlg"
	IupShowXY(mainDlg, IUP_CENTER, IUP_CENTER); //Shows the main window

	aboutDlg = about_init(); //Get the window named "aboutDlg"
	IupSetCallback(IupGetHandle("about"), "ACTION", (Icallback)main_about); //Callback: Associates the click action of the button "about" with the "about" function.

 	IupMainLoop();
 	IupClose();
	return EXIT_SUCCESS;
}
