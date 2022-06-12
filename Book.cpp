#pragma once
#include"book.h"
#include"class.h"
#include"Queue.cpp"
Queue<Human> q;
//Ham xuat file
void outPutFile(Book a[], char fileName[], int n)
{
	FILE *fileptr;
	fileptr = fopen(fileName, "w");
	//bien phu de mang gia tri copy
	char tenSach[100] = "";
	char tacGia[50] = "";
	char theLoai[50] = "";
	char maSach[10] = "";
	char nhaXB[50] = "";
	char tenNguoiMuon[20] = "";
    char tinhTrang[12] = "";
	fprintf(fileptr, "%45s%20s%18s%7s%13s%13s%15s%18s\n", "Ten Sach", "Tac gia", "The Loai", "Ma Sach", "NXB", "Nam XB", "So Luong", "SL nguoi muon");
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		//copy chuoi va thay the cac khoang trang trong chuoi bang dau '_'
		strcpy(tenSach, a[i].TenSach);
		replace_spaces(tenSach);
		strcpy(tacGia, a[i].TacGia);
		replace_spaces(tacGia);
		strcpy(theLoai, a[i].TheLoai);
		replace_spaces(theLoai);
		strcpy(maSach, a[i].MaSach);
		replace_spaces(maSach);
		strcpy(nhaXB, a[i].NhaXuatBan);
		replace_spaces(nhaXB);
		fprintf(fileptr, "%45s%20s%18s%7s%13s%13d%15d%18d\n", tenSach, tacGia, theLoai, maSach, nhaXB, a[i].NamXB, a[i].SoLuong, a[i].SLNguoiMuon);
	for(int j=0;j<a[i].SLNguoiMuon;j++){
		strcpy(tenNguoiMuon, a[i].NguoiMuon[j].TenNguoiMuon);
		strcpy(tinhTrang, a[i].NguoiMuon[j].TinhTrang);
				replace_spaces(tenNguoiMuon);
				replace_spaces(tinhTrang);
		fprintf(fileptr, "%20s%8d%8d%8d%8d%8d%8d%12s\n", tenNguoiMuon, a[i].NguoiMuon[j].NgayMuon.ngay, a[i].NguoiMuon[j].NgayMuon.thang, a[i].NguoiMuon[j].NgayMuon.nam, a[i].NguoiMuon[j].NgayTra.ngay, a[i].NguoiMuon[j].NgayTra.thang, a[i].NguoiMuon[j].NgayTra.nam,tinhTrang);
	}
//	}			
	}
	fclose(fileptr);
}
//Ham doc file
int inputFile(Book a[], char fileName[])
{
	FILE *fileptr;
	fileptr = fopen(fileName, "r");
	int i = 0;
	char line[300];

	if (fileptr == NULL)
	{
		printf("File not found!.\n");
	}
	// doc thong tin sach

	//ham fgets se lay mot dong va dat con tro chuot o dau dong tiep theo
	fgets(line, sizeof(line), fileptr);

	while (fscanf(fileptr, "%45s%20s%18s%7s%13s%13d%15d%18d\n", &a[i].TenSach, &a[i].TacGia,
				  &a[i].TheLoai, &a[i].MaSach, &a[i].NhaXuatBan, &a[i].NamXB, &a[i].SoLuong,
				  &a[i].SLNguoiMuon) != EOF)
	{
		if(a[i].SLNguoiMuon>0){	
			for(int j=0;j<a[i].SLNguoiMuon;++j){
				fscanf(fileptr, "%20s%8d%8d%8d%8d%8d%8d%12s\n", &a[i].NguoiMuon[j].TenNguoiMuon, &a[i].NguoiMuon[j].NgayMuon.ngay, &a[i].NguoiMuon[j].NgayMuon.thang, &a[i].NguoiMuon[j].NgayMuon.nam, &a[i].NguoiMuon[j].NgayTra.ngay, &a[i].NguoiMuon[j].NgayTra.thang, &a[i].NguoiMuon[j].NgayTra.nam,&a[i].NguoiMuon[j].TinhTrang);
				if(DateNow(a[i].NguoiMuon[j].NgayTra) == 0)
				strcpy(a[i].NguoiMuon[j].TinhTrang,"Qua han");
				else strcpy(a[i].NguoiMuon[j].TinhTrang," ");
	}
		}
		i++;
	}
	printf("Compare the books available in the file: %d\n", i);
	fclose(fileptr);
	// tra ve so luong sach duoc doc tu file
	return i;
}
//Ham in hoa
void Upper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
}
//Ham in hoa toan bo
void upperAll(char c[])
{
	for (int i = 0; i < strlen(c); ++i)
	{
		Upper(c[i]);
	}
}
//Ham in hoa chu cai dau
void upperFirstLetter(char c[])
{
	Upper(c[0]);
	for (int i = 0; i < strlen(c); ++i)
	{
		if (c[i] == ' ')
		{
			Upper(c[i + 1]);
		}
	}
}
//ham nhap tu khoa
void keyWord(char keyword[])
{
	fflush(stdin);
	gets(keyword);
	upperFirstLetter(keyword);
}
//Nhap Ngay Thang Nam
void inputDate(Date &a)
{
	int dem = 0;
	while (true)
	{
		printf("\tDay: ");
		scanf("%d", &a.ngay);
		printf("\tMonth: ");
		scanf("%d", &a.thang);
		printf("\tYear: ");
		scanf("%d", &a.nam);
		if (a.nam > 1900)
		{
			switch (a.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				if (a.ngay < 1 || a.ngay > 31)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if (a.ngay < 1 || a.ngay > 30)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 2:
			{
				if (a.nam % 4 == 0)
				{
					if (a.ngay < 1 || a.ngay > 29)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
				else
				{
					if (a.ngay < 1 || a.ngay > 28)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
			}
			default:
			{
				dem = 1;
				break;
			}
			}
		}
		else
			dem = 1;
		if (dem == 1)
		{
			printf("\n              >>Can't hop right now!\nPlease join again.\n");
			dem = 0;
		}
		else
			break;
	}
}
//Xuat ngay thang nam
void outputDate(Date a)
{
	printf("%2d/%2d/%4d", a.ngay, a.thang, a.nam);
}
//So sanh ngay muon va ngay tra
int compareDate(Date a, Date b)
{
	if (a.nam > b.nam)
	{
		return 1;
	}
	else if (a.nam == b.nam)
	{
		if (a.thang > b.thang)
		{
			return 1;
		}
		else if (a.thang == b.thang)
		{
			if (a.ngay > b.ngay)
			{
				return 1;
			}
		}
	}
	return 0;
}
//so sanh ngay vua nhap voi ngay hien tai
int DateNow(Date a){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
		if (a.nam > yearNow)
	{
		return 1;
	}
	else if (a.nam == yearNow)
	{
		if (a.thang > monNow)
		{
			return 1;
		}
		else if (a.thang == monNow)
		{
			if (a.ngay > dayNow)
			{
				return 1;
			}
		}
	}
	return 0;
}

//ham ke ngang
void printLine(int n)
{
	if (n == 1)
	{
		printf("\n");
		for(int i=0;i<121;++i){
			if(i==0 || i==4 || i == 12 || i== 58 || i == 79 || i ==98 || i==104 || i ==115 || i == 120)
				printf("|");
			else printf("_");
			//in dau '|' o vi tri i va in '_' o nhung vi tri con lai
		}
	}
	else
	{
		printf("\n");
		for(int i=0;i<105;++i){
			if(i==0 || i == 4 || i == 50 || i == 71 || i== 82 || i== 93 || i == 104)
			printf("|");
			else printf("_");
		}
	}
}
//Muc Luc
void Contents(int n)
{
	if (n == 1)
	{
		printf(" ");
		for (int i = 0; i < 119; i++)
		{
			printf("_");
		}
		printf("\n|%-3s|%-7s|%-45s|%-20s|%-18s|%-5s|%-10s|%-4s|", "STT", "Ma sach", " Ten sach", " Tac gia", " The Type", "Year", " NXB", " SL");
		printLine(n);
	}
	else
	{
		printf(" ");
		for (int i = 0; i < 103; ++i)
		{
			printf("_");
		}
		printf("\n|%-3s|%-45s|%-20s|%-10s|%-10s|%-10s|", "STT", "Ten sach", "Ten nguoi muon", "Ngay muon", "Ngay tra", "Ghi chu");
		printLine(n);
	}
}
//kiem tra ten nguoi muon co bi trung
int CheckHuman(Human a[],int x){
	for(int i=0;i<x;++i){
		if(strcmp((a[i].TenNguoiMuon),(a[x].TenNguoiMuon))==0){
			return 0;
			break;
		}
	}
	return 1;
}
//Ham kiem tra ma sach hoac ten sach bi trung
int Check(Book a[], int n, int x)
{
	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i != x)
			{
				if (strcmp(a[x].MaSach, a[i].MaSach) == 0 || strcmp(a[x].TenSach, a[i].TenSach) == 0)
				{
					return 0;
					break;
				}
			}
		}
	}
	return 1;
}
//ham sap xep
void Sort(Book a[], int n)
{
	int pos;
	Book x;
	for (int i = 1; i < n; ++i)
	{
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (strcmp(a[pos].MaSach, x.MaSach) > 0))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
//ham tim kiem tu khoa
int findString(char str[],char keyword[]){
	char b[100];
	
	if(strstr(strupr(strcpy(b,str)), strupr(keyword)) != NULL){
		return 1;
	}
	return 0;
}
//ham thay the ky tu '_' bang khoang trang
void replace_underscores(char *str)
{
	while (*str)
	{
		if (*str == '_')
			*str = ' ';
		str++;
	}
}
//ham thay the ki tu '_' bang khoang trang cua thong tin trong mang
void replace_string_underscores(Book a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		replace_underscores(a[i].TenSach);
		replace_underscores(a[i].MaSach);
		replace_underscores(a[i].TacGia);
		replace_underscores(a[i].TheLoai);
		replace_underscores(a[i].NhaXuatBan);
		if (a[i].SLNguoiMuon > 0)
		{
			for (int j = 0; j < a[i].SLNguoiMuon; ++j)
			{
				replace_underscores(a[i].NguoiMuon[j].TenNguoiMuon);
			}
		}
	}
}
//ham thay the khoang trong bang dau'_'
void replace_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			*str = '_';
		str++;
	}
}
//nhan phim bat ky de tiep tuc
void pressAnyKey()
{
	printf("\n\n              >>Press any key to continue....");
	fflush(stdin);
	getch();
	system("cls");
}
//nhap thong tin nguoi muon
void Borrower(Human &human)
{
	printf("              >>Enter the borrower's name: ");
	fflush(stdin);
	gets(human.TenNguoiMuon);
	upperFirstLetter(human.TenNguoiMuon);
	do
	{
		printf("              >>Enter borrow date: \n");
		inputDate(human.NgayMuon);
		printf("              >>Enter payment date: \n");
		inputDate(human.NgayTra);
		if (compareDate(human.NgayMuon, human.NgayTra) == 1)
		{
			printf("\n              >>Borrowing and paying right away is not hop le!\nI love you again.\n");
		}
		else{
			if(DateNow(human.NgayTra) == 0){
			strcpy(human.TinhTrang,"Out of date");
		    }
	    	else strcpy(human.TinhTrang," ");
			break;
		}
	} while ((compareDate(human.NgayMuon, human.NgayTra) == 1));
}
//muon sach
void Borrow(Human &a)
{
	if (a.SoLuong == 0)
	{
		printf("\n              >>Not enough quantity to borrow");
	}
	else
	{
		printf("\n              >>Enter 0 to borrow or 1 to skip: ");
		int u;
		scanf("%d", &u);
		switch (u)
		{
		case 0:
			Borrower(a.NguoiMuon[a.SLNguoiMuon]);
			if(CheckHuman(a.NguoiMuon,a.SLNguoiMuon)==1){
			a.SoLuong--;
			a.SLNguoiMuon++;
			}
			else printf("Borrowed books %s . Can't borrow more.",a.NguoiMuon[a.SLNguoiMuon].TenNguoiMuon);
			break;
		case 1:
			q.push(a);
			break;
		default:
			printf("Error ");
			Borrow(a);
			break;
		}
	}
}
//Xuat thong tin nguoi muon
void outputBorrower(Human a, int STT, char tensach[])
{
	printf("\n|%-3d|%-45s|%-20s|", STT, tensach, a.TenNguoiMuon);
	outputDate(a.NgayMuon);
	printf("|");
	outputDate(a.NgayTra);
	printf("|%-10s|",a.TinhTrang);
	printLine(2);
}
//xuat thong tin nguoi muon theo ten sach
void bookBorrower(Book a)
{
	Contents(2);
	for (int i = 0; i < a.SLNguoiMuon; ++i)
	{
		outputBorrower(a.NguoiMuon[i], i + 1, a.TenSach);
	}
}
//xuat danh sach nguoi muon
void listBorrower(Book a[], int n)
{
	int SL = 0;
	for (int i = 0; i < n; ++i)
	{
		SL += a[i].SLNguoiMuon;
	}
	if (SL == 0)
		printf("\n              >>List is empty!\n");
	else
	{
		int dem = 0;
		Contents(2);
		for (int i = 0; i < n; ++i)
		{
			if (a[i].SLNguoiMuon > 0)
			{
				for (int j = 0; j < a[i].SLNguoiMuon; ++j)
				{
					++dem;
					outputBorrower(a[i].NguoiMuon[j], dem, a[i].TenSach);
				}
			}
		}
	}
}
//Tra sach
void returnBook(Book a[], char ten[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < a[i].SLNguoiMuon; ++j)
		{
			if (strcmp(a[i].NguoiMuon[j].TenNguoiMuon, ten) == 0)
			{
				if (dem == 0)
					Contents(2);
					outputBorrower(a[i].NguoiMuon[j], dem + 1, a[i].TenSach);
					++dem;
			}
		}
	}
	if (dem == 0)
		printf("\n              >>The borrower's name could not be found.");
	else
	{
		int x;
		do
		{
			printf("\n              >>Enter the order number of the person who wants to return the book: ");
			scanf("%d", &x);
		} while (x < 1 || x > dem);
		dem=0;
		for (int i = 0; i < n; ++i)
		{ 
            int y=0;
			for (int j = 0; j < a[i].SLNguoiMuon; ++j)
			{
				if (strcmp(a[i].NguoiMuon[j].TenNguoiMuon, ten) == 0)
				{
					if (dem == x - 1)
					{
						for (int k = dem; k < a[i].SLNguoiMuon; k++)
						{
							a[i].NguoiMuon[k] = a[i].NguoiMuon[k + 1];
						}
						--a[i].SLNguoiMuon;
						++a[i].SoLuong;
						++y;
						break;
					}
					++dem;
				}
			}
			if(y==1)
			break;
		}
	}
}
//Menu muon sach
void borrowBook(Book a[], int n)
{
	int x;
	do
	{
		printf("\n               >>Enter 1 to export the list of borrowers.");
		printf("\n               >>Enter 2 to borrow books.");
		printf("\n               >>Enter 3 to return the book.");
		printf("\n               >>Enter 4 to exit.");
		printf("\n\n                    >>Your choice: ");
		scanf("%d", &x);
	} while (x < 1 || x > 4);
	switch (x)
	{
	case 1:
		listBorrower(a, n);
		break;
	case 2:
		int e;
		listBook(a, n);
		do
		{
			printf("\n              >>Enter the number of books to borrow: ");
			scanf("%d", &e);
		} while (e < 1 || e > n + 1);
		Borrow(a[e - 1]);
		break;
	case 3:
		int dem = 0;
		for (int i = 0; i < n; ++i)
		{
			dem += a[i].SLNguoiMuon;
		}
		if (dem > 0)
		{
			char ten[20];
			printf("\n              >>Enter the borrower's name: ");
			keyWord(ten);
			returnBook(a,ten,n);
		}
	}
}
//xoa sach
void Delete(Book a[], int &n)
{
	//Tim kiem phan tu ma ban muon xoa
	int x, dem = 0;
	char s[100];
	do
	{
		printf("\n              >> Enter 1 to find the name of the book");
		printf("\n              >> Enter 2 to search by book id");
		printf("\n              >>Click 3 to close");
		printf("\n           >>Your choice: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1: //Tim ten phan tu muon xoa
		printf("\n              >>Enter the name of the book to delete: ");
		fflush(stdin);
		keyWord(s);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,s) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				int choice;
				do
				{
					printf("\n              >>Enter 0 de delete and 1 de skip:");
					scanf("%d", &choice);
				} while (choice < 0 || choice > 1);
				if (choice == 0)
				{
					if (n > 1)
					{
						for (int j = i; j < n; j++)
							a[j] = a[j + 1];
					}
					--n;
				}
				++dem;
			}
		}
		if (dem == 0)
		{
			printf("\n              >>Delete element is not in the list");
			break;
		}
		printf("\n              >>List has been updated.");
		break;
	case 2: //Tim ma sach can xoa
		printf("\n              >>Enter id the book to delete: ");
		fflush(stdin);
		gets(s);
		upperAll(s);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].MaSach,s) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				int choice;
				do
				{
					printf("\n              >>Enter 0 de delete and 1 de skip:");
					scanf("%d", &choice);
				} while (choice < 0 || choice > 1);
				if (choice == 0)
				{
					if (n > 1)
					{
						for (int j = i; j < n; j++)
							a[j] = a[j + 1];
					}
					--n;
				}
				++dem;
			}
		}
		if (dem == 0)
		{
			printf("\n              >>Delete element is not in the list");
			break;
		}
		printf("\n              >>List has been updated.");
		break;
	case 3:
		break;
	}
}
//Sua thong tin nguoi muon
void UpdateBorrower(Human &human, int e)
{
	switch (e)
	{
	case 1:
	{
		printf("\n              >>Re-enter the borrower's name: ");
		fflush(stdin);
		gets(human.TenNguoiMuon);
		upperFirstLetter(human.TenNguoiMuon);
		break;
	}
	case 2:
	case 3:
	{
		do
		{
			if (e == 2)
			{
				printf("              >>Enter now to borrow: \n");
				inputDate(human.NgayMuon);
			}
			else
			{
				printf("              >>Enter now to pay: \n");
				inputDate(human.NgayTra);
			}
			if (compareDate(human.NgayMuon, human.NgayTra) == 1)
			{
				printf("\n              >>Borrow and pay immediately!\nLove it again.\n");
			}
			else{
				if(DateNow(human.NgayTra) == 0){
			    strcpy(human.TinhTrang,"Out of date");
	        	}
		        else strcpy(human.TinhTrang, "");
				break;
			}
		} while ((compareDate(human.NgayMuon, human.NgayTra) == 1));
	}
	}
}
//tim vi tri nguoi muon can sua
void UpdatelistBorrower(Human human[], int e, int n)
{
	int i;
	do
	{
		printf("              >>Select the location you want to edit: ");
		scanf("%d", &i);
	} while (i <= 0 || i > n);
	UpdateBorrower(human[i - 1], e);
}
//sua thong tin sach
void Update1(Book &a)
{
	//Chon phan thong tin can sua
	int x;
	do
	{
		printf("\n              >> Enter 1 to edit the name");
		printf("\n              >> Enter 2 to edit the author's name");
		printf("\n              >> Enter 3 to edit category");
		printf("\n              >> Enter 4 to edit the book id");
		printf("\n              >> Enter 5 to edit publisher");
		printf("\n              >> Enter 6 to correct publication year");
		printf("\n              >> Enter 7 to correct the quantity");
		printf("\n              >> Enter 8 to edit the borrower");
		printf("\n              >>Enter 9 to skip");
		printf("\n\n          >>Your choice: ");
		scanf("%d", &x);
	} while (x < 1 || x > 9);
	switch (x)
	{
	case 1: //Ten sach
	{
		printf("\n              >>Name after editing is: ");
		keyWord(a.TenSach);
		break;
	}
	case 2: //Tac gia
	{
		printf("\n              >>the author's name after editing is: ");
		keyWord(a.TacGia);
		break;
	}
	case 3: //The loai
	{
		printf("\n              >>category after editing is:");
		keyWord(a.TheLoai);
		break;
	}
	case 4: //Ma sach
	{
		printf("\n              >>the book id after editing is:");
		keyWord(a.MaSach);
		break;
	}
	case 5: //Nha xuat ban
	{
		printf("\n              >>publisher after editing is: ");
		keyWord(a.NhaXuatBan);
		break;
	}
	case 6: //Nam xuat ban
	{
		printf("\n              >>publication year after editing is:");
		scanf("%d", &a.NamXB);
		break;
	}
	case 7: //So luong
	{
		do
		{
			printf("\n              >>the quantity after editing is:");
			fflush(stdin);
			scanf("%d", a.SoLuong);
		} while (a.SoLuong > 0);
		break;
	}
	case 8: // Thong tin nguoi muon
	{
                if(a.SLNguoiMuon==0){
                    printf("\n              >>the borrower after editing is:!");
                    break;
                }
                else{
		//Nhap phan thong tin cua nguoi muon can sua
		bookBorrower(a);
		int e;
		do
		{
			printf("\n              >> Enter 1 to edit the borrower's name:");
		    printf("\n              >> Enter 2 to correct the loan date:");
		    printf("\n              >>Enter 3 to correct the payment date:");
			printf("\n\n              >>Enter the part you want to edit in the user information: ");
			scanf("%d", &e);
		} while (e < 1 || e > 3);
		UpdatelistBorrower(a.NguoiMuon, e, a.SLNguoiMuon);
		break;}
	}
	}
}
//tim kiem sach can sua
void Update(Book a[], int n)
{
	int x;
	char o[100];
	do
	{
		printf("\n              >> Enter 1 to find the name of the book");
		printf("\n              >> Enter 2 to search by book id");
		printf("\n              >> Click 3 to close");
		printf("\n         >> Your choice: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1:
	{
		printf("\nEnter name book: ");
		fflush(stdin);
		keyWord(o);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,o) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				do
				{
					printf("\n");
					Update1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\n              >>Books/Ten books are used! Please re-enter the Master/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\n              >>Information on books after editing:\n");
				Contents(1);
				Output(a[i], i + 1);
			}
		}
		break;
	}
	case 2:
	{
		printf("\n              >>Enter id book: ");
		fflush(stdin);
		keyWord(o);
		upperAll(o);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].MaSach,o) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				do
				{
					printf("\n");
					Update1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\n              >>Books/Ten books are used! Please re-enter the Master/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\n              >>Information on books after editing:\n");
				Contents(1);
				Output(a[i], i + 1);
			}
		}
		break;
	}
	case 3:
		break;
	}
}
//Menu chinh sua sach
void UpdateBook(Book a[], int &n)
{
	int x;
	do
	{
		printf("\n              >> Enter 1 to correct the information in the book ");
		printf("\n              >> Click 2 to clean the book");
		printf("\n              >> Click 3 to close");
		printf("\n\n          >> Your choice: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1:
		Update(a, n);
		break;
	case 2:
		Delete(a, n);
		break;
	default:
		break;
	}
}
//Nhap thong tin sach
void Input(Book &a)
{
	a.SLNguoiMuon = 0;
	printf("              >>Enter the book id: ");
	keyWord(a.MaSach);
	upperAll(a.MaSach);
	printf("              >>Enter the name of the book: ");
	keyWord(a.TenSach);
	printf("              >>Enter the author's name: ");
	keyWord(a.TacGia);
	printf("              >>Enter category: ");
	keyWord(a.TheLoai);
	printf("              >>Enter year of publication: ");
	scanf("%d", &a.NamXB);
	printf("              >>Enter publisher name: ");
	keyWord(a.NhaXuatBan);
	do
	{
		printf("              >>Enter existing quantity: ");
		scanf("%d", &a.SoLuong);
		if (a.SoLuong < 1)
		{
			printf("              >>Invalid number, please re-enter.\n");
		}
	} while (a.SoLuong < 1);
}
//Them Sach
void addBook(Book a[], int &SoSach)
{
	int n, add;
	n = SoSach;
	printf("              >>Enter the number of books you want to add: ");
	scanf("%d", &add);
	SoSach = n + add;
	for (int i = n; i < SoSach; i++)
	{
		do
		{
			printf("\n\n              >>Enter book information%d\n", i + 1);
			Input(a[i]);
			if (Check(a, SoSach, i) == 0)
			{
				printf("              >>Books/Ten books are used! Please come back again.");
			}
		} while (Check(a, SoSach, i) == 0);
	}
}
//ham tim kiem
Book Search(Book a[], int n)
{
	char keyword[100];
	char b[100] = "";
	int dem = 0;
	printf("\n                     Enter 1 to search by book.");
	printf("\n                     Enter 2 to search by category.");
	printf("\n                     Enter 3 to search by author.");
	printf("\n                     Enter 4 to search by publisher.");
	printf("\n                     Enter 5 to skip.\n");
	int x;
	printf("\n                 >>Please choose: ");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		printf("\n                 >>Enter your search term: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,keyword) == 1)
			{
				dem++;
				Contents(1);
				Output(a[i], 1);
				printf("\n");
			}
		}
		if (dem == 0)
			printf("\n                 Keyword not found.");
		break;
	case 2:
		printf("\n                 >>Enter your search term: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TheLoai,keyword) == 1)
			{
				dem++;
				Contents(1);
				Output(a[i], 1);
				printf("\n");
			}
		}
		if (dem == 0)
			printf("\n                 Keyword not found.");
		break;
	case 3:
		printf("\n                 >>Enter your search term: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TacGia,keyword) == 1)
			{
				++dem;
				Contents(1);
				Output(a[i], dem);
			}
		}
		if (dem == 0)
			printf("\n                 Keyword not found.");
		break;
	case 4:
		printf("\n                 >>Enter your search term: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].NhaXuatBan,keyword) == 1)
			{
				++dem;
				Contents(1);
				Output(a[i], dem);
			}
		}
		if (dem == 0)
			printf("\n                 Keyword not found.");
		break;
	case 5:
		break;
	default:
		printf("\n                 Error!");
		break;
	}
}
//Xuat thong tin Sach
void Output(Book a, int n)
{
	upperAll(a.MaSach);
	printf("\n|%-3d|%-7s|%-45s|%-20s|%-18s|%-5d|%-10s|%-4d|", n, a.MaSach, a.TenSach, a.TacGia, a.TheLoai, a.NamXB, a.NhaXuatBan, a.SoLuong);
	printLine(1);
}
//xuat DS sach
void listBook(Book a[], int n)
{
	Contents(1);
	for (int i = 0; i < n; i++)
	{
		Output(a[i], i + 1);
	}
}
//Ham main book
void bookMain()
{
	/*luu y: chi can nhap thong tin thi file se tu dong tao o o dia D voi ten la quanLiThuVien
			 hoac co the tu tao file va thay doi dia chi o fileName	 */
	char fileName[] = "users.txt";
	Book a[50];
	int soLuongSach = inputFile(a, fileName);
	char choice;
	replace_string_underscores(a, soLuongSach);
	do
	{
		SET_COLOR(14);
cout<<"                 .____     .__ ___.                                       ________         .__       .___" << endl;
cout<<"                 |    |    |__|\\_ |__ _______ _____  _______  ___.__.    /  _____/   ____  |  |    __| _/" << endl;
cout<<"                 |    |    |  | | __ \\\\_  __ \\\\__  \\ \\_  __ \\<   |  |   /   \\  ___  /  _ \\ |  |   / __ | " << endl;
cout<<"                 |    |___ |  | | \\_\\ \\|  | \\/ / __ \\_|  | \\/ \\___  |   \\    \\_\\  \\(  <_> )|  |__/ /_/ | " << endl;
cout<<"                 |_______ \\|__| |___  /|__|   (____  /|__|    / ____|    \\______  / \\____/ |____/\\____ | " << endl;
cout<<"                         \\/         \\/             \\/         \\/                \\/                    \\/ " << endl;
cout<<""<<endl;
SET_COLOR(6);                                  
		printf("                                   _-------------------------_ _------------------------_\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | | 1/ Add book             | 2/Export list          | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | | 3/ Borrow books         | 4/Record files         | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | | 5/ Search book          | 6/Edit book            | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | |                         |                        | |\n");
		printf("                                  | | 0/ Exit                 |                        | |\n");
		printf("                                  | |_-----------------------_^_----------------------_| |\n");
		printf("                                  |_-------------------------_|_------------------------_|\n");
		printf("\n\n              >>Please enter options: ");
		fflush(stdin);
		scanf("%c", &choice);
		fflush(stdin);
		switch (choice)
		{
		case '1':
			addBook(a, soLuongSach);
			pressAnyKey();
			break;
		case '2':
			if (soLuongSach <= 0)
			{
				printf("\n              >>No information available, please enter information.");
			}
			else
			{
				Sort(a, soLuongSach);
				listBook(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '3':
			if (soLuongSach <= 0)
			{
				printf("\n              >>No information available, please enter information.");
			}
			else
			{
				borrowBook(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '4':
			if (soLuongSach <= 0)
			{
				printf("\n              >>No information available, please enter information.");
			}
			else
			{
				outPutFile(a, fileName, soLuongSach);
			}
			printf("\nWrite information to file %s successfully!", fileName);
			pressAnyKey();
			break;
		case '5':
			if (soLuongSach <= 0)
		
			{
				printf("\n              >>No information available, please enter information.");
			}
			else
			{
				Search(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '6':
			if (soLuongSach <= 0)
			{
				printf("\n              >>No information available, please enter information.");
			}
			else
			{
				UpdateBook(a, soLuongSach);
			}
			pressAnyKey();
			break;

		
		default:
			printf("\n              >>Entered incorrectly, please re-enter........\n");
			pressAnyKey();
			break;
		case '0':
			system("cls");
			Lib libObj;
			libObj.librarian();
			break;
		}
	} while (choice != '0');
}




