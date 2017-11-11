# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the bin and lib directories


SUBS = lib bin

it install depend clean:
		-X=`pwd`; \
		for i in ${SUBS}; \
		do echo "<<< $$$i $$X >>>"; cd $$X/$$i; \
		make $@; \
		done
