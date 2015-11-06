#include <stdlib.h>
#include <stdint.h>
#include <iup.h>

void led_load (void);

Ihandle *mainDlg;

//Example code: you probably want to remove this when writing your application.
Ihandle *aboutDlg;

void main_about(){ //callback for the about button of the main dialog
	IupPopup(aboutDlg, IUP_CENTERPARENT, IUP_CENTERPARENT); //Shows the "about" window
}

void about_iupWeb(){ //callback for the link of the about dialog
	IupHelp(IupGetAttribute(IupGetHandle("iupLink"), "URL")); //Launches a web browser to the URL attribute of the iupLink label
}

void about_close(){ //callback for the close button of the about dialog
	IupHide(aboutDlg);
}
//End of example code

int main(int argc, char **argv)
{
  IupOpen(&argc, &argv);
	led_load(); //Loads the GUI compiled from LED files.
	mainDlg = IupGetHandle("mainDlg"); //Get the window named "mainDlg"
	IupShowXY(mainDlg, IUP_CENTER, IUP_CENTER); //Shows the main window

	//Example code
	aboutDlg = IupGetHandle("aboutDlg"); //Get the window named "aboutDlg"
	IupSetAttribute(NULL, "HELPAPP", "xdg-open"); //(Linux only) sets the command to be run to open web links (useful for the help link).
	IupSetCallback(IupGetHandle("about"), "ACTION", (Icallback)main_about); //Callback: Associates the click action of the button "about" with the "about" function.
	IupSetCallback(IupGetHandle("iupLink"), "ACTION", (Icallback)about_iupWeb); //Callback for the about link
	IupSetCallback(IupGetHandle("aboutClose"), "ACTION", (Icallback)about_close); //Callback for the about dialog close button
	//End of example code

  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
