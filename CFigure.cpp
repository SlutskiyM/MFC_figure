#pragma once
#include <iostream>
#include "stdafx.h"
#include <locale.h>
#include <conio.h>
#include <math.h>
using namespace std;
#define PI 3.141592653589793
class CMy2DPoint{
private:
	double m_x;
	double m_y;

public:
	CMy2DPoint(){
		m_x = 0;
		m_y = 0;
	}

	CMy2DPoint(double x, double y){
		m_x = x;
		m_y = y;
	}

	CMy2DPoint(const CMy2DPoint & a){
		m_x = a.m_x;
		m_y = a.m_y;
	}

	void Set (double a, double b){
		m_x = a;
		m_y = b;
	}

	void Set (const CMy2DPoint & point){
		m_x = point.m_x;
		m_y = point.m_y;
	}

	double Get_x ()const{
		return m_x;
	}

	double Get_y ()const{
		return m_y;
	}


	 CMy2DPoint operator +(const CMy2DPoint & a) const
	 {
		return CMy2DPoint(m_x + a.m_x,m_y + a.m_y);
	 }

	 CMy2DPoint operator -(const CMy2DPoint & a) const
	 {
		 return CMy2DPoint(m_x - a.m_x,m_y - a.m_y);
	 }

	 bool operator ==(const CMy2DPoint & a) const
	 {
		 return m_x==a.m_x && m_y==a.m_y;
	 }
	 
	 bool operator !=(const CMy2DPoint & a) const
	 {
		 return !(*this == a);
	 }

	friend ostream& operator << (ostream& output, const CMy2DPoint& object);
	friend istream& operator >> (istream& input, CMy2DPoint& object) ;

	friend CMy2DPoint operator *(const double a,const CMy2DPoint & b);
	friend CMy2DPoint operator *(const CMy2DPoint & b, const double a);
	friend double operator *(const CMy2DPoint & a, const CMy2DPoint& b);

