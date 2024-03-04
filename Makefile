CFLAGS += -g  -I../Symbi-OS/Symlib/include/
SCFLAGS += ${CFLAGS} -static
SLDFLAGS += ${SCFLAGS} ../Symbi-OS/Symlib/build/L0/sym_lib.o

.PHONY: clean

tcp-echo-server: tcp-echo-server.c
	${CC} tcp-echo-server.c \
	-g \
	-o tcp-echo-server

write: write.o skernel.o
	${CC} -o $@ $^

swrite: swrite.o skernel.o 
	${CC} ${SLDFLAGS} -o $@ $^

swrite.o: write.c
	${CC} -c ${SCFLAGS} -o $@ $^

skernel.o: kernel.s
	${CC} -c ${SCFLAGS} -o $@ $^

clean:
	rm -rf $(wildcard *.o swrite)
