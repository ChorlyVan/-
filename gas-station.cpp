#include<iostream>
#include<string>
#include<conio.h>

//#define OVERFLOW -2
#define ERROR     0
#define OK		  1
typedef int Status;
typedef int ElemType;
using namespace std;


typedef struct 
{
	int a;//使用汽油种类
	long id;//车牌号
	string color;
}car;
//struct oiler
//{
//	int x, y;//加油设备加油种类
//};
typedef struct {
	car* elem;
	int length;
}SqList;

SqList L,L1,L2,L3,L4,out;//声明入站队列和四条加油队列
Status InitList(SqList& L) {
	L.elem = new car[50];
	if (!L.elem)
		return(OVERFLOW);
	L.length = 0;
	return OK;
}

Status GetElem(SqList &L)//输出队列中车辆信息
{
	cout << "编号			颜色			汽油型号" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i].id << "			" << L.elem[i].color << "			" << L.elem[i].a << "#" << endl;
	}
	return OK;
}

Status Creat(SqList &L) {//加油站开启，添加加油汽车信息
	int i,k;
	string c;
	cout << "有多少辆汽车需要加油？"<<endl;
	cin >> k;
	if (k <= 50) {
		for (int j = 1; j <= k; j++) {
			
			cout << "第" << j << "辆汽车颜色是：" << endl;
			cin >> c;
			L.elem[L.length].color = c;
			c.clear();
			cout << "第" << j << "辆汽车编号是：" << endl;
			cin >> i;
			L.elem[L.length].id = i;
			cout << "第" << j << "辆汽车使用汽油型号是：" << endl;
			cin >> i;
			L.elem[L.length].a = i;
			L.length++;
		}
		return OK;
	}
	else { cout << "车辆数目超出预设上限" << endl; }
	return ERROR;
}

/*Status Getin(SqList& L,SqList &K,SqList &J ) {
	car temp;
	for (int i = 0; i < L.length;L.length--) {
		if (L.elem[i].a == 89) {//89#汽油车进入对应最短队列
			if (K.length <= J.length) {
				temp = L.elem[i];
				L1.length++;
				L1.elem[L1.length-1] = temp;
				
				for (int j=0; j <= L.length-1; j ++) {
					L.elem[j] = L.elem[j + 1];
				}
				//L.elem[i] = NULL;
			}
			else {
				temp = L.elem[i];
				L4.length++;
				L4.elem[L4.length-1] = temp;
				
				for (int j=0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}
			}
		}
		if (L.elem[i].a == 92) {//92#
			if (L1.length <= L2.length) {
				temp = L.elem[0];
				
				L1.elem[L1.length] = temp;
				L1.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}

				//L.elem[i] = NULL;
			}
			else {
				temp = L.elem[0];
				
				L2.elem[L2.length] = temp;
				L2.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}
			}
		}
		if (L.elem[i].a == 95) {//95#
			if (L2.length <= L3.length) {
				temp = L.elem[0];
				
				L2.elem[L2.length] = temp;
				L2.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}

				//L.elem[i] = NULL;
			}
			else {
				temp = L.elem[0];
				
				L3.elem[L3.length] = temp;
				L3.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}
			}
		}
		if (L.elem[i].a == 95) {//98#
			if (L3.length <= L4.length) {
				temp = L.elem[0];
				
				L3.elem[L3.length] = temp;
				L3.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}

				//L.elem[i] = NULL;
			}
			else {
				temp = L.elem[0];
				
				L4.elem[L4.length] = temp;
				L4.length++;
				for (int j = 0; j <= L.length; j++) {
					L.elem[j] = L.elem[j + 1];
				}
			}
		}


	}
		return OK;	
}*/
Status Getin89(SqList& L, SqList& J, SqList& K,int i) {//汽车进入对应队列
	//car temp;
	if (L.elem[0].a == i) {//判断汽油型号
		if (J.length <= K.length) {//寻找可用最短队列
			//temp = L.elem[i];
			J.length++;
			J.elem[J.length - 1] = L.elem[0];

			for (int j = 0; j <= L.length ; j++) {
				L.elem[j] = L.elem[j + 1];
			}
			//L.elem[i] = NULL;
			//--L.length;
		}
		else {
			//temp = L.elem[i];
			K.length++;
			K.elem[K.length - 1] = L.elem[0];

			for (int j = 0; j <= L.length; j++) {
				L.elem[j] = L.elem[j + 1];
			}
			//--L.length;
		}
		//L.length++;
	}
	return OK;
}

Status Working(SqList& L, SqList& J, int j) {
	//char a;
	for (int i = 0; i < L.length; L.length--) {
		cout << "第" << j << "条加油队列还有" << L.length << "辆车需要加油" << endl;
		////cin >> a;
		//if(_kbhit){ getch(); }
		//a=getchar();
		_getch();
		
		J.length++;
		J.elem[J.length - 1] = L.elem[0];

		for (int j = 0; j <= L.length; j++) {
			L.elem[j] = L.elem[j + 1];
		}
	}
	cout << "第" << j << "条车道的车辆已经全部加油完成" << endl;
	return OK;
}

int main() {
	int choose=0,flag=1;
	//string c="";
	//car temp;
	//SqList L, L1, L2, L3, L4 ,out;//声明入站队列和四条加油队列
	InitList(L);
	InitList(L1);
	InitList(L2);
	InitList(L3);
	InitList(L4);
	InitList(out);
	while (flag==1) {
		cout << "--------------------------------- " << endl;
		cout << "|1.开启加油站                   |" << endl;
		cout << "|2.开启加油机                   |" << endl;
		cout << "|3.显示加油站外车队             |" << endl;
		cout << "|4.显示1号加油机等候车队        |" << endl;
		cout << "|5.显示2号加油机等候车队        |" << endl;
		cout << "|6.显示3号加油机等候车队        |" << endl;
		cout << "|7.显示4号加油机等候车队        |" << endl;
		cout << "|8.显示出站队列                 |" << endl;
		cout << "|9.开始加油                     |" << endl;
		cout << "|0.exit                         |" << endl;
		cout << "---------------------------------" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			Creat(L);
			break;
		case 2:
			/*do{ 
				Getin89(L, L1, L4, 89);
				Getin89(L, L1, L2, 92);
				Getin89(L, L2, L3, 95);
				Getin89(L, L3, L4, 98);
			} while (L.length != 0);*/
			for (int i = 0; i <= L.length; L.length--) {
				Getin89(L, L1, L4, 89);
				Getin89(L, L1, L2, 92);
				Getin89(L, L2, L3, 95);
				Getin89(L, L3, L4, 98);
			}
			L.length++;
			break;
		case 3:
			GetElem(L);
			cout <<"共有"<< L.length<<"辆车在站外等候"<<endl;
			break;
		case 4:
			GetElem(L1);
			break;
		case 5:
			GetElem(L2);
			break;
		case 6:
			GetElem(L3);
			break;
		case 7:
			GetElem(L4);
			break;
		case 8:
			GetElem(out);
			break;
		case 9:
			Working(L1, out, 1);
			Working(L2, out, 2);
			Working(L3, out, 3); 
			Working(L4, out, 4);
			break;
		case 0:
			flag = 0;
			break;
		}
	}
	cout << "-----------------------------" << endl;
	cout << "| 期待与你的下次见面，再见! |" << endl;
	cout << "-----------------------------" << endl;
}
