# File by Ivan Galin

# Minix doesn't support shared libs
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS FALSE)

SET(CMAKE_CXX_LINK_SHARED_LIBRARY )
SET(CMAKE_CXX_LINK_MODULE_LIBRARY )
SET(CMAKE_C_LINK_SHARED_LIBRARY )
SET(CMAKE_C_LINK_MODULE_LIBRARY )

SET(CMAKE_DL_LIBS "" )
SET(CMAKE_SHARED_LIBRARY_C_FLAGS "")            # -pic
SET(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "")       # -shared
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")         # +s, flag for exe link to use shared lib
SET(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG "")       # -rpath
SET(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG_SEP "")   # : or empty

# small Hack while compile CMake - GCC in Minix not use /usr/pkg/include
# as default path for includes.
SET(CMAKE_CXX_LINK_FLAGS "-lssl -lbz2 -lcrypto ${CMAKE_CXX_LINK_FLAGS}")

INCLUDE(Platform/UnixPaths) 
