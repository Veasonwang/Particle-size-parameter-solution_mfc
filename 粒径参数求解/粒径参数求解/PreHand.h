/*

����ģ�飬��Ҫ�������ݵĴ��������������࣬��t_rowΪ����Ľڵ㣬��tableΪ��ȡ�ı�����ڴ��е����ݽṹ����������һ������

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
	char name[20];								//������Ʒ���
	int n_row;
	double *data;								//����ֲ�����
	double *add_data;							//�����ۼ�����

	//������Ԥ����
	double Size_Middle;
	double SO;
	double Size_Average;
	double Skew;
	double Kurtosis;
	t_row *next;
	t_row();
	//���������ֵ
	double get_size_middle(double *data);
	//��÷�ѡϵ��
	double get_so(double *data);
	//���ݰٷֱȻ�ȡ������С
	double get_um(double *data, double per);
	//���ƽ������
	double get_average_size(double *data, int length);
	//���ƫ��
	double get_Skew(double *data, int length);
	//��÷��
	double get_Kurtosis(double *data, int length);
};
//��ȡ�����ݴ��浽����࣬��������һ����������ݽṹ
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

//�ָ��ַ��������table��
int fill_data_table(string &a, int row, table *table1, int column);
//��ȡ�ļ������ж�ȡ���ݵ��ַ�����
void get_restlt_data(string f_name, int *length, table *table1);
//���������ַ�����ת�������ڻ�ͼ
string int_to_str_x(int x, int cxClient,int length);
string int_to_str_y(int y, int cyClient);
string dob_to_str(double x);

//�����ֵ�
double get_table(int i);
string get_table_s(int i);

