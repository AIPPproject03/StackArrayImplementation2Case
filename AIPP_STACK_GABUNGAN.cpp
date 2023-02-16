#include <iostream>
#include <conio.h>
#define MAX1 5
#define MAX2 6
using namespace std;

       //_______________________________________________//
      //   Program Stack Dalam Kehidupan Sehari-Hari   //
     //      1) Membeli buku ditoko dan menumpuknya   //
    //          didalam box.                         //
   //       2) Antrian Pelanggan Drive Thru.        //
  //_______________________________________________//
  
  
// ARRAY UNTUK MENYIMPAN DATA BUKU //
struct Toko {
	int top = 0; // (Data Array Dimulai Dari 0) //
	string buku[MAX1]; // (Batas Maksimal Dari Buku Yang Bisa Ditampung Oleh Box Adalah 5) //
}toko;

// PROCEDURE/FUNCTION UNTUK IMPLEMENTASI STACK //
bool isFull1(){
	if(toko.top >= MAX1){
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty1(){
	if(toko.top == 0){
		return true;
	}
	else{
		return false;
	}
}
//---------------(UNTUK MENUMPUK BUKU DIDALAM BOX)-----------------//
void push1(){
	if (!isFull1()){
		cout <<" What Book Do You Wanna Put : ";
		cin.ignore();
		getline(cin,toko.buku[toko.top]);
		toko.top++;
	}
	else{
		cout <<" Your Box Is Full"<< endl;
	}
}
//---------------(UNTUK MENGELUARKAN 1 BUKU DIDALAM BOX)-----------------//
void pop1(){
	if (!isEmpty1()){
		cout <<" You Have Take Out A Book Name : ("<< toko.buku[toko.top-1] <<")"<< endl;
		toko.top--;
	}
	else{
		cout <<" There Is No Book In Your Box"<< endl;
	}
}
//---------------(UNTUK MENAMPILKAN BUKU DIDALAM BOX)-----------------//
void display1(){
	if (!isEmpty1()){
		cout <<" Inside Your Box : "<< endl;
		cout << endl;
		cout <<"|________               ________|"<< endl;
		for (int i = toko.top-1; i >= 0 ; i--){                       // (Disini Saya Buat Agar Inputan Buku Ditumpuk Kebawah)      //
			cout <<"|Book-"<< i+1 <<" : "<< toko.buku[i] <<"|"<<endl; // (i >= 0 kemudian i-- agar data dari inputan array buku[i]) //
		}                                                             // (diurutkan dari inputan terakhir menurun ke inputan awal)  //
			cout <<"|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|"<< endl;        // (analoginya seperti menumpuk buku pertama, kemudian)       //
	}                                                                 // (disusul dengan tumpukan buku ke-2, ke-3 dan seterusnya)   //
		else{
			cout <<" Your Box Is Empty"<< endl;
		}
		if (isFull1()){
			cout <<" Your Box Is Full Of Books"<< endl;
		}
}
//---------------(UNTUK MENGELUARKAN SEMUA BUKU DIDALAM BOX)-----------------//
void allout(){
	toko.top = 0;        // (Karena Array Selalu Dimulai Dari 0, Maka Saat Kita Buat Nilai Arraynya 0, Jadi Data Didalam Array Kosong) // 
	cout <<" All Your Book Has Been Removed"<< endl;
}
//---------------(UNTUK MELIHAT BUKU PERTAMA YANG DITUMPUK DIDALAM BOX / MELIHAT TOP DARI INPUTAN 0)-----------------//
void firstbook(){
	if (!isEmpty1()){
	cout <<" The First Book That You Put Is : "<< endl;
	cout <<" ("<< toko.buku[0] <<")"<< endl;
    }
    else{
    	cout <<" Your Box Is Empty"<< endl;
	}
}
  
//=================================================================================================================================//

// ARRAY UNTUK MENYIMPAN DATA PELANGGAN //
struct Restaurant {
 	int depan = 0;
 	string pelanggan[MAX2];
 }resto;
 
// PROCEDURE/FUNCTION UNTUK IMPLEMENTASI STACK //
bool isFull2(){
	if(resto.depan >= MAX2){
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty2(){
	if(resto.depan == 0){
		return true;
	}
	else{
		return false;
	}
}
//---------------(UNTUK REGISTRASI ANTRIAN PELANGGAN)-----------------//
void push2(){
	if (!isFull2()){
		cout <<" Costumer Name : ";
		cin.ignore();
		getline(cin,resto.pelanggan[resto.depan]);
		resto.depan++;
	}
	else{
		cout <<" (The Queue Is Full)"<< endl;
	}
}
//---------------(UNTUK PELANGGAN YANG KELUAR DARI ANTRIAN)-----------------//
void pop2(){
	if (!isEmpty2()){
		cout <<" Your Costumer Name : ("<< resto.pelanggan[resto.depan-1] <<") Has Go Out From The Queue!"<< endl;
		resto.depan--;
	}
	else {
		cout <<" (There Is No Costumer)"<< endl;
	}
}
//---------------(UNTUK PELANGGAN YANG TELAH SELESAI MENDAPATKAN PESANAN)-----------------//
void popFirst(){
	if (!isEmpty2()){
		cout <<" ("<< resto.pelanggan[0] <<") Has Complete The Order!" << endl;
		for (int a = 0; a < resto.depan-1; a++){
			resto.pelanggan[a] = resto.pelanggan[a+1];
		}
		resto.depan--;
	}
	else{
		cout <<" (There Is No Costumer)"<< endl;
	}
}
//---------------(UNTUK MENAMPILKAN SUASANA ANTRIAN PELANGGAN DRIVE THRU)-----------------//
void display2(){
	if (!isEmpty2()){
		cout <<" ___________________ "<< endl;
		cout <<" |  The Entry Line | "<< endl;
		cout <<" |    -------->    | "<< endl;
		cout <<" |_________________| "<< endl;
		cout <<"         | |       "<< endl;
		cout <<"         |_|       "<< endl;
		cout << endl;
		for (int i = resto.depan-1; i >= 0; i--){                        
			cout <<"   Costumer Entry-"<< i+1 <<" : "<< resto.pelanggan[i] << endl; 
		}                                                             
			cout <<"|_______________________________________|"<< endl;
			cout <<"|[[[[[[[[[[[     CASHIER     ]]]]]]]]]]]|"<< endl;
			cout <<"|$ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $|"<< endl;
			cout <<"|=======================================|"<< endl;        
	}                                                                 
		else{
			cout <<" (There Is No Costumer)"<< endl;
		}
		if (isFull2()){
			cout <<" (The Queue Is Full Of Costumer)"<< endl;
		}
}

//=================================================================================================================================//

int main(){
	int menu;
	do{
		system("cls");
		cout <<"__________________________________"<< endl;
		cout <<"|<><><><><><>| MENU |<><><><><><>|"<< endl;
		cout <<"[][][][][][][]======[][][][][][][]"<< endl;
		cout <<"|                                |"<< endl;
		cout <<"| 1) Program : Buy A Book And Put|"<< endl;
		cout <<"|    It Into A Box.              |"<< endl;
		cout <<"| 2) Program : A Fast Food Drive |"<< endl;
		cout <<"|    Thru Restaurant Queue.      |"<< endl;
		cout <<"| 3) Exit                        |"<< endl;
		cout <<"|________________________________|"<< endl;
		cout <<"| Choose Your Program : ";
		cin >> menu;
		    switch (menu){
		    	case 1:
	int act1;
	do{
	system("cls");
	cout <<"|====================================|"<< endl;
	cout <<"|             SIGMA_MEDIA            |"<< endl;
	cout <<"|        *The Best Bookstore*        |"<< endl;
	cout <<"|====================================|"<< endl;
	cout <<"| 1) Pile Up The Book To The Box     |"<< endl;
	cout <<"| 2) Take Out A Book From The Box    |"<< endl;
	cout <<"| 3) Look Inside The Box             |"<< endl;
	cout <<"| 4) The First Book That You Put     |"<< endl;
	cout <<"| 5) Empty The Box                   |"<< endl;
	cout <<"| 6) Leave                           |"<< endl;
	cout <<"|<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>|"<< endl;
	cout <<"| What Do You Do : ";
	cin >> act1;
	    switch (act1)
		{
		    case 1:
		    system("cls");
		    push1();
			break;
			case 2:
			system("cls");
			pop1();
			break;	
			case 3:
			system("cls");
			display1();
			break;
			case 4:
			system("cls");
			firstbook();
			break;
			case 5:
			system("cls");
			allout();
			break;
			case 6:
			break;
			default:
			system("cls");
			cout <<" Invalid Command"<< endl;
		}getch();
	}while (act1 != 6);
		    	break;
		case 2:
		int act2;
	do{
	system("cls");
	display2();
	cout << endl;
	cout <<"|====================================|"<< endl;
	cout <<"|        THE VOLCANIC CHICKEN        |"<< endl;
	cout <<"|  FAST FOOD FOR DRIVE THRU SERVICE  |"<< endl;
	cout <<"|      *The Best Spice Is Here*      |"<< endl;
	cout <<"|====================================|"<< endl;
	cout <<"| 1) Register A Costumer             |"<< endl;
	cout <<"| 2) Costumer Cancel Entry           |"<< endl;
	cout <<"| 3) Complete The Order              |"<< endl;
	cout <<"| 4) Leave                           |"<< endl;
	cout <<"|<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>|"<< endl;
	cout <<"| What Do You Do : ";
	cin >> act2;
	    switch (act2)
		{
		    case 1:
		    system("cls");
		    push2();
			break;
			case 2:
			system("cls");
			pop2();
			break;	
			case 3:
			system("cls");
			popFirst();
			break;
			case 4:
			break;
			default:
			cout <<" Invalid Command"<< endl;
		}getch();
        }while (act2 != 4);
		break;
		case 3:
		break;
		 }getch();
	}while (menu != 3);
}
