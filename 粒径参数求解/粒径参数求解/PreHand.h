/*

处理模块，主要负责数据的处理，定义了两个类，类t_row为链表的节点，类table为读取的表格在内存中的数据结构，本质上是一个链表

*/
#pragma once
#include<iostream>   
#include<string>   
#include<fstream> 
#include<stdlib.h>
#include<math.h>
#include "stdafx.h"
using namespace std;
#include<string>
#define PLR 0.2
//int length;
class t_row
{
public:
	char name[20];								//储存样品编号
	int n_row;
	double *data;								//储存分布数据
	double *add_data;							//储存累加数据

	//参数的预定义
	double Size_Middle;
	double SO;
	double Size_Average;
	double Skew;
	double Kurtosis;
	t_row *next;
	t_row();
	//获得粒径中值
	double get_size_middle(double *data);
	//获得分选系数
	double get_so(double *data);
	//根据百分比获取粒径大小
	double get_um(double *data, double per);
	//获得平均粒径
	double get_average_size(double *data, int length);
	//获得偏度
	double get_Skew(double *data, int length);
	//获得峰度
	double get_Kurtosis(double *data, int length);
};
//读取的数据储存到这个类，本质上是一个链表的数据结构
class table
{
protected:
	string *table_head;
	t_row *head;
	int column;
public:
	table();
	table(int column_);
	void createNode();
	void insert_name(char name[20]);
	void insert_data(double *data);
	void insert_add_data(double *adddata);
	double get_data(int row, int column);
	double get_add_data(int row, int column);
	void Caculate();
	double get_SizeMiddle(int row);
	double get_So(int row);
	double get_AverageSize(int row);
	double get_Skew(int row);
	double get_Kurtosis(int row);
	void get_name(int row,char a[20]);
	int name_to_int(string _name);
	void Init();
	int Getlength()
	{
		return column;
	}
	int Getrow();
	int Output(HANDLE hFile);
	void input_column(int _column);
};
double Catof(string a);
int get_row(string &a);
int get_column(string &a);

//分割字符串，填充table类
int fill_data_table(string &a, int row, table *table1, int column);
//读取文件，按行读取数据到字符串中
void get_restlt_data(string f_name, int *length, table *table1);
//浮点数到字符串的转换，用于绘图
string int_to_str_x(int x, int cxClient,int length);
string int_to_str_y(int y, int cyClient);
string dob_to_str(double x);

//粒径字典
double get_table(int i);
string get_table_s(int i);