	friend CMy2DPoint operator /(const CMy2DPoint & b, double a);

};

 class CMy2DObject9B{
 private:
	 double m_A;
	 double m_A1;
	 double m_A2;
	 double m_A3;

	 CMy2DPoint m_center; 
	 double m_dAngle;
 public:
	 CMy2DObject9B(){
		m_A = 1;
		m_A1 = 0;
		m_A2 = 0;
		m_A3 = 0;
		m_center.Set(0,0);
		m_dAngle = 0;
	}


	  CMy2DObject9B(double A,double A1,double A2,double A3,CMy2DPoint point,double angle){
		  if(A >= 0 && A1 >= 0 && A2 >= 0 && A3 >= 0 && A1 <= (A - A2) && A1 <=(A-A3) && (A2+A3) <= A && A2 <=A && A3 <=A)
		  {
			m_A = A;
			m_A1 = A1;
			m_A2 = A2;
			m_A3 = A3;
			m_center.Set(point);
			m_dAngle = angle;
		  }
		  else
		  {
			  cout << "Некорректные размерности фигуры\nСоздан квадрат со стороной 1 в (0,0)\n" <<endl;
			m_A = 1;
			m_A1 = 0;
			m_A2 = 0;
			m_A3 = 0;
			m_center.Set(0,0);
			m_dAngle = 0;
			 
		  }
	}

	  double Get_A (){
		return m_A;
	}

	  void Set_A(double A)
	  {
		  if(A >= 0 && m_A1 >= 0 && m_A2 >= 0 && m_A3 >= 0 && m_A1 <= (A - m_A2) && m_A1 <=(A-m_A3) && (m_A2+m_A3) <= A && m_A2 <=A && m_A3 <=A)
			  m_A = A;
	  }

	  double Get_A1 (){
		return m_A1;
	}

	  void Set_A1 (double A1)
	  {
		   if(m_A >= 0 && A1 >= 0 && m_A2 >= 0 && m_A3 >= 0 && A1 <= (m_A - m_A2) && A1 <=(m_A-m_A3) && (m_A2+m_A3) <= m_A && m_A2 <=m_A && m_A3 <=m_A)
			   m_A1 = A1;
	  }

	  double Get_A2 (){
		return m_A2;
	}

	  void Set_A2(double A2)
	  {
		    if(m_A >= 0 && m_A1 >= 0 && A2 >= 0 && m_A3 >= 0 && m_A1 <= (m_A - A2) && m_A1 <=(m_A-m_A3) && (A2+m_A3) <= m_A && A2 <=m_A && m_A3 <=m_A)
				m_A2 = A2;
	  }

	 double Get_A3 (){
		return m_A3;
	}

	 void Set_A3(double A3)
	 {
		  if(m_A >= 0 && m_A1 >= 0 && m_A2 >= 0 && A3 >= 0 && m_A1 <= (m_A - m_A2) && m_A1 <=(m_A-A3) && (m_A2+A3) <= m_A && m_A2 <=m_A && A3 <=m_A)
			  m_A3 = A3;
		  
	 }

	 CMy2DPoint Get_Center(){
		return m_center;
	}

	 void Set_Center(CMy2DPoint center)
	 {
		 m_center = center;
	 }

	 double Get_Angle (){
		return m_dAngle;
	}

	 void Set_Angle (double angle)
	 {
		 m_dAngle = angle;
	 }

	 void Move(double dX, double dY, double dAngle = 0)
	 {
		 m_center.Set(m_center.Get_x() + dX,m_center.Get_y() + dY);
		 m_dAngle += dAngle;
	 }

	 void Move(const CMy2DPoint &delta, double dAngle = 0){
		  m_center = m_center + delta;
		  m_dAngle += dAngle;

	 }

	 void Rotate(double dAngle) {
		 m_dAngle += dAngle;
	 }

	 bool IsInside(double x, double y)  {
		 
		 double c_x = m_center.Get_x();
		 double c_y = m_center.Get_y();

		 double a_x = x- c_x;
		 double a_y = y- c_y;

		 double d_x = a_x*cos(m_dAngle*PI/-180)-a_y*sin(m_dAngle*PI/-180); 
		 double d_y = a_x*sin(m_dAngle*PI/-180)+a_y*cos(m_dAngle*PI/(-180));
		

		  if((d_x>=-m_A/2 && d_x<=m_A/2)&&(d_y<=m_A/2 && d_y>=-m_A/2) )
		 {
			 if(((d_x<=(m_A/2)-m_A1) || (d_x>=(m_A/2)-m_A1)&&((d_y >=(m_A1/2) || d_y <=-(m_A1/2)))))
			 {
				 if (d_x >= d_y -(m_A -m_A2))
				 {
					 if(sqrt((d_x+(m_A/2))*(d_x+(m_A/2))+(d_y+(m_A/2))*(d_y+(m_A/2)))>=m_A3)
					 {
						 return true;
					 }
				 }
			 }
		 }
		 return false;
	 }
	 

	 bool IsInside(const CMy2DPoint &point){
		 CMy2DPoint a = point;
		 double x = point.Get_x();
		 double y = point.Get_y();
		 return IsInside(x,y);
	 }

	 friend ostream& operator << (ostream& output, const CMy2DPoint& object);
	 friend ostream& operator << (ostream& output, const CMy2DObject9B& object);
 };

 

 double operator *(const CMy2DPoint & a,const CMy2DPoint & b)
 {
	return a.m_x*b.m_x + a.m_y + b.m_y;
 }

 CMy2DPoint operator *(const double a,const CMy2DPoint & b)
 {
	return CMy2DPoint(b.m_x * a,b.m_y * a);
 }

 CMy2DPoint operator *(const CMy2DPoint & b, const double a)
 {
	return CMy2DPoint(b.m_x * a,b.m_y * a);
 }

 CMy2DPoint operator /(const CMy2DPoint & b, const double a)
 {
	return CMy2DPoint(b.m_x / a,b.m_y / a);
 }

 ostream& operator << (ostream& output, const CMy2DPoint& object) {
		output << "(" << object.m_x << "; " << object.m_y << ")"<<endl;
		return output;
	}

 istream& operator >> (istream& input, CMy2DPoint& object) {
		cout << "x = ";
		input >> object.m_x;
		cout << "y = ";
		input >> object.m_y;
		return input;
	}

 ostream&  operator << (ostream& out,const CMy2DObject9B & object)
 {
	out << "A = "<< object.m_A << "\tA1 = "<< object.m_A1<< "\tA2 = "<< object.m_A2<< "\tA3 = "<< object.m_A3 << endl<<object.m_center << object.m_dAngle<<"°"<<endl;

	 return out;
 }