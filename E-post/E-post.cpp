#include "pch.h"
#include <iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

class admin
{
public:
	void delay()
	{
		std::cout << "redirecting to exit";
		for (int l = 0; l < 3; l++)
		{
			std::cout << ".";
			for (int j = 0; j < 500; j++)
			{
				for (int k = 0; k < 999999; k++)
				{
					//this is a delay
				}
			}
		}
	}

	void pcheck()
	{
		std::ifstream fout;
		fout.open("password.txt");
		int a, b;
		std::cout << "enter password - ";
		std::cin >> b;
		fout >> a;
		fout.close();
		if (a == b)
		{
			std::cout << "password matched!\n";
		}
		if (a != b)
		{
			std::cout << "incorrect password\n";
			delay();
			exit(0);
		}
	}
	void acover(int i = 0)
	{
		pcheck();
		int adc;
		std::cout << "CHOOSE OPTIONS FOR ADMIN\n";
		std::cout << "1.CHANGE TYPES OF SERVICES AVAILABLE\n2.CHANGE TYPES OF STAMPS AVAILABLE\n3.CHANGE PRICE OF STAMPS\n4.CHANGE PRICE OF SERVICES\n5.CHANGE PASSWORD\n6.SEARCH RECORDS\n7.EXIT\n";
		std::cin >> adc;
		switch (adc)
		{
		case 1:adf1(); break;
		case 2:adf2(); break;
		case 3:adf3(); break;
		case 4:adf4(); break;
		case 5:adf5(); break;
		case 7:exit(0); break;
		case 6:adf6(); break;
		default:std::cout << "INVALID OPTION\n"; break;
		}
	}

