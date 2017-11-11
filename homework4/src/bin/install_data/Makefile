# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Make file for my_fortune binary



PROJECT_ROOT = ../../..
BINDIR = $(PROJECT_ROOT)/bin
LIBDIR = $(PROJECT_ROOT)/lib
INCLDIR = $(PROJECT_ROOT)/include

SRCS = install_data.cpp
LIBS = $(LIBDIR)/liblog_mgr.a $(LIBDIR)/libshmlib.a

OBJS = $(SRCS:.cpp=.o)
PROJECT = install_data
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
my_fortune.o: my_fortune.cpp \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/iostream \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++config.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/os_defines.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/cpu_defines.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ostream \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ios \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/iosfwd \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stringfwd.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/postypes.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cwchar \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cstddef \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/include/stddef.h \
 /usr/include/wchar.h /usr/include/sys/feature_tests.h \
 /usr/include/sys/ccompile.h /usr/include/sys/isa_defs.h \
 /usr/include/iso/wchar_iso.h /usr/include/stdio_tag.h \
 /usr/include/wchar_impl.h /usr/include/iso/time_iso.h \
 /usr/include/stdio.h /usr/include/iso/stdio_iso.h \
 /usr/include/sys/va_list.h /usr/include/stdio_impl.h \
 /usr/include/iso/stdio_c99.h /usr/include/ctype.h \
 /usr/include/iso/ctype_iso.h /usr/include/iso/ctype_c99.h \
 /usr/include/iso/wchar_c99.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/exception \
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
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/localefwd.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++locale.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/clocale \
 /usr/include/locale.h /usr/include/iso/locale_iso.h \
 /usr/local/include/libintl.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cctype \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/ios_base.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/atomicity.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/gthr.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sys/types.h \
 /usr/include/sys/machtypes.h /usr/include/sys/int_types.h \
 /usr/include/sys/select.h /usr/include/sys/time_impl.h \
 /usr/include/sys/time.h /usr/include/time.h /usr/include/sched.h \
 /usr/include/unistd.h /usr/include/sys/unistd.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/atomic_word.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/locale_classes.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/string \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/c++allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/ext/new_allocator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/new \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/ostream_insert.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cxxabi-forced.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/stl_function.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/backward/binders.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_string.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/initializer_list \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_string.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/locale_classes.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/streambuf \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/streambuf.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_ios.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/locale_facets.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cwctype \
 /usr/include/wctype.h /usr/include/iso/wctype_iso.h \
 /usr/include/iso/wctype_c99.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/ctype_base.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/streambuf_iterator.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/sparc-sun-solaris2.11/bits/ctype_inline.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/locale_facets.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/basic_ios.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/ostream.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/istream \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/bits/istream.tcc \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/include-fixed/limits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/include-fixed/syslimits.h \
 /usr/include/limits.h /usr/include/iso/limits_iso.h \
 /usr/include/sys/int_limits.h \
 /usr/gcc/4.5/lib/gcc/sparc-sun-solaris2.11/4.5.2/../../../../include/c++/4.5.2/cstdlib \
 /usr/include/stdlib.h /usr/include/iso/stdlib_iso.h \
 /usr/include/iso/stdlib_c99.h /usr/include/sys/wait.h \
 /usr/include/sys/resource.h /usr/include/sys/siginfo.h \
 /usr/include/sys/machsig.h /usr/include/sys/procset.h \
 /usr/include/sys/signal.h /usr/include/sys/iso/signal_iso.h \
 /usr/include/sys/ucontext.h /usr/include/sys/regset.h \
 /usr/include/v7/sys/privregs.h /usr/include/v7/sys/psr.h \
 /usr/include/sys/fsr.h /usr/include/string.h \
 /usr/include/iso/string_iso.h /usr/include/fcntl.h \
 /usr/include/sys/stat.h /usr/include/sys/stat_impl.h \
 /usr/include/sys/fcntl.h /usr/include/errno.h /usr/include/sys/errno.h \
 /usr/include/signal.h /usr/include/iso/signal_iso.h \
 ../../../include/log_mgr.h
