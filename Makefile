#############################################################################
# Makefile for building: Mastermind
# Generated by qmake (2.01a) (Qt 4.8.7) on: Sun Feb 10 17:42:10 2019
# Project:  Mastermind.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -o Makefile Mastermind.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mmwindow.cpp \
		Mastermind.cxx moc_mmwindow.cpp \
		qrc_mastermind.cpp
OBJECTS       = main.o \
		mmwindow.o \
		Mastermind.o \
		moc_mmwindow.o \
		qrc_mastermind.o
DIST          = /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		Mastermind.pro
QMAKE_TARGET  = Mastermind
DESTDIR       = 
TARGET        = Mastermind

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mmwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Mastermind.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/libQtGui.prl \
		/usr/lib64/libQtCore.prl
	$(QMAKE) -o Makefile Mastermind.pro
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt4/mkspecs/common/g++-base.conf:
/usr/lib64/qt4/mkspecs/common/g++-unix.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/release.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/shared.prf:
/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/libQtGui.prl:
/usr/lib64/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Mastermind.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Mastermind1.0.0 || $(MKDIR) .tmp/Mastermind1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Mastermind1.0.0/ && $(COPY_FILE) --parents mmwindow.h Mastermind.hxx .tmp/Mastermind1.0.0/ && $(COPY_FILE) --parents mastermind.qrc .tmp/Mastermind1.0.0/ && $(COPY_FILE) --parents main.cpp mmwindow.cpp Mastermind.cxx .tmp/Mastermind1.0.0/ && $(COPY_FILE) --parents mmwindow.ui .tmp/Mastermind1.0.0/ && (cd `dirname .tmp/Mastermind1.0.0` && $(TAR) Mastermind1.0.0.tar Mastermind1.0.0 && $(COMPRESS) Mastermind1.0.0.tar) && $(MOVE) `dirname .tmp/Mastermind1.0.0`/Mastermind1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Mastermind1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mmwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mmwindow.cpp
moc_mmwindow.cpp: Mastermind.hxx \
		mmwindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) mmwindow.h -o moc_mmwindow.cpp

compiler_rcc_make_all: qrc_mastermind.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_mastermind.cpp
qrc_mastermind.cpp: mastermind.qrc \
		img/White_colour_peg.png \
		img/Black_colour_peg_small.png \
		img/White_colour_peg_small.png \
		img/Purple_colour_peg.png \
		img/No_colour_peg_small.png \
		img/Red_colour_peg.png \
		img/Blue_colour_peg.png \
		img/Green_colour_peg.png \
		img/No_colour_peg.png \
		img/Black_colour_peg.png \
		img/Orange_colour_peg.png
	/usr/lib64/qt4/bin/rcc -name mastermind mastermind.qrc -o qrc_mastermind.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mmwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mmwindow.h
ui_mmwindow.h: mmwindow.ui
	/usr/lib64/qt4/bin/uic mmwindow.ui -o ui_mmwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mmwindow.h \
		Mastermind.hxx
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mmwindow.o: mmwindow.cpp mmwindow.h \
		Mastermind.hxx \
		ui_mmwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mmwindow.o mmwindow.cpp

Mastermind.o: Mastermind.cxx Mastermind.hxx
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Mastermind.o Mastermind.cxx

moc_mmwindow.o: moc_mmwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mmwindow.o moc_mmwindow.cpp

qrc_mastermind.o: qrc_mastermind.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_mastermind.o qrc_mastermind.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/Mastermind/bin/ || $(MKDIR) $(INSTALL_ROOT)/opt/Mastermind/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/opt/Mastermind/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/opt/Mastermind/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/Mastermind/bin/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

