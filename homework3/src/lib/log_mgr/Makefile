# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Makefile for the log_mgr

PROJECT_ROOT = ../../..
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = log_mgr.cpp
OBJS = $(SRCS:.cpp=.o)
PROJECT = liblog_mgr.a
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
log_mgr.o: log_mgr.cpp /usr/include/unistd.h \
 /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
 /usr/include/sys/isa_defs.h /usr/include/sys/types.h \
 /usr/include/sys/machtypes.h /usr/include/sys/int_types.h \
 /usr/include/sys/select.h /usr/include/sys/time_impl.h \
 /usr/include/sys/time.h /usr/include/time.h /usr/include/iso/time_iso.h \
 /usr/include/sys/unistd.h /usr/include/fcntl.h /usr/include/sys/stat.h \
 /usr/include/sys/stat_impl.h /usr/include/sys/fcntl.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ctime \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cstddef \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++config.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/os_defines.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/cpu_defines.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/include/stddef.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/include/stdarg.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cstdarg \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cstdio \
 /usr/include/stdio.h /usr/include/iso/stdio_iso.h \
 /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
 /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
 ../../../include/log_mgr.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/string \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stringfwd.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/char_traits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_algobase.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/functexcept.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/exception_defines.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/cpp_type_traits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/type_traits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/numeric_traits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_pair.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/move.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/concept_check.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_iterator_base_types.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_iterator_base_funcs.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_iterator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/debug/debug.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/postypes.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cwchar \
 /usr/include/wchar.h /usr/include/iso/wchar_iso.h \
 /usr/include/wchar_impl.h /usr/include/ctype.h \
 /usr/include/iso/ctype_iso.h /usr/include/iso/ctype_c99.h \
 /usr/include/iso/wchar_c99.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/new_allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/new \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/exception \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/localefwd.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++locale.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/clocale \
 /usr/include/locale.h /usr/include/iso/locale_iso.h \
 /usr/local/include/libintl.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/iosfwd \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cctype \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/ostream_insert.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cxxabi-forced.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_function.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/backward/binders.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_string.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/atomicity.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/gthr.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/atomic_word.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/initializer_list \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_string.tcc
