//处理模块的实现
#include"PreHand.h"
t_row::t_row()
{
	Size_Middle = 0;
	SO = 0;
	Size_Average = 0;
	Skew = 0;
	Kurtosis = 0;
	next = NULL;
	n_row = -1;
}
	//获得粒径中值
double t_row::get_size_middle(double *data)
	{
		int i = 0;
		while (data[i] <= 50)
		{
			i++;
		}
		if (data[i] == 50)
		{
			return get_table(i);
		}
		else
		{
			double k = (data[i] - data[i - 1]) / (get_table(i) - get_table(i - 1));
			double b = data[i] - k*get_table(i);
			double x;
			x = (50 - b) / k;
			return x;
		}
	}

	//获得分选系数
double t_row::get_so(double *data)
	{
		double k = 0;
		double b = 0;
		double x_25;
		int i = 0;
		while (data[i] < 25)
		{
			i++;
		}
		if (i == 0)
		{
			return 0.25;
		}
		else
		{
			k = (data[i] - data[i - 1]) / (get_table(i) - get_table(i - 1));
			b = data[i] - k*get_table(i);
			x_25 = (25 - b) / k;
		}


		//
		while (data[i] < 75)
		{
			i++;
		}
		k = (data[i] - data[i - 1]) / (get_table(i) - get_table(i - 1));
		b = data[i] - k*get_table(i);
		double x_75;
		x_75 = (75 - b) / k;
		double so = x_25 / x_75;
		return so;
	}

	//根据百分比获取粒径大小
double t_row::get_um(double *data, double per)
	{
		if (per > 100 && per < 0)
			return -1;
		if (per == 100)
			return 400;
		if (per == 0)
			return 0;
		else
		{
			int i = 0;
			while (data[i] < per)
			{
				i++;
			}
			if (i == 0)
				return get_table(0);
			else
			{
				double x;
				double k;
				double b;
				k = (data[i] - data[i - 1]) / (get_table(i) - get_table(i - 1));
				b = data[i] - k*get_table(i);
				x = (per - b) / k;
				return x;
			}
		}
	}

	//获得平均粒径
double t_row::get_average_size(double *data, int length)
	{
		double temp= (get_um(add_data, 25) + get_um(add_data, 75)) / 2;
		return temp;
		/*
		int i = 0;
		double temp = 0;
		for (i = 0; i < length; i++)
		{
			temp += data[i] * get_table(i);
		}
		temp = temp / 100;
		return temp;
		*/
	}

	//获得偏度
double t_row::get_Skew(double *data, int length)
	{
		double lg16, lg84, lg50, lg5, lg95;
		lg16 = log(get_um(add_data, 16));
		lg84 = log(get_um(add_data, 84));
		lg50= log(get_um(add_data, 50));
		lg5= log(get_um(add_data, 5));
		lg95= log(get_um(add_data, 95));
		return (lg16 + lg84 - 2 * lg50) / (2 * (lg84 - lg16)) + (lg5 + lg95 - 2 * lg50) / (2 * (lg95 - lg5));
		/*
		int i = 0;
		double Ex = get_average_size(data, length);
		double Ex2 = 0;
		double Ex3 = 0;
		double temp = 0;
		double Skew = 0;
		for (i = 0; i < length; i++)
		{
			temp += data[i] * get_table(i)* get_table(i);
		}
		Ex2 = temp / 100;
		temp = 0;
		for (i = 0; i < length; i++)
		{
			temp += data[i] * get_table(i)* get_table(i)* get_table(i);
		}
		Ex3 = temp / 100;
		Skew = (Ex3 - 3 * Ex*Ex2 + 2 * Ex*Ex*Ex) / (pow((Ex2 - Ex*Ex), 1.5));
		return Skew;
		*/
	}

	//获得峰度
