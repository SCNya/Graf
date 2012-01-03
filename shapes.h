#ifndef SHAPES_H
#define SHAPES_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class shap
{
public:
	shap();
	shap (float, float, float, float, float, float);
	~shap();
	float Get_AX() const
	{
		return (x1);
	}
	float Get_BX() const
	{
		return (x2);
	}
	float Get_CX() const
	{
		return (x3);
	}
	float Get_AY() const
	{
		return (y1);
	}
	float Get_BY() const
	{
		return (y2);
	}
	float Get_CY() const
	{
		return (y3);
	}
	void Start();
	void Mix (float, float, float, float, float, float);
	void Ext();
	void Matrix();
	void Opt (int, int, float, float, float, float);
	void Cr();
	void Set_C (string);
	float Trr (float, float, float, float, float);
	float Max (float, float, float);
	float Min (float, float, float);
	float Min_2 (float, float);
	float Max_2 (float, float);
	float D (float, float, float, float);
	float Vect (float, float);
	float K (float, float, float, float);
	float B (float, float, float, float);
	int Equat_Y (int, float, float, float, float);
	int Equat_X (int, float, float, float, float);
private:
	int *istr;
	int *icol;
	float x1, y1, x2, y2, x3, y3;
	float **mass;
	string *c;
};

#endif // SHAPES_H
