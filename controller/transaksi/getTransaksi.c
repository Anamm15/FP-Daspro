
void get_transaksi() {
    Transaksi get_transaksi;
    FILE *file;
    char line[1000];
    char *token;

    file = fopen("../database/transaksi.bin", "rb");
    if (file == NULL)
    {
        printf("File not Found\n");
    }

    printf("================================================================================\n");
    printf("%-6s | %-12s | %-12s | %-8s | %-15s | %-12s | %-2s\n", "ID", "TANGGAL PINJAM", "TANGGAL KEMBALI", "DENDA", "STATUS", "CUSTOMERID", "BUKUID");
    printf("--------------------------------------------------------------------------------\n");

    while (fread(&get_transaksi, sizeof(Transaksi), 1, file) > 0)
    {
        printf("%-6s |", get_transaksi.id);
        printf(" %-14s |", get_transaksi.tanggal_pinjam);
        printf(" %-15s |", get_transaksi.tanggal_kembali);
        printf(" %-8d |", get_transaksi.denda);
        printf(" %-15s |", get_transaksi.status);
        printf(" %-12s |", get_transaksi.customerID);
        printf(" %-2s", get_transaksi.bukuID);
        fgetc(file);
        puts("");
    }
    printf("\n================================================================================\n");
    printf("\n");

    fclose(file);
}