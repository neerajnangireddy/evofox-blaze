evofox-blaze: main.c
	cc -o $@ $(shell pkg-config --cflags --libs hidapi-libusb) $^

clean:
	rm evofox-blaze
