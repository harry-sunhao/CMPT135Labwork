
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Yile Zhao>
// St.# : <301368719>
// Email: <yza458@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "a1.h"
#include "cmpt_error.h"
#include <iostream>      // no other #includes are allowed
#include <fstream>       // for this assignment
#include <string>
#include <cassert>

using namespace std;



str_array make_empty(int cap = 10) {
	str_array result;
	result.arr = new string[cap];
	result.capacity = cap;
	result.size = 0;
	return result;
}


void deallocate(str_array& arr) {
	//if arr.arr == nullptr
	if (arr.arr != nullptr)
		delete[] arr.arr;
	arr.arr = nullptr;
}


// Returns the percentage of the array that is in use.
double pct_used(const str_array& arr) {
	double num;
	num = (double)arr.size / arr.capacity;
	return num;
}


string to_str(const str_array& arr) {
	if (arr.size == 0) {
		return "[]";
	}
	if (arr.size == 1) {
		string result;
		for (int i = 0; i < arr.size; i++) {
			result = result + arr.arr[i];
		}
		return "["+result+"]";
	}
	else {
		string result;
		for (int i = 0; i < arr.size-1; i++) {
			result = result +"[\""+ arr.arr[i]+"\"],";
		}
		result = result + "[\"" + arr.arr[arr.size - 1] + "\"]";
		return result;
	}


}

bool operator==(str_array a, str_array b) {
	bool flag = true;
	if (a.size != b.size)
		flag = false;
	else
		flag = true;
	for (int i = 0; i < a.capacity; i++) {
		if (a.arr[i] != b.arr[i]) {
			flag = false;
			break;
		}
		else
			flag = true;
	}
	return flag;

}

string get(const str_array& arr, int i)
{
	if (i < 0 || i >= arr.size) {
		cmpt::error("invalid index");
	}
	return arr.arr[i];
}

void set(str_array& arr, int i, const string& s) {
	if (i < 0 || i >= arr.size) {
		cmpt::error("invalid index");
	}
	arr.arr[i] = s;

}
void clear(str_array& arr) {
	arr.size = 0;
}

//[]  size = 0  placetoinsert = 0
void add_right(str_array& arr, const string& s) {

	if (arr.size < arr.capacity) {
		arr.arr[arr.size] = s;
	}
	else
	{
		arr.capacity *= 2;
		string* temp = new string[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			temp[i] = arr.arr[i];
		}
		delete[] arr.arr;
		arr.arr = temp;
		arr.arr[arr.size] = s;
	}
	arr.size += 1;
}
void add_left(str_array& arr, const string& s) {

	if (arr.size < arr.capacity) {
		for (int i = arr.size; i > 0; i--) {
			arr.arr[i] = arr.arr[i - 1];
		}
		arr.arr[0] = s;
	}
	else
	{
		arr.capacity *= 2;
		string* temp = new string[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			temp[i] = arr.arr[i];
		}
		delete[] arr.arr;
		arr.arr = temp;
		for (int i = arr.size; i > 0; i--) {
			arr.arr[i] = arr.arr[i - 1];
		}
		arr.arr[0] = s;
	}
	arr.size += 1;
}


str_array make_fromFile(const string& fname) {
	ifstream fin(fname);
	str_array result = make_empty();
	string s;
	while (fin >> s) add_right(result, s);
	return result;

}
void shrink_to_fit(str_array& arr) {
	if (arr.size==0)
	{
		arr.capacity = 1;
	}
	else
	{
		arr.capacity = arr.size;
	}
}
//
// ... put your test functions here (one test function for each
//     function above) ...
//
void print(const str_array& arr)
{
	cout << to_str(arr);
}
void println(const str_array& arr)
{
	cout << to_str(arr) << endl;
}
void test_Q1(int capacity=15) {
	str_array temp= make_empty(capacity);
	cout << "After make_empty, the str_array size is " << temp.size<<" and the capcity is "<<temp.capacity<<" and the context is ";
	println(temp);
}
void test_Q2(str_array& arr) {
	deallocate(arr);
	cout << "After deallocate, The size is " << arr.size << " and the capcity is " << arr.capacity;
	if (arr.arr==nullptr)
	{
		cout << "It's pointer is nullptr, so it is delete" << endl;
	}
}
void test_Q3(int capacity=15){
	str_array arr = make_empty(capacity);
	arr.size = 5;
	cout << "The size is " << arr.size << " and the capcity is " << arr.capacity;
	cout << "The pct_used is " << pct_used(arr) << endl;
}
void test_Q4(str_array& arr) {
	cout << "Test to_Str: The str_arr is " << to_str(arr) << endl;
}
void test_Q5(str_array& arr) {
	int index = 0;
	arr.size = 1;
	set(arr, index, "aaa");
	cout<<"After set(arr,0,aaa) the str_arr is ";
	println(arr);
	cout << "The str_arr["<<index<<"]is " << get(arr,index) << endl;
}
void test_Q6(str_array& arr, const string& s) {
	add_right(arr, s);
	cout << "The str_arr after add_right is " << to_str(arr) << endl;
}
void test_Q7(str_array& arr1, str_array& arr2) {
	cout << "The str_arr1 (" << to_str(arr1)<<") and str_arr2("<<to_str(arr2) <<") ";
	if (arr1==arr2)
	{
		cout << "is equal";
	}
	else
	{
		cout << "is not equal";
	}
	cout<<endl;
}
void test_Q8(str_array& arr) {
	clear(arr);
	cout << "After clean the str_arr's size is " <<arr.size << endl;
}
void test_Q9(str_array& arr, const string& s) {
	add_left(arr, s);
	cout << "The str_arr after add_left is " << to_str(arr) << endl;
}
void test_Q10(str_array& arr) {
	cout << "Before shrink_to_fit, The size is " << arr.size <<" and the capcity is "<<arr.capacity<< endl;
	shrink_to_fit(arr);
	cout << "After shrink_to_fit, The size is " << arr.size << " and the capcity is " << arr.capacity << endl;

}

int main() {
	cout << "Assignment 1!\n";
	str_array arr = make_empty();
	test_Q1();
	test_Q2(arr);
	test_Q3();
	arr = make_empty();
	test_Q5(arr);
	test_Q4(arr);
	test_Q6(arr, "bbb");
	str_array arr1 = make_empty();
	add_right(arr1, "aaa");
	add_right(arr1,"bbb");
	test_Q7(arr, arr1);
	test_Q9(arr,"000");
	test_Q7(arr, arr1);
	test_Q10(arr);
	test_Q8(arr);
}
