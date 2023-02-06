#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <cstdio> 
#include <windows.h>
#include <omp.h>

using namespace std;
using std::string;

string gener() {
	string s = "Генерация отчётов";
	//Sleep(150);
	return s;
}
//using std::cout;

//47 2329          32 2310

void imagepatcher(int x, int y, string name, cv::Mat bigImage, cv::Mat destRoi)
{
	const cv::Mat smallImageobject = cv::imread(name, -1);
	
	destRoi = bigImage(cv::Rect(x, y, smallImageobject.cols, smallImageobject.rows));
	
	smallImageobject.copyTo(destRoi);
}

void params(string waylog, int waycount) {

	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	char buff[100];
	strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

	srand(ts.tv_nsec); // автоматическая рандомизация

	int wayindex = 1 + rand() % waycount;

	int indxf = 0 + rand() % 9; double indxftransf = (double)indxf / 100;

	int indseconds1 = 0 + rand() % 9, indseconds2 = 0 + rand() % 5;

	srand(ts.tv_nsec);

	int n = 150 + rand() % 350;

	//Sleep(n);




	// Подсчёт времени

	double time = ((((double)indseconds2 * 10) + (double)indseconds1) / 3600) + (29.0 / 60.0); // Выражение общего времени в часах

	double kilometraj = 5 + (indxftransf); // Подсчёт длины пути
	double tempfull = (time / kilometraj) * 60; // Выражение темпа в минутах

	int minutesfulled = (int)(tempfull); // Целых минут
	int secondsfulled = (int)((tempfull - minutesfulled) * 60); // Целых секунд;

	// Получаем разделённые значения десятков и единиц минут и секунд
	int minutesdecimal = ((minutesfulled - (minutesfulled % 10)) / 10), minutesones = (minutesfulled % 10);
	int secondsdecimal = ((secondsfulled - (secondsfulled % 10)) / 10), secondsones = (secondsfulled % 10);


	// Вывод записей по расчёту темпа

	//cout << "indxftransf = " << indxftransf << endl;
	//cout << "kilometraj = " << kilometraj << endl;
	//cout << "Time separate = " << "29' " << indseconds2 << indseconds1 << "''" << endl;
	//cout << "Full time = " << time << endl;
	//cout << "temp minutes fulled = " << tempfull << endl;
	//cout << "temp separate = " << minutesdecimal << minutesones << "' " << secondsdecimal << secondsones << "'" << endl;


	// Создание имён используемыых фрагментов на базе рандомизованных значений

	string kilom = to_string(indxf) + "_3.png", secsec = to_string(indseconds1) + "_2.png", secdec = to_string(indseconds2) + "_2.png";

	string indx = "00"; // Зануление параметра "Часов"
	string name2 = indx + "_2.png";

	string way = to_string(wayindex) + "_1.png"; // Имя выбирамого маршрута
	cv::Mat bigImage = cv::imread(way, -1);


	int x1 = 120, x2 = 1264, xsecsec = 330, xsecdec = 292;
	int y1 = 2626, y2 = 2311, ysecsec = 2626, ysecdec = 2626;


	// Координаты темпа
	int tempzerox = 637, tempzeroy = 2626, tempminutesx = 674, tempminutesy = 2626, tempsecondsdecx = 718, tempsecondsonesx = 753;

	// Формирование имён изображений темпа
	string tempminutes = to_string(minutesones) + "_2.png";
	string tempsecde = to_string(secondsdecimal) + "_2.png";
	string tempsecon = to_string(secondsones) + "_2.png";


	cv::Mat destRoi;
	//________________________________________________________________________________________________________________

	//________________________________________________________________________________________________________________

	// Вставка данных темпа в изображение

	// Зануление часов темпа

	imagepatcher(tempzerox, tempzeroy, "00_2.png", bigImage, destRoi);//Зануление часов темпа
	imagepatcher(tempminutesx, tempminutesy, tempminutes, bigImage, destRoi);// Выставление минут темпа
	imagepatcher(tempsecondsdecx, tempminutesy, tempsecde, bigImage, destRoi);// Выставление десятков секунд темпа
	imagepatcher(tempsecondsonesx, tempminutesy, tempsecon, bigImage, destRoi);// Выставление единиц секунд темпа
	imagepatcher(787, 2624, "virbs.png", bigImage, destRoi);// Выставление двоеточий
	imagepatcher(707, 2624, "vir.png", bigImage, destRoi);//Выставление запятой

	//_____________________________________________________________________________________________________________________
	//_____________________________________________________________________________________________________________________
	// Вставка рандомизованного времени

	imagepatcher(xsecdec - 2, ysecdec, "black.png", bigImage, destRoi); //Заплатка на секунды времени
	imagepatcher(x1, y1, name2, bigImage, destRoi);// Меняем часы времени

	// Меняем километраж 

	imagepatcher(1062, 2293, "zaplatka_3.png", bigImage, destRoi);//Заплатка на километраж
	imagepatcher(1194, y2, "0_3.png", bigImage, destRoi);//Десятые доли километров
	imagepatcher(x2, y2, kilom, bigImage, destRoi); //Сотые доли километров
	imagepatcher(1097, y2, "5_3.png", bigImage, destRoi); //Километры
	imagepatcher(1168, 2414, "HighVirb.png", bigImage, destRoi);//Запятая километража
	imagepatcher(xsecdec, ysecdec, secdec, bigImage, destRoi);// Меняем десятки секунд времени
	imagepatcher(xsecsec, ysecsec, secsec, bigImage, destRoi);// Меняем единицы секунд времени
	imagepatcher(206, 2626, "29_2.png", bigImage, destRoi);//Минуты

	//________________________________________________________________________________________________________

	//________________________________________________________________________________________________________
	//Каденс и прочие параметры

	int cadens = 1 + rand() % 5;
	int calories = 25 + rand() % 40;
	int decscalories = calories / 10, onescalories = calories % 10;
	int step = 0 + rand() % 7;

	string stepway = to_string(step) + "_2.png", deccalway = to_string(decscalories) + "_2.png", onecalway = to_string(onescalories) + "_2.png";
	string cadensway = to_string(cadens) + "_2.png";

	//Каденс
	imagepatcher(631, 2838, "Cadens_patches.png", bigImage, destRoi);
	imagepatcher(682, 2854, "3_2.png", bigImage, destRoi);//Первое число каденса
	imagepatcher(718, 2854, cadensway, bigImage, destRoi);// Второе число каденса

	//________________________________________________________________________________________________________

	//Калории

	imagepatcher(1149, 2626, "Bigblack_2.png", bigImage, destRoi);// Чёрная заплатка
	imagepatcher(1149, 2626, "3_2.png", bigImage, destRoi);// Первое число калорий. Сотни
	imagepatcher(1185, 2626, deccalway, bigImage, destRoi);// Второе число калорий. Десятки
	imagepatcher(1222, 2626, onecalway, bigImage, destRoi);// Третье число калорий. Единицы
	//________________________________________________________________________________________________________

	//________________________________________________________________________________________________________
	// Длина шага 1078 2934
	imagepatcher(1077, 2848, "steppatch_2.png", bigImage, destRoi);// Чёрная заплатка
	imagepatcher(1078, 2934, "step_2.png", bigImage, destRoi);// Строка наименования графы
	imagepatcher(1168, 2854, "8_2.png", bigImage, destRoi);// Десятки шагов
	imagepatcher(1204, 2854, stepway, bigImage, destRoi);// Единицы шагов

	//________________________________________________________________________________________________________

	//cv::imshow("Overlay Image", bigImage);
	//cv::namedWindow("custom window", cv::WINDOW_KEEPRATIO);
	//cv::imshow("custom window", bigImage);
	//cv::resizeWindow("custom window", 360, 760);

	cv::imwrite(waylog, bigImage);
	//cv::waitKey(0);
}

