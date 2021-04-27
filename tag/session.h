#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>
extern void session_init(int soc, char mc, int mx, int my, char pc, int px, int py);
extern void session_loop();
