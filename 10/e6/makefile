
cs=src
hs=src/head
os=$(cs)/obj
flags=-Wall -lm

ofiles=$(os)/main.o $(os)/functions.o $(os)/acciones.o
cfiles=$(cs)/main.c $(cs)/functions.c $(cs)/acciones.c
heads=$(hs)/headers.h $(hs)/punto.h $(hs)/acciones.h

output=result

$(os)/%.o: $(cs)/%.c $(heads)
	gcc -c -o $@ $<	$(flags)

main: $(ofiles)
	gcc -o $(output) $(cfiles) $(flags)

clean:
	rm -f $(os)/*.o
	rm result
