#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void OgrenciEkle();
int numara_karsilastir(int);
void fakulte_birincisi();
void guncelle();
void ogrenciSirala();
void OgrenciSil();
int main()
{
	
	
	menu:
	system("COLOR 2f");
	printf("\n\n");
	printf("\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n");
	printf("\t\t\tOgrenci Ekleme                 ->1\n");
	printf("\t\t\tOgrenci Silme                  ->2\n");
	printf("\t\t\tOgrenci Guncelleme             ->3\n");
	printf("\t\t\tFakulte Birincisi              ->4\n");
	printf("\t\t\tNot ortalamasina gore sirala   ->5\n");
	printf("\t\t\tCikis                          ->6\n\n");
	printf("\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	
	int secenek;
	printf("\n");
tekrar:	printf("\t\tseciminiz -> ",secenek);
	scanf("%d",&secenek);
	
	switch(secenek)
	{
		case 1:
			
			OgrenciEkle();
			system("CLS");
			goto menu;
		    
		break;
		
		case 2:
			   OgrenciSil();
		break;
		
		case 3:
			guncelle();
		break;
		
		case 4:
			fakulte_birincisi();
			goto menu;
		break;
		case 5:
			ogrenciSirala();
		break;
		
		case 6:
			exit(0);
		break;
		default:
			printf("Hatali giris yaptiniz :");
			goto tekrar;
	}

}


struct Ogrenciler {
 long int ogrNo;
	char ad   [30];
	char soyad[30];
	char cinsiyet[5];		// E: Erkek, K:Kiz
	char bolum[30];
    char ortalama[20];
} ;


void OgrenciEkle()
{
	system("CLS");
	struct Ogrenciler ogr;
	FILE *dosya;
	if((dosya=fopen("Ogrenci.txt","a+"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}
	else
	{
		
		
		
	   ogrnu: printf("Ogrenci Numarasi: ");   scanf("%d",&ogr.ogrNo);numara_karsilastir(ogr.ogrNo);
	   
	    if ((numara_karsilastir(ogr.ogrNo))==1)
	    {
	    	
	    	printf("Girilmis Ogrenci Numarasi..\t Yeni bir kayit icin herhangi bir tusa basiniz...");
	    	char numara3[2];
		    scanf("%s",&numara3);
		    system("CLS");
	    	goto ogrnu;
	    	
	    	
		}
	    
	    
	tkr:	printf("Ogrenci Adi: ");        scanf("%s",&ogr.ad);
		
		for(int i=0;i<strlen(ogr.ad);i++)
	   {
	   	
	   	if(('ogr.ad[i]'<65 && 'ogr.ad[i]'>90 )||('ogr.ad[i]'<97 && 'ogr.ad[i]'>122 ))
	   	{
	   		printf("Turkce bir karakter girdiniz tekrar giriniz: \n");goto tkr;
	   		
		}
		
	   }
		
		
		printf("Ogrenci Soyadi: ");     scanf("%s",&ogr.soyad);
		printf("Ogrenci Cinsiyeti: ");   scanf("%s",&ogr.cinsiyet);
		printf("Ogrenci Bolumu: ");     scanf("%s",&ogr.bolum);
		printf("Ogrenci Ortalama: ");     scanf("%s",&ogr.ortalama);
		printf("\n%s %s isimli ogrencinin kaydi yapilmistir ...\n\n Menu icin herhangi bir tusa basiniz...",ogr.ad,ogr.soyad);
		
		
		

		
		
		char numara[2];
		scanf("%s",&numara);
		
		
		printf("\n\n");
		
		fprintf(dosya,"%d\t",ogr.ogrNo);
		fprintf(dosya,"%s\t",ogr.ad);
		fprintf(dosya,"%s\t",ogr.soyad);
		fprintf(dosya,"%s\t",ogr.cinsiyet);
		fprintf(dosya,"%s\t",ogr.bolum);
		fprintf(dosya,"%s\t",ogr.ortalama);
		fprintf(dosya,"\n");
		
		
		
		
		
		
	}
	fclose(dosya);
}


int numara_karsilastir(int sayi)
{
	FILE *dosya;
	int numaralar[20];
	char ad[20][20],soyad[20][20],cinsiyet[20][20],bolum[20][20];
	char ortalama[20][20];
	int i=0;
	int j;
	if((dosya=fopen("Ogrenci.txt","r"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}
	else
	{
		while(!feof(dosya))
		{
			fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
		    i++;
			
		}
		
			
			
			for(int j=0;j<=i;j++)
			{
				
				if(numaralar[j]==sayi)
				{
					return 1;
				}
				else
				{
					
				}
			}
		
		
	}
	fclose(dosya);
}

void fakulte_birincisi()
{
	
	FILE *dosya;
	int numaralar[20];
	char ad[20][20],soyad[20][20],cinsiyet[20][20],bolum[20][20];
	char ortalama[20][20];
	float all[20];
	int i=0;
	if((dosya=fopen("Ogrenci.txt","r"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}
	
	
	else
	{
		while(!feof(dosya))
		{
			fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
		    all[i]=atof(ortalama[i]);
			i++;
		    
		    
		    
		    
			
		}
		
		float max=all[0];
		int indis;
		
		for(int j=0;j<i;j++)
		{
			if(all[j]>max)
			{
				max=all[j];
				indis=j;
				
			}
		}
		
		printf("\n\n%.2f ortalama ile fakulte birincisi %s %s\n\n",max,ad[indis],soyad[indis]);
		printf("Herhangi bir tusa basiniz...");
		char numara3[2];
		scanf("%s",&numara3);
		system("CLS");
		
		
		
	}
	fclose(dosya);
	
	
	
	
	
	
}

void  guncelle()
{
		FILE *dosya,*yeni;
	int numaralar[20];
	char ad[20][20],soyad[20][20],cinsiyet[20][20],bolum[20][20];
	char ortalama[20][20];
	int i=0;
	int j;
	long int guncellenecek;
	gonder:
		
	printf("Guncellemek istediðiniz ogrenci numarasi: ");scanf("%d",&guncellenecek);
	if((dosya=fopen("Ogrenci.txt","r"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}

	else
	{	
	
	yeni=fopen("rehber1.txt","w");
		while(!feof(dosya))
		{
			fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
		    
		    
		    	
			
				
				if(numaralar[i]==guncellenecek)
				{
					printf("%d\n",numaralar[i]);
					printf("%s\n",ad[i]);
					printf("%s\n",soyad[i]);
					printf("%s\n",cinsiyet[i]);
					printf("%s\n",bolum[i]);
					printf("%s\n\n\n",ortalama[i]);
					
					
					
					printf("Ogrenci Numarasi: ");    scanf("%d",&numaralar[i]);
					printf("Ogrenci Adi: ");        scanf("%s",&ad[i]);
					printf("Ogrenci Soyadi: ");     scanf("%s",&soyad[i]);
					printf("Ogrenci Cinsiyeti: ");   scanf("%s",&cinsiyet[i]);
					printf("Ogrenci Bolumu: ");     scanf("%s",&bolum[i]);
					printf("Ogrenci Ortalama: ");     scanf("%s",&ortalama[i]);
					
				    printf("\n\n");printf("%s %s isimli ogrenci bilgileri guncellenmistir...",ad[i],soyad[i]);
					
					
					fscanf(dosya,"\n");
					
				  
				}
			
				else 
				{
					printf("/n Boyle býr kayýt bulunamadý.Tekrar gýrýnýz ");
					goto gonder;
				}
					fprintf(yeni,"%d\t",numaralar[i]);
					fprintf(yeni,"%s\t",ad[i]);
					fprintf(yeni,"%s\t",soyad[i]);
					fprintf(yeni,"%s\t",cinsiyet[i]);
					fprintf(yeni,"%s\t",bolum[i]);
					fprintf(yeni,"%s\t",ortalama[i]);
					fprintf(yeni,"\n");
					
	    
			i++;	
			
		}
		
			
		
			
		
		
	}
	
	fclose(dosya);
	fclose(yeni);

remove("Ogrenci.txt");
rename("rehber1.txt","Ogrenci.txt");
	
}
void ogrenciSirala()
{
	FILE *dosya;
	int numaralar[20];
	char ad[20][20],soyad[20][20],cinsiyet[20][20],bolum[20][20];
	char ortalama[20][20];
	float all[20];
	int i=0;
	if((dosya=fopen("Ogrenci.txt","r"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}
	
	
	else
	{
		while(!feof(dosya))
		{
			fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
		    all[i]=atof(ortalama[i]);
			i++;
		    
		    
		    
		    
			
		}
		for(int h=0;h<i;h++)
		{
			printf("%d. %s %s\t%.2f\n",h+1,ad[h],soyad[h],all[h]);
		}
		
	
		float gecici;

		
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(all[k-1]>all[k])
			{
				gecici=all[k+1];
				all[k+1]=all[k];
				all[k]=gecici;
				
				
			}
			}
			
		}
		
		
		
		printf("Herhangi bir tusa basiniz...");
		char numara3[2];
		scanf("%s",&numara3);
		system("CLS");
}

fclose(dosya);
}

void OgrenciSil()
{
	
	
	FILE *dosya,*yeni;
	int numaralar[20];
	char ad[20][20],soyad[20][20],cinsiyet[20][20],bolum[20][20];
	char ortalama[20][20];
	int i=0;
	int j;
	long int silinecek;
	printf("Silmek istediginiz ogrenci numarasi: ");scanf("%d",&silinecek);
	if((dosya=fopen("Ogrenci.txt","r"))==NULL)
	{
		printf("Dosya açýlamadý..");
	}

	else
	{	
	
	yeni=fopen("rehber1.txt","w");
		while(!feof(dosya))
		{
			fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
		    
		    
		    	
			
				
				if(numaralar[i]==silinecek)
				{
					
					fscanf(dosya,"%d\t%s\t%s\t%s\t%s\t%s\t",&numaralar[i],&ad[i],&soyad[i],&cinsiyet[i],&bolum[i],&ortalama[i]);
					printf("silinen ogrenci ismi: %s %s",ad[i],soyad[i]);
					
					fscanf(dosya,"\n");
					
				  
				}
				else
				{
								
	    	fprintf(yeni,"%d\t",numaralar[i]);
			fprintf(yeni,"%s\t",ad[i]);
			fprintf(yeni,"%s\t",soyad[i]);
			fprintf(yeni,"%s\t",cinsiyet[i]);
			fprintf(yeni,"%s\t",bolum[i]);
			fprintf(yeni,"%s\t",ortalama[i]);
			fprintf(yeni,"\n");
					
				}
				
		
			i++;	
			
		}
		
			
		
			
		
		
	}
	
	fclose(dosya);
	fclose(yeni);

remove("Ogrenci.txt");
rename("rehber1.txt","Ogrenci.txt");
	
}

