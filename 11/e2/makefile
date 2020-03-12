# base directories
#
src=src
dsrc=dsrc
libloc=../info1libs
verloc=../libsrc/ver
head=../info1includes
st=static
sh=shared
dn=dynamic

# result build flags
#
shflags=-L$(libloc) -Wl,-rpath,$(verloc) -l$(sh) -Wall -o 
stflags=-L$(libloc) -l$(st) -Wall -o
dnflags=-ldl -Wall -o 

# c and h files for shared object and static lib
#
cge:=$(wildcard $(src)/*.c)
hge:=$(wildcard $(head)/*.h)

# c and h files for dynamic lib
dcge:=$(wildcard $(dsrc)/*.c)
dhge:=$(wildcard $(dsrc)/*.h)
dfun=$(dsrc)/functions.c

# output names
#
cl=client
sv=server

# static build
#
stbuildc=$(st)/$(cl)
stbuilds=$(st)/$(sv)
stbuild= $(stbuildc) $(stbuilds)

# shared build
#
shbuildc=$(sh)/$(cl)
shbuilds=$(sh)/$(sv)
shbuild=$(shbuildc) $(shbuilds) 

# dynamic build
#
dnbuildc=$(dn)/$(cl)
dnbuilds=$(dn)/$(sv)
dnbuild=$(dnbuildc) $(dnbuilds)

# assumes there exists 
# src storing generic c files
# shared storing shared lib c files
# static storing static lib c files
# head storing header files 
#
buildtree:
	mkdir -v $(st)
	mkdir -v $(sh)
	mkdir -v $(dn)

# compile client and server from static library
#
$(stbuild): $(hge) $(cge)
	gcc $(src)/$(cl).c $(stflags) $(stbuildc) 
	gcc $(src)/$(sv).c $(stflags) $(stbuilds) 

# compile client and server from shared object
#
$(shbuild): $(hge) $(cge)
	gcc $(src)/$(cl).c $(shflags) $(shbuildc)  	
	gcc $(src)/$(sv).c $(shflags) $(shbuilds)  

# compile client and server from dynamic loader
#
$(dnbuild): $(dhge) $(dcge) $(hge)
	gcc $(dsrc)/$(cl).c $(dfun) $(dnflags) $(dnbuildc)  	
	gcc $(dsrc)/$(sv).c $(dfun) $(dnflags) $(dnbuilds)  

all:    buildtree 	\
	$(stbuild) 	\
	$(shbuild)	\
	$(dnbuild)

# avoid build of false target clean 
#
.PHONY: clean

# clean all directory tree
#
clean: 
	for d in $(st) $(sh) $(dn); 	\
		do rm -r $$d; 			\
	done 

