SUB = src

it install depend clean:
		-X=`pwd`; \
		for i in ${SUB}; \
		do echo "<<< $$i >>>"; cd $$X/$$i; make $@; done
