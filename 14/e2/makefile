# base directories
#
src=src

# result build flags
#
shflags=-Wall -o

# c and h files for shared object and static lib
#
cge:=$(wildcard $(src)/*.c)

# output names
#
out=my_stat

# compile client and server from static library
#
$(out): $(cge)
	gcc $(cge) $(shflags) $(out)

# avoid build of false target clean 
#
.PHONY: clean

# clean all directory tree
#
clean: 
	rm -v $(out)
