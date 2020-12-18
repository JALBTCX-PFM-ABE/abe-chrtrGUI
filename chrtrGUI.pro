RC_FILE = chrtrGUI.rc
RESOURCES = icons.qrc
contains(QT_CONFIG, opengl): QT += opengl
QT += 
INCLUDEPATH += /c/PFM_ABEv7.0.0_Win64/include
LIBS += -L /c/PFM_ABEv7.0.0_Win64/lib -lgsf -lCHARTS -lpfm -lnvutility -lgdal -lxml2 -lpoppler -liconv
DEFINES += WIN32 NVWIN3X
CONFIG += console
QMAKE_LFLAGS += 
######################################################################
# Automatically generated by qmake (2.01a) Wed Jan 22 13:59:36 2020
######################################################################

TEMPLATE = app
TARGET = chrtrGUI
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += chrtrGUI.hpp \
           chrtrGUIDef.hpp \
           chrtrGUIHelp.hpp \
           inputPage.hpp \
           inputPageHelp.hpp \
           optionsPage.hpp \
           optionsPageHelp.hpp \
           runPage.hpp \
           runPageHelp.hpp \
           startPage.hpp \
           startPageHelp.hpp \
           version.hpp
SOURCES += chrtrGUI.cpp \
           env_in_out.cpp \
           inputPage.cpp \
           main.cpp \
           optionsPage.cpp \
           runPage.cpp \
           set_defaults.cpp \
           startPage.cpp \
           writeParameterFile.cpp
RESOURCES += icons.qrc