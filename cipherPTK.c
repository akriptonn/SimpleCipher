#include <stdio.h>
#include <math.h>
#include <stdlib.h>
char buffered_text;
int error_catch;
int menu_bantuan();
int menu_utama();
int menu_cipher();
int menu_dekriptor();
int sudah_selesai();
void clean_input();
char getPlainText_to_cipherText(int kunci, int tanda);
void AKHIRI();
char error_angka;

int main(void){
	system("color F0");
    printf("* * * * * * * * * * * * * * * Program Enkripsi dengan Algoritma Caesar Cipher * * * * * * * * * * * \n");
    printf("*                                                                                                 *\n");
    printf("*                               Oleh: Achmad Kripton Nugraha                                      * \n");
    printf("*                                     Johannes Calvin Tjahaja                                     * \n");
    printf("*                                                                                                 *\n");
	printf("* * * * * * * * * * * * * * * * * Proyek Akhir Pengantar Teknik Komputer  * * * * * * * * * * * * * \n");
    int menu_value;
    do{
    menu_value = menu_utama();
    if (menu_value == 1){
                                                menu_value = menu_cipher();
                                }else if (menu_value ==2){
                                                menu_value = menu_dekriptor();
                                }else if (menu_value == 3){
                                    menu_value = menu_bantuan();
                                }else if (menu_value == 4){
                                	menu_value = 0;
								}
                                }
                while (menu_value != 0);
                return 0;
}

int menu_utama(){
                int menu;
                do{
                				printf("\n\t------------------------------MAIN MENU--------------------------------------\n");
                                printf  ("\t|\t   [1] Enkripsi                                                     |\n");
                                printf  ("\t|\t   [2] Dekripsi                                                     |\n");
                                printf("\t|\t   [3] Menu Bantuan                                                 |\n");
                                printf("\t|\t   [4] Keluar dari Program                                          |\n");
                                printf("\t-----------------------------------------------------------------------------\n\n");
                                printf("Masukkan angka untuk memilih menu yang anda inginkan lalu tekan enter: ");
                                error_catch = scanf("%d%c", &menu,&error_angka);
                                system("cls");
                                if ((error_catch == 0) || (error_angka!='\n')){
                                                clean_input();
                                                menu = 0;
                                                printf("Error Message: Harap Masukkan Angka Saja\n");
                                }else if ((menu != 1) && (menu != 2) && (menu != 3)&&(menu !=4)) {
                                                printf("Error Message: Angka yang dimasukkan hanya bisa 1, 2, 3, 4\n");
                                }
                }while((menu != 1) && (menu !=2) && (menu !=3) && (menu !=4));
                return menu;
}

