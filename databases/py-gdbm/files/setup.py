# $NetBSD$

import distutils
from distutils.core import setup, Extension

gdbmprefix = '@GDBMPREFIX@'
gdbmincl = gdbmprefix + '/include'
gdbmlib = gdbmprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'gdbm',
			['Modules/gdbmmodule.c'],
			include_dirs=[gdbmincl],
			library_dirs=[gdbmlib],
			runtime_library_dirs=[gdbmlib],
			libraries=['gdbm']
		)
	]
)
