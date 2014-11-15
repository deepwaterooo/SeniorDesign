/*
bVirtualKey //Virtual Keycode of keys. E.g., VK_RETURN, VK_TAB...
bScanCode //Scan Code value of keys. E.g., 0xb8 for "Left Alt" key.
dwFlags //Flag that is set for key state. E.g., KEYEVENTF_KEYUP.
dwExtraInfo //32-bit extra information about keystroke.

* bVirtualKey: Virtual keycode that has to be send as key input. The following are the available predefined virtu* al key codes:
* VK_SHIFT	0x10
* VK_CONTROL	0x11
VK_LSHIFT	0xA0
VK_RSHIFT	0xA1
VK_LCONTROL	0xA2
VK_RCONTROL	0xA3
Character key can be converted into virtual key using VkKeyScan(TCHAR ch) function.
*/
void keybd_event(BYTE bVirtualKey, BYTE bScanCode, DWORD dwFlags, DWORD dwExtraInfo);

// Simulating a Alt+Tab keystroke
keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
keybd_event(VK_TAB,0x8f,0 , 0); // Tab Press
keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release

// Simulating a Ctrl+A keystroke
keybd_event(VK_CONTROL,0x9d,0 , 0); // Ctrl Press
keybd_event(VkKeyScan('A'),0x9e,0 , 0); // 'A' Press
keybd_event(VkKeyScan('A'),0x9e, KEYEVENTF_KEYUP,0); // 'A' Release
keybd_event(VK_CONTROL,0x9d,KEYEVENTF_KEYUP,0); // Ctrl Release

