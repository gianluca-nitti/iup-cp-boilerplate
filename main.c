#include <stdlib.h>
#include <iup.h>
#include "about.h"

void led_load (void);

Ihandle *mainDlg, *aboutDlg;

void main_about(){ //Callback for the about button of the main dialog
	IupPopup(aboutDlg, IUP_CENTERPARENT, IUP_CENTERPARENT); //Shows the "about" window
}

int main(int argc, char **argv)
{
  IupOpen(&argc, &argv);
	led_load(); //Loads the GUI compiled from LED files.
	mainDlg = IupGetHandle("mainDlg"); //Get the window named "mainDlg"
	IupShowXY(mainDlg, IUP_CENTER, IUP_CENTER); //Shows the main window

	aboutDlg = about_init(); //Get the window named "aboutDlg"
	IupSetCallback(IupGetHandle("about"), "ACTION", (Icallback)main_about); //Callback: Associates the click action of the button "about" with the "about" function.

  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