double t_row::get_Kurtosis(double *data, int length)
	{
		double lg95, lg5, lg75, lg25;
		lg95= log(get_um(add_data, 95));
		lg5= log(get_um(add_data, 5));
		lg75= log(get_um(add_data, 75));
		lg25= log(get_um(add_data, 25));
		return (lg95 - lg5) / (2.44*(lg75 - lg25));
		/*
		int i = 0;
		double Ex = get_average_size(data, length);
		double S = 0;
		for (i = 0; i < length; i++)
		{
			S += (get_table(i) - Ex)*(get_table(i) - Ex) / length;
		}
		S = sqrt(S);
		double temp = 0;
		for (i = 0; i < length; i++)
		{
			temp += pow(((get_table(i) - Ex) / S), 4);
		}
		temp = temp / length;
		temp = temp*(sqrt((length / 24)));
		return temp;
		*/
	}

//table类
table::table()
	{
		head = new t_row;
		head->next = NULL;
		column = 0;
	}
table::table(int column_)
	{
		head = new t_row;
		head->next = NULL;
		column = column_;
	}

//在链表上创建一个新节点
void table::createNode()
	{
		int i = 0;
		t_row *p = head;
		while (p->next != NULL)
		{
			p = p->next;
			i++;
		}
		t_row *p1 = new t_row;
		p->next = p1;
		p1->next = NULL;
		p1->n_row = i;
	}

//插入数据部分
void table::insert_name(char name[20])
	{
		t_row *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		strcpy_s(p->name, name);
	}
void table::insert_data(double *data)
	{
		t_row *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->data = data;
	}
void table::insert_add_data(double *adddata)
	{
		t_row *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->add_data = adddata;
	}

double table::get_data(int row, int column)
	{
		while (row <= 0)
			row++;
		t_row *p = head;
		while (p->n_row != row)
		{
			p = p->next;
		}
		return p->data[column];
	}
double table::get_add_data(int row, int column)
	{
		while (row <= 0)
			row++;
		t_row *p = head;
		while (p->n_row != row&&p->next!=NULL)
		{
			p = p->next;
		}
		return p->add_data[column];
	}
//清空链表，用于重新读取文件时
void table::Init()
{
	t_row *p = head;
	head->next = NULL;
	column = 1;
}

//执行计算步骤，计算参数
void table::Caculate()
	{
		int length = column - 1;
		t_row *p = head;
		if(p->next!=NULL)
			p = p->next;
		while (p->next != NULL)
		{
			p->Size_Middle = p->get_size_middle(p->add_data);
			p->SO = p->get_so(p->add_data);
			p->Size_Average = p->get_average_size(p->data, length);
			p->Skew = p->get_Skew(p->data, length);
			p->Kurtosis = p->get_Kurtosis(p->data, length);
			p = p->next;
		}
		if (p != NULL)
		{
			p->Size_Middle = p->get_size_middle(p->add_data);
			p->SO = p->get_so(p->add_data);
			p->Size_Average = p->get_average_size(p->data, length);
			p->Skew = p->get_Skew(p->data, length);
			p->Kurtosis = p->get_Kurtosis(p->data, length);
		}
	}

//获取表格行的总数
int table::Getrow()
{
	int i = 0;
	t_row *p = this->head;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}

void table::get_name(int row,char a[20])
{
	int i = 0;
	t_row *p = this->head;
	for (i = 0; i < row; i++)
	{
		if(p->next!=NULL)
			p = p->next;
	}
	strcpy_s(a,50, p->name);

}

//获取各种参数
double table::get_SizeMiddle(int row)
	{
		t_row *p = head;
		while (p->n_row < row&&p->next != NULL)
		{
			p = p->next;
		}
		if (p == NULL)
			return 0;
		return p->Size_Middle;
	}
double table::get_So(int row)
	{
		t_row *p = head;
		t_row *p1;
		while (p->n_row < row&&p->next!=NULL)
		{
			p1 = p;
			p = p->next;
		}
		if (p == NULL)
			return 0;
		return p->SO;
	}
double table::get_AverageSize(int row)
	{
		t_row *p = head;
		while (p->n_row < row&&p->next != NULL)
		{
			p = p->next;
		}
		if (p == NULL)
			return 0;
		return p->Size_Average;
	}
double table::get_Skew(int row)
	{
		t_row *p = head;
		while (p->n_row < row&&p->next != NULL)
		{
			p = p->next;
		}
		if (p == NULL)
			return 0;
		return p->Skew;
	}
