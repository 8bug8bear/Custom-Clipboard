// MyClipboard.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <string>
#include <fstream>



void AddTextinClicbord(const std::string& s)
{
	if (OpenClipboard(0))
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		EmptyClipboard();
		HGLOBAL hg = GlobalAlloc(GMEM_FIXED, s.size() + 1);
		memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
		SetClipboardData(CF_TEXT, hg);
		CloseClipboard();
	}
}

void Waiting()
{
	//waits until the key is on pressed
	while (GetKeyState('V') == 0 || GetKeyState('V') == 1)
	{

	}

	//waits until the key is pressed
	while (GetKeyState('V') < 0)
	{
		Sleep(40);

	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string number;
	std::string text;

	std::cout << "Введите путь к файлу" << std::endl;

	std::string fileName;
	getline(std::cin,fileName);
	std::ifstream file;
	file.open(fileName);


	if (!file)
	{
		std::cout << "Файл не найден\n\n";
		return -1;
	}
	else
	{
		std::cout << "Файл открыт!"<<std::endl;
		std::cout << "Введите текст сообщения" << std::endl;
		_flushall();
		getline(std::cin, text);
		system("cls");
		while (std::getline(file, number))
		{
			//Add nymber
			AddTextinClicbord(number);
			std::cout << number;

			Waiting();

			//clear console
			system("cls");

			//add textBymyProgramm
			AddTextinClicbord(text);
			std::cout << text;

			Waiting();

			//clear console
			system("cls");
		}
		
	}
	return 0;
}

