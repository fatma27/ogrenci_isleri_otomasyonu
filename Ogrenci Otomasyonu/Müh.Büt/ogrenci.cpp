#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h> //Derleme sürelerini kýsaltan önceden derlenmiþ baþlýklar için kullanmak için
#include<stdlib.h>

#define pf printf		//printf kýsaltmak için
#define sf scanf		//scanf kýsaltmak için

using namespace std;

struct ogrenci
{
    char name[5000];
    char ID[5000];
    char grade[5000];
    char sec[5000];
    struct ogrenci *next;
};


struct calisan // çakýþma olmamasý için çalýþan ve öðrenci için ayrý ayrý tanýmlýyoruz
{
    char name[5000];
    char ID[5000];
    char salary[5000];

    struct calisan *next; // Çalýþaný referans göster
};


struct result // Bu sonuç panosu sadece öðrenciler için kullanýlabilir.
{
    char name[5000]; 
    char ID[5000];
    char grade[5000];

    struct result *next; 

};

typedef struct result rb;
typedef struct ogrenci si;
typedef struct calisan ei;

si *head = (si*)malloc(sizeof(si));
si *start = head;

ei *head2 = (ei*)malloc(sizeof(ei));
ei *start2 = head2;

rb *head3 = (rb*)malloc(sizeof(rb));
rb *start3 = head3;



/**** ************************ Crud Ýþlemleri ******************** ****/
/**** ************************ Ekleme güncelleme silme******************** ****/

///Sonuç Ekraný
void createResultBoard()
{
    int how;
    pf("\nKac ogrenci sonucu var?:  ");
    sf("%d",&how);

    pf("\n\nSadece no ve sonuclar : \n\n");
    for(int i=0; i<how; i++)
    {
        pf("\nID: ");
        sf(" %[^\n]",&head3->ID);
        pf("Sinif: ");
        sf(" %[^\n]",&head3->grade);

        head3->next = (rb*)malloc(sizeof(rb));
        if(head3->next == NULL)
        {
            pf("Uzgunum, sonuc alamadik!\n");
            return;
        }

        head3 = head3 ->next;
    }
    head3->next = NULL;
    pf("\n");

}

///sonucu gösterilecek veriler
void printResultBoard()
{
    rb *st = start3;
    int sl=0;
    printf("Sl.\t\t\No\t\t\t\t        Sinif\n\n");

    if(st!= NULL)
    {
        while(st->next)
        {
            pf("%d\t\t",++sl);

            int sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->grade);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->grade[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

//        puts(st->No);
//        puts(st->Sýnýf);
            st = st->next;
            pf("\n");
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n\n");
        }
    }

}




///Çalýþan bilgilerini Al
void takeInCalisan() //Çalýþan için girdiler al
{
    pf("\n\nKisi sayisi giriniz: ");
    int how;
    sf("%d",&how);
    getchar();

    for(int i=0; i<how; i++)
    {
        pf("\nCalisanin adini giriniz %d: ",i+1);
        gets(head2->name);
        pf("Numarasini giriniz %d: ",i+1);
        gets(head2->ID);
        pf("\nCalisanin maasini giriniz %d: ",i+1);
        gets(head2->name);
       

        head2->next = (ei*)malloc(sizeof(ei));
        if(head2->next == NULL)
        {
            pf("Uzgunum, Sonuc alamadik.\n");
            return;
        }
        head2 = head2->next;
    }
    head2->next = NULL;
    pf("\n");

}



//Öðrencinin bölümünü için bilgi 
void takeInOgrenciler()
{

    pf("\nGirmek istediginiz ogrenci sayisi: ");
    int how;
    sf("%d",&how);
    getchar();

    for(int i=0; i<how; i++)
    {
        pf("\nOgrenci adi giriniz %d: ",i+1);
        gets(head->name);
        pf("Ogrenci numarasi giriniz %d: ",i+1);
        gets(head->ID);
        pf("Ogrencinin bolumu %d: ",i+1);
        gets(head->sec);

        head->next = (si*)malloc(sizeof(si));
        if(head->next == NULL)
        {
            pf("Tekrar deneyin.\n");
            break;
            return;
        }
        head = head->next;
    }
    head->next = NULL;
    pf("\n");

}



