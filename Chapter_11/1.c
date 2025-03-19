#include <stdio.h>
#include <stdlib.h>

// You are developing a database of measured meteorological data for use in 
// weather and climate research. Define a structure type measured_data_t 
// with components site_id_num (a four-digit integer), wind_speed, 
// day_of_month, and temperature. Each site measures its data daily, at noon 
// local time. Write a program that inputs a file of measured_data_t records 
// and determines the site with the greatest variation in temperature (defined 
// here as the biggest difference between extrema) and the site with the highest 
// average wind speed for all the days in the file. You may assume that there will 
// be at most ten sites. Test the program on the following July daily data col-
// lected over one week at three sites:
// ID DAY WINDSPEED(KNOT) TEMPERATURE(degC)
// 2001 10  11 30
// 2001 11  5 22
// 2001 12  18 25
// 2001 13  16 26
// 2001 14  14 26
// 2001 15  2 25
// 2001 16  14 22
// 3345 10  8 29
// 3345 11  5 23
// 3345 12  12 23
// 3345 13  14 24
// 3345 14  10 24
// 3345 15  9 22
// 3345 16  9 20
// 3819 10  17 27
// 3819 11  20 21
// 3819 12  22 21
// 3819 13  18 22
// 3819 14  15 22
// 3819 15  9 19
// 3819 16  12 18

typedef struct {
    int site_id_num;
    int day_of_month;
    int wind_speed;
    int temperature;
} measured_data_t;

void processSiteData(measured_data_t data[], int size, int *max_variation_site, int *max_avg_wind_site) {
    int i, temp_min, temp_max, total_wind;
    int temp_diff[10] = {0}, avg_wind[10] = {0};

    for (i = 0; i < size; i++) {
        temp_min = temp_max = data[i].temperature;
        total_wind = 0;

        for (int j = i; j < size && data[j].site_id_num == data[i].site_id_num; j++) {
            if (data[j].temperature < temp_min) temp_min = data[j].temperature;
            if (data[j].temperature > temp_max) temp_max = data[j].temperature;
            total_wind += data[j].wind_speed;
        }
        temp_diff[data[i].site_id_num % 10] = temp_max - temp_min;
        avg_wind[data[i].site_id_num % 10] = total_wind / 7; // 7 days of data
        i += 6; // Skip to the next site data block
    }

    int max_diff = -1, max_wind = -1;
    for (i = 0; i < 10; i++) {
        if (temp_diff[i] > max_diff) {
            max_diff = temp_diff[i];
            *max_variation_site = i;
        }
        if (avg_wind[i] > max_wind) {
            max_wind = avg_wind[i];
            *max_avg_wind_site = i;
        }
    }
}

int main() {
    FILE *fp = fopen("weather.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    measured_data_t data[21];
    int count = 0;
    while (fscanf(fp, "%d %d %d %d", &data[count].site_id_num, &data[count].day_of_month, 
                  &data[count].wind_speed, &data[count].temperature) == 4) {
        count++;
    }
    fclose(fp);

    int max_variation_site, max_avg_wind_site;
    processSiteData(data, count, &max_variation_site, &max_avg_wind_site);

    printf("Site with the greatest variation in temperature: %d\n", max_variation_site);
    printf("Site with the highest average wind speed: %d\n", max_avg_wind_site);
    return 0;
}