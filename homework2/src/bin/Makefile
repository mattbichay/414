# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the lots_of_logs, test_log and log_2
# binaries

SUBS = lots_of_logs test_log test_log2

it install depend clean:
		-X=`pwd`; \
		for i in ${SUBS}; \
		do echo "<<< $$$i $$X >>>"; cd $$X/$$i; \
		make $@; \
		done
