# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Make file for the temp_convert library

PROJECT_ROOT = ../../..
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = cent_convert.cpp fahr_convert.cpp
OBJS = $(SRCS:.cpp=.o)
PROJECT = libtemp_convert.a
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
cent_convert.o: cent_convert.cpp ../../../include/temp_convert.hpp
fahr_convert.o: fahr_convert.cpp ../../../include/temp_convert.hpp
