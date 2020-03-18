
cs=src
hs=src/head
flags=-Wall

cfiles=$(wildcard $(cs)/*.c)
heads=$(wildcard $(hs)/*.h)

output=result

main: $(cfiles) $(heads)
	gcc -o $(output) $(cfiles) $(flags)

clean:
	rm result