double table::get_Kurtosis(int row)
	{
		t_row *p = head;
		while (p->n_row < row&&p->next != NULL)
		{
			p = p->next;
		}
		if (p == NULL)
			return 0;
		return p->Kurtosis;
	}

/*将本链表的数据输出到文件中，hFile为文件句柄*/
int table::Output(HANDLE hFile)
	{
		t_row *p = head;
		p = p->next;
		WriteFile(hFile, "样品名", strlen("样品名"), NULL, NULL);
		WriteFile(hFile, ",", strlen(","), NULL, NULL);
		WriteFile(hFile, "平均粒径", strlen("平均粒径"), NULL, NULL);
		WriteFile(hFile, ",", strlen(","), NULL, NULL);
		WriteFile(hFile, "粒径中值", strlen("粒径中值"), NULL, NULL);
		WriteFile(hFile, ",", strlen(","), NULL, NULL);
		WriteFile(hFile, "分选系数", strlen("分选系数"), NULL, NULL);
		WriteFile(hFile, ",", strlen(","), NULL, NULL);
		WriteFile(hFile, "偏度", strlen("偏度"), NULL, NULL);
		WriteFile(hFile, ",", strlen(","), NULL, NULL);
		WriteFile(hFile, "尖度", strlen("尖度"), NULL, NULL);
		WriteFile(hFile, "\r\n", strlen("\r\n"), NULL, NULL);
		string lp;
		if (p == NULL)
			return -1;
		while (p != NULL)
		{
			WriteFile(hFile, p->name, strlen(p->name), NULL, NULL);

			lp = dob_to_str(p->Size_Average);
			WriteFile(hFile, ",", strlen(","), NULL, NULL);
			WriteFile(hFile, lp.c_str(), strlen(lp.c_str()), NULL, NULL);

			lp = dob_to_str(p->Size_Middle);
			WriteFile(hFile, ",", strlen(","), NULL, NULL);
			WriteFile(hFile, lp.c_str(), strlen(lp.c_str()), NULL, NULL);

			lp = dob_to_str(p->SO);
			WriteFile(hFile, ",", strlen(","), NULL, NULL);
			WriteFile(hFile, lp.c_str(), strlen(lp.c_str()), NULL, NULL);

			lp = dob_to_str(p->Skew);
			WriteFile(hFile, ",", strlen(","), NULL, NULL);
			WriteFile(hFile, lp.c_str(), strlen(lp.c_str()), NULL, NULL);

			lp = dob_to_str(p->Kurtosis);
			WriteFile(hFile, ",", strlen(","), NULL, NULL);
			WriteFile(hFile, lp.c_str(), strlen(lp.c_str()), NULL, NULL);
			WriteFile(hFile, "\r\n", strlen("\r\n"), NULL, NULL);
			p = p->next;
		}
		CloseHandle(hFile);
		return 1;
	}
void table::input_column(int _column)
	{
		column = _column;
	}
//数据类型转换，string转Int
int table::name_to_int(string _name)
{
	int i = 0;
	t_row *p = this->head;
	p = p->next;
	string temp = p->name;
	while (temp != _name&&p!=NULL)
	{
		p = p->next;
		if(p!=NULL)
			temp = p->name;
		i++;
	}
	if (p == NULL)
		return 0;
	return i;
}

double Catof(string a)
{
	const char *p = a.c_str();
	return atof(p);
}
//获取原始数据的行和列
int get_row(string &a)
{
	int i = 0;
	int j = 0;
	while (a[i] != '\0')
	{
		i++;
		if (a[i] == '\n')
			j++;
	}
	return j;
}
int get_column(string &a)
{
	int i = 0;
	int j = 0;
	while (a[i] != '\n'&&a[i] != '\0')
	{
		i++;
		if (a[i] == ',')
			j++;
	}
	return j;
}

