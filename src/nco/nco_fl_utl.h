/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_fl_utl.h,v 1.8 2002-09-09 03:40:00 zender Exp $ */

/* Purpose: File manipulation */

/* Copyright (C) 1995--2002 Charlie Zender
   This software is distributed under the terms of the GNU General Public License
   See http://www.gnu.ai.mit.edu/copyleft/gpl.html for full license text */

/* Usage:
   #include "nco_fl_utl.h" *//* File manipulation */

#ifndef NCO_FL_UTL_H
#define NCO_FL_UTL_H

#ifdef HAVE_CONFIG_H
#include <config.h> /* Autotools tokens */
#endif /* !HAVE_CONFIG_H */

/* Standard header files */
#include <math.h> /* sin cos cos sin 3.14159 */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <stdlib.h> /* strtod, strtol, malloc, getopt, exit */
#include <string.h> /* strcmp. . . */
#include <sys/stat.h> /* stat() */
#include <unistd.h> /* POSIX stuff */

#include <sys/types.h> /* needed for _res */
#include <netinet/in.h> /* needed for _res */
#include <pwd.h> /* password structures for getpwuid() */
#ifndef WIN32
#include <arpa/nameser.h> /* needed for _res */
#include <resolv.h> /* Internet structures for _res */
#endif

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions */
#include "nco_netcdf.h" /* netCDF3.0 wrapper functions */

/* Personal headers */
#include "nco.h" /* NCO definitions */
#include "nco_ctl.h" /* Program flow control functions */
#include "nco_mmr.h" /* Memory management */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void
nco_fl_cp /* [fnc] Copy first file to second */
(const char * const fl_src, /* I [sng] Name of source file to copy */
 const char * const fl_dst); /* I [sng] Name of destination file */

void
fl_mv /* [fnc] Move first file to second */
(const char * const fl_src, /* I [sng] Name of source file to move */
 const char * const fl_dst); /* I [sng] Name of destination file */

void 
nco_fl_rm /* [fnc] Remove file */
(char *fl_nm); /* I [sng] File to be removed */

char * /* O [sng] Filename of locally available file */
nco_fl_mk_lcl /* [fnc] Retrieve input file and return local filename */
(char *fl_nm, /* I/O [sng] Current filename, if any (destroyed) */
 const char * const fl_pth_lcl, /* I [sng] Local storage area for files retrieved from remote locations */
 int * const FILE_RETRIEVED_FROM_REMOTE_LOCATION); /* O [flg] File was retrieved from remote location */

char ** /* O [sng] List of user-specified filenames */
nco_fl_lst_mk /* [fnc] Create file list from command line positional arguments */
(CST_CST_CST_FNC(char,argv), /* I [sng] Argument list */
 const int argc, /* I [nbr] Argument count */
 int arg_crr, /* I [idx] Index of current argument */
 int * const nbr_fl, /* O [nbr] Number of files in input file list */
 char ** const fl_out); /* O [sng] Name of output file */

char * /* O [sng] Name of file to retrieve */
nco_fl_nm_prs /* [fnc] Construct file name from input arguments */
(char *fl_nm, /* I/O [sng] Current filename, if any */
 const int fl_nbr, /* I [nbr] Ordinal index of file in input file list */
 int * const nbr_fl, /* I/O [nbr] number of files to be processed */
 char * const * const fl_lst_in, /* I [sng] User-specified filenames */
 const int nbr_abb_arg, /* I [nbr] Number of abbreviation arguments */
 CST_CST_CST_FNC(char,fl_lst_abb), /* I [sng] NINTAP-style arguments, if any */
 const char * const fl_pth); /* I [sng] Path prefix for files in fl_lst_in */

char * /* O [sng] Name of temporary file actually opened */
nco_fl_out_open /* [fnc] Open output file subject to availability and user input */
(const char * const fl_out, /* I [sng] Name of file to open */
 const bool FORCE_APPEND, /* I [flg] Append to existing file, if any */
 const bool FORCE_OVERWRITE, /* I [flg] Overwrite existing file, if any */
 int * const out_id); /* O [id] File ID */

void
nco_fl_out_cls /* [fnc] Close temporary output file, move it to permanent output file */
(const char * const fl_out, /* I [sng] Name of permanent output file */
 const char * const fl_out_tmp, /* I [sng] Name of temporary output file to close and move to permanent output file */
 const int nc_id); /* I [id] file ID of fl_out_tmp */

void
nco_fl_cmp_err_chk(void); /* [fnc] Perform error checking on file */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_FL_UTL_H */
