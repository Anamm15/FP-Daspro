
void add_member( int row )
{
    Member add_member;
    sprintf(add_member.id, "%d", row + 1);
    int c;
    char add, line[100000];
    FILE *file, *readFile;

    readFile = fopen("../database/member.bin", "rb");
    if (readFile == NULL)
    {
        printf("File tidak ada\n");
    }
    
    if (fgets(line, sizeof(line), readFile) == NULL) {
        sprintf(add_member.id, "%d", 1);
    }
    
    printf("===============================================================\n");
    printf("Masukkan email member: ");
    fgets(add_member.email, sizeof(add_member.email), stdin);
    add_member.email[strcspn(add_member.email, "\n")] = '\0';

    printf("\nMasukkan nama member: ");
    fgets(add_member.nama, sizeof(add_member.nama), stdin);
    add_member.nama[strcspn(add_member.nama, "\n")] = '\0';

    printf("\nMasukkan nomor telepon member: ");
    fgets(add_member.no_telp, sizeof(add_member.no_telp), stdin);
    add_member.no_telp[strcspn(add_member.no_telp, "\n")] = '\0';
    
    printf("\nMasukkan alamat member: ");
    fgets(add_member.alamat, sizeof(add_member.alamat), stdin);
    add_member.alamat[strcspn(add_member.alamat, "\n")] = '\0';

    printf("\n===============================================================\n");
    printf("\nID MEMBER: %s\n", add_member.id);
    printf("EMAIL MEMBER: %s\n", add_member.email);
    printf("NAMA MEMBER: %s\n", add_member.nama);
    printf("NOMOR TELEPON MEMBER: %s\n", add_member.no_telp);
    printf("ALAMAT MEMBER: %s\n", add_member.alamat);
    printf("\n===============================================================\n");

    printf("\nApakah anda yakin menambahkan data di atas(y/n): ");
    add = getchar();
    while ((c = getchar()) != '\n' && c != EOF);

    if (add == 'y' | add == 'Y')
    {
        file = fopen("../database/member.bin", "ab");
        if (file == NULL)
        {
            printf("File tidak ada\n");
        }

        fwrite(&add_member, sizeof(Member), 1, file);
        fputc('\n', file);
        fclose(file);
    }
    fclose(readFile);
}