#include <iostream>
#include <string>
#include <vector>

class MENU_Main {

};

class MENU_HELP : public MENU_Main {

};

template <typename T>
void callMenu(T menu);