#ifndef Kyrs
#define Kyrs

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <locale.h>
#include <inttypes.h>
#include <limits.h> // Добавляем этот заголовок для определения INT_MAX и INT_MIN
#include <unistd.h> // Для getopt

#define max_length 1024
#define parametre_counter 6

typedef struct {
    int number_struct;
    int number_parametr;
    char text_error[20];
} error_log;

typedef struct {
    int year;
    int month;
    int day;
    int watch;
    int minutes;
    int t;
} sensor;

void Print_Error(error_log *log_error, int *number_log_error);
void Print_Struct(sensor *Data, int *number_sensor);
void Scan_File(FILE *input, sensor **Data, error_log **log_error, int *number_log_error, int *number_sensor, int *capacity_sensor, int *capacity_error);
void Process_Data(sensor *Data, int number_sensor, int month_filter);
void print_usage();

#endif
