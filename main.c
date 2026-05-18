#include <stdio.h> // printf
#include <wchar.h> // wchar_t
#include <stdint.h>

#include <hidapi/hidapi.h>

#define MAX_STR 255
#define BLAZE_VENDOR_ID 0x30fa
#define BLAZE_PRODUCT_ID 0x1440

int main(int argc, char* argv[])
{
	int res;
	unsigned char buf[65];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;

	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(BLAZE_VENDOR_ID, BLAZE_PRODUCT_ID, NULL);
	if (!handle) {
		printf("Unable to open device\n");
		hid_exit();
 		return 1;
	}

    uint8_t packets[][8] = {
        {0x07,0x18,0x03, 0x04, 0x18, 0x00, 0xa3, 0x07}, // 69 mode + speed
        {0x07,0x18,0x03, 0x05, 0x18, 0x00, 0x90, 0x07}, // 70 color(Ored)
        {0x07,0x18,0x09, 0x00, 0x18, 0x00, 0x00, 0x07}, // 77 DK
        {0x07,0x18,0x10, 0x00, 0x00, 0x00, 0x00, 0x00}, //       Also apply apprently
        {0x07,0x18,0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // 1919 Apply apprently
    };

    size_t n = sizeof(packets)/sizeof(packets[0]);
    for(size_t i=0; i<n; i++) {
        res = hid_write(handle, packets[i], 65);
        printf("%zu/%zu\r", i, n);
    }
    printf("Done\n");
	//
	// // Read requested state
	// res = hid_read(handle, buf, 65);
	//
	// // Print out the returned buffer.
	// for (i = 0; i < 4; i++)
	// 	printf("buf[%d]: %d\n", i, buf[i]);

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return 0;
}
