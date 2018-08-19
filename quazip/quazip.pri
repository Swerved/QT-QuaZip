# Quazip 0.7.3
# DLL for zlib is for MSVC only.
# Useful Doc: http://quazip.sourceforge.net/
# With thanks to VoidRealms
# Uses zlib License
#---

#Set variables
ZLIBCODEDIR =  $$PWD/zlib/1211/dll/release
QUAZIPCODEDIR = $$PWD/quazip/073

#include the compiled code -- WE ARE NOT USING UNIX PLATFORMS IN THIS PROJECT.
#unix {
#  LIBS += -L$${ZLIBCODEDIR} -lz
#}

win32 {
    LIBS += -L$${ZLIBCODEDIR} -lzlibwapi
    DEFINES += QUAZIP_STATIC
}

#include files
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += $${QUAZIPCODEDIR}/*.h
SOURCES += $${QUAZIPCODEDIR}/*.cpp
SOURCES += $${QUAZIPCODEDIR}/*.c
HEADERS += $${QUAZIPCODEDIR}/zlib/*.h
SOURCES += $${QUAZIPCODEDIR}/zlib/*.c
