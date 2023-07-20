#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
int kichthuockhoi[MAX];
int kichthuoctientrinh[MAX];
int khoitotnhat[MAX];
int thutukhoinho[MAX];
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
void nhapSoLuong(int kichthuockhoi[MAX],int kichThuocTienTrinh[MAX],int &soKhoi,int &SoTienTrinh)
{
	do
	{
		printf("\nNhap so luong khoi nho (gioi han %d):",MAX);
		scanf_s("%d",&soKhoi);
	}while(soKhoi>20);
	do
	{
		printf("\nNNhap so luong tien trinh (gioi han %d):",MAX);
		scanf_s("%d",&SoTienTrinh);
	}while(SoTienTrinh>20);
	for(int i=0;i<soKhoi;i++)
	{
		printf("\nNhap kich thuoc cua khoi nho %d:",i+1);
		scanf_s("%d",&kichthuockhoi[i]);
	}
	for(int i=0;i<SoTienTrinh;i++)
	{
		printf("\nNhap kich thuoc cua tien trinh %d:",i+1);
		scanf_s("%d",&kichThuocTienTrinh[i]);
	}
}
void xuatkhoiNho(int kichthuockhoi[MAX],int n)
{
	printf("STT :\t");
	for(int j=1;j<=n;j++)
	{
		printf("%d.\t",j);
	}
	printf("\n");
	printf("khoi:\t");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",kichthuockhoi[i]);
	}
}
void xuatTienTrinh(int kichthuoctientrinh[MAX],int n)
{
	printf("STT    :");
	for(int j=1;j<=n;j++)
	{
		printf("%d.\t",j);
	}
	printf("\nT.Trinh:");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",kichthuoctientrinh[i]);
	}
}
void xuat(int kichthuoctientrinh[MAX],int kichthuockhoi[MAX],int kn,int tt)
{
	xuatkhoiNho(kichthuockhoi,kn);
	printf("\n");
	printf("\n");
	xuatTienTrinh(kichthuoctientrinh,tt);
}
//==============================================================
void firstFit(int kichthuockhoi[MAX],int kichthuoctientrinh[MAX],int tt,int kn)//first fit thì nó sẽ bắt đầu từ khối nhớ trống đầu tiên để nạp tiến trình
{
	int dem=0;
	int i=0;
	printf("\n%-15s%-26s%-21s%-20s%-14s","Tien Trinh","kich thuoc tien trinh","kich thuoc khoi nho","Thu Tu khoi Nho","Phan Manh");
	for(;i<kn;i++)//vùng nhớ
	{
		dem=0;
		for(int j=0;j<tt;j++)//tiến trình
		{
			if(kichthuoctientrinh[j]<=kichthuockhoi[i])//tìm kiếm kích thước tiến trình nhỏ hơn kích thước Khối nhớ
			{
				printf("\n%5d         ",j+1);
				printf("%14d           ",kichthuoctientrinh[j]);
				printf("%13d          ",kichthuockhoi[i]);
				printf("%7d             ",i+1);
				kichthuockhoi[i]=kichthuockhoi[i]-kichthuoctientrinh[j];//thay đổi giá trị của vùng đã cho tiến trình vào
				printf("%6d    ",kichthuockhoi[i]);
				kichthuoctientrinh[j]=999;//thay đổi giá trị của tiến trình đã cho vào khối nhớ 
			}
		}
	}
	//loại bỏ những tiến trình lớn hơn các khối nhớ trong mảng
	for(int k=0;k<tt;k++)
	{
		if(kichthuoctientrinh[k]!=999)//những tiến trình chưa thay đổi giá trị = 999 thì đó là tiến trình có kích thước lớn hơn các khối nhớ
		{
			printf("\n%5d         ",k+1);
			printf("%14d           ",kichthuoctientrinh[k]);
			printf("%13s          ","khong du");
			printf("%7s             ","?");
			printf("%6s    ","?");
		}
	}
}
void sapXepGiamDankhoi(int kichthuockhoi[MAX],int kn)
{
	for(int i=0;i<kn-1;i++)
	{
		for(int j=i+1;j<kn;j++)
		{
			if(kichthuockhoi[i]<kichthuockhoi[j])
			{
				swap(kichthuockhoi[i],kichthuockhoi[j]);
			}
		}
	}
}
//=============================================================
void worstFit(int kichthuockhoi[MAX],int kichthuoctientrinh[MAX],int tt,int kn)//worst fit thì mình sẽ sắp xếp các vùng nhớ từ lớn đến bé để cho dễ hiểu
{
	printf("\n%-15s%-26s%-21s%-20s%-14s","Tien Trinh","kich thuoc tien trinh","kich thuoc khoi nho","Thu Tu khoi Nho","Phan Manh");
	for(int i=0;i<kn;i++)//vùng nhớ
	{
		for(int j=0;j<tt;j++)//tiến trình
		{
			if(kichthuoctientrinh[j]<=kichthuockhoi[i])//nếu có tiến trình nào < vùng 
			{
				printf("\n%5d         ",j+1);
				printf("%14d           ",kichthuoctientrinh[j]);
				printf("%13d          ",kichthuockhoi[i]);
				printf("%7d             ",i+1);
				kichthuockhoi[i]=kichthuockhoi[i]-kichthuoctientrinh[j];//thay đổi giá trị của vùng đã cho tiến trình vào
				printf("%6d    ",kichthuockhoi[i]);
				kichthuoctientrinh[j]=999;//thay đổi giá trị của tiến trình đã cho vào vùng nhớ 
			}
		}
	}
	//loại bỏ những tiến trình lớn hơn các vùng nhớ trong mảng
	for(int k=0;k<tt;k++)
	{
		if(kichthuoctientrinh[k]!=999)//những tiến trình chưa thay đổi giá trị = 999 thì đó là tiến trình có kích thước lớn hơn các vùng nhớ
		{
			printf("\n%5d         ",k+1);
			printf("%14d           ",kichthuoctientrinh[k]);
			printf("%13s          ","khong du");
			printf("%7s             ","?");
			printf("%6s    ","?");
		}
	}
}
void sapXepGiamDanTienTrinh(int kichthuoctientrinh[MAX],int tt)
{
	for(int i=0;i<tt-1;i++)
	{
		for(int j=i+1;j<tt;j++)
		{
			if(kichthuoctientrinh[i]<kichthuoctientrinh[j])
			{
				swap(kichthuoctientrinh[i],kichthuoctientrinh[j]);
			}
		}
	}
}
void DatMacDinhMang(int khoitotnhat[MAX],int thutukhoinho[MAX])
{
	for(int i=0;i<MAX;i++)
	{
		khoitotnhat[i]=0;
		thutukhoinho[i]=0;
	}
}
//=============================================================
void bestFit(int kichthuockhoi[MAX],int kichthuoctientrinh[MAX],int tt,int kn)//best fit sẽ khó hơn những chiến lược phân phối khác là nó sẽ kiếm những vùng nhớ phù hợp với tiến trình đó thì nó sẽ ghép vùng nhớ và tiến trình đó với nhau
{
	int dem=0;
	printf("\n%-15s%-26s%-21s%-20s%-14s","Tien Trinh","kich thuoc tien trinh","kich thuoc khoi nho","Thu Tu khoi Nho","Phan Manh");
	for(int i=0;i<tt;i++)//tiến trình
	{
		for(int j=0;j<kn;j++)//vùng nhớ
		{
			if(kichthuoctientrinh[i]<=kichthuockhoi[j])//nếu có tiến trình < vùng nhớ
			{
				khoitotnhat[dem]=kichthuockhoi[j];//cho vào 1 cái mảng chứa các vùng lớn hơn tiến trình đó
				thutukhoinho[dem]=j;//đánh dấu thứ tự của vùng nhớ đó
				dem++;
			}
		}
		int t;
		int min=0;
		//bắt đầu dò tìm vùng nhớ tối ưu nhất cho tiến trình đó
		for(int k=0;k<dem;k++)
		{
			if(khoitotnhat[k]!=0)//nếu vùng tốt nhất không chứa giá trị nào ngoài 0 thì mảng này không có vùng tốt nhất cho tiến trình này
			{
				if(min==0)
				{
				min=khoitotnhat[k];//tìm vùng min trong vùng tốt nhất
				t=thutukhoinho[k];
				}
				else//nếu min lớn hơn 1 trong các vùng tốt của mảng
				{
					if(min>khoitotnhat[k])
					{
						min=khoitotnhat[k];
						t=thutukhoinho[k];
					}
				}
			}
			else//nếu không có vùng nhớ !=0 thì thoát khỏi vòng lặp này
			{
				break;
			}
		}
		if(dem!=0)//in ra vùng nhớ tối ưu nhất để ghép với tiến trình này
		{
			printf("\n%5d         ",i+1);
			printf("%14d           ",kichthuoctientrinh[i]);
			printf("%13d          ",kichthuockhoi[t]);
			printf("%7d             ",t+1);
			kichthuockhoi[t]=kichthuockhoi[t]-kichthuoctientrinh[i];
			printf("%6d    ",kichthuockhoi[t]);
			kichthuoctientrinh[i]=999;
			dem=0;
		}
		//cho các mảng vùng tốt nhất,thứ tự vùng nhớ về giá trị 0
		DatMacDinhMang(khoitotnhat,thutukhoinho);
	}
	//nếu không có các vùng nhớ > tiến trình đó thì in ra cái này
	if(dem==0)
	{
		for(int k=0;k<tt;k++)
		{
			if(kichthuoctientrinh[k]!=999)
			{
				printf("\n%5d         ",k+1);
				printf("%14d           ",kichthuoctientrinh[k]);
				printf("%13s          ","khong du");
				printf("%7s             ","?");
				printf("%6s    ","?");
			}
		}
	}
}
void readfile(char* filename,int &kn,int &tt)
{
	FILE* f=fopen(filename,"r");
	if(f==NULL)
	{
		printf("\nFile khong ton tai");
		return;
	}
	fscanf_s(f,"%d\t%d\n",&kn,&tt);
	for(int i=0;i<kn;i++)
	{
		fscanf_s(f,"%d\t",&kichthuockhoi[i]);
	}
	for(int i=0;i<tt;i++)
	{
		fscanf_s(f,"%d\t",&kichthuoctientrinh[i]);
	}
	fclose(f);
}
void ghiFilekhoiTTBanNhap(char *filename,int kn,int tt)
{
	FILE* f=fopen(filename,"w");
	if(f==NULL)
	{
		printf("\nFile khong ton tai");
		return ;
	}
	fprintf(f,"%d\t%d\n",kn,tt);
	for(int i=0;i<kn;i++)
	{
		fprintf(f,"%d\t",kichthuockhoi[i]);
	}
	fprintf(f,"\n");
	for(int i=0;i<tt;i++)
	{
		fprintf(f,"%d\t",kichthuoctientrinh[i]);
	}
	fclose(f);
}
//=============================================================
void nextFit(int kichthuockhoi[MAX],int kichthuoctientrinh[MAX],int tt,int kn)
{
	int i=0;
	printf("\n%-15s%-26s%-21s%-20s%-14s","Tien Trinh","kich thuoc tien trinh","kich thuoc khoi nho","Thu Tu khoi Nho","Phan Manh");
	for(;i<tt;i++)
	{
		for(int j=0;j<kn;j++)
		{
			if(kichthuoctientrinh[i]<=kichthuockhoi[j])
			{
				printf("\n%5d         ",i+1);
				printf("%14d           ",kichthuoctientrinh[i]);
				printf("%13d          ",kichthuockhoi[j]);
				printf("%7d             ",j+1);
				kichthuockhoi[j]=kichthuockhoi[j]-kichthuoctientrinh[i];//thay đổi giá trị của vùng đã cho tiến trình vào
				printf("%6d    ",kichthuockhoi[j]);
				kichthuoctientrinh[i]=999;//thay đổi giá trị của tiến trình đã cho vào vùng nhớ 
				kichthuockhoi[j]=0;
				break;
			}
		}
	}
	for(int k=0;k<tt;k++)
	{
		if(kichthuoctientrinh[k]!=999)//những tiến trình chưa thay đổi giá trị = 999 thì đó là tiến trình có kích thước lớn hơn các vùng nhớ
		{
			printf("\n%5d         ",k+1);
			printf("%14d           ",kichthuoctientrinh[k]);
			printf("%13s          ","khong du");
			printf("%7s             ","?");
			printf("%6s    ","?");
		}
	}
}
void MENUDuLieu(int kichthuoctientrinh[MAX],int kichthuockhoi[MAX],int &kn,int &tt,int dem)
{
	int luachon;
	do
	{
		printf("\n================================================================================");
		printf("\n\t\tMoi ban chon 1 trong cac yeu cau sau");
		printf("\n\t\tFILE CHUA CAC khoi NHO VA TIEN TRINH CO SAN");
		printf("\n\t\t1. DOC FILE DU LIEU 1\n\t\t2. DOC FILE DU LIEU 2");
		printf("\n\t\t3. DOC DU LIEU TU BAN PHIM");
		printf("\n\t\t0. THOAT CHUONG TRINH HIEN TAI VA THUC HIEN YEU CAU BAN CHON");
		printf("\n\t\tNHAP LUA CHON CUA BAN:");
		scanf_s("%d",&luachon);
		switch (luachon)
		{
		case 1:
			printf("\n\t\tXem du lieu file ma ban chon\n");
			readfile("hdh.txt",kn,tt);
			xuat(kichthuoctientrinh,kichthuockhoi,kn,tt);
			break;
		case 2:
			printf("\n\t\tXem du lieu file ma ban chon\n");
			readfile("hdh2.txt",kn,tt);
			xuat(kichthuoctientrinh,kichthuockhoi,kn,tt);
			break;
		case 3:
			printf("\n\t\tXem du lieu file ma ban chon\n");
			if(dem==0)
			{
				printf("\nVui long thoat khoi chuong trinh nay va 'chon yeu cau 5 de nhap du lieu ban phim' hoac co the chon cac yeu cau khac");
			}
			else
			{
				readfile("ghiFile.txt",kn,tt);
				xuat(kichthuoctientrinh,kichthuockhoi,kn,tt);
				dem=0;
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	}while(luachon!=0);
}
void MENU()
{
	printf("\n================================================================================");
	printf("\n\t\tCHUONG TRINH QUAN LY CHIEN LUOC PHAN PHOI KHOI NHO");
	printf("\n\t\tMoi ban chon 1 trong cac yeu cau sau");
	printf("\n\t\t1. CHIEN LUOC PHAN PHOI KHOI NHO 'FIRST-FIT'\n\t\t2. CHIEN LUOC PHAN PHOI KHOI NHO 'BEST-FIT'");
	printf("\n\t\t3. CHIEN LUOC PHAN PHOI KHOI NHO 'WORST-FIT'\n\t\t4. CHIEN LUOC PHAN PHOI KHOI NHO 'NEXT-FIT'");
	printf("\n\t\t5. NHAP DU LIEU TU BAN PHIM HOAC CO THE CHON CAC YEU CAU TREN ROI NHAP DU LIEU BANG FILE");
	printf("\n\t\t0. THOAT CHUONG TRINH");
}

int main()
{
      int soTienTrinh,soKhoiNho,luachon,dem=0,p;
	  do
	  {
		  MENU();
		  printf("\n\t\tNHAP LUA CHON CUA BAN:");
		  scanf_s("%d",&luachon);
		switch (luachon)
		{
		case 1:
			MENUDuLieu(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh,dem);
			printf("\n\t\t1. CHIEN LUOC PHAN PHOI khoi NHO 'FIRST-FIT'\n");
			xuat(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh);
			firstFit(kichthuockhoi,kichthuoctientrinh,soTienTrinh,soKhoiNho);
			break;
		case 2:
			MENUDuLieu(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh,dem);
			printf("\n\t\t2. CHIEN LUOC PHAN PHOI khoi NHO 'BEST-FIT'\n");
			xuat(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh);
			bestFit(kichthuockhoi,kichthuoctientrinh,soTienTrinh,soKhoiNho);
			break;
		case 3:
			MENUDuLieu(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh,dem);
			printf("\n\t\t3. CHIEN LUOC PHAN PHOI khoi NHO 'WORST-FIT'\n");
			xuat(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh);
			sapXepGiamDankhoi(kichthuockhoi,soKhoiNho);
			worstFit(kichthuockhoi,kichthuoctientrinh,soTienTrinh,soKhoiNho);
			break;
		case 4:
			MENUDuLieu(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh,dem);
			printf("\n\t\t4. CHIEN LUOC PHAN PHOI khoi NHO 'NEXT-FIT'\n");
			xuat(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh);
			nextFit(kichthuockhoi,kichthuoctientrinh,soTienTrinh,soKhoiNho);
			break;
		case 5:
			nhapSoLuong(kichthuockhoi,kichthuoctientrinh,soKhoiNho,soTienTrinh);
			xuat(kichthuoctientrinh,kichthuockhoi,soKhoiNho,soTienTrinh);
			ghiFilekhoiTTBanNhap("ghiFile.txt",soKhoiNho,soTienTrinh);
			dem++;
			break;
		default:
		break;
		}
	_getch();
	}while(luachon!=0);
}