
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


void get_buku() {
    Buku get_buku;
    FILE *file;
    size_t bytesRead;
    int id;

    file = fopen("../database/buku.bin", "rb");
    if (file == NULL)
    {
        printf("File Tidak Ditemukan\n");
    }

    printf("====================================================================================================\n");
    printf("%-6s | %-30s | %-32s | %5s | %2s\n", "ID", "JUDUL", "PENULIS", "TAHUN", "STOK");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (fread(&get_buku, sizeof(Buku), 1, file) > 0) {
        printf("%-6s |", get_buku.id);
        printf(" %-30s |", get_buku.judul);
        printf(" %-32s |", get_buku.penulis);
        printf(" %5d |", get_buku.tahun);
        printf(" %2d", get_buku.stok);
        fgetc(file);
        puts("");
    }
    printf("\n====================================================================================================\n");
    printf("\n");

    fclose(file);
}
