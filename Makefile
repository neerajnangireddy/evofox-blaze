evofox: main.c
	cc -o evofox main.c $(shell pkg-config --cflags --libs hidapi-libusb)

clean:
	rm evofox
