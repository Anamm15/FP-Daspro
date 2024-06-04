#ifndef UPDATESTOK_H
#define UPDATESTOK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void updateStok(char bukuID[], int newStok) {
    Buku update_stok_buku;
    char line_book[1000], line_update[1000];
    FILE *file, *tempFile;
    file = fopen("../database/buku.bin", "rb");
    tempFile = fopen("../database/tempBuku.bin", "wb");

    while(fread(&update_stok_buku, sizeof(Buku), 1, file) > 0) {
        if(strcmp(update_stok_buku.id, bukuID) == 0) {
            update_stok_buku.stok = newStok;
            fwrite(&update_stok_buku, sizeof(Buku), 1, tempFile);
            fputc('\n', tempFile);
        } else {
            fwrite(&update_stok_buku, sizeof(Buku), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }
    fclose(tempFile);
    fclose(file);
    remove("../database/buku.bin");
    rename("../database/tempBuku.bin", "../database/buku.bin");
}

#endif /* UPDATESTOK_H */