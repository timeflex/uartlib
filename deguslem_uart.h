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

#ifndef DEGUSLEM_UART_H_
#define DEGUSLEM_UART_H_

/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */
#include <stdio.h>
#include <unistd.h>			/*  Used for UART*/
#include <fcntl.h>			/*  Used for UART*/
#include <termios.h>		/*  Used for UART*/
#include <stdint.h>

/*unsigned integer types*/
typedef	uint8_t u8;/**< used for unsigned 8bit */
typedef	uint16_t u16;/**< used for unsigned 16bit */
typedef	uint32_t u32;/**< used for unsigned 32bit */
typedef	uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */


#define UART_RETURN_ERROR -1
#define UART_RETURN_SUCCESS -1
#define UART_BYTES 0
#define UART_DEV_PATH "/dev/ttyS2"
#define UART_TX_MAX_BUFF_SIZE 255
#define UART_RX_MAX_BUFF_SIZE 255


/*
  -------------------------
  ----- SETUP USART  -----
  -------------------------
*/
int uart_filestream = UART_RETURN_ERROR;
u8 sendbytes=UART_BYTES;
int rx_length;
u8 devopen;
/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS PROTOTYPES ------------------------------------------ */


s8 uart_dev_open();



void uart_init_dgus();

/*	\Brief: The function is used as UART read
 *	\Return : Status of the UART dgus read
 *	\param tx_buffer : The dgus device version command
 *	\param size : the size of tx_cmd_buffer
 *	\param rx_buffer : This data read from the device, which is hold in an array ,here version
 */
s8 read_dguslcm_ver(u8 *tx_cmd_buffer,u8 size,u8 *rx_buffer);

/*	\Brief: The function is used as UART write
 *	\Return : Status of the UART function write
 *	\param tx_buffer : the transfer buffer
 *	\param size : the size of transfer buffer
 *
 */
u8 uart_write_(u8 *tx_cmd_buffer, u8 size);

/*	\Brief: The function is used as UART read
 *	\Return : Status of the UART function read
 *	\param tx_buffer : the transfer buffer
 *	\param size : the size of transfer buffer
 *
 */

u8 uart_read_(u8 *tx_cmd_buffer_, u8 size_, u8 *rx_buffer_);


#endif /* DEGUSLEM_UART_H_ */
