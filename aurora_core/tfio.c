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
 * tfio.c : Text File I/O functions .
 */

#include <aurora.h>

unsigned char tfio_sign[]="Copyright (c) 2013-2014 AliReza Forozandeh Nezhad <afn7991@gmail.com>";

int __inline file2int(char *file_path)
{
FILE *file=fopen(file_path, "r");
char *val=malloc(sizeof(char *));
int ret=fscanf(file, "%s", val);
fclose(file);
return atoi(val);
}

void __inline int2file(char *file_path, register int val)
{
FILE *file=fopen(file_path, "w");
fprintf(file, "%d", val);
fclose(file);
}


void __inline str2file(char *file_path, char * val)
{
FILE *file=fopen(file_path, "w");
fprintf(file, "%s", val);
fclose(file);
}

char *file2str(char *file_path)
{
FILE *file=fopen(file_path, "r");
char *val=malloc(sizeof(char *));
int ret=fscanf(file, "%s", val);
fclose(file);
return val;
}

char *lineoffile(char *tf_path,unsigned register int lno)
{
FILE *file=fopen(tf_path, "r");
char *cbuff=malloc(sizeof(char *));
unsigned register int lc=0;
while(!feof(file))
{
lc++;
fgets(cbuff, sizeof(cbuff), file);
if(lno==lc) 
{
fclose(file);
return cbuff;
}
}
}





