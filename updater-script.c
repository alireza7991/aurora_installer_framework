/* A simple example of updater-script s in Aurora Installer Framework */

#include <aurora.h>

int package_main(package *pkg)
{
ui_print("hello world");
vibrate(1); 
ui_print("I'm aurora installer!");
return 0;
}


