#include "MyForm.h"
#include "Fizron.h"
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

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int GetHardDriveInfo(LPCTSTR p)
{
	ULARGE_INTEGER FreeBytesToCaller, TotalBytes, FreeBytes;
	GetDiskFreeSpaceEx(TEXT(p), &FreeBytesToCaller, &TotalBytes, &FreeBytes);

	//cout << TotalBytes.QuadPart << " byte" << endl;
	//cout << FreeBytesToCaller.QuadPart << " byte" << endl;
	std::stringstream stream;

	stream << (FreeBytes.QuadPart)/ 1048576;

	int avspace = FreeBytes.QuadPart;

	string s = stream.str();

	int cislokilov = std::stoi(s);

	String^ str3 = gcnew String(s.data());

	return cislokilov;
}

LPCTSTR p = "C:\\";



void main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TryingToCreate::MyForm form;
	Application::Run(% form);

}

System::Void TryingToCreate::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e) {
	return System::Void();
}

System::Void TryingToCreate::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

	cv::Mat destRoi;
	cv::Mat bigImage = cv::imread("4_1.png", -1);

	//imagepatcher(300, 300, "4_3.png", bigImage, destRoi);

	//cv::imwrite("GOTOVII.png", bigImage);
	//cv::waitKey(0);

	long int dnei = 0, marsh = 0, vremia = 0, imia = 0, delay = 0;

	dnei = System::Int32::Parse(this->textBox2->Text);

	double ves = 0.55 * dnei;
	
	if (ves < GetHardDriveInfo(p)){
	
		if (textBox1->Text != "" && textBox2->Text != "" && textBox3->Text != "" && textBox4->Text != "" && textBox5->Text != "") {

			this->label8->Text = "Начало генерации...";
			MessageBox::Show("Система может подвиснуть, если генерируется много отчётов. Нажмите Ок, чтобы начать генерацию.");

			marsh = System::Int32::Parse(this->textBox1->Text);
			vremia = System::Int32::Parse(this->textBox3->Text);
			imia = System::Int32::Parse(this->textBox4->Text);
			delay = System::Int32::Parse(this->textBox5->Text);
			this->textBox1->Text = "";
			this->textBox2->Text = "";
			this->textBox3->Text = "";
			this->textBox4->Text = "";
			this->textBox5->Text = "";

		}
	}
	
	else { MessageBox::Show("На диске недостаточно места для генерации указанного количества отчётов"); }
	
	string gener1 = gener();

	
	if (dnei != 0 && marsh != 0 && gener1 == "Генерация отчётов" ) {

		unsigned int start_time = clock();

		main1(marsh, dnei, imia, vremia, delay);

		unsigned int end_time = clock();
		unsigned int search_time = (end_time - start_time)/1000;

		this->label8->Text = "Генерация завершена.";
		this->label1->Text = dnei.ToString() + " отчётов сгенерировано за " + search_time + " с.";
	}

	//Sleep(7000);

	//this->label8->Text = "";
	//this->label1->Text = "";
	
	return System::Void();
}



