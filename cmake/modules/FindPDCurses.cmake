# Try to find the PDCurses library
#
# This module defines the following variables:
# 
# PDCURSES_FOUND            - If PDCurses was found
# PDCURSES_INCLUDE_DIR      - The include directory of PDCurses
# PDCURSES_LIBRARY          - Link against this variable
# PDCURSES_LIBRARY_DEBUG    - Contains the debug library if found. Otherwise, contains the release.
# PDCURSES_LIBRARY_RELEASE  - Contains the release library if found. Otherwise, contains the debug.
# 
# This module will use the following variables:
# 
# PDCURSES_ROOT - This will be used to find PDCurses
#

# Defines potential paths for finding PDCurses
SET(PDCURSES_FIND_PATHS
	${PDCURSES_ROOT}
	"C:/Program Files (x86)/pdcurses"
	"C:/Program Files/pdcurses"
	$ENV{PDCURSES_ROOT}
	/usr/local/
	/usr/
	/sw
	/opt/local/
	/opt/csw/
	/opt/
)

if (NOT PDCURSES_FIND_QUIETLY)
	message(STATUS "Looking for PDCurses...")
endif ()

# Look for include folder
find_path(PDCURSES_INCLUDE_DIR
	NAMES curses.h
	HINTS ${PDCURSES_FIND_PATHS})

# Look for debug library
find_library(PDCURSES_LIBRARY_DEBUG
	NAMES         pdcurses_d
	PATH_SUFFIXES lib64 lib win32
	PATHS         ${PDCURSES_FIND_PATHS})

# Look for release library
find_library(PDCURSES_LIBRARY_RELEASE
	NAMES         pdcurses
	PATH_SUFFIXES lib64 lib win32
	PATHS         ${PDCURSES_FIND_PATHS})

# If at least one library was found
if (PDCURSES_LIBRARY_DEBUG OR PDCURSES_LIBRARY_RELEASE)

	# Mark as found
	SET(PDCURSES_FOUND TRUE)

	if (PDCURSES_LIBRARY_DEBUG AND PDCURSES_LIBRARY_RELEASE)
		# Both libraries were found
		SET(PDCURSES_LIBRARY
			debug     ${PDCURSES_LIBRARY_DEBUG}
			optimized ${PDCURSES_LIBRARY_RELEASE})

	elseif(PDCURSES_LIBRARY_DEBUG)
		# Only debug version was found
		SET(PDCURSES_LIBRARY ${PDCURSES_LIBRARY_DEBUG})
		SET(PDCURSES_LIBRARY_RELEASE ${PDCURSES_LIBRARY_DEBUG})

	elseif(PDCURSES_LIBRARY_RELEASE)
		# Only release version was found
		SET(PDCURSES_LIBRARY ${PDCURSES_LIBRARY_RELEASE})
		SET(PDCURSES_LIBRARY_DEBUG ${PDCURSES_LIBRARY_RELEASE})
	endif()
else()
	# PDCurses was not found
	SET(PDCURSES_FOUND FALSE)
endif()

# Don't show variables to user
mark_as_advanced(
	PDCURSES_INCLUDE_DIR
	PDCURSES_LIBRARY
	PDCURSES_LIBRARY_RELEASE
	PDCURSES_LIBRARY_DEBUG
)

if (PDCURSES_FOUND)
	message(STATUS "-- Found PDCurses : ${PDCURSES_LIBRARY}")
else()
	if(PDCURSES_FIND_REQUIRED)
		# Fatal error
		message(FATAL_ERROR "Could NOT find PDCurses")
	elseif(NOT PDCURSES_FIND_QUIETLY)
		# Error, but continue
		message("Could NOT find PDCurses")
	endif()
endif()