/*
 * japaneseString.cpp
 *
 *  Created on: 2012/04/03
 *      Author: dasher
 */

#include <string>
#include <iostream>

using namespace std;

/* 実行結果：
 * あいうえお と あいうえお を比較
 * OK
 *
 * あいうえお と かきくけこ を比較
 * NG
 *
 * あいうえお と あいうえお を 0 から長さ 5 で比較
 * NG
 *
 * あいうえお と あいうえお を 0 から長さ 15 で比較
 * OK
 */
int main()
{
	int ret;
	string str="あいうえお";

	// 結果 OK
	cout << str << " と あいうえお を比較" << endl;
	if(str.compare("あいうえお")==0) {
		cout << "OK" << endl;
	} else {
		cout << "NG" << endl;
	}
	cout << endl;

	// 結果 NG
	cout << str << " と かきくけこ を比較" << endl;
	if(str.compare("かきくけこ")==0) {
		cout << "OK" << endl;
	} else {
		cout << "NG" << endl;
	}
	cout << endl;

	// 結果NG
	cout << str << " と あいうえお を 0 から長さ 5 で比較" << endl;
	if(str.compare(0,5,"あいうえお")==0) {
		cout << "OK" << endl;
	} else {
		cout << "NG" << endl;
	}
	cout << endl;

	// 結果OK
	// UTF-8の場合 1文字の長さは3
	cout << str << " と あいうえお を 0 から長さ " << str.length() << " で比較" << endl;
	if(str.compare(0,str.length(),"あいうえお")==0) {
		cout << "OK" << endl;
	} else {
		cout << "NG" << endl;
	}

	return 0;
}
