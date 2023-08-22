#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
void handle_functions(char c, va_list args, int *char_printed);
int print_string(char *s);
void print_number(int n, int *cp);
void print_unsigned(unsigned int n, int *cp);
void dectobase(unsigned int n, unsigned int d, int maj, int *cp);

#endif
