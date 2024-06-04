#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int parseDate(const char* dateStr, struct Date* date) {
    if (sscanf(dateStr, "%d-%d-%d", &date->day, &date->month, &date->year) == 3) {
        return 1; // Parsing berhasil
    } else {
        return 0; // Parsing gagal
    }
}

int selisihHari(char time1[], char time2[]) {
    
    struct Date date1, date2;
    if (parseDate(time1, &date1) && parseDate(time2, &date2)) {
        // Menghitung selisih hari
        int dayDiff = (date2.year - date1.year) * 365 + (date2.month - date1.month) * 30 + (date2.day - date1.day);
        return dayDiff;
    } else {
        return 0;
    }

    return 0;
}