	void adf1()
	{
		std::cout << "\n1.delete service\n2.add service\n3.rename service\n4.main admin menu\nenter the serial no of the choice - ";
		int ch;
		std::cin >> ch;
		if (ch == 1)            //deleting a type of service
		{
			std::ifstream fout;
			fout.open("typesofservices.txt");
			std::cout << "\ntypes of services available\n";
			int i = 0, b;
			fout >> b;
			char a[30];
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				std::cout << i << ".";
				fout.getline(a, 30, '/');
				std::puts(a);

			}
			fout.close();
			std::cout << "\nenter the serial no of the service you want to delete - ";
			int s;
			i = 0;
			std::ifstream fo;
			std::ofstream fi;
			std::ifstream foo;
			std::ofstream fii;
			std::ofstream ft;
			fi.open("tempo.txt");
			fo.open("priceofservices.txt");
			fii.open("tempoo.txt");
			foo.open("sb.txt");
			char t[10];
			std::cin >> s;
			char f[4];
			ft.open("temp.txt");
			fout.open("typesofservices.txt");
			if (s > 0 && s <= b)
			{
				fout >> b;
				b = b - 1;
				ft << b;
				while (fout)           //deleting operation creates a temp file 
				{                      //inputs the data except the deleted one and renames it to the original text file
					i = i + 1;
					if (i == b + 1)
					{
						fo.getline(f, 4, '/');
						fi << f;
						foo.getline(t, 10, '/');
						fii << t;
						fout.getline(a, 30, '/');
						ft << a;
						break;
					}
					if (i == s)
					{
						foo.getline(t, 10, '/');
						fo.getline(f, 4, '/');
						fout.getline(a, 30, '/');
						continue;
					}
					fo.getline(f, 4, '/');
					fi << f << "/";
					fout.getline(a, 30, '/');
					ft << a << "/";
					foo.getline(t, 10, '/');
					fii << t << "/";
				}
				std::cout << "the selected service is deleted\n";
			}
			else
				std::cout << "invalid input";

			fi.close();
			fo.close();
			ft.close();
			fii.close();
			foo.close();
			fout.close();

			remove("sb.txt");
			rename("tempoo.txt", "sb.txt");
			remove("priceofservices.txt");
			rename("tempo.txt", "priceofservices.txt");
			remove("typesofservices.txt");
			rename("temp.txt", "typesofservices.txt");
			delay();
		}
		if (ch == 2)         //adding a service
		{
			int i = 0;
			char a[30];
			std::cout << "enter the name of the service - ";
			std::cin.ignore();
			std::cin.getline(a, 30);
			std::cout << "enter the pricing of the service -";
			int p;
			std::cin >> p;
			std::ofstream fout;
			fout.open("typesofservices.txt", std::ios::app);
			fout << "/" << a;
			fout.close();
			fout.open("priceofservices.txt", std::ios::app);
			fout << "/" << p;
			fout.close();
			std::ifstream fi;
			std::ofstream ft;
			ft.open("temp.txt");
			fi.open("typesofservices.txt");
			fi >> p;
			p = p + 1;
			ft << p;
			while (fi)           //updating the number in the starting of the file 
			{
				i = i + 1;
				if (i == p)
				{
					fi.getline(a, 30, '/');
					ft << a;
					break;
				}
				fi.getline(a, 30, '/');
				ft << a << "/";
			}
			fi.close();
			ft.close();
			std::ofstream v;
			v.open("sb.txt", std::ios::app);
			std::cout << "enter the criteria thats supposed to be inside the service\nrecievers address is a compulsory criteria for all\ndo you want to add senders address, enter y for yes and n for no- ";
			char z;
			int k;
			std::cin >> z;
			std::ifstream f;
			ft.open("n.txt");
			f.open("n.txt");
			f >> k;
			f.close();
			ft << k + 1;
			ft.close();
			v << "/" << k + 1 << "x1";
			if (z == 'y' || z == 'Y')
			{
				v << "1";
			}
			else
				v << "0";
			std::cout << "content/note is also a compulsary criteria\ndo you want to add the money criteria, if yes type and if no then type n - ";
			std::cin >> z;
			v << "1";
			if (z == 'y' || z == 'Y')
			{
				v << "1";
			}
			else
				v << "0";
			std::cout << "do you want to add the info on luggage criteria, if yes type and if no then type n - ";
			std::cin >> z;
			if (z == 'y' || z == 'Y')
			{
				v << "1";
			}
			else
				v << "0";
			std::cout << "do you want to add flowers with delivery criteria, if yes type and if no then type n - ";
			std::cin >> z;
			if (z == 'y' || z == 'Y')
			{
				v << "1";
			}
			else
				v << "0";
			std::cout << "do you want to add music with delivery criteria, if yes type and if no then type n - ";
			std::cin >> z;
			if (z == 'y' || z == 'Y')
			{
				v << "1";
			}
			else
				v << "0";
			v.close();

			remove("typesofservices.txt");
			rename("temp.txt", "typesofservices.txt");
			delay();
		}
		if (ch == 3)
		{
			std::ifstream fout;
			fout.open("typesofservices.txt");
			std::cout << "types of services available\n";
			int i = 0, b;
			fout >> b;
			char a[30];
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				std::cout << i << ".";
				fout.getline(a, 30, '/');
				std::puts(a);

			}
			fout.close();
			std::cout << "\nenter the serial no of the service you want to replace - ";
			int s;
			i = 0;
			std::ofstream ft;
			std::cin >> s;
			char f[30];
			std::cout << "enter the replacing text - ";
			std::cin.ignore();
			std::cin.getline(f, 30);
			ft.open("temp.txt");
			fout.open("typesofservices.txt");
			if (s > 0 && s <= b)
			{
				fout >> b;
				ft << b;
				while (fout)           //replacing operation creates a temp file 
				{                      //inputs the data except the deleted one and renames it to the original text file
					i = i + 1;
					if (i == b + 1)
					{
						fout.getline(a, 30, '/');
						ft << a;
						break;
					}
					if (i == s)
					{
						if (s == b + 1)
						{
							fout.getline(a, 30, '/');
							ft << a;
							continue;
						}
						fout.getline(a, 30, '/');
						ft << f << "/";
						continue;
					}
					fout.getline(a, 30, '/');
					ft << a << "/";
				}
				std::cout << "the selected service is replaced with another name\n";
			}
			else
				std::cout << "invalid input";

