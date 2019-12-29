	#include <iostream>
	#include <iomanip>
	#include <string.h>
	#include <fstream>
	#include <conio.h>
	#include <ctime>
	using namespace std;
	
	char ihi, ya[100];
	struct toko {
		int kode;
		int harga;
		int jumlah;
	};
	void selesai();
	void awal();
	void reset();
	int hasil, pilih, p=0, pil, he, total[100], beli=0, jumlahbeli[100], hargabeli[100], pilih2, kembalian, jml, uang, total1=0, main();
	ifstream file1;
	ofstream file;
	string barangbeli[100], cetak, namapembeli;
	time_t now = time(0);
	char* dt = ctime(&now);
	toko besi;
		
	int pecahan[10] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
	int hargabr[15][2] = {	
		{1,45000},
		{2,52500},
		{3,62000},
		{4,70000},
		{5,25000},
		{6,35000},
		{7,58000},
		{8,84000},
		{9,150000},
		{10,45000},
		{11,53000},
		{12,44000},
		{13,50500},
		{14,42000},
		{15,7500},
	};
	
	string produk[15][3]={
		{"1 ","Asbes ukuran 150 x 105            ","Rp 45.000/pcs "},
		{"2 ","Asbes ukuran 180 x 105            ","Rp 52.500/pcs "},
		{"3 ","Asbes ukuran 210 x 105            ","Rp 62.000/pcs "},
		{"4 ","Asbes ukuran 270 x 105            ","Rp 70.000/pcs "},
		{"5 ","Besi Beton Diameter 6 mm 12 meter ","Rp 25.000/pcs "},
		{"6 ","Besi Beton Diameter 8 mm 12 meter ","Rp 35.000/pcs "},
		{"7 ","Besi Beton Diameter 10 mm 12 meter","Rp 58.000/pcs "},
		{"8 ","Besi Beton Diameter 12 mm 12 meter","Rp 84.000/pcs "},
		{"9 ","Besi Beton Diameter 16 mm 12 meter","Rp 150.000/pcs"},
		{"10","Semen Tiga Roda (50 kg)           ","Rp 45.000/pcs "},
		{"11","Semen Gresik (50 kg)              ","Rp 53.000/pcs "},
		{"12","Semen Holcim (40 kg)              ","Rp 44.000/pcs "},
		{"13","Semen Holcim (50 kg)              ","Rp 50.500/pcs "},
		{"14","Semen Padang (40 kg)              ","Rp 42.000/pcs "},
		{"15","Kayu Meranti (2x3)                ","Rp 7.500/pcs  "},
	};
		
	void selesai (){
		cout <<"\n+---------------------------------------------------------------------+";
	    cout <<"\n+---------------------------------------------------------------------+";
		cout <<"\n+         TERIMA KASIH TELAH MENGGUNAKAN APLIKASI QQKASIR             +";
		cout <<"\n+                       PRASETIYANTO NUGROHO                          +";
		cout <<"\n+---------------------------------------------------------------------+";
	    cout <<"\n+---------------------------------------------------------------------+\n";
	}
		
	void awal (){
		system ("cls");
		cout <<"\n+---------------------------------------------------------------------+";
	    cout <<"\n+---------------------------------------------------------------------+";
		cout <<"\n+              SELAMAT DATANG DI TOKO BANGUNAN MADUKISMO              +";
		cout <<"\n+              Jl. Madukismo No. 45 Yogyakarta Indonesia              +";
		cout <<"\n+---------------------------------------------------------------------+";
	    cout <<"\n+---------------------------------------------------------------------+\n"<<endl;
	    cout <<"Masukkan Nama Pembeli :";
		getline(cin,namapembeli);
	}
	
	void daftarproduk(){
		cout << "\t =============================================" << endl;
		cout << "\t |           DAFTAR BARANG DAN HARGA         |" << endl;
		cout << "\t =============================================\n" << endl;
		cout << "+" << setfill('-') << setw(64) << "+" << endl;
		cout <<"| NO\t|          	Barang	       	    |      Harga  	|"<<endl;	
		cout << "+" << setfill('-') << setw(64) << "+" << endl;
		for(int i=0;i<15;i++){
			cout<<"| "<<produk[i][0]<<".\t|"<<produk[i][1]<<" | "<<produk[i][2]<<"	|"<<endl;
		}
		cout << "+" << setfill('-') << setw(64) << "+" << endl;
	}
	
	void cetakfile(){
		file.open("kasir.txt",ios::app );
		file << " ________________________________________________________________________" << endl;
		file << "|                                                                       |" << endl;
		file << "|                         TOKO BANGUNAN MADUKESMO                       |" << endl;
		file << "|                  Madukismo No. 45 Yogyakarta Indonesi                 |" << endl;
		file << "|_______________________________________________________________________|" << endl;
		file << "|_______________________________________________________________________|" << endl;
		file << "|   Tanggal Pembelian   = "<<dt;
		file << "|   Nama Pembeli        = "<<namapembeli <<endl;
		file << "|_______________________________________________________________________|" << endl;
		file << "|                  Barang                 |   Jumlah   |      Harga     |" << endl;
		file << "|_________________________________________|____________|________________|" << endl;
		for(int a=1; a<=beli;a++)
			file <<barangbeli[a]<<"              "<<jumlahbeli[a]<<"           "<<hargabeli[a]<<endl;
		file << "_________________________________________________________________________" << endl;
		file << "_________________________________________________________________________" << endl;
		file << "Total       =                                               " <<total1<<endl;
		file << "jumlah uang =                                               " <<uang<<endl;
		file << "kembalian   =                                               " <<uang-total1<<endl;
		file << "_________________________________________________________________________" << endl;
		file << endl;
		file.close();
	}
	
	void reset(){
		hasil=0, pilih=0, p=0, pil=0, he=0, total[100],total1=0,beli=0,ihi=0;
		ifstream file1;
		ofstream file;
		char ya[100];
		main();
	}
	
	void tambah (){
		cout <<"Masukkan kode barang	: ";
		beli++;
		cin >>besi.kode;
		besi.kode = besi.kode - 1;
		barangbeli[beli] = produk[besi.kode][1];
		cout <<"Nama barang		: "<<produk[besi.kode][1];
		if(besi.kode>=0)
			besi.harga = hargabr[besi.kode][1];
		else
			cout<<"Kode barang yang anda masukkan salah.";
		cout <<"\nMasukkan jumlah barang	: "; cin  >>besi.jumlah;
		jumlahbeli[beli] = besi.jumlah;				
		if(besi.jumlah>0){
			hasil = besi.harga * besi.jumlah;
			hargabeli[beli] = hasil;
			cout<<"Harga total		: "<<hasil<<endl;;
			total[p] = hasil;
			p++;
		} 
		else 
			cout<<"MASUKKAN JUMLAH BARANG LEBIH DARI 0";
	}
	
	int main (){
		awal ();
	    menu :
	    system("cls");
	    cout << "\t\t=====================================================================" << endl;
		cout << "\t\t|                              MENU                                 |" << endl;
		cout << "\t\t====================================================================\n" << endl;
		cout<<"\t\tMenu : "<<endl;
		cout<<"\t\t1. Daftar Produk"<<endl;
		cout<<"\t\t2. Pembelian"<<endl;
		cout<<"\t\t3. Pembayaran"<<endl;
		cout<<"\t\t4. Cetak"<<endl;
		cout<<"\t\t5. Keluar"<<endl;
		cout<<"\t\tPilih : "; cin>>pilih;
		cout<<"\n";		
		switch(pilih){
				case 1:
					system("cls");
					daftarproduk();
					cout <<"Kembali Ke Menu : 1. Ya \n";
					cout <<"                  2. Tidak\n";
					cout <<"Pilih : "; cin  >>pil;
					if (pil == 1 )
						goto menu;
					else 
						goto end;
					break;	
				case 2:
	    			system("cls");
					cout << "======================================================================" << endl;
					cout << "|                                 PEMBELIAN                           |" << endl;
					cout << "======================================================================\n" << endl;
					daftarproduk();
					cout <<"Masukkan kode barang	: "; cin  >> besi.kode;
					beli++;
					besi.kode = besi.kode - 1;
					barangbeli[beli] = produk[besi.kode][1];
					cout <<"Nama barang		: "<<produk[besi.kode][1];
					if(besi.kode>=0)
						besi.harga = hargabr[besi.kode][1];
					else
						cout <<"Kode barang yang anda masukkan salah.";
					cout <<"\nMasukkan jumlah barang	: ";
					cin  >>besi.jumlah;
					jumlahbeli[beli] = besi.jumlah;
					if(besi.jumlah>0){
						hasil = besi.harga * besi.jumlah;
						hargabeli[beli]=hasil;
						cout<<"Harga total		: "<<hasil;
						cout<<"\n";
						total[0] = hasil;
						p=1;
					}
					else 
						cout<<"MASUKKAN JUMLAH BARANG LEBIH DARI 0";
					cout <<"\nTambah Barang Lagi : 1. Ya \n";
					cout <<"                     2. Tidak\n";
					cout <<"Pilih : ";
					cin  >>he;
					if (he == 1 ){
						tambah ();
						cout <<"\n1. Tambah Barang\n";
						cout <<"2. Kembali Ke Menu\n";
						cout <<"Pilih : ";cin  >>pil;
						cin.ignore();
						if (pil == 1 )
							tambah();
						else if (pil == 2)
							goto menu;
						else {
							cout<<"EROR";
							system("pause");
							system("cls");
							goto end;
						}}
					else if (he == 2)
						goto menu;
					else {
						cout<<"EROR";
						system("pause");
						system("cls");
						goto end;
					}
					cout <<"\nKembali Ke Menu : 1. Ya \n";
					cout <<"                  2. Tidak\n";
					cout <<"Pilih : "; cin  >>pil;
					if (pil == 1 ){
						goto menu;
					}
					else {
						goto end;	
					}
					break;				
				case 4:
					file1.open("kasir.txt");
					while(!file1.eof()){
						file1.get(ihi);
						cout<<ihi;
					}
					goto end;
					break;
				case 5:
					goto rampungan;
					break;
				case 3:
					system("cls");
					cout << "======================================================================" << endl;
					cout << "|                                PEMBAYARAN                          |" << endl;
					cout << "======================================================================" << endl;
					int temp = 0;
					for (int i=0;i<p;i++) 
						temp = temp + total[i];
					if (temp==0){
						cout<<"Masukkan Barang Terlebih Dahulu !\n";
						system("pause");
						system("cls");
						cout <<"\nKembali Ke Menu : 1. Ya \n";
						cout <<"                  2. Tidak\n";
						cout <<"Pilih : ";cin  >>pil;
						if (pil == 1 )
							goto menu;
						else
							goto end;
					}
					cout <<"\nHarga total			: "<<temp;
					cout <<"\n";
					cout <<"Masukkan jumlah uang pelanggan	: "; cin  >>uang;
					kembalian = uang-temp;
					if(temp>uang)					
						cout<<"Uang pelanggan tidak cukup"<<endl;
					else if(temp==uang) 
						cout<<"Uang pelanggan pas"<<endl;
					else {
						cout<<"================================";
						cout<<endl<<"Kembalian Rp"<<kembalian<<" dalam bentuk : "<<endl;
						for(int i=0; i<10; i++) {
							jml = kembalian/pecahan[i];
							if(jml > 0){
								cout<<jml<<" lembar uang Rp"<<pecahan[i]<<endl;
								kembalian = kembalian%pecahan[i];
						}}
						cout<<"================================"<<endl;
					}
					cout <<"Print Nota   : 1. Ya \n";
					cout <<"               2. Tidak\n";
					cout <<"Pilih : ";cin  >>pil;
					if (pil == 1 ){
						system("cls");
						cout << " ________________________________________________________________________" << endl;
						cout << "|                                                                       |" << endl;
						cout << "|                         TOKO BANGUNAN MADUKESMO                       |" << endl;
						cout << "|                  Madukismo No. 45 Yogyakarta Indonesi                 |" << endl;
						cout << "|_______________________________________________________________________|" << endl;
						cout << "|_______________________________________________________________________|" << endl;
						cout << "|   Tanggal Pembelian   = "<<dt;
						cout << "|   Nama Pembeli        = "<<namapembeli <<endl;
						cout << "|_______________________________________________________________________|" << endl;
						cout << "|                  Barang                 |   Jumlah   |      Harga     |" << endl;
						cout << "|_________________________________________|____________|________________|" << endl;
						for(int a=1; a<=beli;a++){
							total1 = total1+hargabeli[a];
							cout <<barangbeli[a]<<"              "<<jumlahbeli[a]<<"           "<<hargabeli[a]<<endl;
						}
						cout << "_________________________________________________________________________" << endl;
						cout << "Total       =                                               " <<total1<<endl;
						cout << "jumlah uang =                                               " <<uang<<endl;
						cout << "kembalian   =                                               " <<uang-total1<<endl;
						cout << "_________________________________________________________________________" << endl;
						cout << endl;
						cetakfile();
						goto end;
					}
					else if (pil==2){
						cetakfile();
						goto end;
					}
					break;	
			}
		end :
		system("pause");
		cout <<"\n1. Pelanggan Selanjutnya ";
	    cout <<"\n2. Keluar ";
	    cout <<"\nPilih . . . "; cin>>pilih2;
	    cin.ignore();
	    
	    if(pilih2==1)
	    	reset();
		else
			goto rampungan;
		rampungan:
		selesai();
		return 0;
	}
	
