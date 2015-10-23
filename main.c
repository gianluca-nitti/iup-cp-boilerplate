#include <stdlib.h>
#include <stdint.h>
#include <iup.h>

void led_load (void);

int main(int argc, char **argv)
{
  IupOpen(&argc, &argv);
	led_load(); //Loads the GUI compiled from LED files.
	Ihandle *dlg = IupGetHandle("main"); //Get the window named "main"
	IupShowXY(dlg, IUP_CENTER, IUP_CENTER); //Shows the window
  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
