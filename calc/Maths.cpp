//
//  Maths.cpp
//  DepositCalc
//
//  Created by Grisha Okin on 14/04/2019.
//  Copyright © 2019 Grisha Okin. All rights reserved.
//

#include "Maths.hpp"
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
#include <locale>
#include <iostream>

Maths::Maths(){}

Maths::Maths(currency value, date::year_month_day openingDate, date::year_month_day endDate, amount amount, date::year_month_day dateOfEarlyClosing){
	
	depositCurrnecy = value;
	depositOpeningDate = openingDate;
	depositEndDate = endDate;
	depositAmount = amount;
	termOfDeposit = calculateEndDate(openingDate, dateOfEarlyClosing);
	interestCapitalization = false;
	earlyClosingOfTheDeposit = true;
	if (termOfDeposit < 184) {
		interstRate = 0.0001;
	}else{
		switch (depositCurrnecy) {
			case RU:
				setCurrnetProcent(correctDateValueRU(), correctAmountValueRU(), depositCurrnecy);
				break;
			case USD:
				setCurrnetProcent(correctDateValueUSD(), correctAmountValueUSD(), depositCurrnecy);
				break;
			default:
				break;
		}
		interstRate *= 2./3;
	}
	yourIncome();
}

Maths::Maths(currency value, date::year_month_day openingDate, date::year_month_day endDate, amount amount, bool isCapitilization = true, bool isEarlyClosing = false){
	depositCurrnecy = value;
	depositOpeningDate = openingDate;
	depositEndDate = endDate;
	depositAmount = amount;
	interestCapitalization = isCapitilization;
	earlyClosingOfTheDeposit = isEarlyClosing;
	termOfDeposit = calculateEndDate(openingDate, endDate);
	switch (depositCurrnecy) {
		case RU:
			setCurrnetProcent(correctDateValueRU(), correctAmountValueRU(), depositCurrnecy);
			break;
		case USD:
			setCurrnetProcent(correctDateValueUSD(), correctAmountValueUSD(), depositCurrnecy);
		default:
			break;
	}
	yourIncome();
}

term Maths::calculateEndDate(date::year_month_day openingDate, date::year_month_day endDate){
	std::cout << (date::sys_days{endDate} - date::sys_days{openingDate}).count() << std::endl;
	 return (date::sys_days{endDate} - date::sys_days{openingDate}).count();
}

void Maths::setCurrnetProcent(int countMonth, int maney, currency currency ){
	
	float procent = 0.0;
	switch (currency) {
		case RU:
		{
//
			procent = procentSafeRU[maney][countMonth]/100;
		}
			break;
		case USD:
		{
//
			procent = procentSafeUSD[maney][countMonth]/100;
		}
			break;
		default:
			break;
	}
	interstRate = procent;
//	std::cout << interstRate << std::endl;
}

int Maths::correctAmountValueRU(){
	int returned;
	if ((1000 <= depositAmount) && (depositAmount < 100000)) returned = 0;
	else if ((100000 <= depositAmount) && (depositAmount < 400000)) returned = 1;
	else if ((400000 <= depositAmount) && (depositAmount < 700000)) returned = 2;
	else if ((700000 <= depositAmount) && (depositAmount < 2000000)) returned = 3;
	else returned = 4;
	return returned;
	
}
int Maths::correctDateValueRU(){
	int returned ;
	if ((30 <=  termOfDeposit) && (termOfDeposit < 61)) returned = 0;
	else if ((61 <= termOfDeposit) && (termOfDeposit < 91)) returned = 1;
	else if ((91 <= termOfDeposit) && (termOfDeposit < 183)) returned = 2;
	else if ((183 <= termOfDeposit) && (termOfDeposit < 366)) returned = 3;
	else returned =  4;
 	return returned;
}

int Maths::correctAmountValueUSD(){
	int returned;
	
	if ((100 <= depositAmount) && (depositAmount < 3000)) returned = 0;
	else if ((3000 <= depositAmount) && (depositAmount < 10000)) returned = 1;
	else if ((10000 <= depositAmount) && (depositAmount < 20000)) returned = 2;
	else if ((20000 <= depositAmount) && (depositAmount < 100000)) returned = 3;
	else returned = 4;
	
	return returned;
}
int Maths::correctDateValueUSD(){
	int returned = correctDateValueRU();
	return returned;
}

double Maths::yourIncome(){
	
	if (interestCapitalization){
//		std::cout << pow(1+interstRate/12,termOfDeposit/30) << std::endl;
		double procent = std::round(((pow(1+interstRate/12,termOfDeposit/30)-1)*12/(termOfDeposit/30))*10000)/10000;
		return  income = depositAmount * procent * termOfDeposit/365;
	}
	
	return income = depositAmount*interstRate*termOfDeposit/365;
	
}

double Maths::showResult(){
	std::cout << "Ваша вклад на: " << termOfDeposit << " дней, выгода составит: " << income << " и того на вашем счету к концу срока будет: " << depositAmount + income << std::endl;
	return depositAmount + income;
}