// Çalýþan bilgi çýktýsý
void printCalisanInfo()
{
    int sl=1;
    ei *st = start2;

    printf("Sl.\t\tAd\t\t\t\t        ID\t\t        \t\tMaas\t\t\n\n");

    while(st->next)
    {
        pf("%d\t\t",sl++);

        int sz = strlen(st->name);
        for(int i=0; i<sz; i++)
        {
            printf("%c",st->name[i]);
        }
//        printf("\t\t\t      ");

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->ID);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->ID[i]);
        }

        for(int i=0; i<abs(40-sz); i++)//Ýki kolon arasýndaki bilgiler
        {
            pf(" ");
        }

        sz = strlen(st->salary);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->salary[i]);
        }
        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        st = st->next;
        pf("\n");
        for(int i=0; i<112; i++)
        {
            pf("-");///iki bölüm girildiðinde araya - iþareti koymak için
        }
        pf("\n\n");
    }

}



///Öðrenci ekran çýktýsý
void printOgrenciInfo()
{
    int sl=1;
    si *st = start;

    printf("Sl.\t\tAdi\t\t\t\t        No\t\t        \t\tBolumu\t\t\n\n");

    while(st->next) //Veri çýktýlarýný göstermek için
    {
        pf("%d\t\t",sl++);

        int sz = strlen(st->name);
        for(int i=0; i<sz; i++)
        {
            printf("%c",st->name[i]);
        }
        
        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->ID);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->ID[i]);
        }

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->sec);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->sec[i]);
        }

        for(int i=0; i<abs(40-sz); i++) //Ýki bilgi arasýndaki ortak alanlar için
        {
            pf(" ");
        }

//        puts(st->no);
//        puts(st->sýnýf);
        st = st->next;
        pf("\n"); // araya - iþateti koymak için
        for(int i=0; i<111; i++)
        {
            pf("-");
        }
        pf("\n\n");
    }


}



/// Silme iþlemi için
void deleteOgrenciInfo(si *prev,si *cur)
{

    if(prev == NULL && cur == start) // ilk düðüm
    {
        si *temp = start;
        start = start->next;
        free(temp); //ilk düðüm için biligilendirme
    }
    else if(cur == NULL && prev != NULL) //Son düðüm
    {
        prev->next = NULL;
        free(cur);
    }
    else if(prev != NULL && cur != NULL) //Orta düðümden birini kullanýr.

    {
        prev->next = cur->next;
        free(cur);
    }
}




//Çalýþan biligisi silmek için
void deleteCalisanInfo(ei *prev,ei *cur)
{

    if(prev == NULL && cur == start2) // ilk düðüm
    {
        ei *temp = start2;
        start2 = start2->next;
        free(temp); // ilk düðümün bilgilendirilmesi
    }
    else if(cur == NULL && prev != NULL) //Son düðüm
    {
        prev->next = NULL;
        free(cur);
    }
    else if(prev != NULL && cur != NULL) // Orta düðümden birini kullanýr.
    {
        prev->next = cur->next;
        free(cur);
    }


}


/// Öðrenci bilgilerini güncelleme iþlemleri
void updateOgrenciInfo(si *cur)
{
    //Gücellenecek bilgileri girmek için
    if(cur != NULL)
    {
        char ID[5000];
        char sec[5000];
        char name[5000];

        pf("Guncellenecek ogrenci adini girin: ");
        sf(" %[^\n]",&name);
        strcpy(cur->name,name);

        pf("Guncellnecek no'yu girin: ");
        sf(" %[^\n]",&ID);
        strcpy(cur->ID,ID);

        pf("Guncellemek istediginiz bolum: ");
        sf(" %[^\n]",&sec);
        strcpy(cur->sec,sec);

        pf("Bilgileriniz basariyla guncellendi.\n");
    }
    else if(cur == NULL)
    {
        pf("Adres Bulunamadi"); // yanlýþ iþlemler sonuucunda 
    }

}



// Öðrenci bilgilerini güncellemek için
void updateCalisanInfo(ei *cur) 
{
    
    if(cur != NULL)
    {
        char ID[5000];
        char salary[5000];
        char name[5000];

        pf("Guncellemek istediginiz calisan adi: ");
        sf(" %[^\n]",&name);
        strcpy(cur->name,name);

        pf("Guncellemek istediginiz calisan No'su': ");
        sf(" %[^\n]",&ID);
        strcpy(cur->ID,ID);

        pf("Maasi Guncelle: ");
        sf(" %[^\n]",&salary);
        strcpy(cur->salary,salary);

        pf("Bilgileriniz basariyla guncellendi.\n");
    }
    else if(cur == NULL)
    {
        pf("Bilgiler Guncellenemedi"); 
    }

}


