CC=g++
CPPFLAGS=-Wall -Wextra
INSTALL_PATH=/usr/local/bin

delete-openwrt:
	$(CC) -o delete delete.cpp $(CFLAGS)

install:
	cp delete $(INSTALL_PATH)

clean:
	rm delete
