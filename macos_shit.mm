#include <AppKit/AppKit.h>

extern "C" void SetMacWindowMenu(NSMenu *pMenu)
{
    NSApplication *pApp = NSApplication.sharedApplication;

    [pApp setWindowsMenu:(pMenu)];
}
