# base directories
#
src=libsrc
verloc=$(src)/ver
objdir=$(src)/obj
libhead=info1includes
libdest=info1libs

# output names
#
st=libstatic.a
sh=libshared.so

# result build flags
#
shflags=-shared -Wl,-soname,$(sh).1 -o $(verloc)/$(sh).1.0.0 -Wall
stflags= srv -o $(stbuild)
flags=-fpic -Wall

# c and h files for shared object and static lib
#
cge:=$(wildcard $(src)/*.c)
hge:=$(wildcard $(head)/*.h)
oge:=$(patsubst %.c,%.o,$(cge))
oge:=$(subst $(src),$(objdir),$(oge))

# static and shared build output
#
stbuild=$(libdest)/$(st)
shbuild=$(libdest)/$(sh)

# assumes there exists 
# src storing generic c files
# shared storing shared lib c files
# static storing static lib c files
# head storing header files 
#
buildtree:
	mkdir -v $(verloc)
	mkdir -v $(objdir)
	mkdir -v $(libdest)

$(objdir)/%.o: $(src)/%.c $(libhead)
	gcc -c -o $@ $<	$(flags)

# compile client and server from static library
#
$(stbuild): $(oge)
	@echo CONSTRUYENDO ESTATICA
	ar $(stflags) $^

# compile client and server from shared object
#
$(shbuild): $(oge)
	@echo CONSTRUYENDO DINAMICA
	gcc $(shflags) $^
	sudo ldconfig -n $(verloc)
	ln -s ../$(verloc)/$(sh).1 $(shbuild)

builde2: $(shbuild) $(stbuild)
	@echo CONSTRUYENDO E2:
	make all -C ./e2

all:    buildtree 	\
	builde2		\

# avoid build of false target clean 
#
.PHONY: clean

# clean all directory tree
#
clean: 
	@echo DESTRUYENDO BIBLIOTECAS
	for d in $(objdir) $(libdest) $(verloc); 	\
		do rm -r $$d; 				\
	done 
	@echo DESTRUYENDO E2 
	make clean -C e2

