#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char tablo[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

char oyuncular[2][20] = {"1.","2."};

int oyuncusirasi = 0;

int oyunbitiskontrol(){

for(int i=0;i<3;i++){
    if(tablo[i][0] == 'X' && tablo[i][2] == 'X' && tablo[i][1] == 'O'){
        return 1;
    }
}// satir kontrol
for(int i=0;i<3;i++){
    if(tablo[0][i] == 'X' && tablo[2][i] == 'X' && tablo[1][i] == 'O'){
        return 1;
    }
}// sütun kontrol

    if (tablo[0][0] == 'X' && tablo[1][1] == 'O' && tablo[2][2] == 'X') {
        return 1;  // Soldan sa?a çapraz
    }

    if (tablo[0][2] == 'X' && tablo[1][1] == 'O' && tablo[2][0] == 'X') {
        return 1;  // Sa?dan sola çapraz
    }
    // Beraberlik kontrolü
    int beraberekontrol = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablo[i][j] == ' ') {
                beraberekontrol = 0;  // Boþ hücre bulundu, oyun devam ediyor
                break;
            }
        }
        if (!beraberekontrol) {
            break;
        }
    }
    if (beraberekontrol) {
        return 2;  // Bütün hücreler dolu, oyun berabere bitti
    }

    // Kazanan yok, oyun devam ediyor
    return 0;
}
void tabloyazdirma(){
    printf("\n\t0.Sutun\t\t1.Sutun\t\t2.Sutun\n");
    for (int i=0;i<3;i++){
        printf("%d.Satir:   ",i);

    for (int j=0;j<3;j++){
        printf("%c\t\t",tablo[i][j]);
    }
    printf("\n\n");
    }
}

int hamle(){

char harfsecim;
int satir;
int sutun;
bool harfkontrol=false;
bool secimkontrol=false;

while(harfkontrol==false){
    tabloyazdirma();
    printf("\n%s Oyuncunun sirasi, lutfen girmek istediginiz harfi (X veya O) seciniz: ",oyuncular[oyuncusirasi]);
    scanf("%s",&harfsecim);

    if(harfsecim == 'X' || harfsecim == 'O'){
        harfkontrol=true;
    }
    else if(harfsecim == 'x' || harfsecim == 'o'){
    	printf("\nKucuk harf kullandiniz, lutfen buyuk harf ile giris yapiniz.\n");
	}
    else {
        printf("\nGecersiz hamle yaptiniz.Lutfen tekrar deneyiniz.\n");
    }
}

while(secimkontrol==false){
    printf("\nLutfen satir numarasini girin : ");
    scanf("%d", &satir);
    printf("\nLutfen sutun numarasini girin : ");
    scanf("%d", &sutun);

    if(satir>=0 && satir<3 && sutun>=0 && sutun<3 && tablo[satir][sutun] == ' '){
        tablo[satir][sutun] = harfsecim;
        secimkontrol=true;

        oyuncusirasi = (oyuncusirasi + 1) % 2;

    }
    else {
        printf("\nGecersiz hamle yaptiniz.Lutfen tekrar deneyiniz\n");
    }
 }
}

int main(){
	
while(!oyunbitiskontrol()){
	
system("cls");
printf("\tXOX Oyununa Hos Geldiniz!\n");
printf("----------------------------------------------\n");
hamle();
}

system("cls");
printf("\tXOX Oyununa Hos Geldiniz!\n");
printf("----------------------------------------------\n");
tabloyazdirma();

if (oyunbitiskontrol() == 2) {
    printf("Oyun berabere bitti.\n");
}
else {
    printf("Oyun bitti! %s kazandi!\n", oyuncular[(oyuncusirasi + 1) % 2]);
}

return 0;
}

