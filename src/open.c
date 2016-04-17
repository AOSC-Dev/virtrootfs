/*
    Anthon Uniform Configuration Helper
    Copyright (C) 2016 bobcao3 <bobcaocheng@163.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "virtrootfs.h"
#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fuse.h>

int vrfs_open(const char *path, struct fuse_file_info *fi) {
	// Here goes codes to make phy path
	// p = xxx
	char *p;
	p = "/etc/fstab"; // Test usage
	
	int fd = open(p, fi->flags);
	if (fd == -1) return -errno;
	
	fi->fh = (unsigned long)fd;
	
	return 0;
}

int vrfs_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
	int i = pread(fi->fh, buf, size, offset);

	if (i == -1) return -errno;

	return i;
}