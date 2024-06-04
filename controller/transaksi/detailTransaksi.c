
void detail_transaksi() {
    Transaksi detail_transaksi; Buku detail_buku; Member detail_member;
    FILE *bookFile, *memberFile, *transaksiFile;

    bookFile = fopen("../database/buku.bin", "rb");
    memberFile = fopen("../database/member.bin", "rb");
    transaksiFile = fopen("../database/transaksi.bin", "rb");

    char yourTransaksiId[10];
    int c;
    printf("===============================================================\n");
    printf("Masukkan id_transaksi Anda: ");
    scanf("%s", yourTransaksiId);
    while ((c = getchar()) != '\n' && c != EOF);

    while (fread(&detail_transaksi, sizeof(Transaksi), 1, transaksiFile) > 0) {
        if(strcmp(yourTransaksiId, detail_transaksi.id) == 0) {
            break;
        }
        fgetc(transaksiFile);
    }

    while (fread(&detail_buku, sizeof(Buku), 1, bookFile) > 0) {
        if(strcmp(detail_buku.id, detail_transaksi.bukuID) == 0) {
            break;
        }
        fgetc(bookFile);
    }

    while (fread(&detail_member, sizeof(Member), 1, memberFile) > 0) {
        if(strcmp(detail_member.id, detail_transaksi.customerID) == 0) {
            break;
        }
        fgetc(memberFile);
    }

    printf("DATA TRANSAKSI DARI %s DENGAN ID MEMBER %s\n", detail_member.nama, detail_member.id);
    printf("================================================\n");
    printf("ID BUKU: %s\n", detail_buku.id);
    printf("JUDUL BUKU: %s\n", detail_buku.judul);
    printf("PENULIS: %s\n", detail_buku.penulis);
    printf("TAHUN TERBIT BUKU: %d\n", detail_buku.tahun);
    printf("TANGGAL PINJAM BUKU: %s\n", detail_transaksi.tanggal_pinjam);
    printf("TANGGAL PENGEMBALIAN BUKU: %s\n", detail_transaksi.tanggal_kembali);
    printf("STATUS PEMINJAMAN: %s\n", detail_transaksi.status);
    printf("DENDA: %d\n", detail_transaksi.denda);
    printf("NO TELP MEMBER: %s\n", detail_member.no_telp);
    printf("ALAMAT MEMBER: %s\n", detail_member.alamat);
    printf("================================================");


    fclose(bookFile);
    fclose(memberFile);
    fclose(transaksiFile);
}