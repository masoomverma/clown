#include "render/screen.hpp"

int main(const int argc, char *argv[])
{
    screen::Screen screen;
    screen.init_terminal();

    if (argc < 2 || argc > 3)
    {
        screen.clear_terminal();

        if (argc < 2)
        {
            printw("Error: Pass the other arguments.\n");
        }
        else
        {
            printw("Error: Too many arguments.\n");
        }

        printw("clown [filename/-arg]\n");
        screen.refresh_all();
        refresh();
        return 1;
    }


    screen.refresh_all();
    refresh();
    getch();

    return OK;
}
