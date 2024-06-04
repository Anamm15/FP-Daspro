
void search_transaksi()
{
    Transaksi search_transaksi;
    char searcher[100];
    char line[100000];
    printf("===============================================================\n");
    printf("Masukkan id customer/tanggal pinjam/tanggal kembali/status yang ingin dicari: ");
    gets(searcher);

    FILE *file;
    file = fopen("../database/transaksi.bin", "rb");
    printf("\n================================================================================\n");
    printf("%-6s | %-12s | %-12s | %-8s | %-15s | %-2s\n", "ID", "TANGGAL PINJAM", "TANGGAL KEMBALI", "DENDA", "STATUS", "CUSTOMERID");
    printf("--------------------------------------------------------------------------------\n");

    while (fread(&search_transaksi, sizeof(Transaksi), 1, file) > 0)
    {
        for (int i = 0; search_transaksi.status[i]; i++)
        {
            search_transaksi.status[i] = tolower(search_transaksi.status[i]);
        }
        for (int i = 0; searcher[i]; i++)
        {
            searcher[i] = tolower(searcher[i]);
        }
        if (strcmp(searcher, search_transaksi.customerID) == 0 || strcmp(searcher, search_transaksi.tanggal_pinjam) == 0 || strcmp(searcher, search_transaksi.tanggal_kembali) == 0 || strcmp(searcher, search_transaksi.status) == 0)
        {
            printf("%-6s |", search_transaksi.id);
            printf(" %-14s |", search_transaksi.tanggal_pinjam);
            printf(" %-15s |", search_transaksi.tanggal_kembali);
            printf(" %-8d |", search_transaksi.denda);
            printf(" %-15s |", search_transaksi.status);
            printf(" %-12s", search_transaksi.customerID);
            printf(" %-2s", search_transaksi.bukuID);
            printf("\n================================================================================\n");
            break;
        }
        fgetc(file);
    }
    fclose(file);
}