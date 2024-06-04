
void get_member() {
    Member get_member;
    FILE *file;
    size_t bytesRead;

    file = fopen("../database/member.bin", "rb");
    if (file == NULL)
    {
        printf("File not Found\n");
    }

    printf("===========================================================================================================\n");
    printf("%-6s | %-30s | %-32s | %-16s | %-20s\n", "ID", "EMAIL", "NAMA", "NO TELP", "ALAMAT");
    printf("-----------------------------------------------------------------------------------------------------------\n");

    while (fread(&get_member, sizeof(Member), 1, file) > 0)
    {
        printf("%-6s |", get_member.id);
        printf(" %-30s |", get_member.email);
        printf(" %-32s |", get_member.nama);
        printf(" %-16s |", get_member.no_telp);
        printf(" %-20s", get_member.alamat);
        fgetc(file);
        puts("");
    }
    printf("\n===========================================================================================================\n");
    printf("\n");

    fclose(file);
}