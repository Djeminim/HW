// temp_functions.c
#include "temp_functions.h"

// Объявление функции compare на уровне файла
static int compare(const void *a, const void *b);

void Print_Error(error_log *log_error, int *number_log_error)
{
    for (int i = 0; i < *number_log_error; i++) {
        // Печатаем структуру ошибок
        printf("Error string - %d; Error parametr - %d Error code %s\n", log_error[i].number_struct,
               log_error[i].number_parametr, log_error[i].text_error);
    }
}

void Print_Struct(sensor *Data, int *number_sensor)
{
    for (int i = 0; i < *number_sensor; i++)
    {
        printf("%d-%02d-%02d time:%02d-%02d t=%d\n", Data[i].year, Data[i].month, Data[i].day,
               Data[i].watch, Data[i].minutes, Data[i].t);
    }
    printf("\nTotal structures: %d\n", *number_sensor);
}

void Scan_File(FILE *input, sensor **Data, error_log **log_error, int *number_log_error, int *number_sensor, int *capacity_sensor, int *capacity_error) {
    int number_parametr;
    // Заносим ошибки в структуру ошибок
    while ((number_parametr = fscanf(input, "%d; %d; %d; %d; %d; %d", &(*Data)[*number_sensor].year, &(*Data)[*number_sensor].month, &(*Data)[*number_sensor].day,
                                                                     &(*Data)[*number_sensor].watch, &(*Data)[*number_sensor].minutes, &(*Data)[*number_sensor].t)) > 0) {
        if (number_parametr < parametre_counter)
        {
            // Заносим ошибки в структуру ошибок
            if (fscanf(input, "%[^\n]\n", (*log_error)[*number_log_error].text_error) == 1)
            {
                (*log_error)[*number_log_error].number_struct = *number_sensor;
                (*log_error)[*number_log_error].number_parametr = number_parametr;

                // Увеличиваем размер массива ошибок
                if (*number_log_error >= *capacity_error)
                {
                    *capacity_error *= 2;
                    *log_error = realloc(*log_error, sizeof(error_log) * (size_t)(*capacity_error));
                    if (*log_error == NULL) {
                        perror("Unable to reallocate memory for log_error");
                        exit(EXIT_FAILURE);
                    }
                }

                (*number_log_error)++;
            }
        } else {
            // Увеличиваем размер массива данных
            if (*number_sensor >= *capacity_sensor)
            {
                *capacity_sensor *= 2;
                *Data = realloc(*Data, sizeof(sensor) * (size_t)(*capacity_sensor));
                if (*Data == NULL) {
                    perror("Unable to reallocate memory for Data");
                    exit(EXIT_FAILURE);
                }
            }

            (*number_sensor)++;
        }
    }
}

void Process_Data(sensor *Data, int number_sensor, int month_filter)
{
    // Сортировка данных qsort (указатель на массив, количество элементов в массиве,  размер одного элемента массива, функция сравнения)
    qsort(Data, number_sensor, sizeof(sensor), compare);

    //Принимает данные до 100 лет с 2000 года, каждого месяца и для каждого месяца есть sum,min,max
    int year_temps[100][12][3] = {0}; // [year][month][0] - sum, [year][month][1] - min, [year][month][2] - max
    int year_counts[100][12] = {0}; // Количество записей в каждом месяце каждого года
    int year_sum[100] = {0};
    int year_min[100] = {0};
    int year_max[100] = {0};
    int year_count[100] = {0};

    for (int i = 0; i < number_sensor; i++)
    {
        int year = Data[i].year - 2000; // Преобразуем год из формата 2000, 2001, 2002 и так далее в формат 0, 1, 2 и так далее
        int month = Data[i].month - 1;// Преобразуем месяц из формата 1-12 в формат 0-11
        int temp = Data[i].t;

        year_temps[year][month][0] += temp; //Добавляет текущую температуру к сумме температур для данного года и месяца
        year_counts[year][month]++; //Увеличивает количество записей для данного года и месяца

        //Проверка минимальной температуры конкретного месяца конкретного года
        if (temp < year_temps[year][month][1] || year_temps[year][month][1] == 0)
        {
            year_temps[year][month][1] = temp;
        }

        //Проверка максимальной температуры конкретного месяца конкретного года
        if (temp > year_temps[year][month][2])
        {
            year_temps[year][month][2] = temp;
        }

        year_sum[year] += temp; //cумма температуры за год

        //Ищет минимальную температуру за год
        if (temp < year_min[year] || year_min[year] == 0)
        {
            year_min[year] = temp;
        }

        //Ищет минимальную температуру за год
        if (temp > year_max[year])
        {
            year_max[year] = temp;
        }

        year_count[year]++;//подсчитывает сколько было записей температуры в конкретном году
    }

    //цикл до 2099 года
    for (int y = 0; y < 100; y++)
    {
        //проверка наличия данных для конкретного года
        if (year_count[y] != 0)
        {
            printf("\nYear %d:\n", y + 2000);
            for (int m = 0; m < 12; m++)
            {
                //Проверяет, есть ли данные за текущий месяц и год Если year_counts[y][m] не равно 0, это означает, что в этом месяце есть записи температуры.
                //Если month_filter равно 0, это означает, что фильтр не установлен и выводятся данные за все месяцы. Если month_filter равно m + 1, это означает,
                // что фильтр установлен на конкретный месяц и выводятся данные только за этот месяц.
                if (year_counts[y][m] != 0 && (month_filter == 0 || month_filter == m + 1))
                {
                    printf("  Month %d:\n", m + 1);
                    printf("  Average temperature: %.2f\n", (double)year_temps[y][m][0] / year_counts[y][m]);
                    printf("  Minimum temperature: %d\n", year_temps[y][m][1]);
                    printf("  Maximum temperature: %d\n", year_temps[y][m][2]);
                }
            }
            //Блок для выведения годовой статистики, выводится только если запрашивают полный отчёт (со всеми месяцами)
            if (month_filter == 0)
            {
                printf("  Year Statistics:\n");
                printf("  Average temperature: %.2f\n", (double)year_sum[y] / year_count[y]);
                printf("  Minimum temperature: %d\n", year_min[y]);
                printf("  Maximum temperature: %d\n", year_max[y]);
            }
        }
    }
}

// Определение функции compare
static int compare(const void *a, const void *b) {
    sensor *sensorA = (sensor *)a;
    sensor *sensorB = (sensor *)b;

    // определяет какой параметр больше a или b или равны (обязательное условие qsort)
   if (sensorA->year != sensorB->year)
    {
        return sensorA->year - sensorB->year;
    }
    if (sensorA->month != sensorB->month)
    {
        return sensorA->month - sensorB->month;
    }
    if (sensorA->day != sensorB->day)
    {
        return sensorA->day - sensorB->day;
    }
    if (sensorA->watch != sensorB->watch)
    {
        return sensorA->watch - sensorB->watch;
    }
    return sensorA->minutes - sensorB->minutes;
}

void print_usage() {
    printf("Usage: file_name [-h] [-f <filename.csv>] [-m <month>] [-exit]\n");
    printf("Options:\n");
    printf("  -h    Show this help message and exit\n");
    printf("  -f <filename.csv>     Input CSV file for processing (./file -f name_csv_file.csv)\n");
    printf("  -m <month>    If specified, output statistics for the given month only (./file_name -f name_csv_file.csv -m number_month(1-12))\n");
    printf("  -exit or -e            Exit the program\n");
}