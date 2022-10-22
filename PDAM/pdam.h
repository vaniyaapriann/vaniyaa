#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define BPM_RT 10 //Biaya Pemliharaan Meter Rumah Tangga
#define BPM_U 20 //Biaya Pemeliharaan Meter Usaha
#define ADM 50 //Biaya Administrasi
#define BIAYA_10 50 //Biaya 10 meter kubik pertama adalah Rp 50,- 
#define BIAYA_N 10 //Biaya 10+n meter kubik adalah Rp 10,- 
#define DENDA_100 20 //Denda pemakaian lebih dari 100 meter kubik adalah 20,-
#define DENDA_10_100 10 //Denda pemakaian lebih dari 10 meter kubik dan tidak lebih dari 100 meter kubik adalah Rp 10,-
int kelompok, dua, lebar_jalan, listrik, bulan_sebelumnya, bulan_sekarang, bulan, totalm, tagihan, baca;
char name[50], alamat[100], alamat_niaga[255], niaga[255];
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
void range_Validasi_Int_Baca(int *var, int range1, int range2, char *nama){
    while(1){
        reValidasi_Int(var, nama);
        fflush(stdin);
        if(*var == range1 || *var == range2)
            break;
        printf("\n\t\t\t\t Maaf, Input yang Anda masukan salah.\n"); 
		printf("\t\t\t\t Pilih nomor yang tersedia: \n");
    }
}
void identity(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|       Program Pembayaran Air Oleh ....      |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t| I Kadek Indra Agusta Pratama   (2205551056) |\n");
	printf("\t\t\t\t| Ni Komang Vaniya Apriandani    (2205551019) |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
	system("pause");
	system("cls");
}
void explanation(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|         Penjelasan Tentang Kelompok         |\n");
	printf("\t\t\t\t|               Pengguna Layanan              |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t| Kelompok I merupakan golongan rumah tangga  |\n");
	printf("\t\t\t\t| bersubsidi.                                 |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t| Kelompok II merupakan golongan rumah tangga |\n");
	printf("\t\t\t\t| tanpa subsidi.                              |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t| Kelompok III merupakan golongan niaga.      |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
	system("pause");
	system("cls");
}
void input_kelompok(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|               Pilihan Kelompok              |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|               1. Kelompok I                 |\n");
	printf("\t\t\t\t|               2. Kelompok II                |\n");
	printf("\t\t\t\t|               3. Kelompok III               |\n");
	printf("\t\t\t\t|               0. Keluar                     |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void jalan(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|             Pilihan Lebar Jalan             |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|             1. 0 - 3,99 meter               |\n");
	printf("\t\t\t\t|             2. 4 - 6,99 meter               |\n");
	printf("\t\t\t\t|             3. 7 - 10 meter                 |\n");
	printf("\t\t\t\t|             4. >10 meter                    |\n");
	printf("\t\t\t\t|             0. Keluar                       |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void jalan_tiga(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|             Pilihan Lebar Jalan             |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|             1. 0 - 6,99 meter               |\n");
	printf("\t\t\t\t|             2. 7 - 10 meter                 |\n");
	printf("\t\t\t\t|             3. >10 meter                    |\n");
	printf("\t\t\t\t|             0. Keluar                       |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void decicions_dua(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          Pilih Jenis Rumah Tangga           |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          1. Rumah Tangga Biasa              |\n");
	printf("\t\t\t\t|          2. Rumah Tangga Berisi Niaga       |\n");
	printf("\t\t\t\t|          0. Keluar                          |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void listrik_satu(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          Pilih Daya Listrik                 |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          1. 450 VA                          |\n");
	printf("\t\t\t\t|          2. 900 VA                          |\n");
	printf("\t\t\t\t|          0. Keluar                          |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void listrik_dua(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          Pilih Daya Listrik                 |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          1. 1300 VA                         |\n");
	printf("\t\t\t\t|          2. >1300 VA                        |\n");
	printf("\t\t\t\t|          0. Keluar                          |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void listrik_tiga(){
	printf("\t\t\t\t===============================================\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          Pilih Daya Listrik                 |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t|          1. 450 VA                          |\n");
	printf("\t\t\t\t|          2. 900 VA                          |\n");
	printf("\t\t\t\t|          3. 1300 VA                         |\n");
	printf("\t\t\t\t|          4. >1300 VA                        |\n");
	printf("\t\t\t\t|          0. Keluar                          |\n");
	printf("\t\t\t\t|                                             |\n");
	printf("\t\t\t\t===============================================\n\v");
}
void rta1450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta1450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*1780;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*2060;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*5880;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*1780;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*2060;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*5080;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta1900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta1900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*2060;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*2340;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*5940;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*2060;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*2340;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*5940;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta2450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta2450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*2340;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*2620;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6000;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*2340;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*2620;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6000;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta2900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta2900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*2620;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*2900;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6060;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*2620;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*2900;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6060;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta3450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta3450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*2900;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*3180;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6120;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*2900;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*3180;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6120;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta3900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta3900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*3180;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*3460;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6180;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*3180;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*3460;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6180;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta4450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta4450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*3460;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*3740;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6240;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*3460;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*3740;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6240;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta4900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta4900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*3740;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*4020;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*6300;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*3740;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*4020;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*6300;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta11300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta11300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6340;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9200;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*9600;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6340;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9200;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*9600;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta11301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta11301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6420;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9350;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*9650;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6420;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9350;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*9650;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta21300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta21300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6490;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9500;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*9800;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6490;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9500;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*9800;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta21301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta21301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6570;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9650;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*9950;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6570;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9650;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*9950;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta31300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta31300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6640;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9800;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10100;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6640;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9800;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10100;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta31301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta31301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6720;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9950;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10250;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6720;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9950;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10250;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta41300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta41300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6790;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10100;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10400;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6790;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10100;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10400;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rta41301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rta41301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6870;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10250;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10550;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6870;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10250;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10550;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D4-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rtb450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rtb450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*6940;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10400;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10700;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*6940;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10400;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10700;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rtb900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rtb900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*7020;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10550;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10850;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*7020;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10550;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10850;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rtb1300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rtb1300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*7090;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10700;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*11000;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*7090;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10700;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*11000;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void rtb1301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return rtb1301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*7170;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10850;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*11150;
			tagihan = BPM_RT + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*7170;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10850;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*11150;
			tagihan = BPM_RT + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Golongan Anda        : D5-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_RT));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_kecil_450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_kecil_450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*9200;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*9850;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*10950;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*9200;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*9850;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*10950;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_kecil_900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_kecil_900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*9500;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10150;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*11250;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*9500;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10150;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*11250;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_kecil_1300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_kecil_1300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*9800;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10450;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*11550;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*9800;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10450;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*11550;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_kecil_1301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_kecil_1301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*10100;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*10750;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*11850;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*10100;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*10750;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*11850;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E1-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_sedang_450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_sedang_450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*10400;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*11050;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*12150;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*10400;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*11050;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*12150;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_sedang_900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_sedang_900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*10700;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*11350;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*12550;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*10700;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*11350;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*12550;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_sedang_1300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_sedang_1300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*11000;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*11650;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*13150;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*11000;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*11650;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*13150;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_sedang_1301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_sedang_1301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*11300;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*11950;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*13950;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*11300;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*11950;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*13950;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E2-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_besar_450(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_besar_450();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*11600;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*12250;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*14750;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*11600;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*12250;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*14750;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-1\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_besar_900(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_besar_900();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*11900;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*12550;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*15050;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*11900;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*12550;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*15050;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-2\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_besar_1300(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_besar_1300();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*12200;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*12850;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*15850;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*12200;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*12850;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*15850;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-3\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void niaga_besar_1301(){
	range_Validasi_Bulan(&bulan_sekarang, 0, "\t\t\t\t Masukkan penggunaan bulan sekarang (M^3): ");
	range_Validasi_Bulan(&bulan_sebelumnya, 0, "\t\t\t\t Masukkan penggunaan bulan sebelumnya (M^3): ");
	system("cls");
	if(bulan_sekarang < bulan_sebelumnya){
		printf("\t\t\t\t Input salah!\n");
		printf("\t\t\t\t Masukkan kembali!\n");
		return niaga_besar_1301();
	}else if(bulan_sebelumnya == 0){
		if (bulan_sekarang <= 10){
			totalm = 10*12500;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan_sekarang >= 11 && bulan_sekarang <= 20){
			totalm = bulan_sekarang*13150;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan_sekarang*16650;
			tagihan = BPM_U + ADM + totalm + BIAYA_10;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Biaya 10 m^3 pertama : Rp %d,-\n",(0+BIAYA_10));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}else{
		bulan = bulan_sekarang - bulan_sebelumnya;
		if (bulan <= 10){
			totalm = 10*12500;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else if(bulan >= 11 && bulan <= 20){
			totalm = bulan*13150;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}else{
			totalm = bulan*16650;
			tagihan = BPM_U + totalm + ADM;
			printf("\t\t\t\t===============================================\n");
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t Nama Pemilik         : %s\n",name);
			printf("\t\t\t\t Alamat               : %s\n",alamat);
			printf("\t\t\t\t Nama Niaga           : %s\n",niaga);
			printf("\t\t\t\t Alamat               : %s\n",alamat_niaga);
			printf("\t\t\t\t Golongan Anda        : E3-4\n");
			printf("\t\t\t\t Biaya Administrasi   : Rp %d,-\n",(0+ADM));
			printf("\t\t\t\t Biaya Pemeliharaan   : Rp %d,-\n",(0+BPM_U));
			printf("\t\t\t\t Total Tagihan        : Rp %d,00\n",tagihan);
			printf("\t\t\t\t                                               \n");
			printf("\t\t\t\t===============================================\n");
		}
	}
}
void menuutama(){ //PROGRAM UTAMA
	do{
		printf("\t\t\t\t Masukkan nama Anda: ");
		fflush(stdin);
		fgets(name, sizeof(name), stdin);
		printf("\t\t\t\t Masukkan alamat Anda: ");
		fflush(stdin);
		fgets(alamat, sizeof(alamat), stdin);
		system("cls");
		explanation();
		//masukkin kelompoknya
		input_kelompok();
		range_Validasi_Int(&kelompok, 0, 3, "\t\t\t\t Masukkan golongan kelompok Anda: ");
		system("cls");
		switch(kelompok){
			case 1: //kelompok 1
				//jalan
				jalan();
				range_Validasi_Int(&lebar_jalan, 0, 4, "\t\t\t\t Masukkan input: ");
				system("cls");
				switch(lebar_jalan){
					case 1:
						//pilihan listrik
						listrik_satu();
						range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								rta1450();
								break;
							case 2:
								rta1900();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
								//terima kasih
						}
						break;
					case 2:
						listrik_satu();
						range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								rta2450();
								break;
							case 2:
								rta2900();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
								//terima kasih
						}
						break;
					case 3:
						listrik_satu();
						range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								rta3450();
								break;
							case 2:
								rta3900();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
								//terima kasih
						}
						break;
					case 4:
						listrik_satu();
						range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								rta4450();
								break;
							case 2:
								rta4900();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
								//terima kasih
						}
						break;
					default:
						printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
				}
				break;
			case 2: //kelompok 2
				decicions_dua();
				range_Validasi_Int(&dua, 0, 2, "\t\t\t\t Masukkan input: ");
				system("cls");
				switch(dua){
					case 1:
						jalan();
						range_Validasi_Int(&lebar_jalan, 0, 4, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(lebar_jalan){
							case 1:
								listrik_dua();
								range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
								system("cls");
								switch(listrik){
									case 1:
										rta11300();
										break;
									case 2:
										rta11301();
										break;
									default:
										printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
										//terima kasih
								}
								break;
							case 2:
								listrik_dua();
								range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
								system("cls");
								switch(listrik){
									case 1:
										rta21300();
										break;
									case 2:
										rta21301();
										break;
									default:
										printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
										//terima kasih
								}
								break;
							case 3:
								listrik_dua();
								range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
								system("cls");
								switch(listrik){
									case 1:
										rta31300();
										break;
									case 2:
										rta31301();
										break;
									default:
										printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
										//terima kasih
								}
								break;
							case 4:
								listrik_dua();
								range_Validasi_Int(&listrik, 0, 2, "\t\t\t\t Masukkan input: ");
								system("cls");
								switch(listrik){
									case 1:
										rta41300();
										break;
									case 2:
										rta41301();
										break;
									default:
										printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
										//terima kasih
								}
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
						}
						break;
					case 2:
						listrik_tiga();
						range_Validasi_Int(&listrik, 0, 4, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								rtb450();
								break;
							case 2:
								rtb900();
								break;
							case 3:
								rtb1300();
								break;
							case 4:
								rtb1301();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
						}
						break;
					default:
						printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
				}
				break;
			case 3: //kelompok 3
				printf("\t\t\t\t Masukkan nama niaga Anda: ");
				fflush(stdin);
				fgets(niaga, sizeof(niaga), stdin);
				printf("\t\t\t\t Masukkan alamat niaga Anda: ");
				fflush(stdin);
				fgets(alamat_niaga, sizeof(alamat_niaga), stdin);
				system("cls");
				jalan_tiga();
				range_Validasi_Int(&lebar_jalan, 0, 3, "\t\t\t\t Masukkan input: ");
				system("cls");
				switch(lebar_jalan){
					case 1:
						listrik_tiga();
						range_Validasi_Int(&listrik, 0, 4, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								niaga_kecil_450();
								break;
							case 2:
								niaga_kecil_900();
								break;
							case 3:
								niaga_kecil_1300();
								break;
							case 4:
								niaga_kecil_1301();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
						}
						break;
					case 2:
						listrik_tiga();
						range_Validasi_Int(&listrik, 0, 4, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								niaga_sedang_450();
								break;
							case 2:
								niaga_sedang_900();
								break;
							case 3:
								niaga_sedang_1300();
								break;
							case 4:
								niaga_sedang_1301();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
						}
						break;
					case 3:
						listrik_tiga();
						range_Validasi_Int(&listrik, 0, 4, "\t\t\t\t Masukkan input: ");
						system("cls");
						switch(listrik){
							case 1:
								niaga_besar_450();
								break;
							case 2:
								niaga_besar_900();
								break;
							case 3:
								niaga_besar_1300();
								break;
							case 4:
								niaga_besar_1301();
								break;
							default:
								printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
						}
						break;
					default:
						printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");
				}
				break;
			default:
				printf("\t\t\t\t Terima kasih, mohon maaf bila ada kesalahan, dan sampai jumpa di lain waktu.\n");		
		}
		printf("\t\t\t\t Apakah Anda ingin melakukan pembayaran lagi?\n");
		printf("\t\t\t\t (Tekan 0 jika tidak, tekan 9 jika iya)\n");
		range_Validasi_Int_Baca(&baca, 0, 9, "\t\t\t\t Masukkan input: ");
		system("cls");
	}while(baca == 9);
}
