#include <stdlib.h>
#include <stdint.h>
#include <iup.h>

#include <stdio.h>

void led_load (void);

Ihandle *mainDlg, *aboutDlg;

void main_about(){
	IupPopup(aboutDlg, IUP_CENTER, IUP_CENTER); //Shows the "about" window
}

void about_iupWeb(){
	IupHelp(IupGetAttribute(IupGetHandle("iupLink"), "URL"));
}

void about_close(){
	IupHide(aboutDlg);
}

int main(int argc, char **argv)
{
  IupOpen(&argc, &argv);
	led_load(); //Loads the GUI compiled from LED files.
	mainDlg = IupGetHandle("mainDlg"); //Get the window named "mainDlg"
	aboutDlg = IupGetHandle("aboutDlg"); //Get the window named "aboutDlg"
	IupShowXY(mainDlg, IUP_CENTER, IUP_CENTER); //Shows the window

	IupSetAttribute(NULL, "HELPAPP", "xdg-open");
	IupSetCallback(IupGetHandle("about"), "ACTION", (Icallback)main_about); //Callback: Associates the click action of the button "about" with the "about" function.
	IupSetCallback(IupGetHandle("iupLink"), "ACTION", (Icallback)about_iupWeb); //Callback for the about link
	IupSetCallback(IupGetHandle("aboutClose"), "ACTION", (Icallback)about_close); //Callback for the about dialog close button

  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
