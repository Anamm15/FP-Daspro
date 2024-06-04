
void search_buku()
{
    Buku search_buku;
    size_t bytesRead;
    char search[100];
    char dummyJudul[100];

    printf("===============================================================\n");
    printf("Masukkan nama buku yang ingin dicari: ");
    gets(search);

    FILE *file;
    file = fopen("../database/buku.bin", "rb");
    printf("=======================================================================\n");
    printf("%-6s | %-20s | %-20s | %5s | %2s\n", "ID", "JUDUL", "PENULIS", "TAHUN", "STOK");
    printf("-----------------------------------------------------------------------\n");

    while (fread(&search_buku, sizeof(Buku), 1, file) > 0)
    {
        strcpy(dummyJudul, search_buku.judul);        
        for (int i = 0; search[i]; i++)
        {
            search[i] = tolower(search[i]);
        }
        for (int i = 0; dummyJudul[i]; i++)
        {
            dummyJudul[i] = tolower(dummyJudul[i]);
        }  
            if (strstr(dummyJudul, search) != NULL)
            {
                printf("%-6s |", search_buku.id);
                printf(" %-20s |", search_buku.judul);
                printf(" %-20s |", search_buku.penulis);
                printf(" %-5d |", search_buku.tahun);
                printf(" %2d\n", search_buku.stok);
                printf("=======================================================================\n");
                break;
            }
        fgetc(file);
    }
    fclose(file);
}