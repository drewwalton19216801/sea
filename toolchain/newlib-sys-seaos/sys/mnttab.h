/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/


/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_MNTTAB_H
#define	_SYS_MNTTAB_H


#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	MNTTAB	"/config/mnttab"
#define	MNT_LINE_MAX	1024

#define	MNT_TOOLONG	1	/* entry exceeds MNT_LINE_MAX */
#define	MNT_TOOMANY	2	/* too many fields in line */
#define	MNT_TOOFEW	3	/* too few fields in line */

#define	mntnull(mp)\
	((mp)->mnt_special = (mp)->mnt_mountp = \
	    (mp)->mnt_fstype = (mp)->mnt_mntopts = \
	    (mp)->mnt_time = NULL)

#define	putmntent(fd, mp)	(-1)

struct mnttab {
	char	*mt_special;
	char	*mt_mountp;
	char	*mt_filsys;
	char	*mt_mntopts;
	char	*mt_time;
	char *mt_dev;
	char   __mt_special_buf[128];
	char   __mt_mountp_buf[256];
	char   __mt_filsys_buf[256];
	char   __mt_mntopts_buf[128];
	char   __mt_time_buf[12];
	char   __mt_dev_buf[256];
};

/*
 * NOTE: fields in extmnttab should match struct mnttab till new fields
 * are encountered, this allows hasmntopt to work properly when its arg is
 * a pointer to an extmnttab struct cast to a mnttab struct pointer.
 */
struct extmnttab {
	char	*mnt_special;
	char	*mnt_mountp;
	char	*mnt_fstype;
	char	*mnt_mntopts;
	char	*mnt_time;
	char *mnt_dev;
	unsigned	mnt_major;
	unsigned	mnt_minor;
	char   __mt_special_buf[128];
	char   __mt_mountp_buf[256];
	char   __mt_filsys_buf[256];
	char   __mt_mntopts_buf[128];
	char   __mt_time_buf[12];
	char   __mt_dev_buf[256];
};

#if !defined(_KERNEL)
#ifdef __STDC__
extern void	resetmnttab(FILE *);
extern int	getmntent(FILE *, struct mnttab *);
extern int	getextmntent(FILE *, struct extmnttab *, size_t);
extern int	getmntany(FILE *, struct mnttab *, struct mnttab *);
extern char	*hasmntopt(struct mnttab *, char *);
extern char	*mntopt(char **);
#else
extern void	resetmnttab();
extern int	getmntent();
extern int	getextmntent();
extern int	getmntany();
extern char	*hasmntopt();
extern char	*mntopt();
#endif
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_MNTTAB_H */
