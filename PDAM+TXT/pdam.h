#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#define JATUH_TEMPO 25
#define BPM_RT 10 //Biaya Pemliharaan Meter Rumah Tangga
#define BPM_U 20 //Biaya Pemeliharaan Meter Usaha
#define ADM 50 //Biaya Administrasi
#define BIAYA_10 50 //Biaya 10 meter kubik pertama adalah Rp 50,- 
#define BIAYA_N 10 //Biaya 10+n meter kubik adalah Rp 10,- 
#define DENDA_100 20 //Denda pemakaian lebih dari 100 meter kubik adalah 20,-
#define DENDA_10_100 10 //Denda pemakaian lebih dari 10 meter kubik dan tidak lebih dari 100 meter kubik adalah Rp 10,-
int kelompok, rt, jalan, listrik, harga1, harga2, harga3, baca, bulan_sekarang, bulan_sebelumnya, bulan, totalm, tagihan, cetak, sisa;
char nama[100], alamat[100], nama_niaga[100], alamat_niaga[100], golongan[] = "X0-0";
int validasi_Int(int *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}
void reValidasi_Int(int *var, char *nama){
    while(1){
        printf("%s", nama);
        fflush(stdin);
        if(validasi_Int(var))
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void range_Validasi_Int(int *var, int range1, int range2, char *nama){
    while(1){
        reValidasi_Int(var, nama);
        fflush(stdin);
        if(*var >= range1  &&*var <= range2)
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void range_Validasi_Baca(int *var, int range1, int range2, char *nama){
    while(1){
        reValidasi_Int(var, nama);
        fflush(stdin);
        if(*var == range1  ||*var == range2)
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void range_Validasi_Baca2(int *var, int range1, int range2, char *nama){
    while(1){
        reValidasi_Int(var, nama);
        fflush(stdin);
        if(*var == range1  ||*var == range2)
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void range_Validasi_Bulan(int *var, int range1, char *nama){
    while(1){
        reValidasi_Int(var, nama);
        fflush(stdin);
        if(*var >= range1)
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void bukti_rumah_tangga_0(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
    fprintf(pF, "\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_tangga_d(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_tangga_d100(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_tangga_n(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_niaga_0(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
    fprintf(pF, "\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_niaga_d(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_niaga_d100(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_rumah_niaga_n(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_niaga_0(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
    fprintf(pF, "\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
	fprintf(pF, "\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_niaga_d(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
    fprintf(pF, "\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
	fprintf(pF, "\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_niaga_d100(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
    fprintf(pF, "\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
	fprintf(pF, "\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
    fprintf(pF, "\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void bukti_niaga_n(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    FILE *pF = fopen("bukti.txt","w");
    if(pF == NULL){
        printf("\n\t\t\t\t Maaf, tidak dapat mencetak bukti pembayaran.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(pF, "\t\t\t\t===============================================\n");
	fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t Nama Pemilik         : %s\n",nama);
	fprintf(pF, "\t\t\t\t Alamat               : %s\n",alamat);
    fprintf(pF, "\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
	fprintf(pF, "\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
	fprintf(pF, "\t\t\t\t Golongan Anda        : %s\n",golongan);
    fprintf(pF, "\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
    fprintf(pF, "\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
	fprintf(pF, "\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
	fprintf(pF, "\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
	fprintf(pF, "\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
    fprintf(pF, "\t\t\t\t                                               \n");
	fprintf(pF, "\t\t\t\t===============================================\n");
    fclose(pF);

    printf("\t\t\t\t Bukti pembayaran berhasil dicetak.\n");
}
void struk_rumah_tangga(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    sisa = JATUH_TEMPO - tm.tm_mday;
    range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan pemakaian bulan sekarang (M^3): ");
    range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan pemakaian bulan sebelumnya (M^3): ");
    system("cls");
    if(bulan_sekarang < bulan_sebelumnya){
        printf("\t\t\t\t Input Salah!\n");
        printf("\t\t\t\t Masukkan kembali!\n");
        return struk_rumah_tangga();
    }else if(bulan_sebelumnya == 0){
        if(bulan_sekarang <= 10){
            totalm = 10*harga1;
            tagihan = BPM_RT + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_tangga_0();
            }
        }else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
            totalm = bulan_sekarang*harga2;
            tagihan = BPM_RT + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_tangga_0();
            }
        }else{
            totalm = bulan_sekarang*harga3;
            tagihan = BPM_RT + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_tangga_0();
            }
        }
    }else{
        if(sisa < 0){
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_RT + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_d();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_RT + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_d();
                }
            }else if(bulan > 20 && bulan < 100){
                totalm = bulan*harga3;
                tagihan = BPM_RT + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_d();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_RT + ADM + totalm + DENDA_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_d100();
                }
            }
        }else{
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_RT + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_n();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_RT + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_n();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_RT + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_tangga_n();
                }
            }
        }
    }
}
void struk_rumah_niaga(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    sisa = JATUH_TEMPO - tm.tm_mday;
    range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan pemakaian bulan sekarang (M^3): ");
    range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan pemakaian bulan sebelumnya (M^3): ");
    system("cls");
    if(bulan_sekarang < bulan_sebelumnya){
        printf("\t\t\t\t Input Salah!\n");
        printf("\t\t\t\t Masukkan kembali!\n");
        return struk_rumah_niaga();
    }else if(bulan_sebelumnya == 0){
        if(bulan_sekarang <= 10){
            totalm = 10*harga1;
            tagihan = BPM_RT + BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_niaga_0();
            }
        }else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
            totalm = bulan_sekarang*harga2;
            tagihan = BPM_RT + BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_niaga_0();
            }
        }else{
            totalm = bulan_sekarang*harga3;
            tagihan = BPM_RT + BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_rumah_niaga_0();
            }
        }
    }else{
        if(sisa < 0){
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_RT + BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_d();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_RT + BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_d();
                }
            }else if(bulan > 20 && bulan < 100){
                totalm = bulan*harga3;
                tagihan = BPM_RT + BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_d();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_RT + BPM_U + ADM + totalm + DENDA_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_d100();
                }
            }
        }else{
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_RT + BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_n();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_RT + BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_n();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_RT + BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_RT + BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_rumah_niaga_n();
                }
            }
        }
    }
}
void struk_niaga(){
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    sisa = JATUH_TEMPO - tm.tm_mday;
    range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan pemakaian bulan sekarang (M^3): ");
    range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan pemakaian bulan sebelumnya (M^3): ");
    system("cls");
    if(bulan_sekarang < bulan_sebelumnya){
        printf("\t\t\t\t Input Salah!\n");
        printf("\t\t\t\t Masukkan kembali!\n");
        return struk_niaga();
    }else if(bulan_sebelumnya == 0){
        if(bulan_sekarang <= 10){
            totalm = 10*harga1;
            tagihan = BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
            printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_niaga_0();
            }
        }else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
            totalm = bulan_sekarang*harga2;
            tagihan = BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
            printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_niaga_0();
            }
        }else{
            totalm = bulan_sekarang*harga3;
            tagihan = BPM_RT + BPM_U + ADM + totalm + BIAYA_10;
            printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
            printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
            printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",BIAYA_10);
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
            printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
            printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
            range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
            if(cetak == 9){
                bukti_niaga_0();
            }
        }
    }else{
        if(sisa < 0){
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_d();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_d();
                }
            }else if(bulan > 20 && bulan < 100){
                totalm = bulan*harga3;
                tagihan = BPM_U + ADM + totalm + DENDA_10_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_10_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_d();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_U + ADM + totalm + DENDA_100;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Denda                : Rp %d,-\n",DENDA_100);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_d100();
                }
            }
        }else{
            bulan = bulan_sekarang - bulan_sebelumnya;
            if(bulan <= 10){
                totalm = 10*harga1;
                tagihan = BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_n();
                }
            }else if(bulan >= 11 && bulan <= 20){
                totalm = bulan*harga2;
                tagihan = BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_n();
                }
            }else{
                totalm = bulan*harga3;
                tagihan = BPM_U + ADM + totalm;
                printf("\t\t\t\t===============================================\n");
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t Nama Pemilik         : %s\n",nama);
                printf("\t\t\t\t Alamat               : %s\n",alamat);
                printf("\t\t\t\t Nama Niaga           : %s\n",nama_niaga);
			    printf("\t\t\t\t Alamat Niaga         : %s\n",alamat_niaga);
                printf("\t\t\t\t Golongan Anda        : %s\n",golongan);
                printf("\t\t\t\t Tanggal              : %d-%d-%d\n",tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Tanggal Jatuh Tempo  : %d-%d-%d\n",JATUH_TEMPO, tm.tm_mon, tm.tm_year);
                printf("\t\t\t\t Jatuh Tempo Dalam    : %d hari\n",sisa);
                printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",ADM);
                printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",BPM_U);
                printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
                printf("\t\t\t\t                                               \n");
                printf("\t\t\t\t===============================================\n");
                printf("\n\t\t\t\t Apakah Anda ingin mencetak bukti pembayaran?\n");
                printf("\t\t\t\t (0 jika tidak, 9 jika iya)\n");
                range_Validasi_Baca2(&cetak, 0, 9, "\t\t\t\t >>");
                if(cetak == 9){
                    bukti_niaga_n();
                }
            }
        }
    }
}
void identity(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |      This Program Created By     |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |==================================|\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |   I Kadek Indra Agusta Pratama   |\n");
    printf("\t\t\t\t |            2205551056            |\n");
    printf("\t\t\t\t |   Ni Komang Vaniya Apriandani    |\n");
    printf("\t\t\t\t |            2205551019            |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    system("pause");
    system("cls");
}
void pilihan1(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |        Kelompok Pelanggan        |\n");
    printf("\t\t\t\t |   1. Rumah Tangga                |\n");
    printf("\t\t\t\t |   2. Rumah Tangga Berisi Niaga   |\n");
    printf("\t\t\t\t |   3. Niaga                       |\n");
    printf("\t\t\t\t |   0. Keluar                      |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&kelompok, 0, 3, "\t\t\t\t Masukkan pilihan kelompok pelanggan: ");
    system("cls");
}
void rumah_tangga(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |           Rumah Tangga           |\n");
    printf("\t\t\t\t |   1. Rumah Tangga Bersubsidi     |\n");
    printf("\t\t\t\t |   2. Rumah Tangga Non-Subsidi    |\n");
    printf("\t\t\t\t |   0. Keluar                      |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&rt, 0, 2, "\t\t\t\t Masukkan pilihan rumah tangga: ");
    system("cls");
}
void jalan_subsidi(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |       Pilihan Lebar Jalan        |\n");
    printf("\t\t\t\t |       1. 0 - 3,99 meter          |\n");
    printf("\t\t\t\t |       2. 4 - 6,99 meter          |\n");
    printf("\t\t\t\t |       3. 7 - 10 meter            |\n");
    printf("\t\t\t\t |       4. > 10 meter              |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&jalan, 0, 4, "\t\t\t\t Masukkan pilihan lebar jalan: ");
    system("cls");
}
void jalan_niaga(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |       Pilihan Lebar Jalan        |\n");
    printf("\t\t\t\t |       1. 0 - 6,99 meter          |\n");
    printf("\t\t\t\t |       2. 7 - 10 meter            |\n");
    printf("\t\t\t\t |       3. > 10 meter              |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&jalan, 0, 3, "\t\t\t\t Masukkan pilihan lebar jalan: ");
    system("cls");
}
void listrik_subsidi(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |          Pilihan Listrik         |\n");
    printf("\t\t\t\t |       1. 450 VA                  |\n");
    printf("\t\t\t\t |       2. 900 VA                  |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan pilihan listrik: ");
    system("cls");
}
void listrik_nonsubsidi(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |          Pilihan Listrik         |\n");
    printf("\t\t\t\t |       1. 1300 VA                 |\n");
    printf("\t\t\t\t |       2. > 1300 VA               |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan pilihan listrik: ");
    system("cls");
}
void listrik_campur(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |          Pilihan Listrik         |\n");
    printf("\t\t\t\t |       1. 450 VA                  |\n");
    printf("\t\t\t\t |       2. 900 VA                  |\n");
    printf("\t\t\t\t |       3. 1300 VA                 |\n");
    printf("\t\t\t\t |       4. > 1300 VA               |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Int(&listrik, 0, 4, "\t\t\t\t Masukkan pilihan listrik: ");
    system("cls");
}
void usaha(){
    printf("\t\t\t\t Masukkan nama niaga Anda: ");
    fgets(nama_niaga, sizeof(nama_niaga), stdin);
    fflush(stdin);
    printf("\t\t\t\t Masukkan alamat niaga Anda: ");
    fgets(alamat_niaga, sizeof(alamat_niaga), stdin);
    fflush(stdin);
    system("cls");
}
void terakhir(){
    printf("\t\t\t\t ====================================\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t |            Terima Kasih          |\n");
    printf("\t\t\t\t |       9. Ke Menu Utama           |\n");
    printf("\t\t\t\t |       0. Keluar                  |\n");
    printf("\t\t\t\t |                                  |\n");
    printf("\t\t\t\t ====================================\n");
    range_Validasi_Baca(&baca, 0, 9, "\n\n\t\t\t\t Masukkan pilihan: ");
    system("cls");
}
void utama(){
    do{
        printf("\t\t\t\t Masukkan nama Anda: ");
        fflush(stdin);
        fgets(nama, sizeof(nama), stdin);
        printf("\t\t\t\t Masukkan alamat Anda: ");
        fflush(stdin);
        fgets(alamat, sizeof(alamat), stdin);
        system("cls");
        pilihan1();
        switch(kelompok){
            case 1:
                rumah_tangga();
                switch(rt){
                    case 1:
                        jalan_subsidi();
                        switch(jalan){
                            case 1:
                                listrik_subsidi();
                                switch(listrik){
                                    case 1:
                                        golongan[0] = 'D';
                                        golongan[1] = '1';
                                        golongan[2] = '-';
                                        golongan[3] = '1';
                                        harga1 = 1780;
                                        harga2 = 2060;
                                        harga3 = 5880;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        golongan[0] = 'D';
                                        golongan[1] = '1';
                                        golongan[2] = '-';
                                        golongan[3] = '2';
                                        harga1 = 2060;
                                        harga2 = 2340;
                                        harga3 = 5940;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 2:
                                listrik_subsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D2-1";
                                        golongan[0] = 'D';
                                        golongan[1] = '2';
                                        golongan[2] = '-';
                                        golongan[3] = '1';
                                        harga1 = 2340;
                                        harga2 = 2620;
                                        harga3 = 6000;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D2-2";
                                        golongan[0] = 'D';
                                        golongan[1] = '2';
                                        golongan[2] = '-';
                                        golongan[3] = '2';
                                        harga1 = 2620;
                                        harga2 = 2900;
                                        harga3 = 6060;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 3:
                                listrik_subsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D3-1";
                                        golongan[0] = 'D';
                                        golongan[1] = '3';
                                        golongan[2] = '-';
                                        golongan[3] = '1';
                                        harga1 = 2900;
                                        harga2 = 3180;
                                        harga3 = 6120;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D3-2";
                                        golongan[0] = 'D';
                                        golongan[1] = '3';
                                        golongan[2] = '-';
                                        golongan[3] = '2';
                                        harga1 = 3180;
                                        harga2 = 3460;
                                        harga3 = 6180;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 4:
                                listrik_subsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D4-1";
                                        golongan[0] = 'D';
                                        golongan[1] = '4';
                                        golongan[2] = '-';
                                        golongan[3] = '1';
                                        harga1 = 3460;
                                        harga2 = 3740;
                                        harga3 = 6240;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D4-2";
                                        golongan[0] = 'D';
                                        golongan[1] = '4';
                                        golongan[2] = '-';
                                        golongan[3] = '2';
                                        harga1 = 3740;
                                        harga2 = 4020;
                                        harga3 = 6240;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            default:
                                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                        }
                        break;
                    case 2:
                        jalan_subsidi();
                        switch(jalan){
                            case 1:
                                listrik_nonsubsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D1-3";
                                        golongan[0] = 'D';
                                        golongan[1] = '1';
                                        golongan[2] = '-';
                                        golongan[3] = '3';
                                        harga1 = 6340;
                                        harga2 = 9200;
                                        harga3 = 9600;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D1-4";
                                        golongan[0] = 'D';
                                        golongan[1] = '1';
                                        golongan[2] = '-';
                                        golongan[3] = '4';
                                        harga1 = 6420;
                                        harga2 = 9350;
                                        harga3 = 9650;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 2:
                                listrik_nonsubsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D2-3";
                                        golongan[0] = 'D';
                                        golongan[1] = '2';
                                        golongan[2] = '-';
                                        golongan[3] = '3';
                                        harga1 = 6490;
                                        harga2 = 9500;
                                        harga3 = 9800;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D2-4";
                                        golongan[0] = 'D';
                                        golongan[1] = '2';
                                        golongan[2] = '-';
                                        golongan[3] = '4';
                                        harga1 = 6570;
                                        harga2 = 9650;
                                        harga3 = 9950;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 3:
                                listrik_nonsubsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D3-3";
                                        golongan[0] = 'D';
                                        golongan[1] = '3';
                                        golongan[2] = '-';
                                        golongan[3] = '3';
                                        harga1 = 6640;
                                        harga2 = 9800;
                                        harga3 = 10100;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D3-4";
                                        golongan[0] = 'D';
                                        golongan[1] = '3';
                                        golongan[2] = '-';
                                        golongan[3] = '4';
                                        harga1 = 6720;
                                        harga2 = 9950;
                                        harga3 = 10250;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            case 4:
                                listrik_nonsubsidi();
                                switch(listrik){
                                    case 1:
                                        //char golongan[4] = "D4-3";
                                        golongan[0] = 'D';
                                        golongan[1] = '4';
                                        golongan[2] = '-';
                                        golongan[3] = '3';
                                        harga1 = 6790;
                                        harga2 = 10100;
                                        harga3 = 10400;
                                        struk_rumah_tangga();
                                        break;
                                    case 2:
                                        //char golongan[4] = "D4-4";
                                        golongan[0] = 'D';
                                        golongan[1] = '4';
                                        golongan[2] = '-';
                                        golongan[3] = '4';
                                        harga1 = 6870;
                                        harga2 = 10250;
                                        harga3 = 10550;
                                        struk_rumah_tangga();
                                        break;
                                }
                                break;
                            default:
                                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                        }
                        break;
                    default:
                        printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                }
                break;
            case 2:
                listrik_campur();
                switch(listrik){
                    case 1:
                        //char golongan[4] = "D5-1";
                        golongan[0] = 'D';
                        golongan[1] = '5';
                        golongan[2] = '-';
                        golongan[3] = '1';
                        harga1 = 6940;
                        harga2 = 10400;
                        harga3 = 10700;
                        struk_rumah_niaga();
                        break;
                    case 2:
                        //char golongan[4] = "D5-2";
                        golongan[0] = 'D';
                        golongan[1] = '5';
                        golongan[2] = '-';
                        golongan[3] = '2';
                        harga1 = 7020;
                        harga2 = 10550;
                        harga3 = 10850;
                        struk_rumah_niaga();
                        break;
                    case 3:
                        //char golongan[4] = "D5-3";
                        golongan[0] = 'D';
                        golongan[1] = '5';
                        golongan[2] = '-';
                        golongan[3] = '3';
                        harga1 = 7090;
                        harga2 = 10700;
                        harga3 = 11000;
                        struk_rumah_niaga();
                        break;
                    case 4:
                        //char golongan[4] = "D5-4";
                        golongan[0] = 'D';
                        golongan[1] = '5';
                        golongan[2] = '-';
                        golongan[3] = '4';
                        harga1 = 7170;
                        harga2 = 10850;
                        harga3 = 11150;
                        struk_rumah_niaga();
                        break;
                    default:
                        printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                }
                break;
            case 3:
                usaha();
                jalan_niaga();
                switch(jalan){
                    case 1:
                        listrik_campur();
                        switch(listrik){
                            case 1:
                                //char golongan[4] = "E1-1";
                                golongan[0] = 'E';
                                golongan[1] = '1';
                                golongan[2] = '-';
                                golongan[3] = '1';
                                harga1 = 9200;
                                harga2 = 9850;
                                harga3 = 10950;
                                struk_niaga();
                                break;
                            case 2:
                                //char golongan[4] = "E1-2";
                                golongan[0] = 'E';
                                golongan[1] = '1';
                                golongan[2] = '-';
                                golongan[3] = '2';
                                harga1 = 9500;
                                harga2 = 10150;
                                harga3 = 11250;
                                struk_niaga();
                                break;
                            case 3:
                                //char golongan[4] = "E1-3";
                                golongan[0] = 'E';
                                golongan[1] = '1';
                                golongan[2] = '-';
                                golongan[3] = '3';
                                harga1 = 9800;
                                harga2 = 10450;
                                harga3 = 11550;
                                struk_niaga();
                                break;
                            case 4:
                                //char golongan[4] = "E1-4";
                                golongan[0] = 'E';
                                golongan[1] = '1';
                                golongan[2] = '-';
                                golongan[3] = '4';
                                harga1 = 10100;
                                harga2 = 10750;
                                harga3 = 11850;
                                struk_niaga();
                                break;
                            default:
                                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                        }
                        break;
                    case 2:
                        listrik_campur();
                        switch(listrik){
                            case 1:
                                //char golongan[4] = "E2-1";
                                golongan[0] = 'E';
                                golongan[1] = '2';
                                golongan[2] = '-';
                                golongan[3] = '1';
                                harga1 = 10400;
                                harga2 = 11050;
                                harga3 = 12150;
                                struk_niaga();
                                break;
                            case 2:
                                //char golongan[4] = "E2-2";
                                golongan[0] = 'E';
                                golongan[1] = '2';
                                golongan[2] = '-';
                                golongan[3] = '2';
                                harga1 = 10700;
                                harga2 = 11350;
                                harga3 = 12550;
                                struk_niaga();
                                break;
                            case 3:
                                //char golongan[4] = "E2-3";
                                golongan[0] = 'E';
                                golongan[1] = '2';
                                golongan[2] = '-';
                                golongan[3] = '3';
                                harga1 = 11000;
                                harga2 = 11650;
                                harga3 = 13150;
                                struk_niaga();
                                break;
                            case 4:
                                //char golongan[4] = "E2-4";
                                golongan[0] = 'E';
                                golongan[1] = '2';
                                golongan[2] = '-';
                                golongan[3] = '4';
                                harga1 = 11300;
                                harga2 = 11950;
                                harga3 = 13950;
                                struk_niaga();
                                break;
                            default:
                                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                        }
                        break;
                    case 3:
                        listrik_campur();
                        switch(listrik){
                            case 1:
                                //char golongan[4] = "E3-1";
                                golongan[0] = 'E';
                                golongan[1] = '3';
                                golongan[2] = '-';
                                golongan[3] = '1';
                                harga1 = 11600;
                                harga2 = 12250;
                                harga3 = 14750;
                                struk_niaga();
                                break;
                            case 2:
                                //char golongan[4] = "E3-2";
                                golongan[0] = 'E';
                                golongan[1] = '3';
                                golongan[2] = '-';
                                golongan[3] = '2';
                                harga1 = 11900;
                                harga2 = 12550;
                                harga3 = 15050;
                                struk_niaga();
                                break;
                            case 3:
                                //char golongan[4] = "E3-3";
                                golongan[0] = 'E';
                                golongan[1] = '3';
                                golongan[2] = '-';
                                golongan[3] = '3';
                                harga1 = 12200;
                                harga2 = 12850;
                                harga3 = 15850;
                                struk_niaga();
                                break;
                            case 4:
                                //char golongan[4] = "E3-4";
                                golongan[0] = 'E';
                                golongan[1] = '3';
                                golongan[2] = '-';
                                golongan[3] = '4';
                                harga1 = 12500;
                                harga2 = 13150;
                                harga3 = 16650;
                                struk_niaga();
                                break;
                            default:
                                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                        }
                        break;
                    default:
                        printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
                }
                break;
            default:
                printf("\t\t\t\t Terima kasih karena telah meluangkan waktu Anda.\n\n");
        }
        system("pause");
        system("cls");
        terakhir();
    }while(baca == 9);
    system("pause");
    system("cls");
}
