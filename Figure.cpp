#include "CFigure.cpp"




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");
	cout << "Домашнее задание №1, модуль 3\n\n";
	cout << "Выполнил Слуцкий Михаил Георгиевич\nГруппа БПМ-143, подгруппа 2\nВариант 25, Фигура 9B\n\n\n";
	char c;

	cout << "Введите 1, чтобы увидеть пример.\nВведите 2, чтобы самому ввести данные"<<endl;
	double A,A1,A2,A3,angle;
	CMy2DPoint centre;
	cin >> c;
	if(c == '1')
	{
		A = 4;
		A1 = 1;
		A2 = 1;
		A3 = 1;
		centre.Set(0,0);
		angle = 0;
	}
	else
	{
		cout << "Ввод параметров фигуры/координат ее центра/угла поворота \n";
	
		cout << "A = ";
		cin >> A;
		cout << "A1 = ";
		cin >> A1;
		cout << "A2 = ";
		cin >> A2;
		cout << "A3 = ";
		cin >> A3;
		cout << "Координаты центра квадрата:\n";
		cin >> centre;
		cout << "Угол поворота фигуры относительно оси против часовой стрелки (в градусах):\n";
		cin >> angle;
		cout << endl;
	}

	CMy2DObject9B Figure(A, A1, A2, A3, centre, angle);

	cout <<"Параметры получившейся фигуры"<<endl<<Figure<<endl;
	double x,y;
	cout << "Введите координаты точки\nx = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		if (Figure.IsInside(x, y))
			cout << "Точка принадлежит фигуре\n";
		else
			cout << "Точка не принадлежит фигуре\n";
		
	return 0;
}