const int year() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	int y = (now->tm_year + 1900);
	return y;
}
const int month() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	int y = (now->tm_mon + 1);
	return y;
}
const int day() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	int y = (now->tm_mday);
	return y;
}
const int hour() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	int y = (now->tm_hour);
	return y;
}
const int mint() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	int y = (now->tm_min);
	return y;
}

string waylog(int i) {
	string waylog = to_string(i) + ".jpg";
	return waylog;
}

void percchange(string waylog, int delay) {
	//cout << d << "-" << m << "-" << y << endl; // логирование Даты

	// 1 77 69        85 67
	// 2 108 69			116 67
	// 3 152 69			160 67
	// 4 182 69			190 67
	// 5 944 69  perc   952 67
	// 6 974 69			982 67
	// 1005 65 percentage/black 1013 63

	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	char buff[100];
	strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

	srand(ts.tv_nsec);
	 // автоматическая рандомизация

	int hourran = hour() + delay, hourrandecs = (hourran / 10), hourones = (hourran % 10);
	//cout << hourran << " = " << hourrandecs << hourones << endl;

	int mins = mint() + (1 + rand() % 3), minsdecs = mins / 10, minones = mins % 10;

	int percentage = 16 + rand() % 20, percdecs = percentage / 10, percones = percentage % 10;
	//cout << "percentage = " << percentage << endl;
	std::string hourf = to_string(hourrandecs) + "_4.png", hoursec = to_string(hourones) + "_4.png";
	std::string minf = to_string(minsdecs) + "_4.png", minsec = to_string(minones) + "_4.png";
	std::string percdec = to_string(percdecs) + "_4.png", percsec = to_string(percones) + "_4.png";
	std::string black = "Blackpercent.png";

	int y = 67;
	int xhodec = 85, xhones = 116, xmdec = 159, xmones = 188, xpdec = 938, xpones = 968, xpblack = 1013, ypblack = 63;

	cv::Mat bigImage = cv::imread(waylog, -1);

	cv::Mat destRoi;

	//cout << "Poluchennoe Imia = " << waylog << endl;

	imagepatcher(74, y, "Percgray_4.png", bigImage, destRoi); //Заплатка на проценты
	imagepatcher(xhodec, y, hourf, bigImage, destRoi);//Часы
	imagepatcher(xhones, y, hoursec, bigImage, destRoi);//Второе число часов
	imagepatcher(146, 75, "DOTS_4.png", bigImage, destRoi);//Двоеточие
	imagepatcher(xmdec, y, minf, bigImage, destRoi);//Десятки минут
	imagepatcher(xmones, y, minsec, bigImage, destRoi);//Единицы минут
	imagepatcher(928, 61, "chargegray_4.png", bigImage, destRoi);//Заплатка
	imagepatcher(xpdec, y, percdec, bigImage, destRoi);//Десятки процентов
	imagepatcher(xpones, y, percsec, bigImage, destRoi);//Единицы процентов
	imagepatcher(998, 64, "percent_4.png", bigImage, destRoi);

	cv::imwrite(waylog, bigImage);
	//cv::waitKey(0);
}

