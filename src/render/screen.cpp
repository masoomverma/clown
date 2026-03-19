#include "render/screen.hpp"

namespace screen
{
    namespace
    {
        void clearWindow(WINDOW* window)
        {
            if (window != nullptr)
            {
                werase(window);
            }
        }

        void refreshWindow(WINDOW* window)
        {
            if (window != nullptr)
            {
                wrefresh(window);
            }
        }
    }

    Screen::Screen()
        : menu_win(nullptr),
          editor_win(nullptr),
          status_win(nullptr),
          rows(0),
          columns(0),
          initialized(false)
    {
    }

    Screen::~Screen() noexcept
    {
        shutdown_terminal();
    }

    void Screen::destroyWindows() noexcept
    {
        if (menu_win != nullptr)
        {
            delwin(menu_win);
            menu_win = nullptr;
        }

        if (editor_win != nullptr)
        {
            delwin(editor_win);
            editor_win = nullptr;
        }

        if (status_win != nullptr)
        {
            delwin(status_win);
            status_win = nullptr;
        }
    }

    void Screen::createWindows()
    {
        menu_win = newwin(1, columns, 0, 0);
        editor_win = newwin(rows - 2, columns, 1, 0);
        status_win = newwin(1, columns, rows - 1, 0);
    }

    void Screen::init_terminal()
    {
        if (initialized)
        {
            updateScreenSize();
            return;
        }

        initscr();
        noecho();
        raw();
        keypad(stdscr, TRUE);

        getmaxyx(stdscr, rows, columns);
        createWindows();

        initialized = true;
    }

    void Screen::shutdown_terminal()
    {
        if (!initialized)
        {
            return;
        }

        destroyWindows();
        endwin();
        initialized = false;
        rows = 0;
        columns = 0;
    }

    void Screen::clear_terminal()
    {
        ::clear();
    }

    void Screen::clearMenu()
    {
        clearWindow(menu_win);
    }

    void Screen::clearEditor()
    {
        clearWindow(editor_win);
    }

    void Screen::clearStatus()
    {
        clearWindow(status_win);
    }

    void Screen::terminal_border()
    {
        box(stdscr, 0, 0);
    }

    void Screen::refreshMenu()
    {
        refreshWindow(menu_win);
    }

    void Screen::refreshEditor()
    {
        refreshWindow(editor_win);
    }

    void Screen::refreshStatus()
    {
        refreshWindow(status_win);
    }

    void Screen::refresh_all()
    {
        refreshWindow(menu_win);
        refreshWindow(editor_win);
        refreshWindow(status_win);
    }

    void Screen::updateScreenSize()
    {
        if (!initialized)
        {
            return;
        }

        getmaxyx(stdscr, rows, columns);
        destroyWindows();
        createWindows();
    }

    void Screen::getScreenSize(int& r, int& c) const
    {
        r = rows;
        c = columns;
    }
}
