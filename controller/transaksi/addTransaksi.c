#include "updateStok.h"

void add_transaksi(int row) {
    Transaksi add_transaksi; Buku add_buku_transaksi; Member add_member_transaksi;
    FILE *file, *readFile, *bookFile;
    add_transaksi.denda = 0;
    int choiceUpdate, c;
    char add, line[1000], line_book[1000], line_update[1000];

    strcpy(add_transaksi.status, "DIPINJAM");
    sprintf(add_transaksi.id, "%d", row + 1);
    int newStok;
    time_t current_time;
    struct tm *local_time;
    
    bookFile = fopen("../database/buku.bin", "rb");
    file = fopen("../database/transaksi.bin", "ab+");
    readFile = fopen("../database/transaksi.bin", "rb");

    // Cek jika file kosong, jika iya, set newId ke 1
    if (fgets(line, sizeof(line), readFile) == NULL) {
        sprintf(add_transaksi.id, "%d", 1);
    }

    strcpy(add_transaksi.tanggal_kembali, "-");

    current_time = time(NULL);
    local_time = localtime(&current_time);
    strftime(add_transaksi.tanggal_pinjam, sizeof(add_transaksi.tanggal_pinjam), "%d-%m-%Y", local_time);
    add_transaksi.tanggal_pinjam[strcspn(add_transaksi.tanggal_pinjam, "\n")] = '\0';

    printf("===============================================================\n");
    printf("\nMasukkan id customer: ");
    fgets(add_transaksi.customerID, sizeof(add_transaksi.customerID), stdin);
    add_transaksi.customerID[strcspn(add_transaksi.customerID, "\n")] = '\0';

    printf("\nMasukkan id buku: ");
    fgets(add_transaksi.bukuID, sizeof(add_transaksi.bukuID), stdin);
    add_transaksi.bukuID[strcspn(add_transaksi.bukuID, "\n")] = '\0';

    while(fread(&add_buku_transaksi, sizeof(Buku), 1, bookFile) > 0) {
        if(strcmp(add_buku_transaksi.id, add_transaksi.bukuID) == 0) {
            newStok = add_buku_transaksi.stok;
            break;
        }
        fgetc(bookFile);
    }
    fclose(bookFile);

    printf("\n=========================================================================\n");
    printf("ID TRANSAKSI: %s\n",add_transaksi.id);
    printf("TANGGAL PINJAM TRANSAKSI: %s\n", add_transaksi.tanggal_pinjam);
    printf("TANGGAL KEMBALI TRANSAKSI: %s\n", add_transaksi.tanggal_kembali);
    printf("DENDA: %d\n", add_transaksi.denda);
    printf("STATUS TRANSAKSI: %s\n", add_transaksi.status);
    printf("ID BUKU TRANSAKSI: %s\n", add_transaksi.bukuID);
    printf("ID MEMBER TRANSAKSI: %s\n", add_transaksi.customerID);
    printf("\n========================================================================\n");

    printf("Apakah anda yakin menambahkan data di atas(y/n): ");
    add = getchar();
    while ((c = getchar()) != '\n' && c != EOF);
    if ((add == 'y' || add == 'Y')) {
        if(newStok > 0) {
        newStok = newStok - 1;
        updateStok(add_transaksi.bukuID, newStok);
        fwrite(&add_transaksi, sizeof(Transaksi), 1, file);
        fputc('\n', file);
        } else {
            printf("Buku yang tersebut sedang tidak tersedia, mohon meminjamnya lain waktu\n");
        }
    }  
    fclose(file);
    fclose(readFile);
}