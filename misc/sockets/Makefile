all: tcpclient.o tcpserver.o udpclient.o udpserver.o
tcpclient.o: tcpserver.o
	cc tcpclient.c -o $@
tcpserver.o: 
	cc tcpserver.c -o $@
udpclient.o: udpserver.o
	cc udpclient.c -o $@
udpserver.o: 
	cc udpserver.c -o $@
clean:
	rm -f *.o