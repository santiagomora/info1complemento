# base directories
#
src=src
libloc=../../11/info1libs
head=../../11/info1includes
libso=../../11/libsrc/ver
sh=shared

# result build flags
#
shflags=-L$(libloc) -Wl,-rpath,$(libso) -l$(sh) -Wall -o

# c and h files for shared object and static lib
#
hge:=$(wildcard $(head)/*.h)
cge:=$(wildcard $(src)/*.c)

# output names
#
cl=client
sv=server

# static build
#
shbuildc=$(cl)
shbuilds=$(sv)
shbuild= $(shbuildc) $(shbuilds)

# compile client and server from static library
#
$(shbuild): $(hge) $(cge)
	gcc $(src)/$(cl).c $(shflags) $(shbuildc) 
	gcc $(src)/$(sv).c $(shflags) $(shbuilds) 

# avoid build of false target clean 
#
.PHONY: clean

# clean all directory tree
#
clean: 
	rm -v $(cl)
	rm -v $(sv)
