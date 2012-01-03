//alpha 0.2 03.01.12 16:50 by AEffect
#include "shapes.h"

int main()
{
	shap*tr=new shap (10, 15, 18, 15, 14, 10);
	//tr->Ext();
	//system ("cls");
	tr->Set_C (".");
	tr->Cr();
	//cout << endl;
	//cout << tr->K(tr->Get_AX(), tr->Get_AY(), tr->Get_BX(), tr->Get_BY()) << endl;
	//cout << tr->B(tr->Get_AX(), tr->Get_AY(), tr->Get_BX(), tr->Get_BY());
	delete tr;
	return (0);
}
