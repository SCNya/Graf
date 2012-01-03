#include "shapes.h"

shap::shap()
{
	istr=new int;
	icol=new int;
	c=new string;
	Start();
}

shap::shap (float ix1, float iy1, float ix2, float iy2, float ix3, float iy3)
{
	c=new string;
	istr=new int;
	icol=new int;
	Mix (ix1, iy1, ix2, iy2, ix3, iy3);
}

shap::~shap()
{
	for (int i (0); i<*istr; i++)
		{
			delete mass [i];
			mass [i]=0;
		}
	delete [] mass;
	mass=0;
	delete istr;
	istr=0;
	delete icol;
	icol=0;
	delete c;
	c=0;

}

void shap::Start()
{
	float ix1, ix2, ix3;
	float iy1, iy2, iy3;
	cout << "Enter A" << endl;
	cin >> ix1 >> iy1;
	cout << endl;
	cout << "Enter B" << endl;
	cin >> ix2 >> iy2;
	cout << endl;
	cout << "Enter C" << endl;
	cin >> ix3 >> iy3;
	cout << endl;
	Mix (ix1, iy1, ix2, iy2, ix3, iy3);
}

void shap::Mix (float ix1, float iy1, float ix2, float iy2, float ix3, float iy3)
{
	float minx, miny, maxx;
	minx=Min (ix1, ix2, ix3);
	miny=Min (iy1, iy2, iy3);
	x3=abs (minx-ix3);
	y3=abs (miny-iy3);
	x2=abs (minx-ix2);
	y2=abs (miny-iy2);
	x1=abs (minx-ix1);
	y1=abs (miny-iy1);
	*istr=((Max (y1, y2, y3)+1));
	*icol=((Max (x1, x2, x3)+1));
	mass=new float*[*istr];
	for (int i (0); i<*istr; i++)
		{
			mass [i]=new float [*icol];
		}
}

void shap::Ext()
{
	cout << endl;
	cout << x1 << endl;
	cout << y1 << endl;
	cout << x2 << endl;
	cout << y2 << endl;
	cout << x3 << endl;
	cout << y3 << endl;
	cout << endl;
}

void shap::Set_C (string ic)
{
	*c=ic;
}

float shap::Trr (float max, float min, float i1, float i2, float i3)
{
	float trr, s1, s2;
	float a [2];
	trr=min;
	s1=0;
	s2=0;
	a[0]=i1;
	a[1]=i2;
	a[2]=i3;
	for (int i (0); i<=2; i++)
		{
			if (max==a[i])
				{
					s1++;
				}
			if (min==a[i])
				{
					s2++;
				}
			if ((min!=a[i]) && (max!=a[i]))
				{
					trr=a[i];
				}
		}
	if ((s1>1) && (trr==max))
		{
			trr=max;
		}
	if ((s2>1) && (trr==min))
		{
			trr=min;
		}
	return (trr);

}

float shap::D (float xa, float ya, float xb, float yb)
{
	float d;
	d=sqrt((((xb-xa)*(xb-xa))+((yb-ya)*(yb-ya))));
	return (d);
}

float shap::Vect (float a, float b)
{
	float V;
	V=b-a;
	return (V);
}

float shap::K (float xa, float ya, float xb, float yb)
{
	float K;
	if ((Vect (xa, xb)!=0) && (Vect (ya, yb)!=0))
		{
			K=Vect (ya, yb)/Vect (xa, xb);
		}
	else
		{
			K=0;
		}
	return (K);
}

float shap::B (float xa, float ya, float xb, float yb)
{
	float b;
	b=((-xa)*K (xa, ya, xb, yb))+ya;
	return (b);
}

int shap::Equat_X (int y, float xa, float ya, float xb, float yb)
{
	int x;
	x=((y-B (xa, ya, xb, yb))/K (xa, ya, xb, yb));
	return (x);
}

int shap::Equat_Y (int x, float xa, float ya, float xb, float yb)
{
	int y;
	y=(K (xa, ya, xb, yb)*x)+B (xa, ya, xb, yb);
	return (y);
}


float shap::Max (float ix1, float ix2, float ix3)
{
	float max;
	max=ix1;
	if (max<ix2)
		{
			max=ix2;
		}
	if (max<ix3)
		{
			max=ix3;
		}
	return (max);
}

float shap::Min (float ix1, float ix2, float ix3)
{
	float min;
	min=ix1;
	if (min>ix2)
		{
			min=ix2;
		}
	if (min>ix3)
		{
			min=ix3;
		}
	return (min);
}


float shap::Min_2 (float Ya, float Yb)
{
	float min;
	min=Ya;
	if (min>Yb)
		{
			min=Yb;
		}
	return (min);
}

float shap::Max_2 (float Xa, float Xb)
{
	float max;
	max=Xa;
	if (max<Xb)
		{
			max=Xb;
		}
	return (max);
}

void shap::Opt (int i, int j, float xa, float ya, float xb, float yb)
{
	if ((Vect (xa, xb)!=0) && (Vect (ya, yb)==0))
		{
			if ((ya==i) && (((j>=xa) && (j<=xb)) || ((j>=xb) && (j<=xa))) )
				{
					mass [i] [j]=1;
				}
		}
	if ((Vect (xa, xb)==0) && (Vect (ya, yb)!=0))
		{
			if ((xa==j) && (((i>=ya) && (i<=yb)) || ((i>=yb) && (i<=ya))) )
				{
					mass [i] [j]=1;
				}
		}
	if ((Vect (xa, xb)!=0) && (Vect (ya, yb)!=0))
		{
			if ((i==Equat_Y (j, xa, ya, xb, yb)) && (((j>=xa) && (j<=xb)) || ((j>=xb) && (j<=xa))) )
				{
					mass [i] [j]=1;
				}
		}
}

void shap::Matrix()
{
	for (int i (0); i<*istr; i++)
		{
			for (int j (0); j<*icol; j++)
				{
					mass [i] [j]=0;
					Opt (i, j, x1, y1, x2, y2);
					Opt (i, j, x2, y2, x3, y3);
					Opt (i, j, x1, y1, x3, y3);
				}
		}
}

void shap::Cr()
{
	Matrix();
	cout << endl;
	for (int i (*istr-1); i>=0; i--)
		{
			cout << "\n";
			for (int j (0); j<*icol; j++)
				{
					if (mass [i] [j]==1)
						cout << " " << *c << "\t";
					else
						cout << "  " << "\t";
				}
			cout << endl;
		}
	cout << endl;

}
