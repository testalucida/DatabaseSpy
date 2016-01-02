#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/635d88bc/Controller.o \
	${OBJECTDIR}/_ext/635d88bc/ResultGroup.o \
	${OBJECTDIR}/_ext/635d88bc/SearchCriteriaGroup.o \
	${OBJECTDIR}/_ext/635d88bc/SearchCriteriaModel.o \
	${OBJECTDIR}/_ext/635d88bc/ToolBarGroup.o \
	${OBJECTDIR}/_ext/635d88bc/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../My_1_5/lib/Debug -L../Flx_1/lib/Debug -L../../fltk-1.3.2/lib -L/usr/local/lib -L/usr/lib -lflx_1 -lmy_1_5 -lfltk -lfltk_forms -lfltk_images -lfltk_jpeg -lfltk_png

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/databasespy

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/databasespy: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/databasespy ${OBJECTFILES} ${LDLIBSOPTIONS} `fltk-config --use-images --ldstaticflags` `mysql_config --libs`

${OBJECTDIR}/_ext/635d88bc/Controller.o: /home/max/cpp/fltk/DatabaseSpy/src/Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/Controller.o /home/max/cpp/fltk/DatabaseSpy/src/Controller.cpp

${OBJECTDIR}/_ext/635d88bc/ResultGroup.o: /home/max/cpp/fltk/DatabaseSpy/src/ResultGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/ResultGroup.o /home/max/cpp/fltk/DatabaseSpy/src/ResultGroup.cpp

${OBJECTDIR}/_ext/635d88bc/SearchCriteriaGroup.o: /home/max/cpp/fltk/DatabaseSpy/src/SearchCriteriaGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/SearchCriteriaGroup.o /home/max/cpp/fltk/DatabaseSpy/src/SearchCriteriaGroup.cpp

${OBJECTDIR}/_ext/635d88bc/SearchCriteriaModel.o: /home/max/cpp/fltk/DatabaseSpy/src/SearchCriteriaModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/SearchCriteriaModel.o /home/max/cpp/fltk/DatabaseSpy/src/SearchCriteriaModel.cpp

${OBJECTDIR}/_ext/635d88bc/ToolBarGroup.o: /home/max/cpp/fltk/DatabaseSpy/src/ToolBarGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/ToolBarGroup.o /home/max/cpp/fltk/DatabaseSpy/src/ToolBarGroup.cpp

${OBJECTDIR}/_ext/635d88bc/main.o: /home/max/cpp/fltk/DatabaseSpy/src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/635d88bc
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/max/cpp/My_1_5 -I/home/max/cpp/fltk/Flx_1 -I/home/max/cpp/fltk-1.3.2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/635d88bc/main.o /home/max/cpp/fltk/DatabaseSpy/src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/databasespy

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
