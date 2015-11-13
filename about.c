#include <stdlib.h>
#include <iup.h>
#include "about.h"

Ihandle* about_init(){
	IupSetAttribute(NULL, "HELPAPP", "xdg-open"); //(Linux only) sets the command to be run to open web links (useful for the help link).
	IupSetCallback(IupGetHandle("iupLink"), "ACTION", (Icallback)about_iupWeb); //Callback for the about link
	IupSetCallback(IupGetHandle("aboutClose"), "ACTION", (Icallback)about_close); //Callback for the about dialog close button
	return IupGetHandle("aboutDlg"); //Loads the GUI definiton of the about dialog, passing it to the code that calls this function
}

void about_iupWeb(){ //Callback for the link of the about dialog
	IupHelp(IupGetAttribute(IupGetHandle("iupLink"), "URL")); //Launches a web browser to the URL attribute of the iupLink label
}

int about_close(Ihandle *btn){ //Callback for the close button of the about dialog
	IupHide(IupGetDialog(btn)); //Closes this about dialog
	return IUP_DEFAULT;
}
