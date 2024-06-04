
void delete_buku() {
    Buku delete_buku;
    FILE *file, *tempFile;
    char choiceDelete[10];

    file = fopen("../database/buku.bin", "rb");
    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    tempFile = fopen("../database/tempBuku.bin", "wb");
    if (tempFile == NULL) {
        fclose(file);
        printf("Gagal membuat file sementara\n");
        return;
    }

    printf("Masukkan id buku yang akan dihapus: ");
    scanf("%s", choiceDelete);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("=======================================================================\n");
    while ( fread(&delete_buku, sizeof(Buku), 1, file) > 0) {
        if (strcmp(choiceDelete, delete_buku.id) != 0) {
            fwrite(&delete_buku, sizeof(Buku), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }

    fclose(tempFile);
    fclose(file);
    remove("../database/buku.bin");
    rename("../database/tempBuku.bin", "../database/buku.bin");
}