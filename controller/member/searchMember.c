
void search_member()
{
    Member search_member;
    size_t bytesRead;
    char search[100];
    char *subNama;

    printf("===============================================================\n");
    printf("Masukkan nama member yang ingin dicari: ");
    gets(search);

    FILE *file;
    file = fopen("../database/member.bin", "rb");
    printf("========================================================================================\n");
    printf("%-6s | %-25s | %-20s | %-16s | %-20s\n", "ID", "EMAIL", "NAMA", "NO TELP", "ALAMAT");
    printf("----------------------------------------------------------------------------------------\n");

    while (fread(&search_member, sizeof(Member), 1, file) > 0)
    {
        char dummyNama[100];
        strcpy(dummyNama, search_member.nama);
        for (int i = 0; dummyNama[i]; i++)
        {
            dummyNama[i] = tolower(dummyNama[i]);
        }
        for (int i = 0; search[i]; i++)
        {
            search[i] = tolower(search[i]);
        }
        if (strstr(dummyNama, search) != NULL)
            {
                printf("%-6s |", search_member.id);
                printf(" %-25s |", search_member.email);
                printf(" %-20s |", search_member.nama);
                printf(" %-16s |", search_member.no_telp);
                printf(" %-20s\n", search_member.alamat);
                printf("========================================================================================\n");
                break;
            }
        fgetc(file);
    }
    fclose(file);
}