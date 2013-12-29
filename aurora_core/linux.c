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
 * linux.c : linux kernel related functions. 
 */
#include <syscall.h>
#include <unistd.h>

#define MS_MGC_VAL 0xc0ed0000

int __aurora_mount(const char *special, const char *dir, const char *fstype)
{
	return syscall(SYS_mount, special, dir, fstype, MS_MGC_VAL , "");
}

int __aurora_umount(const char *special)
{
	return syscall(SYS_umount2, special, 0);
}