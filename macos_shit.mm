#include <AppKit/AppKit.h>

extern "C" void SetMacWindowMenu(NSMenu *pMenu)
{
    NSApplication *pApp = NSApplication.sharedApplication;
    if (pApp.windowsMenu)
    {
        return;
    }

    [pApp setWindowsMenu:(pMenu)];
}
