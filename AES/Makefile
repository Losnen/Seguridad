CXX=g++ 
CXXFLAGS=-g

OBJS = AES.o CBC.o main.o

all: ${OBJS}
	$(CXX)  $(CXXFLAGS) -o aes ${OBJS}

clean: 
	rm -rf *.o aes