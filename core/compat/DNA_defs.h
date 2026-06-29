/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Campbell Barton
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file DNA_defs.h
 *  \ingroup DNA
 *
 * Group generic defines for all DNA headers may use in this file.
 */

#ifndef __DNA_DEFS_H__
#define __DNA_DEFS_H__

/* makesdna ignores */
#ifdef DNA_DEPRECATED_ALLOW
   /* allow use of deprecated items */
#  define DNA_DEPRECATED
#else
#  ifndef DNA_DEPRECATED
#    ifdef __GNUC__
#      define DNA_DEPRECATED __attribute__ ((deprecated))
#    else
       /* TODO, msvc & others */
#      define DNA_DEPRECATED
#    endif
#  endif
#endif


/* poison pragma */
#ifdef DNA_DEPRECATED_ALLOW
#  define DNA_DEPRECATED_GCC_POISON 0
#else
#  define DNA_DEPRECATED_GCC_POISON 1
#endif

#if DNA_DEPRECATED_GCC_POISON
#  ifdef __GNUC__
#    define DNA_DEPRECATED_GCC_POISON(x) \
        _Pragma("GCC poison \"" x "\"")
#  else
#    define DNA_DEPRECATED_GCC_POISON(x)
#  endif
#else
#  define DNA_DEPRECATED_GCC_POISON(x)
#endif

/* check if we are reading the file from DNA generator */
#ifdef DNA_INTERNAL
#  define DNA_DEPRECATED_ALLOW 0
#else
#  define DNA_DEPRECATED_ALLOW 1
#endif

#ifndef DNA_INTERNAL
#  ifdef DNA_DEPRECATED
#    define DNA_DEPRECATED(x) DNA_DEPRECATED
#  else
#    define DNA_DEPRECATED(x)
#  endif
#endif

/* makesdna ignores */
#define DNA_DEPRECATED_ALLOW_GEN DNA_DEPRECATED_ALLOW

#define DNA_STRUCT_ALIGN_16 1
#define DNA_STRUCT_ALIGN_8 1

#define DNA_MAX_NAME 64
#define DNA_MAX_NAME_LONG 256
#define DNA_MAX_FILEPATH 1024

/* maximum lengths for string IDs */
#define MAX_ID_NAME 66
#define MAX_ID_NAME_LONG 256
#define MAX_ID_FILEPATH 1024
#define MAX_ID_FILEPATH_LONG 4096

#define ID_NAME_LEN 66

#define MAX_ID_NAME 66
#define MAX_ID_NAME_LONG 256
#define MAX_ID_FILEPATH 1024

/* Gene and RNA IDs for dependency graph */
#define GENE_ID_SIZE 16
#define RNA_ID_SIZE 16

/* GSet and GHash types */
typedef unsigned int uint;

#endif /* __DNA_DEFS_H__ */