CC=		gcc
CFLAGS=		-g -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs

TARGETS=	libstr.a \
		libstr.so \
		str-static \
		str-dynamic

all:		$(TARGETS)

library.o:	library.c str.h
	$(CC) $(CFLAGS) -c -o library.o library.c

main.o: 	main.c str.h
	$(CC) $(CFLAGS) -c -o main.o main.c

libstr.so:	library.o
	$(LD) $(LDFLAGS) -shared -o libstr.so library.o

libstr.a:	library.o
	$(AR) $(ARFLAGS) libstr.a library.o

str-dynamic:	main.o libstr.so
	$(LD) $(LDFLAGS) -o str-dynamic main.o -lstr

str-static:	main.o libstr.a
	$(LD) $(LDFLAGS) -static -o str-static main.o -lstr

test:		
	@$(MAKE) -sk test-all
	
test-all:	test-libstr test-str

test-libstr:	libstr.so
	curl -sLO https://raw.githubusercontent.com/nd-cse-20289-sp23/cse-20289-sp23-assignments/master/homework07/test_libstr.py
	chmod +x test_libstr.py
	./test_libstr.py -v

test-str:	str-static str-dynamic
	curl -sLO https://raw.githubusercontent.com/nd-cse-20289-sp23/cse-20289-sp23-assignments/master/homework07/test_str.sh
	chmod +x test_str.sh
	./test_str.sh

clean:
	rm -f $(TARGETS) *.o

# TODO: Add rules for libstr.a libstr.so

# TODO: Add rules for str-dynamic str-static
