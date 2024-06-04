
typedef struct {
    char id[10];
    char email[100];
    char nama[100];
    char alamat[100];
    char no_telp[16];
} TempMember;

void update_member() {
    Member update_member; TempMember tempMember;
    FILE *file, *tempFile;
    char choiceUpdate[10], add;

    file = fopen("../database/member.bin", "rb");
    tempFile = fopen("../database/tempMember.bin", "wb");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening files");
        return;
    }

    printf("Masukkan id member yang akan diupdate: ");
    scanf("%s", choiceUpdate);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\n=======================================================================\n");

    while (fread(&update_member, sizeof(Member), 1, file) > 0) {
        if (strcmp(update_member.id, choiceUpdate) == 0) {
            strcpy(tempMember.id, update_member.id);
            printf("\nMasukkan email member: ");
            fgets(tempMember.email, sizeof(tempMember.email), stdin);
            tempMember.email[strcspn(tempMember.email, "\n")] = '\0';
            printf("\nMasukkan nama member: ");
            fgets(tempMember.nama, sizeof(tempMember.nama), stdin);
            tempMember.nama[strcspn(tempMember.nama, "\n")] = '\0';
            printf("\nMasukkan nomor telepon member: ");
            fgets(tempMember.no_telp, sizeof(tempMember.no_telp), stdin);
            tempMember.no_telp[strcspn(tempMember.no_telp, "\n")] = '\0';
            printf("\nMasukkan alamat member: ");
            fgets(tempMember.alamat, sizeof(tempMember.alamat), stdin);
            tempMember.alamat[strcspn(tempMember.alamat, "\n")] = '\0';

            printf("\n===============================================================\n");
            printf("\nID MEMBER: %s\n", tempMember.id);
            printf("EMAIL MEMBER: %s\n", tempMember.email);
            printf("NAMA MEMBER: %s\n", tempMember.nama);
            printf("NO TELEPON MEMBER: %s\n", tempMember.no_telp);
            printf("ALAMAT MEMBER: %s\n", tempMember.alamat);
            printf("\n===============================================================\n");

            printf("\nApakah anda yakin mengupdate data di atas(y/n): ");
            scanf(" %c", &add);
            while ((c = getchar()) != '\n' && c != EOF);

            if (add == 'y' | add == 'Y')
            {
                fwrite(&tempMember, sizeof(Member), 1, tempFile);
                fputc('\n', tempFile);
            } else {
                fwrite(&update_member, sizeof(Member), 1, tempFile);
                fputc('\n', tempFile);
            }
        } else {
            fwrite(&update_member, sizeof(Member), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }

    fclose(tempFile);
    fclose(file);

    remove("../database/member.bin");
    rename("../database/tempMember.bin", "../database/member.bin");
}