/**** ************************Crud arama ogrenci******************** ****/





si* SearchByOgrenci(char *name,int ret) 
{
    int len = strlen(name);

    int sl = 1,flag=0;
    si *st = start;

    if(ret == 2) 
    {
        while(st->next->next)
        {
            if((((strcmp(st->next->name,name)) == 0) || ((strcmp(st->next->ID,name)) == 0 ))) 
            {
                return st; 
            }
            st=st->next; 
        }
        return NULL; 
    }

    if(ret)printf("Sl.\t\tAdi\t\t\t\t        ID\t\t        \t\tBolum\t\t\n\n"); 

    while(st->next)
    {
        if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 1)
        {
            pf("%d\t\t",sl++);

            int sz = strlen(st->name);
            for(int i=0; i<sz; i++)
            {
                printf("%c",st->name[i]);
            }


            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");

            }

            sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->sec);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->sec[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            st = st->next;
            pf("\n");
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n");
            flag = 1;
            break;
        }
        else if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 0)
        {
            flag = 1;
            return st;
        }

        st= st->next;
    }

    if(!flag)
    {
        pf("Kayit Bulunamadi\n");
        return NULL;
    }

}


ei* SearchByCalisan(char *name,int ret) 
{
    int len = strlen(name);
    int sl = 1,flag=0;
    ei *st = start2;

    if(ret == 2) 
    {
        while(st->next->next)
        {
            if((((strcmp(st->next->name,name)) == 0) || ((strcmp(st->next->ID,name)) == 0 )))
            {
                return st;
            }
            st=st->next;
        }
        return NULL;
    }

    if(ret)printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tMaas\t\t\n\n"); 

    while(st->next)
    {
        if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 1)
        {
            pf("%d\t\t",sl++);

            int sz = strlen(st->name);
            for(int i=0; i<sz; i++)
            {
                printf("%c",st->name[i]);
            }


            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");

            }

            sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->salary);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->salary[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            st = st->next;
            pf("\n"); 
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n");
            flag = 1;
            break;
        }
        else if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 0)
        {
            flag = 1;
            return st;
        }

        st= st->next;
    }

    if(!flag)
    {
        pf("Kayit Bulunamadi\n");
        return NULL;
    }

}

/**** ************************ Arama ******************** ****/






