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

ixgbe_hello: ixgbe_hello.o skernel.o
	${CC} ${SLDFLAGS} -o $@ $^

ixgbe_napi_disable: ixgbe_napi_disable.o skernel.o
	${CC} ${SLDFLAGS} -o $@ $^

ixgbe_napi_enable: ixgbe_napi_enable.o skernel.o
	${CC} ${SLDFLAGS} -o $@ $^

ixgbe_poll: ixgbe.o skernel.o
	${CC} ${SLDFLAGS} -o $@ $^

ixgbe_poll_single: ixgbe_poll_single.o skernel.o
	${CC} ${SLDFLAGS} -o $@ $^

swrite: swrite.o skernel.o 
	${CC} ${SLDFLAGS} -o $@ $^

swrite.o: write.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe.o: ixgbe_poll.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe_hello.o: ixgbe_hello.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe_poll_single.o: ixgbe_poll_single.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe_napi_disable.o: ixgbe_napi_disable.c
	${CC} -c ${SCFLAGS} -o $@ $^

ixgbe_napi_enable.o: ixgbe_napi_enable.c
	${CC} -c ${SCFLAGS} -o $@ $^

skernel.o: kernel.S
	${CC} -c ${SCFLAGS} -o $@ $^

clean:
	rm -rf $(wildcard *.o swrite tcp-echo-server ixgbe_napi_disable ixgbe_napi_enable ixgbe_poll ixgbe_hello)
