
nested = {'folderA': {'sub1': None, 'sub2': {'subsub1': None}},
          'folderB': {'sub1': None}}


TOP_LEVEL_MAKE="""
# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the {} directories


SUBS = {}

it install depend clean:
		-X=`pwd`; \
		for i in ${SUBS}; \
		do echo "<<< $$$i $$X >>>"; cd $$X/$$i; \
		make $@; \
		done
"""


BIN_MAKE="""
# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Make file for {} binary



PROJECT_ROOT = ../../..
BINDIR = $(PROJECT_ROOT)/bin
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = FILL_ME_IN.cpp FILL_ME_IN.cpp
LIBS = $(LIBDIR)/FILL_ME_IN.a $(LIBDIR)/FILL_ME_IN.a

OBJS = $(SRCS:.cpp=.o)
PROJECT = {}
FLAGS = -I$(INCLDIR)
CC = g++ $(FLAGS)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) -c $<

$(PROJECT): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

it: $(PROJECT)

install: $(BINDIR)/$(PROJECT)
$(BINDIR)/$(PROJECT): $(PROJECT)
	cp $(PROJECT) $(BINDIR)

clean:
	rm -f $(OBJS) $(PROJECT)

depend: $(SRCS)
	$(CC) -M $(SRCS) > dependList
	sed -e '1,/^# DO NOT DELETE/!d' Makefile > make.tmp
	cat dependList >> make.tmp
	mv make.tmp Makefile
	rm dependList


# DO NOT DELETE THIS LINE
"""

LIB_MAKE="""
# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Make file for the {} library

PROJECT_ROOT = ../../..
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = FILL_ME_IN.cpp FILL_ME_IN.cpp
OBJS = $(SRCS:.cpp=.o)
PROJECT = {}.a
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
"""

GIT_KEEP_DIR="""
# Ignore everything in this directory
*
# Except this file
!.gitignore
"""


def make_dirs_from_dict(d, current_dir='./'):
    for key, val in d.items():
        path = os.path.join(current_dir, key)
        os.makedirs(path)
        if type(val) == dict:
            write_file(TOP_LEVEL_MAKE, path, format_arg=' '.join(val.keys()))
            make_dirs_from_dict(val, os.path.join(current_dir, key))
        elif val == LIBRARY:
            write_file(LIB_MAKE, path, format_arg=)
        elif val == BINARY:
            write_file(BIN_MAKE, path, format_arg=)
        elif val == KEEP:





if __name__ == '__main__':
