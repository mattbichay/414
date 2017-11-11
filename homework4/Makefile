# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: Top level make file for the src directory


SUB = src

it install depend clean:
		-X=`pwd`; \
		for i in ${SUB}; \
		do echo "<<< $$i >>>"; cd $$X/$$i; make $@; done