int main()
{
    pf("****************islemleri yurutmek icin numara girin.****************\n\n");
    pf("1.  Ogrenciler\n");
    pf("2.  Calisanlar\n");
    pf("3.  Kayitlar\n");
    pf("4.  Arama yap\n");
    pf("5.  Sonuclari goster\n");
    pf("6.  Kullanici Menusu\n");
    pf("0.  Cikis\n\n");

    pf("islemler: ");
    int cmd;

    while(sf("%d",&cmd))
    {
        if(!cmd)
        {
            pf("islem sonlandirildi!\n");
            break;
        }

      

        puts("");

        if(cmd == 1)
        {
            printf("1. Yeni ogrenci ekle\n");// SUBMENU
            pf("2. Ogrenci sil.\n");
            pf("3. Tum ogrencileri goruntule.\n");
            pf("4. Ogrenci bilgilerini guncelle.\n");
            pf("5. Geri\n\n");

            int cmds,x=0;
            while(scanf("%d",&cmds))
            {

                if(cmds == 1)
                {
                        takeInOgrenciler();
                }
                else if(cmds == 2)
                {
                    pf("Silmek istediginiz ogrencinin  nosu:  ");
                    char s[5000];
                    sf(" %[^\n]",&s);

                    si *DEL = SearchByOgrenci(s,0); 
                    if(DEL == NULL)
                    {
                        pf("Baska bir islem yap.\n");
                        continue;
                    }


                    pf("\n%s %s %s\n",DEL->name,DEL->ID,DEL->sec);
                    pf("\nSilmek istediginiz kisi bu mu? \n1. Evet\n2. Hayir\n\n");

                    int n;
                    sf("%d",&n);


                    if(n==1)
                    {
                        si *PRE = SearchByOgrenci(s,2); 
                        deleteOgrenciInfo(PRE,DEL); 
                    }
                    else if(n=2)
                    {
                        continue;
                    }

                }
                else if(cmds == 3)
                {
                    printOgrenciInfo();

                }
                else if(cmds == 4)
                {
				char sarc[5000];

                    pf("Ogrenci bilgilerini guncellemek icin, once istenen bilgileri giriniz: ");
                    pf("\nnosu : ");
                    sf(" %[^\n]",&sarc);

                    si *cur =  SearchByOgrenci(sarc,0); 
                    if(cur == NULL)
                    {
                        pf("Bulunamadi");
                        continue;
                    }

                    pf("%s %s %s\n",cur->name,cur->ID,cur->sec);


                    pf("\n\nGuncellemek istediginiz bilgi bu mu?\n1. Evet\n2. Hayir\n");
                    int n;
                    scanf("%d",&n);

                    if(n==1)
                    {
                        updateOgrenciInfo(cur);
                    }
                    else
                    {
                        pf("Lutfen baska bir islem seciniz.\n\n");
                        continue;
                    }
                }
                else if(cmds == 5)
                {
                    
                    printf("Baska bir islem yap.  \n");
                    break;
                }
                else
                {
                    printf("Tekrar deneyiniz.\n");
                }

                if(!x)
                {
                    pf("\n");
                    printf("1. Yeni ogrenci bilgisi ekle\n");
                    pf("2. Ogrenci bilgilerini sil\n");
                    pf("3. Tum ogrencileri goruntule\n");
                    pf("4. Ogrenci bilgisini guncelle.\n");
                    pf("5. Geri\n\n");
                }

                x =0;
            }


        }

        else if(cmd == 2)
        {
            printf("1. Yeni Calýsan Bilgileri Ekle\n"); // SUBMENU
            pf("2. Calisan bilgilerini sil\n");
            pf("3. Tüm Calisanlari Goruntule\n");
            pf("4. Calýsan Bilgilerini Güncelle\n" );
            pf("5. Geri\n");

            int cmds,x=0;
            while(sf("%d",&cmds))
            {

                if(cmds == 1)
                {
                    
                    takeInCalisan();
                }
                else if(cmds == 2)
                {
                    

                    pf("Silmek istediginiz calisanin adini ve numarasini giriniz:  ");
                    char s[5000];

                    sf(" %[^\n]",&s);
                    ei *DEL = SearchByCalisan(s,0);

                    if(DEL == NULL) 
                    {
                        pf("Run another Operation\n");
                        continue;
                    }
                    pf("\n%s %s %s\n",DEL->name,DEL->ID,DEL->salary);
                    pf("\nSilmek istediginiz bilgi bu mu? \n1. Evet\n2. Hayir\n\n");

                    int n;
                    sf("%d",&n); // CMD in submenu

                    if(n==1)
                    {
                        ei *pre = SearchByCalisan(s,2);
						deleteCalisanInfo(pre,DEL); 
                    }
                    else if(n=2)
                    {
                        pf("\nTekrar Deneyiniz\n");
                        continue;
                    }

                    if(!x)
                    {
                         printf("1. Yeni Calýsan Bilgileri Ekle\n"); 
           				 pf("2. Calisan bilgilerini sil\n");
           				 pf("3. Tüm Calisanlari Goruntule\n");
         	    		 pf("4. Calýsan Bilgilerini Güncelle\n" );
     			         pf("5. Geri\n");
                    }



                }
                else if(cmds == 3)
                {
                  
                    printCalisanInfo();

                }
                else if(cmds == 4)
                {
                    
                    char sarc[5000];

                    pf("Calisan bilgilerini goruntulemek icin once istenilen bilgileri giriniz. ");
                    pf("\nAdý ve nosu ");
                    sf(" %[^\n]",&sarc);

                    ei *cur =  SearchByCalisan(sarc,0); 
                    if(cur == NULL)
                    {
                        pf("Kayit bulunamadi!");
                        continue;
                    }


                  
                    pf("%s %s %s\n",cur->name,cur->ID,cur->salary);


                    pf("\n\nGuncellemek istediginiz bilgi bu mu?\n1. Evet\n2. Hayir\n");
                    int n;
                    scanf("%d",&n);

                    if(n==1)
                    {
                        
                        updateCalisanInfo(cur);
                    }
                    else
                    {
                        pf("Baska bir islem deneyin.\n\n");
                        continue;
                    }


                }
                else if(cmds == 5)
                {
                    
                    printf("Baska bir islem yap: \n");
                    break;
                }
                else
                {
                    printf("Tanimlanamadi, Tekrar Deneyin.\n");
                }

                 printf("1. Yeni Calýsan Bilgileri Ekle\n"); // SUBMENU
           		 pf("2. Calisan bilgilerini sil\n");
           		 pf("3. Tüm Calisanlari Goruntule\n");
           		 pf("4. Calýsan Bilgilerini Güncelle\n" );
           		 pf("5. Geri\n");

            }

        }
        else if(cmd == 3)
        {
            

            pf("1. Sonuc Listesi olustur\n");
            pf("2. Son Sonuc Listesini yaz/goster\n");
            pf("3. Onceki Sonuc Listesini sil\n");
            pf("4. Geri\n");

            int x,ff=0;
            while(sf("%d",&x))
            {
                ff = 1;
                if(x==1)
                {
                    createResultBoard();
                }
                else if(x == 2)
                {
                    printResultBoard();
                }
                else if(x == 3) 
                {
                    start3 = head3;
                    pf("Sonuclar temizlendi.\n");
                }
                else if(x == 4)
                {
                    break;
                }

                if(ff) // Alt menü çalýþacak
                {
                    pf("1. Sonuc Listesi olustur\n");
            		pf("2. Son Sonuc Listesini yaz/goster\n");
          		    pf("3. Onceki Sonuc Listesini sil\n");
            		pf("4. Geri\n");
                }
            }

        }
        else if(cmd == 4)
        {
            /*isme göre arama*/
            pf("1. isme Gore Ara\n");
            pf("2. no'ya göre Ara\n");
            pf("3. Geri\n");

            int src,ff=0;
            while(sf("%d",&src))
            {
                ff=1; // Flagging the source
                if(src == 1)
                {
                    
              /* Arama fonksiyonunu kullan parametre gönder 1 */
                    char searchName[256];

                    pf("isim girin: ");
                    scanf("\n"); 
                    gets(searchName);

                    pf("\n\nOgrenci icin\n\n");
                    SearchByOgrenci(searchName,1); //Öðrencide bilgisi, eþleþen biigiler ile ilgili

                    pf("\n\nCalisan icin\n\n");
                    SearchByCalisan(searchName,1); 

                    pf("Baska bir islem yapmak ister misiniz?\n");
                    memset(searchName,'\0',sizeof(searchName)); // Diziyi sil

                }
                else if(src == 2)
                {
                    //send parameter.

                    char searchID[256];
                    pf("NO gir: ");
                    sf("\n");
                    gets(searchID); 

                    pf("Ogrenci icin\n\n");
                    SearchByOgrenci(searchID,1);

                    pf("\n\nCalisan icin\n\n");
                    SearchByCalisan(searchID,1);

                    pf("\nBaska bir islem yapmak ister misiniz?\n");
                    memset(searchID,'\0',sizeof(searchID));
                }
                else if(src == 3)
                {
                    break;
                }

                if(ff)
                {
                    pf("1. isme gore ara\n");
                    pf("2. no'ya gore ara'\n");
                    pf("3. Geri\n");
                }


            }

        }

        else if(cmd == 5)
        {
            //aþagýdaki bilgileri gösterir
            pf("Mevcut Tum Ogrenciler \n");
            printOgrenciInfo();
            pf("\n\n");
            pf("Mevcut Tum Calisanlar: \n");
            printCalisanInfo();
        }
        else if(cmd == 6) //kullanýmý yazdýrma
        {
            pf("Tesekkurler\n");
           
        }
        else if(cmd == 0)
            break;
        else
        {
            pf("Bulunamadi");
        }

        puts(""); // Döngü kýrýldýðýnda bu menüye dönerken tekrar çalýþýr
        pf("1.  Ogrenciler\n");
        pf("2.  Calisanlar\n");
        pf("3.  Sonus \n");
        pf("4.  Arama\n");
        pf("5.  Output all data base.\n");
        pf("6.  User Manual\n");
        pf("0.  exit\n\n");
        pf("Operation: ");


    }


    return 0;
}
