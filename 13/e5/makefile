# base directories
#
src=src
libloc=../../11/info1libs
libhead=../../11/info1includes
head=./src/head/
libso=../../11/libsrc/ver
sh=shared
conf=$(src)/aux.c

# result build flags
#
shflags=-L$(libloc) -Wl,-rpath,$(libso) -l$(sh) -Wall -o

# c and h files for shared object and static lib
#
hge:=$(wildcard $(head)/*.h) $(wildcard $(libhead)/*.h)
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
$(shbuild): $(hge) $(cge) configfile
	gcc $(src)/$(cl).c $(shflags) $(shbuildc) 
	gcc $(src)/$(sv).c $(conf) $(shflags) $(shbuilds) 

configfile:
	sudo cp ../servidor.conf /etc/	

# avoid build of false target clean 
#
.PHONY: clean

# clean all directory tree
#
clean: 
	rm -v $(cl)
	rm -v $(sv)
