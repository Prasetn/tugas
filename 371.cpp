#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
#include<conio.h>

using namespace std;
struct login {
	int norek, pin, pilih, pil;
};
int ambil, tf, nom, isi;
int i;
int saldo=1000000;
ofstream file;
time_t now = time(0);
char* x = ctime(&now);
void sal () {
	cout<<"Saldo anda adalah "<<saldo-ambil-nom+isi;
	file.open("saldo_awal.txt");
	file<<saldo;
	file.close();
	
	file.open("saldo_akhir.txt");
	file<<saldo-ambil-nom+isi;
	file.close();
}

void tarik(){
	cout<<"Masukkan Nominal Penarikan : ";
	cin>>ambil;
	cout<<"sisa saldo anda : "<<saldo-ambil-nom+isi;
	
	file.open("tarik.txt");
	file<<x;
	file<<"\nsaldo awal          : "<<saldo;
	file<<"\nnominal tarik tunai : "<<ambil;
	file<<"\nSaldo Akhir         : "<<saldo-ambil-nom+isi;
	file.close();
	
	file.open("saldo_akhir.txt");
	file<<saldo-ambil-nom+isi;
	file.close();
}

void transfer () {
	cout<<"Masukkan Nomer Rekening Tujuan : ";
	cin>>tf;
	cout<<"Masukkan Nominal : ";
	cin>>nom;
	cout<<"\nTransfer Berhasil";
	cout<<"\nSisa Saldo "<<saldo-ambil-nom+isi;
	
	file.open("trasnfer.txt");
	file<<x;
	file<<"\n\nNomer Rekening Tujuan : "<<tf;
	file<<"\nJumlah Transfer         : "<<nom;
	file<<"\nSaldo Akhir             : "<<saldo-ambil-nom+isi;
	file.close();
	
	file.open("saldo_akhir.txt");
	file<<saldo-ambil-nom+isi;
	file.close();
}

void nabung () {
	cout<<"Masukkan Jumlah Uang : ";
	cin>>isi;
	cout<<"\nIsi Saldo Sukses ";
	cout<<"\nSaldo Akhir "<<saldo-ambil-nom+isi;
	
	file.open("isi_saldo.txt");
	file<<x;
	file<<"\n\nNominal Stor     : "<<isi;
	file<<"\nSaldo Akhir       : "<<saldo-ambil-nom+isi;
	file.close();
	
	file.open("saldo_akhir.txt");
	file<<saldo-ambil-nom+isi;
	file.close();
	
}
int main (){
	login atm;
	do {
		cout<<"masukkan Nomer Rekening : ";
		cin>>atm.norek;
		cout<<"Masukkan Pin Anda : ";
		cin>>atm.pin;
			if (atm.norek == 1234 && atm.pin == 1111){
				file.open("Nomer_rekening.txt");
				file<<atm.norek;
				file.close();
				
				file.open("Pin.txt");
				file<<atm.pin;
				file.close();
				
				goto menu;
			}else {
				cout<<"Maaf Data Anda Salah\n";
				cout<<"Silahkan Masukkan Dengan Benar\n";
				system("pause");
				system("cls");
				i=i+1;
			}
	} while (i<3) ;
		cout<<"Anda Sudah Salah 3 Kali \n";
		cout<<"silahkan hubungi 123231";
		goto end;
		getch ();
		
	
	menu: 
	system("cls");
	cout<<"+++++++ATM+++++++\n";
	cout<<"1. Cek Saldo\n";
	cout<<"2. Tarik Tunia\n";
	cout<<"3. Transfer\n";
	cout<<"4. Isi Saldo\n";
	cout<<"5. Keluar";
	cout<<"Masukkan Pilihan : ";
	cin>>atm.pilih;
	
	switch (atm.pilih){
		case 1 :
		sal();
		cout<<"\n\nKembali Ke Menu : (1.ya 2.tidak) ";
		cout<<"\npilih : ";
		cin>>atm.pil;
		if (atm.pil==1)
			goto menu;
		else if (atm.pil == 2)
			goto end;
		else {
			cout<<"ERORR";
			system("pause");
			system("cls");
		}
		break;
		
		case 2 :
		tarik();
		cout<<"\n\nKembali Ke Menu : (1.ya 2.tidak) ";
		cout<<"\npilih : ";
		cin>>atm.pil;
		if (atm.pil==1)
			goto menu;
		else if (atm.pil == 2)
			goto end;
		else {
			cout<<"ERORR";
			system("pause");
			system("cls");
		}
		break;
		
		case 3 :
		transfer();
		cout<<"\n\nKembali Ke Menu : (1.ya 2.tidak) ";
		cout<<"\npilih : ";
		cin>>atm.pil;
		if (atm.pil==1)
			goto menu;
		else if (atm.pil == 2)
			goto end;
		else {
			cout<<"ERORR";
			system("pause");
			system("cls");
		}
		break;
		
		case 4 :
		nabung();
		cout<<"\n\nKembali Ke Menu : (1.ya 2.tidak) ";
		cout<<"\npilih : ";
		cin>>atm.pil;
		if (atm.pil==1)
			goto menu;
		else if (atm.pil == 2)
			goto end;
		else {
			cout<<"ERORR";
			system("pause");
			system("cls");
		}
		break;
		
		case 5 :
		goto end;
	}
	
	end :
	system("cls");
}
	
