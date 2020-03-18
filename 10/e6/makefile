
cs=src
hs=$(cs)/head
flags=-Wall -lm

cfiles=$(wildcard $(cs)/*.c)
heads=$(wildcard $(hs)/*.h)

output=result

main: $(cfiles) $(heads)
	gcc -o $(output) $(cfiles) $(flags)

clean:
	rm result
