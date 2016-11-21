cmake_minimum_required (VERSION 3.0)

# Add project
project (tiaontia)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

# Include headers directory
include_directories (includes)

# Set sources directory
set(SOURCES_COMMON_DIR "sources/common")
set(SOURCES_UNIX_DIR "sources/unix")
set(SOURCES_WIN32_DIR "sources/win32")

# Set sources
set(SOURCES
	${SOURCES_COMMON_DIR}/main.cpp
)

#Add sources
if (UNIX)
    set(SOURCES ${SOURCES} ${SOURCES_UNIX_DIR}/UnixCurses.cpp)
else()
    set(SOURCES ${SOURCES} ${SOURCES_WIN32_DIR}/WindowsCurses.cpp)
endif()

# Add executable
add_executable(tiaontia ${SOURCES})

# Linking libraries
if (UNIX)
	# Search for NCURSES
	set(CURSES_NEED_NCURSES TRUE)
	find_package(CURSES REQUIRED)
	# If found
	if (CURSES_FOUND)
		# Adds NCURSES includes to project
		include_directories(${CURSES_INCLUDE_DIR})
		# Links executable against NCURSES library
		target_link_libraries(tiaontia ${CURSES_LIBRARIES})
	endif(CURSES_FOUND)
else()
	set(PDCURSES_ROOT "${CMAKE_CURRENT_LIST_DIR}/pdcurses/")
	# Search for PDCurses
	find_package(PDCURSES REQUIRED)
	# If found
	if (PDCURSES_FOUND)
		message(${PDCURSES_INCLUDE_DIR})
		# Adds PDCurses includes to project
		include_directories(${PDCURSES_INCLUDE_DIR})
		# Links executable against NCURSES library
		target_link_libraries(tiaontia ${PDCURSES_LIBRARIES})
	endif(PDCURSES_FOUND)
endif()

# Active le C++11
target_compile_features (tiaontia PRIVATE cxx_constexpr)
# Active le C++14
# target_compile_features (tiaontia PRIVATE cxx_relaxed_constexpr)

if (UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
endif()