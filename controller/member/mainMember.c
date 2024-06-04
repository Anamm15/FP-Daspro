#include "getMember.c"
#include "deleteMember.c"
#include "addMember.c"
#include "updateMember.c"
#include "searchMember.c"

void main_member() {
    Member member;
    char choice;
    int selectedOption = 1;
    int isContinue = 1;
    int id = 1;
    FILE *file;
    file = fopen("../database/member.bin", "rb");
    if (file == NULL)
    {
        printf("File Tidak Ditemukan\n");
    }
    
    while (fread(&member, sizeof(Member), 1, file)) {
        id = atoi(member.id);
        fgetc(file);
    }
    fclose(file);
        
    while (isContinue)
    {
        system("cls || clear");

        printf("=======================================\n");
        if (selectedOption == 1) printf("\033[1;31m->\033[0m");
        printf("\t1. Tampilkan Data Member\n");
        if (selectedOption == 2) printf("\033[1;31m->\033[0m");
        printf("\t2. Tambah Data Member\n");
        if (selectedOption == 3) printf("\033[1;31m->\033[0m");
        printf("\t3. Update Data Member\n");
        if (selectedOption == 4) printf("\033[1;31m->\033[0m");
        printf("\t4. Hapus Data Member\n");
        if (selectedOption == 5) printf("\033[1;31m->\033[0m");
        printf("\t5. Cari Data Member\n");
        printf("=======================================\n");
        printf("TEKAN TOMBOL BACKSPACE UNTUK KEMBALI KE PROGRAM SEBELUMNYA\n");
        choice = getch();
        switch(choice) {
            case 13:
                switch(selectedOption) {
                    case 1:
                        get_member();
                        isContinue = confirm_out();
                        break;
                    case 2:
                        add_member(id);
                        isContinue = confirm_out();
                        break;
                    case 3:
                        update_member();
                        isContinue = confirm_out();
                        break;
                    case 4:
                        delete_member();
                        isContinue = confirm_out();
                        break;
                    case 5:
                        search_member();
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

