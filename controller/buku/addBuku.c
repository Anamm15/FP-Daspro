
void add_buku( int row )
{
    Buku add_buku;
    sprintf(add_buku.id, "%d", row + 1);
    int c;
    char add, line[100000];
    FILE *file, *readFile;

    readFile = fopen("../database/buku.bin", "rb");
    if (readFile == NULL)
    {
        printf("File tidak ada\n");
    }
    
    if (fgets(line, sizeof(line), readFile) == NULL) {
        sprintf(add_buku.id, "%d", 1);
    }

    printf("===============================================================\n");
    printf("\nMasukkan judul buku: ");
    fgets(add_buku.judul, sizeof(add_buku.judul), stdin);
    add_buku.judul[strcspn(add_buku.judul, "\n")] = '\0'; 

    printf("\nMasukkan nama penulis: ");
    fgets(add_buku.penulis, sizeof(add_buku.penulis), stdin);
    add_buku.penulis[strcspn(add_buku.penulis, "\n")] = '\0'; 

    printf("\nMasukkan tahun terbit: ");
    scanf(" %d", &add_buku.tahun);

    printf("\nMasukkan stok buku: ");
    scanf(" %d", &add_buku.stok);

    printf("\n===============================================================\n");
    printf("ID BUKU: %s\n",add_buku.id);
    printf("JUDUL BUKU: %s\n",add_buku.judul);
    printf("PENULIS BUKU: %s\n",add_buku.penulis);
    printf("TAHUN TERBIT BUKU: %d\n",add_buku.tahun);
    printf("STOK BUKU: %d\n",add_buku.stok);
    printf("===============================================================\n");


    printf("\nApakah anda ingin menambahkan data (y/n): ");
    scanf(" %c", &add);
    while ((c = getchar()) != '\n' && c != EOF);

    if (add == 'y' | add == 'Y')
    {
        file = fopen("../database/buku.bin", "ab");
        
        if (file == NULL)
        {
            printf("File tidak ada\n");
        }

        fwrite(&add_buku, sizeof(Buku), 1, file);
        fputc('\n', file);
        fclose(file);
    }
    fclose(readFile);
}