/*
   Copyright (c) 2009-2010 Jay Sorg

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <freerdp/freerdp.h>
#include <freerdp/kbd.h>
#include "xf_types.h"
#include "xf_win.h"
#include "xf_keyboard.h"

static int xf_kb_keyboard_layout = 0;
static RD_BOOL pressed_keys[256] = { False };

void
xf_kb_init(unsigned int keyboard_layout_id)
{
	xf_kb_keyboard_layout = freerdp_kbd_init(keyboard_layout_id);
	printf("freerdp_kbd_init: %X\n", xf_kb_keyboard_layout);
}

void
xf_kb_inst_init(xfInfo * xfi)
{
	xfi->inst->settings->keyboard_layout = xf_kb_keyboard_layout;
};

void
xf_kb_send_key(xfInfo * xfi, int flags, uint8 keycode)
{
	int scancode;

	if (keycode == xfi->pause_key)
	{
		/* This is a special key the actually sends two scancodes to the
		   server.  It looks like Control - NumLock but with special flags. */
		//printf("special VK_PAUSE\n");
		if (flags & KBD_FLAG_UP)
		{
			xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, 0x8200, 0x1d, 0);
			xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, 0x8000, 0x45, 0);
		}
		else
		{
			xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, 0x0200, 0x1d, 0);
			xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, 0x0000, 0x45, 0);
		}
	}
	else
	{
		scancode = freerdp_kbd_get_scancode_by_keycode(keycode, &flags);
#ifndef WITH_DEBUG_KBD
		if (scancode == 0)
		{
#endif
			printf("xf_kb_send_key: (keycode=%d keysym=0x%04X scancode=%d)\n",
				keycode, (unsigned int)XKeycodeToKeysym(xfi->display, keycode, 0), scancode);
#ifndef WITH_DEBUG_KBD
		}
		else
#endif
		{
			xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, flags, scancode, 0);
		}
	}
}

static int
xf_kb_read_keyboard_state(xfInfo * xfi)
{
	uint32 state;
	Window wdummy;
	int dummy;

	XQueryPointer(xfi->display, xfi->wnd, &wdummy, &wdummy, &dummy, &dummy,
		&dummy, &dummy, &state);
	return state;
}

static RD_BOOL
xf_kb_get_key_state(xfInfo * xfi, int state, int keysym)
{
	int modifierpos, key, keysymMask = 0;
	int offset;
	KeyCode keycode = XKeysymToKeycode(xfi->display, keysym);

	if (keycode == NoSymbol)
	{
		return False;
	}
	for (modifierpos = 0; modifierpos < 8; modifierpos++)
	{
		offset = xfi->mod_map->max_keypermod * modifierpos;
		for (key = 0; key < xfi->mod_map->max_keypermod; key++)
		{
			if (xfi->mod_map->modifiermap[offset + key] == keycode)
			{
				keysymMask |= 1 << modifierpos;
			}
		}
	}
	return (state & keysymMask) ? True : False;
}

int
xf_kb_get_toggle_keys_state(xfInfo * xfi)
{
	int toggle_keys_state = 0;
	int state;

	state = xf_kb_read_keyboard_state(xfi);
	if (xf_kb_get_key_state(xfi, state, XK_Scroll_Lock))
	{
		toggle_keys_state |= KBD_SYNC_SCROLL_LOCK;
	}
	if (xf_kb_get_key_state(xfi, state, XK_Num_Lock))
	{
		toggle_keys_state |= KBD_SYNC_NUM_LOCK;
	}
	if (xf_kb_get_key_state(xfi, state, XK_Caps_Lock))
	{
		toggle_keys_state |= KBD_SYNC_CAPS_LOCK;
	}
	if (xf_kb_get_key_state(xfi, state, XK_Kana_Lock))
	{
		toggle_keys_state |= KBD_SYNC_KANA_LOCK;
	}
	return toggle_keys_state;
}

void
xf_kb_focus_in(xfInfo * xfi)
{
	int flags;
	int scancode;

	/* on focus in send a tab up like mstsc.exe */
	scancode = freerdp_kbd_get_scancode_by_virtualkey(xfi->tab_key);
	xfi->inst->rdp_send_input(xfi->inst, RDP_INPUT_SCANCODE, KBD_FLAG_UP, scancode, 0);
	/* sync num, caps, scroll, kana lock */
	flags = xf_kb_get_toggle_keys_state(xfi);
	xfi->inst->rdp_sync_input(xfi->inst, flags);
}

void
xf_kb_set_keypress(uint8 keycode, KeySym keysym)
{
	if (keycode < 8 || keycode > 255)
		return;
	pressed_keys[keycode] = keysym;
}

void
xf_kb_unset_keypress(uint8 keycode)
{
	if (keycode < 8 || keycode > 255)
		return;
	pressed_keys[keycode] = NoSymbol;
}

static RD_BOOL
xf_kb_key_pressed(xfInfo * xfi, KeySym keysym)
{
	KeyCode keycode = XKeysymToKeycode(xfi->display, keysym);
	return pressed_keys[keycode] == keysym;
}

RD_BOOL
xf_kb_handle_special_keys(xfInfo * xfi, KeySym keysym)
{
	if (keysym == XK_Return)
	{
		if ((xf_kb_key_pressed(xfi, XK_Alt_L) || xf_kb_key_pressed(xfi, XK_Alt_R))
		    && (xf_kb_key_pressed(xfi, XK_Control_L) || xf_kb_key_pressed(xfi, XK_Control_R)))
		{
			/* Ctrl-Alt-Enter: toggle full screen */
			xf_toggle_fullscreen(xfi);
			return True;
		}
	}

	return False;
}
