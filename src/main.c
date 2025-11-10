#include <stdio.h>
#include "BearLibTerminal.h"

int main() 
{
    printf("Star Traveller C\n");

    terminal_open();

    terminal_set("window: size=80x25");
    terminal_print(2, 1, "Hello, World!");
    terminal_refresh();
    terminal_read();
    terminal_close();

    return 0;
}
