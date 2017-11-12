# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Makefile for the shmlib

PROJECT_ROOT = ../../..
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = shared_mem.cpp
OBJS = $(SRCS:.cpp=.o)
PROJECT = libshmlib.a
FLAGS = -I$(INCLDIR)
CC = g++ $(FLAGS)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) -c $<

$(PROJECT): $(OBJS)
	ar -cr $(PROJECT) $(OBJS)

it: $(PROJECT)

install: $(LIBDIR)/$(PROJECT)
$(LIBDIR)/$(PROJECT): $(PROJECT)
	cp $(PROJECT) $(LIBDIR)


clean:
	rm -f $(OBJS) $(PROJECT)

depend: $(SRCS)
	$(CC) -M $(SRCS) > dependList
	sed -e '1,/^# DO NOT DELETE/!d' Makefile > make.tmp
	cat dependList >> make.tmp
	mv make.tmp Makefile
	rm dependList


# DO NOT DELETE THIS LINE
shared_mem.o: shared_mem.cpp /usr/include/stdc-predef.h \
 ../../../include/shared_mem.h /usr/include/sys/shm.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include/stddef.h \
 /usr/include/sys/ipc.h /usr/include/bits/ipctypes.h \
 /usr/include/bits/ipc.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/shm.h \
 /usr/include/bits/types/time_t.h /usr/include/c++/7.2.0/cstddef \
 /usr/include/c++/7.2.0/x86_64-pc-linux-gnu/bits/c++config.h \
 /usr/include/c++/7.2.0/x86_64-pc-linux-gnu/bits/os_defines.h \
 /usr/include/c++/7.2.0/x86_64-pc-linux-gnu/bits/cpu_defines.h
