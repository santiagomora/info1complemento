
cs=src
hs=$(cs)/head
flags=-Wall -lm

cfiles=$(wildcard $(cs)/*.c)
cfiles1=$(subst $(cs)/functions2.c,,$(cfiles))
cfiles2=$(subst $(cs)/functions.c,,$(cfiles))
heads=$(wildcard $(hs)/*.h)

o1=result1
o2=result2

main: $(cfiles) $(heads)
	gcc -o $(o2) $(cfiles2) $(flags)
	gcc -o $(o1) $(cfiles1) $(flags)

clean:
	rm -v $(o1)
	rm -v $(o2)
