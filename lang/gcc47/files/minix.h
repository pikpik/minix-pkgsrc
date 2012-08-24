/* Base configuration file for all Minix targets.
   Copyright (C) 1999, 2000, 2001, 2007, 2008, 2009,
   2010 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* Common MINIX configuration. 
   All Minix architectures should include this file, which will specify
   their commonalities.
*/

/* In case we need to know.  */
#define USING_CONFIG_MINIX 1

/* This defines which switch letters take arguments.  On MINIX, most of
   the normal cases (defined in gcc.c) apply, and we also have -h* and
   -z* options (for the linker) (coming from SVR4).
   We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() MINIX_TARGET_OS_CPP_BUILTINS()

#undef  CPP_SPEC
#define CPP_SPEC MINIX_CPP_SPEC

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC MINIX_STARTFILE_SPEC

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC MINIX_ENDFILE_SPEC

#undef  LIB_SPEC
#define LIB_SPEC MINIX_LIB_SPEC


/************************[  Target stuff  ]***********************************/

/* All MINIX Architectures support the ELF object file format.  */
#undef  OBJECT_FORMAT_ELF
#define OBJECT_FORMAT_ELF

/* Don't assume anything about the header files.  */
#undef  NO_IMPLICIT_EXTERN_C
#define NO_IMPLICIT_EXTERN_C	1

/* Code generation parameters.  */

/* Use periods rather than dollar signs in special g++ assembler names.
   This ensures the configuration knows our system correctly so we can link
   with libraries compiled with the native cc.  */
#undef NO_DOLLAR_IN_LABEL
