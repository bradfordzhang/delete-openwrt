CC=g++
CPPFLAGS=-Wall -Wextra
INSTALL_PATH=/usr/local/bin
BINARY_FILE=delete-openwrt

delete-openwrt:
	$(CC) -o $(BINARY_FILE) delete.cpp $(CFLAGS)

install:
	cp $(BINARY_FILE) $(INSTALL_PATH)

clean:
	rm $(BINARY_FILE)
