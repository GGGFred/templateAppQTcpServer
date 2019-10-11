QT += network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

MOC_DIR     += generated/mocs
UI_DIR      += generated/uis
RCC_DIR     += generated/rccs
OBJECTS_DIR += generated/objs

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += test/main.cpp \
    src/gtcpserver.cpp \

HEADERS += \
    src/gtcpserver.h

win32{
    CONFIG(debug, debug|release) {
        DEST_DIRECTORY = $$PWD/win32/debug
    }
    CONFIG(release, debug|release) {
        DEST_DIRECTORY = $$PWD/win32/release
    }
}

unix:!mac{
    CONFIG(debug, debug|release) {
        DEST_DIRECTORY = $$PWD/linux/debug
    }
    CONFIG(release, debug|release) {
        DEST_DIRECTORY = $$PWD/linux/release
    }
}

MOC_DIR     += $${DEST_DIRECTORY}/generated/mocs
UI_DIR      += $${DEST_DIRECTORY}/generated/uis
RCC_DIR     += $${DEST_DIRECTORY}/generated/rccs
OBJECTS_DIR += $${DEST_DIRECTORY}/generated/objs
DLLDESTDIR = $${DEST_DIRECTORY}
DESTDIR    = $${DEST_DIRECTORY}
