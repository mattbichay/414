# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the log_mgr directories

SUBS = log_mgr shmlib

it install depend clean:
		-X=`pwd`; \
		for i in ${SUBS}; \
		do echo "<<< $$$i $$X >>>"; cd $$X/$$i; \
		make $@; \
		done
