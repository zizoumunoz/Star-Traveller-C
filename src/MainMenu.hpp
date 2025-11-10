#pragma once

typedef enum MenuOption
{
    START_GAME,
    SETTINGS,
    HELP,
    EXIT
} MenuOption;

typedef struct MainMenu
{
    MenuOption _currentOption;
    void (*display_options)();
    const char *menu_options[4] = {
        "Start Game",
        "Settings",
        "Help",
        "Exit"};

} MainMenu;
