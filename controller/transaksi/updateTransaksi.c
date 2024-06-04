#include "date.c"
#include "updateStok.h"

typedef struct 
{
    char id[10];
    char tanggal_pinjam[11];
    char tanggal_kembali[11];
    int denda;
    char status[10];
    char customerID[20];
    char bukuID[20];
} TempTransaksi;

void update_transaksi() {
    FILE *file, *tempFile, *bookFile;
    Transaksi update_transaksi; Buku update_buku_transaksi; TempTransaksi tempTransaksi;
    int c;
    char add, bukuID[100], choiceUpdate[10];
    int newStok;

    file = fopen("../database/transaksi.bin", "rb");
    tempFile = fopen("../database/tempTransaksi.bin", "wb");
    bookFile = fopen("../database/buku.bin", "rb");

    printf("===============================================================\n");
    printf("Masukkan id transaksi yang akan diupdate: ");
    scanf(" %s", choiceUpdate);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("=======================================================================\n");

    while (fread(&update_transaksi, sizeof(Transaksi), 1, file) > 0) {
        int updateDenda = 0;
        if (strcmp(update_transaksi.id, choiceUpdate) == 0) {
            strcpy(tempTransaksi.id, update_transaksi.id);
            strcpy(tempTransaksi.tanggal_pinjam, update_transaksi.tanggal_pinjam);
            tempTransaksi.denda = update_transaksi.denda;
            strcpy(tempTransaksi.status, "SELESAI");
            strcpy(tempTransaksi.customerID, update_transaksi.customerID);
            strcpy(tempTransaksi.bukuID, update_transaksi.bukuID);
            while(fread(&update_buku_transaksi, sizeof(Buku), 1, bookFile) > 0) {
                if(strcmp(update_buku_transaksi.id, update_transaksi.bukuID) == 0) {
                    newStok = update_buku_transaksi.stok;
                    break;
                }
                fgetc(bookFile);
            }

            newStok = newStok + 1;
            printf("\nMasukkan tanggal kembali transaksi format(dd-mm-yyyy): ");
            fgets(tempTransaksi.tanggal_kembali, sizeof(tempTransaksi.tanggal_kembali), stdin);
            tempTransaksi.tanggal_kembali[strcspn(tempTransaksi.tanggal_kembali, "\n")] = '\0';

            if(selisihHari(tempTransaksi.tanggal_pinjam, tempTransaksi.tanggal_kembali) >  3) {
                updateDenda = 5000 * (selisihHari(tempTransaksi.tanggal_pinjam, tempTransaksi.tanggal_kembali) - 3);
                tempTransaksi.denda = updateDenda;
            }
            
            fclose(bookFile);

            printf("\n===============================================================\n");
            printf("ID TRANSAKSI: %s\n", tempTransaksi.id);
            printf("TANGGAL PINJAM TRANSAKSI: %s\n", tempTransaksi.tanggal_pinjam);
            printf("TANGGAL KEMBALI TRANSAKSI: %s\n", tempTransaksi.tanggal_kembali);
            printf("DENDA: %d\n", tempTransaksi.denda);
            printf("STATUS TRANSAKSI: %s\n", tempTransaksi.status);
            printf("ID BUKU TRANSAKSI: %s\n", tempTransaksi.bukuID);
            printf("ID MEMBER TRANSAKSI: %s\n", tempTransaksi.customerID);
            printf("\n===============================================================\n");

            printf("Apakah anda yakin mengupdate data di atas(y/n): ");
            add = getchar();
            while ((c = getchar()) != '\n' && c != EOF);
            if ((add == 'y' || add == 'Y')) {
                updateStok(tempTransaksi.bukuID, newStok);
                fwrite(&tempTransaksi, sizeof(Transaksi), 1, tempFile);
                fputc('\n', tempFile);
            } else {
                fwrite(&update_transaksi, sizeof(Transaksi), 1, tempFile);
                fputc('\n', tempFile);
            }
        } else {
            fwrite(&update_transaksi, sizeof(Transaksi), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }

    fclose(tempFile);
    fclose(file);
    remove("../database/transaksi.bin");
    rename("../database/tempTransaksi.bin", "../database/transaksi.bin");
}
