#include "stdint.h"
#include "stdlib.h"
// stmlink virtual com port

void print_time(uint16_t time);

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