void dataset(string waylog, int day, int month, int year, int delay) {
	//cout << d << "-" << m << "-" << y << endl; // логирование Даты

	// 1 47 2402
	// 2 70 2402			
	// 3 102 2402
	// 4 125 2402
	// 5 202 2402
	// 6 223 2402
	// 1005 65 percentage/black 1013 63

	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	char buff[100];
	strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

	srand(ts.tv_nsec);

	//srand(time(0)); // автоматическая рандомизация

	int God = year, godd = ((God / 10) % 10), godo = (God % 10);
	//cout << God << " = " << godd << godo << endl;

	int mesiac = month, mesdecs = mesiac / 10, mesones = mesiac % 10;

	int den = day, dendec = den / 10, denones = den % 10;

	int hourran = hour() + delay, hourrandecs = (hourran / 10), hourones = (hourran % 10);
	//cout << hourran << " = " << hourrandecs << hourones << endl;

	int mins = mint() - (1 + rand() % 2), minsdecs = mins / 10, minones = mins % 10;

	//cout << "poluchen den = " << den << " imeem = " << dendec << denones << endl;

	std::string godfirst = to_string(godd) + "_5.png", godsecon = to_string(godo) + "_5.png";
	std::string mesfir = to_string(mesdecs) + "_5.png", messec = to_string(mesones) + "_5.png";
	std::string dendecst = to_string(dendec) + "_5.png", densecon = to_string(denones) + "_5.png";
	std::string hourf = to_string(hourrandecs) + "_5.png", hoursec = to_string(hourones) + "_5.png";
	std::string minf = to_string(minsdecs) + "_5.png", minsec = to_string(minones) + "_5.png";
	//std::string black = "Blackpercent.png";

	int y = 2402;
	int xddec = 47, xdones = 70, xmdec = 102, xmones = 125, xydec = 202, xyones = 223; //xpblack = 1013, ypblack = 63;
	int xhourdec = 256, xhourones = 278, xminutesdec = 310, xminutesones = 332;

	cv::Mat bigImage = cv::imread(waylog, -1);

	cv::Mat destRoi;

	//cout << "Poluchennoe Imia = " << waylog << endl;


	imagepatcher(xhourdec, y, hourf, bigImage, destRoi); //Десятки часов
	imagepatcher(xhourones, y, hoursec, bigImage, destRoi); //Единицы часов
	imagepatcher(xminutesdec, y, minf, bigImage, destRoi); //Десятки минут
	imagepatcher(xminutesones, y, minsec, bigImage, destRoi); //Единицы минут
	imagepatcher(xddec, y, dendecst, bigImage, destRoi); //Десятки дней
	imagepatcher(xdones, y, densecon, bigImage, destRoi); //Единицы дней
	imagepatcher(xmdec, y, mesfir, bigImage, destRoi); //Десятки месяцев
	imagepatcher(xmones, y, messec, bigImage, destRoi); //Единицы месяцев
	imagepatcher(xydec, y, godfirst, bigImage, destRoi); //Десятки лет
	imagepatcher(xyones, y, godsecon, bigImage, destRoi); //Единицы лет

	string saveway = "Screenshot_" + to_string(year) + to_string(month) + to_string(day) + "17033" + waylog[0] + "_MiFit" + waylog;

	cv::imwrite(saveway, bigImage);
	//cv::waitKey(0);
}

