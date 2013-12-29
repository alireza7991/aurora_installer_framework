/* Aurora Installer - a Framework for creating CWM update-binaries
 * Copyright (c) 2013-2014 AliReza Forozandeh Nezhad <afn7991@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * ui.c : generic user interface
 */

#include <aurora.h>

void __inline vibrate(register unsigned int seconds)
{
int2file("/sys/class/timed_output/vibrator/enable", seconds * 1000);
sleep(seconds);
}

void __inline uvibrate(register unsigned int mseconds)
{
int2file("/sys/class/timed_output/vibrator/enable", mseconds);
usleep(mseconds * 1000);
}

void __inline _vibrate(register unsigned int seconds)
{
int2file("/sys/class/timed_output/vibrator/enable", seconds * 1000);
}

void __inline _uvibrate(register unsigned int mseconds)
{
int2file("/sys/class/timed_output/vibrator/enable", mseconds);
}


void __inline setbacklight(unsigned int percent)
{
int2file("/sys/class/leds/lcd-backlight/brightness", (percent / 100) * file2int("/sys/class/leds/lcd-backlight/max_brightness"));
}

void ui_print(const char *fmt, ...)
{
    FILE *recovery_pipe=fdopen(fdid, "wb");
    va_list ap;
    va_start(ap, fmt);
    fprintf(recovery_pipe, "ui_print ");
    vfprintf(recovery_pipe, fmt, ap);
    fprintf(recovery_pipe, "\nui_print\n");
    va_end(ap);
}

void ui_error(const char *fmt, ...)
{
    FILE *recovery_pipe=fdopen(fdid, "wb");
    va_list ap;
    va_start(ap, fmt);
    fprintf(recovery_pipe, "ui_print error: ");
    vfprintf(recovery_pipe, fmt, ap);
    fprintf(recovery_pipe, "\nui_print\n");
    va_end(ap);
    exit(76);
}