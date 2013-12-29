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
 * core.c : setup initializations and jump into package_main. 
 */

const char aurora_copyright[]="Aurora Installer Framework - copyright 2013-2014 Alireza Forozandeh Nezhad aka alireza7991 <afn7991@gmail.com>";

#include <aurora.h>

int main(int argc, char **argv)
{
package *pkg=malloc(sizeof(package *));
pkg->recovery_api=atoi(argv[1]);
pkg->recovery_pipe=fdopen(atoi(argv[2]), "wb");
fdid=atoi(argv[2]);
pkg->package_path=argv[3];
pkg->aurora_version=AURORA_VERSION;
return package_main(pkg);
}