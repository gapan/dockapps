include $(top_srcdir)/Makefile.common.am

bin_PROGRAMS = wmclockmon-config

wmclockmon_config_SOURCES =   \
	actions.c \
	actions.h \
	configfile.h \
	defines.h \
	edit.c \
	edit.h \
	main.c \
	mainwindow.c \
	mainwindow.h \
	tools.c \
	tools.h \
	variables.h

AM_CFLAGS += $(gtk_CFLAGS) $(x11_CFLAGS) $(xext_CFLAGS) $(xpm_CFLAGS)

LDADD = $(gtk_LIBS) $(x11_LIBS) $(xext_LIBS) $(xpm_LIBS)