void cleaner(string waylog) { remove(waylog.c_str()); }

void naming(string waylog, int flag) {

	if (flag == 1) {

		cv::Mat bigImage = cv::imread(waylog, -1);

		cv::Mat destRoi;

		//cout << "Poluchennoe Imia = " << waylog << endl;

		imagepatcher(32, 2304, "nameBlack.png", bigImage, destRoi);
		imagepatcher(47, 2329, "Lada.png", bigImage, destRoi);

		cv::imwrite(waylog, bigImage);
		//cv::waitKey(0);

	}

}

const int Delay(int delay) {
	//int delay = 0;
	//cout << "Sdvig vremeni v zzelih chislah: Delay is: "; cin >> delay; cout << endl << endl;
	return delay;
}

void NameTag() {
	//cout << endl;
	//cout << "Made with the utmost respect for your free time by tg: @RegenTaller " << endl;
	//cout << endl;
	//cout << endl;
}

void main1(int ways, int choice, int flag, int timeway, int delay) {

	NameTag();

	//cout << "currentDateTime()=" << currentDateTime() << std::endl;
	//cout << "year = " << year() << endl;

	int Day = day(), Month = month(), Year = year(), n = 0;
	//int choice = 0, ways = 0;
	int step = 0;

	//cout << "Please, enter the count of available ways (colichestvo marshrutov): "; cin >> ways;
	//cout << endl;
	//cout << "Please, enter the count of logs, you need to get (nujnoe kolichestvo dnei): ";
	//cin >> choice;

	//int flag = 0;
	//cout << endl << "(ignore it => enter 0) The flag is: "; cin >> flag; cout << endl;
	//int timeway = 1;
	//cout << "The time direction is ( 1 => forward ; 0 => back ): "; cin >> timeway; cout << endl;

	//int delay = Delay(delay);

	//cout << endl << "Ok, let's do it..." << endl;
	//cout << endl;

	int* days = new int[choice];
	int* months = new int[choice];
	int* years = new int[choice];

	for (int i = 0; i < choice; i++) {

		if (timeway == 1) {
			if (Day + 1 > 31) { Day = 0; Month++; if (Month > 12) { Month = 1; Year++; } }
			Day++;
		}

		else {
			if (Day - 1 < 1) { Day = 31; Month--; if (Month < 1) { Month = 12; Year--; } }
			Day--;
		}

		// Заполнение массива и вывод значений его элементов
		days[i] = Day;
		months[i] = Month;
		years[i] = Year;
		//cout << "Value of " << i << " element is " << days[i] << "   " << months[i] << "   " << years[i] << endl;
	}

#pragma omp parallel for schedule(dynamic, 4)

	for (int i = 0; i < choice; i++) {

		int delay1 = delay;

		struct timespec ts;
		timespec_get(&ts, TIME_UTC);
		char buff[100];
		strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

		srand(ts.tv_nsec);

		//srand(time(NULL));
		n = 100 + rand() % 350;
		//Sleep(n);

		if (delay != 0) {

			struct timespec ts;
			timespec_get(&ts, TIME_UTC);
			char buff[100];
			strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

			srand(ts.tv_nsec);
			//srand(time(0));
			step = -2 + (rand() % 3);
			delay1 = delay1 + step;
			//cout << "Current delay is: " << delay1 << endl;
		}

		params(waylog(i), ways);

		naming(waylog(i), flag);

		percchange(waylog(i), delay1);
		//cout << Day << "-" << Month << "-" << Year << endl;

		dataset(waylog(i), days[i], months[i], years[i], delay1);

		cleaner(waylog(i));
	}

	delete[] days; // очистка памяти

	//system("pause");
}
