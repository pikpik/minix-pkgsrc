/* MINIX OS header file */

#undef  TARGET_VERSION
#define TARGET_VERSION fprintf (stderr, " (i386 MINIX)");

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()				\
	do							\
	{							\
		builtin_define ("__minix");			\
		builtin_define ("__i386");			\
								\
		builtin_define_with_int_value ("_EM_WSIZE", 4);	\
		builtin_define_with_int_value ("_EM_PSIZE", 4);	\
		builtin_define_with_int_value ("_EM_SSIZE", 2);	\
		builtin_define_with_int_value ("_EM_LSIZE", 4);	\
		builtin_define_with_int_value ("_EM_FSIZE", 4);	\
		builtin_define_with_int_value ("_EM_DSIZE", 8);	\
	} while ( 0 )

#undef  LIB_SPEC
#define LIB_SPEC \
	"-lc"

#undef  STANDARD_STARTFILE_PREFIX_1
#define STANDARD_STARTFILE_PREFIX_1 "/usr/gnu/lib/"

#undef  STARTFILE_SPEC
/* #define STARTFILE_SPEC \
 *	"/usr/gnu/lib/crtso%O%s"
 */
#define STARTFILE_SPEC \
	"crtso.o%s"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC \
	"libend.a%s"

/* Definitions for Unix assembler syntax for the Intel 80386.
   Copyright (C) 1988, 1994, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* This file defines the aspects of assembler syntax
   that are the same for all the i386 Unix systems
   (though they may differ in non-Unix systems).  */

/* Define macro used to output shift-double opcodes when the shift
   count is in %cl.  Some assemblers require %cl as an argument;
   some don't.  This macro controls what to do: by default, don't
   print %cl.  */
#define SHIFT_DOUBLE_OMITS_COUNT 1

/* Define the syntax of pseudo-ops, labels and comments.  */

/* String containing the assembler's comment-starter.  */

#define ASM_COMMENT_START "/"

/* Output to assembler file text saying following lines
   may contain character constants, extra white space, comments, etc.  */

#define ASM_APP_ON "/APP\n"

/* Output to assembler file text saying following lines
   no longer contain unusual constructs.  */

#define ASM_APP_OFF "/NO_APP\n"

/* Output before read-only data.  */

#define TEXT_SECTION_ASM_OP "\t.text"

/* Output before writable (initialized) data.  */

#define DATA_SECTION_ASM_OP "\t.data"

/* Output before writable (uninitialized) data.  */

#define BSS_SECTION_ASM_OP "\t.bss"

/* Globalizing directive for a label.  */
#define GLOBAL_ASM_OP ".globl "

/* By default, target has a 80387, uses IEEE compatible arithmetic,
   and returns float values in the 387.  */
/* But MINIX doesn't use the 387 yet, so disable it */
#undef  TARGET_SUBTARGET_DEFAULT
#define TARGET_SUBTARGET_DEFAULT (MASK_IEEE_FP)

#undef  LONG_DOUBLE_TYPE_SIZE
#define LONG_DOUBLE_TYPE_SIZE 64

/* The string value for __SIZE_TYPE__.  */

#undef  SIZE_TYPE
#define SIZE_TYPE "unsigned int"


/* This is how we tell the assembler that a symbol is weak.  */

#undef ASM_WEAKEN_LABEL
#define ASM_WEAKEN_LABEL(FILE,NAME)					\
  do 									\
    {									\
      fputs ("\t" GLOBAL_ASM_OP "\t", FILE); assemble_name (FILE, NAME);		\
      fputc ('\n', FILE);						\
      fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME);		\
      fputc ('\n', FILE);						\
    }									\
  while (0)

