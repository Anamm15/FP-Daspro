#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include "confirm.c"


typedef struct {
    char id[10];
    char judul[100];
    char penulis[100];
    int tahun;
    int stok;
} Buku;

typedef struct {
    char id[10];
    char email[100];
    char nama[100];
    char alamat[100];
    char no_telp[16];
} Member;

typedef struct 
{
    char id[10];
    char tanggal_pinjam[11];
    char tanggal_kembali[11];
    int denda;
    char status[10];
    char customerID[20];
    char bukuID[20];
} Transaksi;

#include "../controller/buku/mainBuku.c"
#include "../controller/member/mainMember.c"
#include "../controller/transaksi/mainTransaksi.c"

int main() {
    char choice;
    int isContinue = 1;
    char outChoice[1];
    int selectedOption = 1;

    while (isContinue)
    {
        system("cls || clear");
        printf("=======================================\n");
        if (selectedOption == 1) printf("\033[1;31m->\033[0m");
        printf("\t1. Informasi Buku\n");
        if (selectedOption == 2) printf("\033[1;31m->\033[0m");
        printf("\t2. Informasi Member\n");
        if (selectedOption == 3) printf("\033[1;31m->\033[0m");
        printf("\t3. Informasi Transaksi\n");
        printf("=======================================\n");
        printf("TEKAN TOMBOL ESC UNTUK KELUAR DARI PROGRAM\n");
        
        choice = getch();
        switch(choice) {
            case 13:
                switch (selectedOption)
                {
                    case 1:
                        main_buku();
                        break;
                    case 2:
                        main_member();
                        break;
                    case 3:
                        main_transaksi();
                        break;
                    default:
                        printf("Input salah!!! silahkan masukkan input yang benar\n");
                        break;
                }
                break;
            case 80:
                selectedOption = (selectedOption % 3) + 1;
                break;
            case 72:
                selectedOption = (selectedOption - 2 + 3) % 3 + 1;
                break;
            case 27:
                isContinue = 0;
                break;
        }
    }
    return 0;
}