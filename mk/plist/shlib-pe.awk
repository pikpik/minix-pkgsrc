# $NetBSD$
#
### 
### PLIST shlib filter for Portable Executable format, PE on Cygwin.
###

# Libtoolized packages don't need any special attention, but for others we need
# to manually deal with the .dll library suffix.

# Match shared libs
/.*\/lib[^\/]+\.so(\.[0-9]+)*$/ {
	sub("\.so\.", ".dll.");
}
# Match dynamically loaded modules
/.*\.so$/ {
	sub("\.so$", ".dll");
}
{
	print
}
