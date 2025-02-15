// main.c
#include "temp_functions.h"

int main(int argc, char *argv[]) {
    int opt;
    char *filename = NULL;
    int error_log_flag  = 0;
    int month_filter = 0;
    int exit_flag = 0;
    int number_log_error = 0;
    int number_sensor = 0;
    int capacity_sensor = 1000000; // Начальная емкость массива данных
    int capacity_error = 1000000; // Начальная емкость массива ошибок

    printf("Starting program...\n");
    //opt возвращает -1 когда конец списка опций или неизвестная опция
    while ((opt = getopt(argc, argv, "hef:m:")) != -1) //"hef:m:" - cписок обций если после символа есть : значит опия с аргументом
    {
        switch (opt)
        {
            case 'h':
                print_usage();
                break;

            case 'f':
                filename = optarg;//optarg - глобальная переменная объявленная в <unistd.h> хранит аргумент текущей опции
                printf("File specified: %s\n", filename);
                break;

            case 'm':
                month_filter = atoi(optarg); //преобразует каждый строковый символ массива в целое число
                if (month_filter < 1 || month_filter > 12)
                {
                    //stderr - файловый поток ошибок
                    fprintf(stderr, "Invalid month: %d. Month should be between 1 и 12.\n", month_filter);
                    return 1;
                }
                printf("Month filter specified: %d\n", month_filter);
                break;

            case 'e':
                exit_flag = 1;
                printf("Exit flag set.\n");

                break;

            default:
                print_usage();
                return 1;
        }
    }

    if (filename == NULL) {
        fprintf(stderr, "Error: No input file specified. Use -f <filename.csv> to specify the input file.\n");
        print_usage();
        return 1;
    }

    FILE *input = fopen(filename, "r"); //открываем файл для чтения
    if (input == NULL)
    {
        printf("errno: %d\n", errno);
        perror(filename);
        return 1;
    }

    printf("File opened successfully.\n");

    // Выделяем начальную память на структуры
    sensor *Data = (sensor *)malloc(sizeof(sensor) * capacity_sensor);
    error_log *log_error = (error_log *)malloc(sizeof(error_log) * capacity_error);

    if (Data == NULL || log_error == NULL)
    {
        perror("Unable to allocate memory");
        fclose(input);
        return 1;
    }

    printf("Memory allocated successfully.\n");

    Scan_File(input, &Data, &log_error, &number_log_error, &number_sensor, &capacity_sensor, &capacity_error);

    printf("File scanned successfully.\n");

    Print_Struct(Data, &number_sensor);
    Print_Error(log_error, &number_log_error);

    // Обработка данных и вывод статистики
    Process_Data(Data, number_sensor, month_filter);

    fclose(input);
    free(Data);
    free(log_error);

    // Проверка флага выхода
    if (exit_flag)
    {
        printf("Exiting the program.\n");
        return 0;
    }

    // Зацикливание программы до ввода ключа -exit
    while (1)
    {
        printf("Enter command (-h for help, -exit or -e to exit): ");
        char command[10];
        if (scanf("%9s", command) == 1) //возвращает 1 если все прошло успешно/ %9s считывает 9 символов из массива
        {
            if ((strcmp(command, "-exit") == 0) || (strcmp(command, "-e") == 0)) //strcmp - лексегрофическое сравнение для завершения программы
            {
                printf("Exiting the program.\n");
                break;
            }

            else if (strcmp(command, "-l") == 0)
            {
                Print_Error(log_error, &number_log_error);
            }

            else if (strcmp(command, "-h") == 0) //запуск справки
            {
                print_usage();
            }

            else if (strcmp(command, "-f") == 0) //запуск программы
            {
                char new_filename[100];
                if (scanf("%99s", new_filename) == 1) //считываем новое имя файла
                {
                    filename = new_filename;
                    input = fopen(filename, "r"); //открываем новый файл для чтения
                    if (input == NULL)
                    {
                        printf("errno: %d\n", errno);
                        perror(filename);
                        continue;
                    }
                    number_log_error = 0;
                    number_sensor = 0;
                    capacity_sensor = 1000000; // Начальная емкость массива данных
                    capacity_error = 1000000; // Начальная емкость массива ошибок

                    // Выделяем начальную память на структуры
                    Data = (sensor *)malloc(sizeof(sensor) * capacity_sensor);
                    log_error = (error_log *)malloc(sizeof(error_log) * capacity_error);

                    if (Data == NULL || log_error == NULL)
                    {
                        perror("Unable to allocate memory");
                        fclose(input);
                        continue;
                    }

                    Scan_File(input, &Data, &log_error, &number_log_error, &number_sensor, &capacity_sensor, &capacity_error);

                    Print_Struct(Data, &number_sensor);
                    Print_Error(log_error, &number_log_error);
                    // Обработка данных и вывод статистики
                    Process_Data(Data, number_sensor, month_filter);

                    fclose(input);
                    free(Data);
                    free(log_error);
                }

                else
                {
                    printf("Invalid filename.\n");
                }

            }

            else if (strcmp(command, "-m") == 0)
            {
                int new_month_filter;
                if (scanf("%d", &new_month_filter) == 1)
                {
                    if (new_month_filter < 1 || new_month_filter > 12)
                    {
                        fprintf(stderr, "Invalid month: %d. Month should be between 1 и 12.\n", new_month_filter);
                        continue;
                    }
                    month_filter = new_month_filter;
                    Process_Data(Data, number_sensor, month_filter);
                }

                else
                {
                    printf("Invalid month.\n");
                }
            }

            else
            {
                printf("Invalid command. Enter -h for help.\n");
            }
        }

        else
        {
            printf("Invalid input. Enter -h for help.\n");
        }
    }

    return 0;
}