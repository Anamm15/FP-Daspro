#include "getBuku.c"
#include "addBuku.c"
#include "deleteBuku.c"
#include "updateBuku.c"
#include "searchBuku.c"

void main_buku() {
    Buku buku;
    FILE *file;
    size_t bytesRead;
    long int fileSize;
    char choice;
    int selectedOption = 1;
    int isContinue = 1;
    int id = 1;
    char outChoice[1]; 

    file = fopen("../database/buku.bin", "rb");

    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    while (fread(&buku, sizeof(Buku), 1, file))
    {
        id = atoi(buku.id);
        fgetc(file);
    } 
    fclose(file);

    while (isContinue)
    {
        system("cls || clear");

        printf("=======================================\n");
        if (selectedOption == 1) printf("\033[1;31m->\033[0m");
        printf("\t1. Tampilkan Data Buku\n");
        if (selectedOption == 2) printf("\033[1;31m->\033[0m");
        printf("\t2. Tambah Data Buku\n");
        if (selectedOption == 3) printf("\033[1;31m->\033[0m");
        printf("\t3. Update Data Buku\n");
        if (selectedOption == 4) printf("\033[1;31m->\033[0m");
        printf("\t4. Hapus Data Buku\n");
        if (selectedOption == 5) printf("\033[1;31m->\033[0m");
        printf("\t5. Cari Data Buku\n");
        printf("=======================================\n");
        printf("TEKAN TOMBOL BACKSPACE UNTUK KEMBALI KE PROGRAM SEBELUMNYA\n");
        choice = getch();
        switch(choice) {
            case 13:
                switch(selectedOption) {
                    case 1:
                        get_buku();
                        isContinue = confirm_out();
                        break;
                    case 2:
                        add_buku(id);
                        isContinue = confirm_out();
                        break;
                    case 3:
                        update_buku();
                        isContinue = confirm_out();
                        break;
                    case 4:
                        delete_buku();
                        isContinue = confirm_out();
                        break;
                    case 5:
                        search_buku();
                        isContinue = confirm_out();
                        break;
                    }
                break;
            case 80:
                selectedOption = (selectedOption % 5) + 1;
                break;
            case 72:
                selectedOption = (selectedOption + 4) % 5;
                selectedOption == 0 ? selectedOption = 5 : selectedOption;
                break;
            case 8:
                isContinue = 0;
                break;
        }
    }
}