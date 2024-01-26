#include "stdint.h"
#include "stdlib.h"
// stmlink virtual com port

void print_time(uint16_t time);
static char add_32_int[] = "\r\nAdd two 32bit int: ";
static char add_64_int[] = "\r\nAdd two 64bit int: ";

static char mul_32_int[] = "\r\nMul two 32bit int: ";
static char mul_64_int[] = "\r\nMul two 64bit int: ";

static char div_32_int[] = "\r\nDiv two 32bit int: ";
static char div_64_int[] = "\r\nDiv two 64bit int: ";

static char cpy_8_byte_struct[] = "\r\nCpy 8 byte struct: ";
static char cpy_128_byte_struct[] = "\r\nCpy 128 byte struct: ";
static char cpy_1024_byte_struct[] = "\r\nCpy 1024 byte struct: ";





char* convertIntegerToChar(int N);
static char prompt[] = "\r\nSTM32 CLI (time/help): ";

static char invalid_cmd[] = "\r\nInvalid command: ";

static char help[] =
    "\r\nSupported Commands:"
    "\r\n    time: preform timer measurements"
    "\r\n    help: display this help command";

static char help_cmd[] = "help\r";
static char time_cmd[] = "time\r";

static char success[] = "\r\nSuccess";

/// @brief send a string over the serial
/// @param p_data char buffer of data to send
/// @param size length of the buffer to send
void CLI_transmit(char p_data[], unsigned int size);

/// @brief block untill the buffer of `size` is filled or a return carriage is
/// detected
/// @param p_data char buffer of data to be received/placed in
/// @param size length of the buffer
void CLI_receive(void);

/// @brief refresh the screen with ANSI control characters
/// @param should_init decides if to init scroll, clear or save and restore
/// cursor
void refresh_screen(unsigned int should_init);

/// @brief NULL every position in the buffer
/// @param p_data char buffer to clear
/// @param size length of buffer
void flush_buff(char p_data[], unsigned int size);