			ft.close();
			fout.close();
			remove("typesofservices.txt");
			rename("temp.txt", "typesofservices.txt");
			std::cout << "\nthe service has been added!\n";
			delay();
		}
		if (ch == 4)
			acover();
		if (ch > 5 || ch < 1)
		{
			exit(0);
		}
	}

	void adf2()
	{
		std::cout << "\n1.delete stamps\n2.add a stamp\n3.rename stamp\n4.main admin menu\nenter the serial no of the choice - ";
		int ch;
		std::cin >> ch;
		if (ch == 1)            //deleting a type of stamp
		{
			std::ifstream fout;
			fout.open("typesofstamps.txt");
			std::cout << "types of stamps available\n";
			int i = 0, b;
			fout >> b;
			char a[30];
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				std::cout << i << ".";
				fout.getline(a, 30, '/');
				std::puts(a);

			}
			fout.close();
			std::cout << "\nenter the serial no of the stamp you want to delete - ";
			int s;
			i = 0;
			std::ifstream fo;
			std::ofstream fi;
			std::ofstream ft;
			fi.open("tempo.txt");
			fo.open("priceofstamps.txt");
			std::cin >> s;
			char f[4];
			ft.open("temp.txt");
			fout.open("typesofstamps.txt");
			if (s > 0 && s <= b)
			{
				fout >> b;
				b = b - 1;
				ft << b;
				while (fout)           //deleting operation creates a temp file 
				{                      //inputs the data except the deleted one and renames it to the original text file
					i = i + 1;
					if (i == b + 1)
					{
						fo.getline(f, 4, '/');
						fi << f;
						fout.getline(a, 30, '/');
						ft << a;
						break;
					}
					if (i == s)
					{
						fo.getline(f, 4, '/');
						fout.getline(a, 30, '/');
						continue;
					}
					fo.getline(f, 4, '/');
					fi << f << "/";
					fout.getline(a, 30, '/');
					ft << a << "/";
				}
				std::cout << "the selected stamp is deleted\n";
			}
			else
				std::cout << "invalid input";

			fi.close();
			fo.close();
			ft.close();
			fout.close();
			remove("priceofstamps.txt");
			rename("tempo.txt", "priceofstamps.txt");
			remove("typesofstamps.txt");
			rename("temp.txt", "typesofstamps.txt");
			delay();
		}
		if (ch == 2)         //adding a service
		{
			int i = 0;
			char a[30];
			std::cout << "enter the name of the stamp - ";
			std::cin.ignore();
			std::cin.getline(a, 30);
			std::cout << "enter the pricing of the stamp -";
			int p;
			std::cin >> p;
			std::ofstream fout;
			fout.open("typesofstamps.txt", std::ios::app);
			fout << "/" << a;
			fout.close();
			fout.open("priceofstamps.txt", std::ios::app);
			fout << "/" << p;
			fout.close();
			std::ifstream fi;
			std::ofstream ft;
			ft.open("temp.txt");
			fi.open("typesofstamps.txt");
			fi >> p;
			p = p + 1;
			ft << p;
			while (fi)           //updating the number in the starting of the file 
			{
				i = i + 1;
				if (i == p)
				{
					fi.getline(a, 30, '/');
					ft << a;
					break;
				}
				fi.getline(a, 30, '/');
				ft << a << "/";
			}
			fi.close();
			ft.close();
			remove("typesofstamps.txt");
			rename("temp.txt", "typesofstamps.txt");

			delay();
		}
		if (ch == 3)
		{
			std::ifstream fout;
			fout.open("typesofstamps.txt");
			std::cout << "types of stamps available\n";
			int i = 0, b;
			fout >> b;
			char a[30];
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				std::cout << i << ".";
				fout.getline(a, 30, '/');
				std::puts(a);

			}
			fout.close();
			std::cout << "\nenter the serial no of the stamp you want to replace - ";
			int s;
			i = 0;
			std::ofstream ft;
			std::cin >> s;
			char f[30];
			std::cout << "enter the replacing text - ";
			std::cin.ignore();
			std::cin.getline(f, 30);
			ft.open("temp.txt");
			fout.open("typesofstamps.txt");
			if (s > 0 && s <= b)
			{
				fout >> b;
				ft << b;
				while (fout)           //replacing operation creates a temp file 
				{                      //inputs the data except the deleted one and renames it to the original text file
					i = i + 1;
					if (i == b + 1)
					{
						fout.getline(a, 30, '/');
						ft << a;
						break;
					}
					if (i == s)
					{
						if (s == b + 1)
						{
							fout.getline(a, 30, '/');
							ft << a;
							continue;
						}
						fout.getline(a, 30, '/');
						ft << f << "/";
						continue;
					}
					fout.getline(a, 30, '/');
					ft << a << "/";
				}
				std::cout << "the selected stamp is replaced with another name\n";
			}
			else
				std::cout << "invalid input";

			ft.close();
			fout.close();
			remove("typesofstamps.txt");
			rename("temp.txt", "typesofstamps.txt");
			std::cout << "\nthe stamp has been added!\n";
			delay();
		}
		if (ch == 4)
			acover();
		if (ch > 5 || ch < 1)
		{
			exit(0);
		}
	}
	void adf3()
	{
		std::ifstream fout;
		std::ifstream fo;
		fo.open("priceofstamps.txt");
		fout.open("typesofstamps.txt");
		std::cout << "types of stamps available\n";
		int i = 0, b;
		fout >> b;
		char a[30], m[4], s[4];
		while (fout)        //shows the menu by reaading from the file
		{
			if (i == b)
				break;
			i = i + 1;
			std::cout << i << ".";
			fout.getline(a, 30, '/');
			fo.getline(s, 4, '/');
			std::puts(a);
			std::cout << "     rs - ";
			std::puts(s);
		}
		fo.close();
		fout.close();
		int v;
		std::cout << "enter the serial number of stamp you want to change the price of - ";
		std::cin >> v;
		std::cout << "enter the new price - ";
		std::cin.ignore();
		std::cin.getline(m, 4);
		std::ofstream fi;
		fo.open("typesofstamps");
		fo >> b;
		fout.open("priceofstamps.txt");
		fi.open("temp.txt");
		i = 0;
		while (fout)           //deleting operation creates a temp file 
		{                      //inputs the data except the deleted one and renames it to the original text file
			i = i + 1;
			if (i == b + 1)
			{
				fout.getline(s, 4, '/');
				fi << s;
				break;
			}
			if (i == v)
			{
				if (v == b)
				{
					fout.getline(s, 4, '/');
					fi << m;
					continue;
				}
				fout.getline(s, 4, '/');
				fi << m << "/";
				continue;
			}
			fout.getline(s, 4, '/');
			fi << s << "/";
		}
		fi.close();
		fout.close();
		fo.close();
		remove("priceofstamps.txt");
		rename("temp.txt", "priceofstamps.txt");
		std::cout << "\nthe price of stamp has been changed!\n";
		delay();
	}
	void adf4()
	{
		std::ifstream fout;
		std::ifstream fo;
		fo.open("priceofservices.txt");
		fout.open("typesofservices.txt");
		std::cout << "types of services available\n";
		int i = 0, b;
		fout >> b;
		char a[30], m[4], s[4];
		while (fout)        //shows the menu by reaading from the file
		{
			if (i == b)
				break;
			i = i + 1;
			std::cout << i << ".";
			fout.getline(a, 30, '/');
			fo.getline(s, 4, '/');
			std::puts(a);
			std::cout << "     rs - ";
			std::puts(s);
		}
		fo.close();
		fout.close();
		int v;
		std::cout << "enter the serial number of service you want to change the price of - ";
		std::cin >> v;
		std::cout << "enter the new price - ";
		std::cin.ignore();
		std::cin.getline(m, 4);
		std::ofstream fi;
		fo.open("typesofservices");
		fo >> b;
		fout.open("priceofservices.txt");
		fi.open("temp.txt");
		i = 0;
		while (fout)           //deleting operation creates a temp file 
		{                      //inputs the data except the deleted one and renames it to the original text file
			i = i + 1;
			if (i == b + 1)
			{
				fout.getline(s, 4, '/');
				fi << s;
				break;
			}
			if (i == v)
			{
				if (v == b)
				{
					fout.getline(s, 4, '/');
					fi << m;
					continue;
				}
				fout.getline(s, 4, '/');
				fi << m << "/";
				continue;
			}
			fout.getline(s, 4, '/');
			fi << s << "/";
		}
		fi.close();
		fout.close();
		fo.close();
		remove("priceofservices.txt");
		rename("temp.txt", "priceofservices.txt");
		std::cout << "\nthe price of service has been changed!\n";
		delay();
	}
	void adf5()
	{
		int a;
		std::ofstream fout;
		fout.open("password.txt");
		std::cout << "enter the new password";
		std::cin >> a;
		fout << a;
		std::cout << "password changed!";
		fout.close();
		delay();
	}
	void adf6()
	{
		//Searching records code
		std::ifstream fout;
		fout.open("typesofservices.txt");
		std::cout << "types of services available\n";
		int i = 0, b, m;
		fout >> b;
		char z[9], a[30], zz;
		while (fout)        //shows the menu by reaading from the file
		{
			if (i == b)
				break;
			i = i + 1;
			std::cout << i << ".";
			fout.getline(a, 30, '/');
			std::puts(a);
		}
		fout.close();
		std::cout << "enter the serial number of the service records you want to see - ";
		std::cin >> m;
		fout.open("sb.txt");
		i = 0;
		while (fout)
		{
			i=i + 1;
			fout >> b;
			fout.getline(z, 9, '/');
			if (i == m)
			{
				break;
			}
		}
		std::cout << b;
		fout.close();
		std::cout << b;
		char c[700];
		fout.open("records.txt");
		while (fout)
		{
			fout >> m;
			fout >> zz;
			if (m == b && zz == 'x')
			{
				if (z[1] == '1')
				{
					std::cout << "recievers address - ";
					fout.getline(c, 100,'.');
					std::puts(c);
				}
				if (z[2] == '1')
				{
					std::cout << "senders address - ";
					fout.getline(c, 100,'.');
					std::puts(c);
				}
				if (z[3] == '1')
				{
					std::cout << "the note/content - ";
					fout.getline(c, 700,'.');
					std::puts(c);
				}
				if (z[4] == '1')
				{
					std::cout << "the amount of money (not more than 400000) - ";
					fout.getline(c, 6, '.');
					std::puts(c);
				}
				if (z[5] == '1')
				{
					std::cout << "the info on luggage - ";
					fout.getline(c, 50, '.');
					std::puts(c);
				}
				if (z[6] == '1')
				{
					std::cout << "the types of flower - ";
					fout.getline(c, 20, '.');
					std::puts(c);
				}
				if (z[7] == '1')
				{
					std::cout << "the title of music you want - ";
					fout.getline(c, 30, '/');
					std::puts(c);
				}
				std::cout << "press 1 for the next or 0 to stop -";
				int n;
				std::cin >> n;
				if (n == 0)
					break;
			}
			else
				fout.getline(c, 700, '.');
		}
		fout.close();
		delay();
	}
};

