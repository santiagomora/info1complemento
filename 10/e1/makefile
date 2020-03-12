
cs=src
hs=src/head
os=$(cs)/obj
flags=-Wall

ofiles=$(os)/main.o $(os)/functions.o
cfiles=$(cs)/main.c $(cs)/functions.c
heads=$(hs)/headers.h

output=result

$(os)/%.o: $(cs)/%.c $(heads)
	gcc -c -o $@ $<	$(flags)

main: $(ofiles)
	gcc -o $(output) $(cfiles) $(flags)

clean:
	rm -f $(os)/*.o
	rm result
