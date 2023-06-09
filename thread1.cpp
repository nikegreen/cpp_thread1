﻿// thread1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//ввод вывод на консоль
#include <iostream>
//для многопоточности
#include <thread>
//для задержки времени
#include <chrono>

using namespace std;

//метод
void DoWork() 
{
	cout << "start thread id=" << this_thread::get_id() << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока DoWork = " << this_thread::get_id() << " i=" << i << endl;
		this_thread::sleep_for(chrono::microseconds(1000));
	}
	cout << "finish thread id=" << this_thread::get_id() << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "start main" << endl;

	thread thread1(DoWork); // выполнение в новом потоке не в Name
	thread thread2(DoWork); // выполнение в новом потоке не в Name
	//thread1.detach(); // разъеденить потоки (или убираем detach и добавляем join внизу)

	//DoWork(); // выполнение в одном потоке с main 

	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока Main = " << this_thread::get_id() << " i=" << i << endl;
		this_thread::sleep_for(chrono::microseconds(500));
	}

	cout << "ждём когда закончит работать поток thread1" << endl;
	//ожидание когда закончит работу поток thread1
	thread1.join();
	thread2.join();

    std::cout << "finish\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