class customer
{
	int adc;
public:
	float price, sprice, tprice;
	void ccover()
	{
		std::cout << "Welcome to Epost\n";
		std::ifstream fout;
		std::ifstream fo;
		fo.open("priceofservices.txt");
		fout.open("typesofservices.txt");
		std::cout << "types of services available\n";
		int i = 0, b;
		fout >> b;
		float v;
		char a[30],l;
		while (fout)        //shows the menu by reaading from the file
		{
			if (i == b)
				break;
			i = i + 1;
			std::cout << i << ".";
			fout.getline(a, 30, '/');
			fo >> v;
			std::puts(a);
			std::cout << "     rs - ";
			std::cout<<v << "\n";
			fo >> l;
		}
		fo.close();
		fout.close();
		std::cout << "\nenter 100 to exit.\nPlease enter the serial number of the service you would like to avail - ";
		std::cin >> adc;
		fo.open("priceofservices.txt");
		fout.open("typesofservices.txt");
		fout >> b;
		i = 0;
		while (fout)        //shows the menu by reaading from the file
		{
			if (i == b)
				break;
			i = i + 1;
			if (adc == i)
			{
				fout.getline(a, 30, '/');
				fo >> v;
				fo >> l;
				sprice = v;
				break;
			}
			fout.getline(a, 30, '/');
			fo >> v;
			fo >> l;
		}
		fo.close();
		fout.close();
		if (adc > 0 && adc <= b)
		{
			fo.open("priceofstamps.txt");
			fout.open("typesofstamps.txt");
			std::cout << "types of stamps available\n";
			i = 0;
			fout >> b;
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				std::cout << i << ".";
				fout.getline(a, 30, '/');
				fo >> v;
				std::puts(a);
				std::cout << "     rs - ";
				std::cout << v << "\n";
				fo >> l;
			}
			fo.close();
			fout.close();
			int adcc;
			std::cout << "enter the serial number of the stamp you want to choose - ";
			std::cin >> adcc;
			i = 0;
			fo.open("priceofstamps.txt");
			fout.open("typesofstamps.txt");
			fout >> b;
			while (fout)        //shows the menu by reaading from the file
			{
				if (i == b)
					break;
				i = i + 1;
				if (adcc == i)
				{
					fout.getline(a, 30, '/');
					fo >> v;
					fo >> l;
					tprice = v;
					break;
				}
				fout.getline(a, 30, '/');
				fo >> v;
				fo >> l;
			}
			fo.close();
			fout.close();
			custofunc();		
		}
		else if (adc == 100)
			exit(0);
		else
			std::cout << "INVALID OPTION\n";

	}


	void delay()
	{
		std::cout << "redirecting to exit";
		for (int l = 0; l < 3; l++)
		{
			std::cout << ".";
			for (int j = 0; j < 500; j++)
			{
				for (int k = 0; k < 999999; k++)
				{
					//this is a delay
				}
			}
		}
	}

	void custofunc()
	{
		std::ifstream lo;
		std::ifstream ft;
		std::ofstream yo;
		std::ifstream fin;
		lo.open("typesofservices.txt");
		fin.open("sb.txt");
		ft.open("norecords.txt");
		yo.open("temp.txt");
		char  c[700];
		std::ofstream fout;
		fout.open("records.txt", std::ios::app);

		int x, y, j, i = 0;
		lo >> j;
		lo.close();
		char a;
		while (fin)
		{
			i = i + 1;
			fin >> x;
			if (i == adc)
				fout << x;
			fin >> a;
			if (i == adc)
				fout << a;
			if (i == j + 1)
				break;
			ft >> y;
			std::cout << y;
			if (i == adc && i==4)
				yo << y + 1;
			else if (i == adc && i != 4)
				yo << y + 1 << "/";
			else if (i == 4)
				yo << y;
			else
				yo << y << "/";
			if (i == adc)
				fout << y + 1 << "/";
			ft >> a;
			std::cout << a;
			fin >> a;
			if(a == '1' && i == adc)
			{
				std::cout << "enter recievers address - ";
				std::cin.ignore();
				std::cin.getline(c, 100);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter senders address - ";
				std::cin.ignore();
				std::cin.getline(c, 100);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter the note/content - ";
				std::cin.ignore();
				std::cin.getline(c, 700);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter the amount of money (not more than 400000) - ";
				std::cin.ignore();
				std::cin.getline(c, 6);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter the info on luggage - ";
				std::cin.ignore();
				std::cin.getline(c, 50);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter the types of flower ( rose, lilly etc. )- ";
				std::cin.ignore();
				std::cin.getline(c, 20);
				fout << c << ".";
			}
			fin >> a;
			if (a == '1' && i == adc)
			{
				std::cout << "enter the title of music you want (eg. september song by JP Cooper etc.) - ";
				std::cin.ignore();
				std::cin.getline(c, 30);
				fout << c << ".";
			}
			if (i == adc)
				fout << "/";
			fin >> a;
		}
		yo.close();
		fout.close();
		fin.close();
		ft.close();
		remove("norecords.txt");
		rename("temp.txt", "norecords.txt");
		price = sprice + tprice;
		std::cout << "total expense of the service availed is - " << price<<"\n";
		delay();
	}

	void help()
	{

	}
};

