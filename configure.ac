AC_INIT(etac, 0.0.1)

AC_LANG(C)
AC_PROG_CC

AC_CHECK_HEADERS(termbox.h, [], [AC_ERROR([termbox must be installed])],[[
#if HAVE_TERMBOX_H
# include <termbox.h>
#endif
]])

AC_SEARCH_LIBS(tb_init, termbox, [], [AC_ERROR([termbox must be installed])])

AC_CHECK_HEADERS(lauxlib.h lua.h lualib.h, [], [AC_ERROR([lua must be installed])],[[
#if HAVE_LAUXLIB_H
# include <lauxlib.h>
#endif

#if HAVE_LUA_H
# include <lua.h>
#endif

#if HAVE_LUALIB_H
# include <lualib.h>
#endif
]])
AC_SEARCH_LIBS(luaL_newstate, lua, [], [AC_ERROR([lua must be installed])])

AC_OUTPUT(Makefile)