//分割字符串，填充table类
int fill_data_table(string &a, int row, table *table1, int column)
{
	int n = 0;
	char temp[255];
	int ptr = 0;
	int i = 0;
	double *data = new double[column];
	double *add_data = new double[column];
	add_data[0] = 0;
	while (a[n] != ',')
	{
		temp[ptr] = a[n];
		ptr++;
		n++;
	}
	temp[ptr] = '\0';
	ptr = 0;
	table1->createNode();
	table1->insert_name(temp);

	while (a[n] != '\0')
	{
		temp[ptr] = a[n];
		ptr++;
		n++;
		if (a[n] == ',')
		{
			temp[ptr] = '\0';
			data[i] = Catof(temp);
			if (i == 0)
				add_data[i] = data[i];
			else
				add_data[i] = data[i] + add_data[i - 1];
			ptr = 0;
			n++;
			i++;
		}
	}
	temp[ptr] = '\0';
	data[i] = Catof(temp);
	add_data[i] = data[i] + add_data[i - 1];
	table1->insert_data(data);
	table1->insert_add_data(add_data);
	return 1;
}
//读取文件，按行读取数据到字符串中
void get_restlt_data(string f_name, int *length, table *table1)
{
	int i = 0;
	ifstream file(f_name);
	string a;

	//读取文件的行数、列数
	while (file.good())
	{
		getline(file, a, '*');
	}
	int column = get_column(a);
	int row = get_row(a) - 1;
	file.close();

	file.open(f_name, ios::in);

	//再次按行读取
	getline(file, a, '\n');  //读取第一行表头
	while (file.good())
	{
		getline(file, a, '\n');
		if (i < row)
			fill_data_table(a, i, table1, column);
		i++;
	}
	*length = column;
	table1->input_column(column);
	table1->Caculate();
}

//浮点数到字符串的转换，用于绘图
string int_to_str_x(int x, int cxClient,int length)
{

	if (length == 0)
	{
		return "请读取数据";
	}
	double cx;
	cx = (x - PLR*cxClient) / ((0.8 - PLR)*cxClient) * get_table(length - 1);
	char buffer[20];
	//_itoa_s(cx, buffer, 10);
	int diglt;
	if (cx < 10) diglt = 3;
	else diglt = 4;
	_gcvt_s(buffer, 20, cx, diglt);
	string s(buffer);
	return s + "um";
}
string int_to_str_y(int y, int cyClient)
{
	double cy;
	cy = ((0.8*cyClient - y) / (0.5*cyClient)) * 100;
	char buffer[20];
	//_itoa_s(cy, buffer,10);
	_gcvt_s(buffer, 20, cy, 4);
	string s(buffer);
	return s + "%";
}

string dob_to_str(double x)
{
	if (x == 0)
	{
		return "";
	}
	else
	{
		char buffer[20];
		_gcvt_s(buffer, 20, x, 4);
		string s(buffer);
		return s;
	}
}

//粒径字典
double get_table(int i)
{
	double table[28];
	table[0] = 0.1;
	table[1] = 1.1;
	table[2] = 3.5;
	table[3] = 6.25;
	table[4] = 8.75;
	table[5] = 12.5;
	table[6] = 17.5;
	table[7] = 22.5;
	table[8] = 27.5;
	table[9] = 32.5;
	table[10] = 37.5;
	table[11] = 42.5;
	table[12] = 47.5;
	table[13] = 55;
	table[14] = 65;
	table[15] = 75;
	table[16] = 85;
	table[17] = 95;
	table[18] = 110;
	table[19] = 130;
	table[20] = 150;
	table[21] = 170;
	table[22] = 190;
	table[23] = 225;
	table[24] = 275;
	table[25] = 325;
	table[26] = 375;
	table[27] = 400;
	return table[i];
}
string get_table_s(int i)
{
	string table[28];
	table[0] = "0.1";
	table[1] = "1.1";
	table[2] = " 3.5";
	table[3] = "6.25";
	table[4] = "8.75";
	table[5] = "12.5";
	table[6] = "17.5";
	table[7] = "22.5";
	table[8] = "27.5";
	table[9] = "32.5";
	table[10] = " 37.5";
	table[11] = " 42.5";
	table[12] = " 47.5";
	table[13] = " 55";
	table[14] = "65";
	table[15] = "75";
	table[16] = "85";
	table[17] = "95";
	table[18] = "110";
	table[19] = "130";
	table[20] = "150";
	table[21] = "170";
	table[22] = "190";
	table[23] = "225";
	table[24] = "275";
	table[25] = "325";
	table[26] = "375";
	table[27] = "400";
	return table[i];
}


