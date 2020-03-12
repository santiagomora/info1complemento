dirs=./e1 ./e2 ./e3 

all:
	for d in $(dirs); 				\
	do 						\
		echo "COMPILANDO DIRECTORIO $$d";	\
		make -C $$d; 				\
	done
clean:
	for d in $(dirs); 				\
	do 						\
		echo "LIMPIANDO DIRECTORIO $$d";	\
		make clean -C $$d;			\
	done
