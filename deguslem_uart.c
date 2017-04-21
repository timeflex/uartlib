/*
 * Copyright (C) 2016 - 2017 Timeflex Data pvt ltd
 * deguslcm_uart.h
 * Date: 20/05/2017
 * Revision:
 *
 *
 * Usage:
 * _____               __  _
  |__  _|             / / | |
    | | (_)__ __ ___ _| |_| |____ __   __
    | | | |  '  | __(_   _) | ___)\ \ / /
    | | | | | | | ___ | | | | ___  \   /
    |_| |_|_|_|_|____)|_| |_|____) /_/\_\
 *
 * deguslem_uart.h
 *
 *
 *   Author: Sijo k saju
 */

#include "deguslem_uart.h"

/*
	 CONFIGURE THE UART
	 The flags (defined in /usr/include/termios.h - see http:  pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
	 Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
	 CSIZE:- CS5, CS6, CS7, CS8
	 CLOCAL - Ignore modem status lines
	 CREAD - Enable receiver
	 IGNPAR = Ignore characters with parity errors
	 ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
	 PARENB - Parity enable
	 PARODD - Odd parity (else even)
	 */

void uart_init_dgus() {

	struct termios uartoptions;
	tcgetattr(uart_filestream, &uartoptions);
	uartoptions.c_cflag = B115200 | CS8 | CLOCAL | CREAD; /*  <Set baud rate*/
	uartoptions.c_iflag = IGNPAR;
	uartoptions.c_oflag = 0;
	uartoptions.c_lflag = 0;
	tcflush(uart_filestream, TCIFLUSH);
	tcsetattr(uart_filestream, TCSANOW, &uartoptions);

}

s8 read_dguslcm_ver(u8 *tx_cmd_buffer, u8 size, u8 *rx_buffer) {

	devopen=uart_dev_open();
	if (uart_filestream != UART_RETURN_ERROR) {
		uart_write_(tx_cmd_buffer, size);
	} else {
		/*  ERROR - CAN'T OPEN SERIAL PORT*/
		printf(
				"Error - Unable to open UART.  Ensure it is not in use by another application\n");
	}

	uart_read_(uart_filestream,UART_RX_MAX_BUFF_SIZE,rx_buffer);
}

u8 uart_write_(u8 *tx_cmd_buffer_, u8 size_) {

	sendbytes = write(uart_filestream, tx_cmd_buffer_, size_); /* Filestream, bytes to write, number of bytes to write*/

	return sendbytes;
}

u8 uart_read_(u8 *tx_cmd_buffer_, u8 size_, u8 *rx_buffer_) {

	rx_length = read(uart_filestream, (void*) rx_buffer_, size_);/*  Filestream, buffer to store in, number of bytes to read (max)*/

	return rx_length;
}

s8 uart_dev_open(){
	uart_filestream = open(UART_DEV_PATH, O_RDWR | O_NOCTTY | O_NDELAY);/*  Open in non blocking read/write mode*/
return uart_filestream;
}
