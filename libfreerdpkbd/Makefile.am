## Process this file with automake to produce Makefile.in

# libfreerdpkbd
libfreerdpkbddir = $(libdir)

libfreerdpkbd_LTLIBRARIES = libfreerdpkbd.la

libfreerdpkbd_la_SOURCES = \
	keyboard.h \
	locales.h \
	libfreerdpkbd.c

libfreerdpkbd_la_CFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include \
	-DKEYMAP_PATH=\"$(KEYMAP_PATH)\"

libfreerdpkbd_la_LDFLAGS =

# extra
EXTRA_DIST =

DISTCLEANFILES = 

