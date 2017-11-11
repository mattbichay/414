# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the my_fortune and pipe
# binaries

SUBS = install_data monitor_shm install_and_monitor

it install depend clean:
		-X=`pwd`; \
		for i in ${SUBS}; \
		do echo "<<< $$$i $$X >>>"; cd $$X/$$i; \
		make $@; \
		done
