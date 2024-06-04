
void delete_transaksi()
{
    Transaksi delete_transaksi;
    FILE *file, *tempFile;
    char line[1000];
    char choiceDelete[10];

    file = fopen("../database/transaksi.bin", "rb");
    tempFile = fopen("../database/tempTransaksi.bin", "wb");

    printf("Masukkan id transaksi yang akan dihapus: ");
    scanf(" %s", choiceDelete);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("=======================================================================\n");
    while (fread(&delete_transaksi, sizeof(Transaksi), 1, file) > 0)
    {
        if (strcmp(delete_transaksi.id, choiceDelete) != 0)
        {
            fwrite(&delete_transaksi, sizeof(Transaksi), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }
    fclose(file);
    fclose(tempFile);
    remove("../database/transaksi.bin");
    rename("../database/tempTransaksi.bin", "../database/transaksi.bin");
}