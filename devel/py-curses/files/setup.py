# $NetBSD$

import distutils
from distutils.core import setup, Extension

ncursesprefix = '@NCURSESPREFIX@'
ncincl = ncursesprefix + '/include'
nclib = ncursesprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_curses',
			['Modules/_cursesmodule.c'],
			define_macros=[('HAVE_NCURSES_H', None)],
			include_dirs=[ncincl],
			library_dirs=[nclib],
			runtime_library_dirs=[nclib],
			libraries=['ncurses']
		)
	]
)
