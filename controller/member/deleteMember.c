
void delete_member()
{
    Member delete_member;
    FILE *file, *tempFile;
    size_t bytesRead;
    char choiceDelete[10];

    file = fopen("../database/member.bin", "rb");
    tempFile = fopen("../database/tempMember.bin", "wb");

    printf("Masukkan id member yang akan dihapus: ");
    scanf("%s", choiceDelete);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("=======================================================================\n");
    while (fread(&delete_member, sizeof(Member), 1, file) > 0)
    {
        if (strcmp(choiceDelete, delete_member.id) != 0)
        {
            fwrite(&delete_member, sizeof(Member), 1, tempFile);
            fputc('\n', tempFile);
        }
        fgetc(file);
    }
    fclose(tempFile);
    fclose(file);
    remove("../database/member.bin");
    rename("../database/tempMember.bin", "../database/member.bin");
}