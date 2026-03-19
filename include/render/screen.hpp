#ifndef CLOWN_SCREEN_HPP
#define CLOWN_SCREEN_HPP

#include "../curses.h"

namespace screen
{
    class Screen
    {
    private:
        WINDOW* menu_win;
        WINDOW* editor_win;
        WINDOW* status_win;

        int rows;
        int columns;

        bool initialized;

        void destroyWindows() noexcept;
        void createWindows();

    public:
        Screen();
        ~Screen() noexcept;

        Screen(const Screen&) = delete;
        Screen& operator=(const Screen&) = delete;
        Screen(Screen&&) = delete;
        Screen& operator=(Screen&&) = delete;

        void init_terminal();
        void shutdown_terminal();

        void clear_terminal();
        void clearMenu();
        void clearEditor();
        void clearStatus();

        void terminal_border();

        void refreshMenu();
        void refreshEditor();
        void refreshStatus();
        void refresh_all();

        void getScreenSize(int& r, int& c) const;
        void updateScreenSize();
    };
}

#endif // CLOWN_SCREEN_HPP