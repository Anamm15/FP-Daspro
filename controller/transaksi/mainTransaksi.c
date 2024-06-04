#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "getTransaksi.c"
#include "searchTransaksi.c"
#include "deleteTransaksi.c"
#include "updateTransaksi.c"
#include "addTransaksi.c"
#include "detailTransaksi.c"

void main_transaksi() {
    Transaksi transaksi;
    int choice;
    int isContinue = 1;
    int id = 1;
    int selectedOption = 1;    
    int originalOption = 1;

    FILE *file;
    file = fopen("../database/transaksi.bin", "rb");
    if (file == NULL)
    {
        printf("File Tidak Ditemukan\n");
    }
    
    while (fread(&transaksi, sizeof(Transaksi), 1, file)) {
        id = atoi(transaksi.id);
        fgetc(file);
    }
    fclose(file);
        
    while (isContinue)
    {
        system("cls || clear");
        printf("=======================================\n");
        if (selectedOption == 1) printf("\033[1;31m->\033[0m");
        printf("\t1. Tampilkan Data Transaksi\n");
        if (selectedOption == 2) printf("\033[1;31m->\033[0m");
        printf("\t2. Tambah Data Transaksi\n");
        if (selectedOption == 3) printf("\033[1;31m->\033[0m");
        printf("\t3. Update Data Transaksi\n");
        if (selectedOption == 4) printf("\033[1;31m->\033[0m");
        printf("\t4. Hapus Data Transaksi\n");
        if (selectedOption == 5) printf("\033[1;31m->\033[0m");
        printf("\t5. Cari Data Transaksi\n");
        if (selectedOption == 6) printf("\033[1;31m->\033[0m");
        printf("\t6. Tampilkan Detail Transaksi Tertentu\n");
        printf("=======================================\n");
        printf("TEKAN TOMBOL BACKSPACE UNTUK KEMBALI KE PROGRAM SEBELUMNYA\n");
        choice = getch();
        switch(choice) {
            case 13:
                switch(selectedOption) {
                    case 1:
                        get_transaksi();
                        isContinue = confirm_out();
                        break;
                    case 2:
                        add_transaksi(id);
                        isContinue = confirm_out();
                        break;
                    case 3:
                        update_transaksi();
                        isContinue = confirm_out();
                        break;
                    case 4:
                        delete_transaksi();
                        isContinue = confirm_out();
                        break;
                    case 5:
                        search_transaksi();
                        isContinue = confirm_out();
                        break;
                    case 6:
                        detail_transaksi();
                        isContinue = confirm_out();
                        break;
                }
                break;
            case 80:
                selectedOption = (selectedOption % 6) + 1;
                break;
            case 72:
                selectedOption = (selectedOption + 5) % 6;
                selectedOption == 0 ? selectedOption = 6 : selectedOption;
                break;
            case 8:
                isContinue = 0;
                break;
        }
    }
}