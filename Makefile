CFLAGS += -g  -DCONFIG_X86_64 -I../Symbi-OS/Symlib/include/
IXGBEFLAGS = -I../Symbi-OS/linux/drivers/net/ethernet/intel/
SCFLAGS += ${CFLAGS} -static
SLDFLAGS += ${SCFLAGS} ../Symbi-OS/Symlib/build/L0/sym_lib.o

.PHONY: clean

tcp-echo-server: tcp-echo-server.c
	${CC} tcp-echo-server.c \
	-g \
	-o tcp-echo-server

write: write.o skernel.o
	${CC} -o $@ $^

ixgbe: ixgbe.o sixgbe.o
	${CC} ${SLDFLAGS} -o $@ $^

swrite: swrite.o skernel.o 
	${CC} ${SLDFLAGS} -o $@ $^

swrite.o: write.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe.o: ixgbe.c
	${CC} -c ${SCFLAGS} -o $@ $^

skernel.o: kernel.S
	${CC} -c ${SCFLAGS} -o $@ $^

sixgbe.o: ixgbe.S
	${CC} -c ${SCFLAGS} -o $@ $^

clean:
	rm -rf $(wildcard *.o swrite ixgbe tcp-echo-server)
