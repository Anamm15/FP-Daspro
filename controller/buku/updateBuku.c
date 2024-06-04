typedef struct {
    char id[10];
    char judul[100];
    char penulis[100];
    int tahun;
    int stok;
} TempBuku;

void update_buku() {
    FILE *file, *tempFile;
    Buku update_buku; TempBuku tempBuku;
    char line[10000], add;
    char choiceUpdate[10];

    file = fopen("../database/buku.bin", "rb");
    tempFile = fopen("../database/tempBuku.bin", "wb");

    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    printf("Masukkan id buku yang akan diupdate: ");
    scanf("%s", choiceUpdate);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("=======================================================================\n");
    while (fread(&update_buku, sizeof(Buku), 1, file) > 0) {
        if (strcmp(update_buku.id, choiceUpdate) == 0) {
            strcpy(tempBuku.id, update_buku.id);
            printf("\nMasukkan judul buku: ");
            fgets(tempBuku.judul, sizeof(tempBuku.judul), stdin);
            tempBuku.judul[strcspn(tempBuku.judul, "\n")] = '\0'; 

            printf("\nMasukkan nama penulis: ");
            fgets(tempBuku.penulis, sizeof(tempBuku.penulis), stdin);
            tempBuku.penulis[strcspn(tempBuku.penulis, "\n")] = '\0'; 

            printf("\nMasukkan tahun terbit: ");
            scanf(" %d", &tempBuku.tahun);
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\nMasukkan stok buku: ");
            scanf(" %d", &tempBuku.stok);
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n===============================================================\n");
            printf("ID BUKU: %s\n", tempBuku.id);
            printf("JUDUL BUKU: %s\n",tempBuku.judul);
            printf("PENULIS BUKU: %s\n",tempBuku.penulis);
            printf("TAHUN TERBIT BUKU: %d\n", tempBuku.tahun);
            printf("STOK BUKU: %d\n", tempBuku.stok);
            printf("===============================================================\n");

            printf("\nApakah anda ingin mengupdate data (y/n): ");
            scanf(" %c", &add);
            while ((c = getchar()) != '\n' && c != EOF);

            if (add == 'y' | add == 'Y')
            {
                fwrite(&tempBuku, sizeof(Buku), 1, tempFile);
                fputc('\n', tempFile);
            } else {
                fwrite(&update_buku, sizeof(Buku), 1, tempFile);
                fputc('\n', tempFile);
            }
        } else {
            fwrite(&update_buku, sizeof(Buku), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }

    fclose(tempFile);
    fclose(file);
    remove("../database/buku.bin");
    rename("../database/tempBuku.bin", "../database/buku.bin");
}