int menu_cipher(){
	int dapatkan;
	do{
		printf("-------------------------------------------Menu Enkriptor------------------------------------------------\n\n");
	    printf("Deskripsi: Menu Enkriptor ini untuk mengenkripsi kalimat yang anda masukkan dengan menggesernya sesuai \n\t   dengan keynya\n");
	    printf("=========================================================================================================\n");
	    int key;
	    do{
	        printf("Masukkan Key(key haruslah angka dan tidak boleh nol), lalu tekan enter: ");
	        error_catch = scanf("%d%c", &key,&error_angka);
	        key = round(key);
	        if ((error_catch == 0) || (error_angka!='\n')){
	            clean_input();
	            key = 0;
	            system("cls");
	            system("color C6");
	            printf("Error Message: KEY HARUSLAH ANGKA, Silahkan ulangi lagi\n");
	            system("color F0");
	            printf("-------------------------------------------Menu Enkriptor------------------------------------------------\n\n");
	    		printf("Deskripsi: Menu Enkriptor ini untuk mengenkripsi kalimat yang anda masukkan dengan menggesernya sesuai \n\t   dengan keynya\n");
	    		printf("=========================================================================================================\n");
	        }else if (key == 0){
		        system("cls");
		        system("color C6");
		        printf("Error Message: KEY TIDAK BOLEH 0, Ulangi lagi\n");
		        system("color F0");
		        printf("-------------------------------------------Menu Enkriptor------------------------------------------------\n\n");
	    		printf("Deskripsi: Menu Enkriptor ini untuk mengenkripsi kalimat yang anda masukkan dengan menggesernya sesuai \n\t   dengan keynya\n");
	    		printf("=========================================================================================================\n");
	        }
	    }while(key == 0);
	    if (key<0){
	        key *= -1;
	    }
	    printf("Masukkan Kalimat yang ingin dienkripsi,lalu tekan enter: ");
	    int urutan = 0;
		do{
			do{
				buffered_text= getPlainText_to_cipherText(key,1);
			}while ((urutan ==0)&&(buffered_text == '\n'));
			if (buffered_text!='\n'){
				if ((urutan==0)&&(buffered_text !='\n')){
					printf("Kalimat setelah dienkripsi : ");
					urutan ++;
				}
		        printf("%c",buffered_text);
			}
		}while(buffered_text!='\n');
		printf("\n");
		AKHIRI();
	    dapatkan = sudah_selesai(0);
	}while (dapatkan == 1);
    return dapatkan;
}
int menu_dekriptor(){
    int dapatkan;
    do{
		printf("-------------------------------------------Menu Dekriptor------------------------------------------\n\n");
	    printf("Deskripsi: Menu Dekriptor ini untuk mendapatkan kalimat yang telah dienkripsi dengan menggunakan key\n");
	    int key;
	    printf("====================================================================================================\n");
	    do{
	        printf("Masukkan Key(key haruslah angka dan tidak boleh nol),lalu tekan enter: ");
	        error_catch = scanf("%d%c", &key,&error_angka);
	        key = round(key);
	        if ((error_catch == 0) || (error_angka!='\n')){
	            clean_input();
	            key = 0;
	            system("cls");
	            system("color C6");
				printf("Error Message: KEY HARUSLAH ANGKA, Silahkan ulangi lagi\n");
				system("color F0");
	            printf("-------------------------------------------Menu Dekriptor------------------------------------------\n\n");
	    		printf("Deskripsi: Menu Dekriptor ini untuk mendapatkan kalimat yang telah dienkripsi dengan menggunakan key\n");
	    		printf("====================================================================================================\n");
	        }else if (key == 0){
	            system("cls");
	            system("color C6");
	            printf("Error Message: KEY TIDAK BOLEH 0, Ulangi lagi\n");
	            system("color F0");
	            printf("-------------------------------------------Menu Dekriptor------------------------------------------\n\n");
	    		printf("Deskripsi: Menu Dekriptor ini untuk mendapatkan kalimat yang telah dienkripsi dengan menggunakan key\n");
	    		printf("====================================================================================================\n");
				}
	    }while(key == 0);
	    if (key<0){
	        key *= -1;
	    }
	    printf("Masukkan Kalimat yang ingin didekripsi,lalu tekan enter : ");
	    int urutan = 0;
		do{
			do{
				buffered_text= getPlainText_to_cipherText(key,0);
			}while ((urutan ==0)&&(buffered_text == '\n'));

			if (buffered_text!='\n'){
	            if ((urutan==0)&&(buffered_text !='\n')){
					printf("Kalimat setelah didekripsi : ");
					urutan ++;
				}
				printf("%c",buffered_text);
			}
		}while((buffered_text!='\n')&&(urutan != 0));
		printf("\n");
		AKHIRI();
	    dapatkan = sudah_selesai(1);
	}while (dapatkan == 1);
    return dapatkan;
}

int menu_bantuan() {
	printf("Bantuan Untuk Menu Enkriptor\n\n");
	printf ("1.Masukkan Angka 1 untuk masuk ke menu Enkriptor\n");
	printf ("2.Silahkan masukkan angka yang mengindikasi berapa panjang karakter akan diubah\n");
	printf ("3.Masukkan kalimat yang ingin anda ubah\n\n\n");
	printf ("----------------------------\n\n");
	printf ("Bantuan Untuk Menu Dekriptor\n\n");
	printf ("1.Tekan Angka 2 untuk masuk ke menu Dekriptor\n");
	printf ("2.Silahkan masukkan angka yang mengindikasi berapa panjang karakter akan diubah\n");
	printf ("3.Masukkan kalimat yang ingin anda ubah\n\n\n");
	printf ("----------------------------\n\n");
	printf ("Notes: Jika anda memasukkan input yang tidak sesuai dengan seharusnya, akan muncul error message yang menjelaskan kesalahan\n");
	printf("Press Any key to Continue...");
	getch();
	system("cls");
	return 1;
}