class base :public admin
{
public:

	void FAQ()
	{}

	void feedback()
	{}

	void cover()
	{
		admin o;
		customer oo;		int a;
		std::cout << "               *******        ******  ******  *******  *********\n";
		std::cout << "               *              *    *  *    *  *            *\n";
		std::cout << "               *******  ***** ******  *    *  *******      *\n";
		std::cout << "               *              *       *    *        *      *\n";
		std::cout << "               *******        *       ******  *******      *\n";
		std::cout << "               *************************************************\n MADE BY :VIKRANT ATTRI\n";
		std::ifstream fout;
		fout.open("password.txt");
		if (!fout)
		{
			std::cout << "The program is running for the 1st time please configure it,\nall the other features would be the default ones\nset the password";
			int a;
			std::ofstream fo;
			fo.open("password.txt");
			std::cout << "\nenter the password - ";
			std::cin >> a;
			fo << a;
			std::cout << "\npassword is set up!";
			fo.close();
			defa();
		}
		fout.close();
		std::cout << "\n                                menu\nenter the serial number of the choice you want\n1.administrator\n2.customer\n3.FAQ\n4.feedback\nenter your choice - ";
		std::cin >> a;
		switch (a)
		{
		case 1:o.acover(); break;

		case 2:oo.ccover(); break;

		default:std::cout << "invalid choice\ntry again"; break;
		}
	}

	void defa()
	{
		std::ofstream fout;
		fout.open("typesofservices.txt");
		fout << "4LETTER/SPEED POST/DRAFT/COURIER";
		fout.close();
		fout.open("priceofservices.txt");
		fout << "50/100/200/300";
		fout.close();
		fout.open("typesofstamps.txt");
		fout << "4Scinde Dawk/Double Headed Anna/Mahatma Gandhi Stamp/Standard Stamp";
		fout.close();
		fout.open("priceofstamps.txt");
		fout << "20/100/150/10";
		fout.close();
		fout.open("sb.txt");
		fout << "1x1010000/2x1010000/3x1111000/4x1110100";
		fout.close();
		fout.open("norecords.txt");
		fout << "0/0/0/0";
		fout.close();
		fout.open("n.txt");
		fout << "4";
		fout.close();
	}
};

int main()
{
	base o;
	o.cover();
	return 0;
}
