
bool confirm_out() {
    char outChoice;
    int c;
    while (true)
        {
            printf("\nApakah anda ingin keluar dari sesi data Buku? (y/n) : ");
            scanf(" %c", &outChoice);
            if (outChoice == 'y' || outChoice == 'Y')
            {
                while ((c = getchar()) != '\n' && c != EOF);
                return false;
            }
            else if (outChoice == 'n' || outChoice == 'N')
            {
                while ((c = getchar()) != '\n' && c != EOF);
                return true;
            }
            else
            {
                printf("Input salah!!! silahkan masukkan y/n\n");
                return true;
            }
        } 
}