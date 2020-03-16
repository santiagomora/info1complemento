
cs=src
hs=src/head
os=$(cs)/obj
flags=-Wall -lm

ofiles=$(os)/main.o $(os)/functions.o $(os)/calculos.o
cfiles=$(cs)/main.c $(cs)/functions.c $(cs)/calculos.c
heads=$(hs)/headers.h $(hs)/calculos.h

ofiles2=$(os)/main.o $(os)/functions2.o $(os)/calculos.o
cfiles2=$(cs)/main.c $(cs)/functions2.c $(cs)/calculos.c

o1=result1
o2=result2

$(os)/%.o: $(cs)/%.c $(heads)
	gcc -c -o $@ $<	$(flags)

main: $(ofiles) $(ofiles2)
	gcc -o $(o2) $(cfiles2) $(flags)
	gcc -o $(o1) $(cfiles) $(flags)

clean:
	rm -rv $(os)/*.o
	rm -v $(o1)
	rm -v $(o2)
