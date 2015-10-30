#include <stdlib.h>
#include <stdint.h>
#include <iup.h>

void led_load (void);

Ihandle *mainDlg, *aboutDlg;

void about(){
	IupPopup(aboutDlg, IUP_CENTER, IUP_CENTER); //Shows the "about" window
}

int main(int argc, char **argv)
{
  IupOpen(&argc, &argv);
	led_load(); //Loads the GUI compiled from LED files.
	mainDlg = IupGetHandle("mainDlg"); //Get the window named "mainDlg"
	aboutDlg = IupGetHandle("aboutDlg"); //Get the window named "aboutDlg"
	IupShowXY(mainDlg, IUP_CENTER, IUP_CENTER); //Shows the window
	IupSetCallback(IupGetHandle("about"), "ACTION", (Icallback)about); //Associates the click action of the button "about" with the "about" function.
  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
