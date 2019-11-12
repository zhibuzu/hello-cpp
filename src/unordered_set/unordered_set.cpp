/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/set/unordered_set.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/11/06 10:49:09
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	//cout  << "test\n";
	std::unordered_set<int> S = {1, 1, 2, 3, 4};
	std::unordered_set<int>::const_iterator itor = S.begin();
	for (; itor != S.end(); ++itor) {
	    std::cout << (*itor) << " ,";
	}
	std::cout << std::endl;

	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