int sudah_selesai(int ngecek){
    int akhir;
	do {
    	printf("------------------------MENU KELUAR PROGRAM--------------------------------------\n");
    	printf("|                                                                               |\n");
		switch(ngecek){
    	case 0:
    	printf("|                [1] Kembali ke Menu Enkripsi                                   |\n");
    		break;
    	case 1:
    	printf("|                [1] Kembali Ke Menu Dekripsi                                   |\n");
    		break;
		}
		printf("|                [2] Kembali Ke Main Menu                                       |\n");
		printf("|                [3] Keluar dari Program                                        |\n");
		printf("---------------------------------------------------------------------------------\n");
		printf("Silahkan menekan angka yang diinginkan,lalu tekan enter: ");
		error_catch = scanf("%d%c", &akhir,&error_angka);
		system("cls");
		if ((error_catch == 0) || (error_angka != '\n')) {
			printf("Error Message: Masukan Hanya boleh angka saja\n");
			clean_input();
			akhir = -1;
		}else if ((akhir != 1)&&(akhir !=2)&&(akhir !=3)){
			printf("Error Message: Masukan hanya boleh angka 1, 2, 3\n");
			akhir = -1;
		}
		if (akhir == 3){
			akhir = 0;
		}

	}while (akhir == -1);
	return akhir;

    /*
	do {
        printf("Masih ingin memakai program?\nTekan y jika ingin kembali ke menu awal dan tekan n jika ingin keluar: ");
        akhir = getche();
        system("cls");
        if ( (akhir != 'n') && (akhir != 'y') ){
            printf("Hanya bisa y dan n saja\n");
        }
    }while( (akhir != 'n') && (akhir != 'y') );
    if (akhir == 'y'){
        return 1;
    }else {
        return 0;
    }
    */
}

void clean_input(){
                while (getchar()!= '\n');
}

char getPlainText_to_cipherText(int kunci, int tanda){
    char sementara;
	scanf("%c",&sementara);
    int temp = sementara;
    if (tanda == 0){
        if (( sementara != '\n' ) && (sementara != ' ')) {
            if ( ( sementara >= '0' ) && ( sementara <= '9' ) ){
                while ( kunci > 9 ){
                	kunci -= 10;
                }
                temp -= kunci;
                if (temp < '0'){
                    temp += 10;
                }
            }else if (( temp >= 'A' ) && ( temp <= 'Z' )){
                while ( kunci > 25 ){
                    kunci = kunci - 26;
                }
                temp -= kunci;
                if (temp < 'A') {
                temp += 26;
                }
            }else if (( temp >= 'a' ) && ( temp <= 'z' )){
                while ( kunci > ( 25 ) ){
                    kunci = kunci - 26;
                }
                temp -= kunci;
                if (temp < 'a') {
                    temp += 26;
                }
            }
        }
    }else{
        if (( temp != '\n' ) && (temp != ' ')) {
            if ( ( temp >= '0' ) && ( temp <= '9' ) ){
                while ( kunci > 9){
                    kunci -= 10;
                }
                temp += kunci;
                if (temp > '9'){
                    temp -= 10;
                }
            }else if (( temp >= 'A' ) && ( temp <= 'Z' )){
                while ( kunci > 25 ){
                    kunci = kunci - 26;
                }
                temp += kunci;
                if (temp > 'Z') {
                    temp -= 26;
                }
            }else if (( temp >= 'a' ) && ( temp <= 'z' )){
                while ( kunci > 25 ){
                    kunci = kunci - 26;
            	}
                temp += kunci;
                if (temp > 'z') {
                temp -= 26;
				}
            }
        }
    }
    sementara = temp;
    return sementara;
}

void AKHIRI(){
	printf("Press Any Key to continue...");
	getch();

	system("cls");
}
