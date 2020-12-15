//============================================================================
// Name        : ProductTrackingSystem.cpp
// Author      : Nevzat TANVER
// Version     : v0.1
// Copyright   : No rights are reserved. Available for commercial usage.
// Description : Product Tracking System. All inputs should be given in one blank between each other.
//============================================================================
#include <fstream>
#include <string>
#include <cstring>
#include "string.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;


int main(){
int product_id[10]={0};
int product_amount[10]={0};
float product_price_per_unit[10]={0};
int product_id_temp,product_amount_temp;
float product_price_per_unit_temp;
int secim,discount_amount,sold_amount;
int i,j=0;
int quit_req=0,w_En;
int totalAmountOfProduct,totalPrice=0;

while(1){
printf("Merhabalar, urun takip sistemine hos geldiniz.\n");
printf("Lutfen Yapmak istediginiz islemi seciniz...\n");
			cout << "Urun eklemek icin  1 e" << endl
			<< "Urun silmek icin 2 ye" << endl
			<< "Zam yapmak icin icin 3 e " << endl
			<< "Indirim yapmak icin icin 4 e"<<endl
			<< "Satis yapmak 5 e"<<endl
			<< "Mevcut stogu goruntulemek icin 9 a"<<endl
			<< "Programdan cikis yapmak icin -1 e"<< endl;
printf("Secim : ");
cin >> secim;

switch(secim)
  {
	case -1:
    	printf("Program Sonlandiriliyor...\n\n");
    	cout<<"Urun ID"<<"\t"<<"Adet"<<"\t"<<"Birim Fiyat"<<endl;;
    		for(i=0;i<10;i++){

    		if(product_id[i]!=0){
    		totalAmountOfProduct+=1;
    		totalPrice= totalPrice + product_amount[i]*product_price_per_unit[i];
    		}
    		printf("%d \t",product_id[i]);
    		printf("%d \t",product_amount[i]);
    		printf("%.2f \t",product_price_per_unit[i]);
    		cout<<endl;
    		}
    		cout<<endl;
    		cout<<endl;
    		cout<<"Toplam elde kalan urun cesidi adedi : "<<totalAmountOfProduct<<endl;
    		cout<<"Toplam mal varligi bedeli : "<<totalPrice<<endl;

    	quit_req=1;
      break;

	case 1:
		cout<< "Urune ait bilgileri giriniz..." << endl;
		scanf("%d %d %f",&product_id_temp,&product_amount_temp,&product_price_per_unit_temp);
    	for(i=0;i<10;i++){
    	if (product_id[i]==product_id_temp){//ayni id kontrolü
    	cout << "Girilen ID ye ait urun bulundu, urun bilgileri guncelleniyor..."<< endl;
    	cout<<endl;
    	product_amount[i]=product_amount[i] + product_amount_temp;
        product_price_per_unit[i]=product_price_per_unit_temp;
        w_En=1;
        break;
    	}
    	}

    	for(i=0;i<10;i++){
		if(w_En==1)
		{
			w_En=0;
			break;
		}
		if (product_id[i] == 0){
		if(i>0){
			for(j=i;j>0;j--){
			if(product_id_temp < product_id[j-1]){
					product_id[j]=product_id[j-1];
					product_amount[j]=product_amount[j-1];
					product_price_per_unit[j]=product_price_per_unit[j-1];
					i--;
					}
					}
		}

		product_id[i]=product_id_temp;
		product_amount[i]=product_amount_temp;
		product_price_per_unit[i]=product_price_per_unit_temp;
		cout << "Girilen ID ye ait urun basari ile eklendi..."<< endl;
		cout<<endl;
		break;
		}

		}

    	if(i==10){
    		cout<<"Hafiza dolu, urun ekleme islemi tamamlanamadi..."<<endl;
    		break;
    	}
    break;

	case 2:
	cout<< "Urune ait ID bilgilerini giriniz..." << endl;
	cin>>product_id_temp;
	for(i=0;i<10;i++){
	if (product_id[i]==product_id_temp){//urunu silme
	cout << "Girilen ID ye ait urun bulundu, urun basari ile silindi..."<< endl;
	product_id[i]=0;
	product_amount[i]=0;
	product_price_per_unit[i]=0;
	break;
	}
	}
	if(i==10){
	cout << "Girilen ID ye ait urun bulunamadi, silme islemi basarisiz..."<< endl;
	}
    break;

    case 3:
    cout<< "Urune ait ID bilgilerini ve zam oranini giriniz..." << endl;
    scanf("%d %d",&product_id_temp,&discount_amount);
	for(i=0;i<10;i++){
	if (product_id[i]==product_id_temp){
	cout << "Girilen ID ye ait urun bulundu, belirlenen oranda zam yapiliyor..."<< endl;
	product_price_per_unit[i]+=product_price_per_unit[i]*discount_amount/100;
	break;
	}
	}
	if(i==10){
	cout << "Girilen ID ye ait urun bulunamadi, zam yapma islemi basarisiz..."<< endl;
	}
    break;

    case 4:
    cout<< "Urune ait ID bilgilerini ve indirim oranini giriniz..." << endl;
    scanf("%d %d",&product_id_temp,&discount_amount);
	for(i=0;i<10;i++){
	if (product_id[i]==product_id_temp){
		cout << "Girilen ID ye ait urun bulundu, belirlenen oranda indirim yapiliyor..."<< endl;
	product_price_per_unit[i]=product_price_per_unit[i] - product_price_per_unit[i]*discount_amount/100;	break;
	}
	}
	if(i==10){
		cout << "Girilen ID ye ait urun bulunamadi, indirim yapma islemi basarisiz..."<< endl;
		}
    break;

    case 5:
    cout<< "Urune ait ID bilgilerini ve satilacak urun miktarini giriniz..." << endl;
    scanf("%d %d",&product_id_temp,&sold_amount);
	for(i=0;i<10;i++){

	if (product_id[i]==product_id_temp){


	if(product_amount[i] < sold_amount){
				cout << "Girilen ID ye ait urun bulundu ancak girilen satis miktari, mevcut adetten fazla..."<< endl
						<< "Islem iptal ediliyor..."<< endl;
				}
	else{
		cout << "Girilen ID ye ait urun bulundu, belirlenen miktarda satis yapiliyor..."<< endl;
		product_amount[i]=product_amount[i]-sold_amount;

		if(product_amount[i]==0){
			product_id[i]=0;
			product_price_per_unit[i]=0;
			cout << "Girilen ID ye ait urun stokta kalmadi, stoktan silindi..."<< endl;
		}

}

	break;
    	}
    	}

	if(i==10){
		cout << "Girilen ID ye ait urun bulunamadi, satis yapma islemi basarisiz..."<< endl;
		}

    break;

    case 9:
	cout<<"Urun ID"<<"\t"<<"Adet"<<"\t"<<"Birim Fiyat"<<endl;;
	for(i=0;i<10;i++){
	printf("%d \t",product_id[i]);
	printf("%d \t",product_amount[i]);
	printf("%.2f \t",product_price_per_unit[i]);
	cout<<endl;
	}
	cout<<endl;
    cout << endl;
    break;

    default:
    printf("Hatali giris yapildi, lutfen tekrar giris yapiniz...\n");
    cout << endl;
    cout << endl;

  }

if(quit_req==1){
return 0;
}

}

}
