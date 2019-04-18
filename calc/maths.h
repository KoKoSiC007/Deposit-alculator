#ifndef MATHS_H
#define MATHS_H


#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
#include <locale>
#include "../Documents/Prog/Semestr2/DepositCalc/DepositCalc/date-master/include/date/date.h"
#include "safe.cpp"

// перечесление валюты (она у всех вкладов одинаковая(одна из трех))
enum currency{
    RU,
    USD
};
/*

 Это базовый класс для рассчета всех вкладов так как у вкладов Сохраняй, Пополняй, Управляй есть одинаковые характиристики такие как проценты сумма в клада и т д.

 */
typedef int term;
typedef double amount;

class Maths {
    currency depositCurrnecy; // валюта
    float interstRate; // процент
    date::year_month_day depositOpeningDate; // дата открытия
    date::year_month_day depositEndDate; // дата закрытия
    term termOfDeposit; // срок вклада
    amount depositAmount; // сумма вклада
    bool interestCapitalization = true; // капитализация процентов
    bool earlyClosingOfTheDeposit = false; // досрочное закрытие вклада
    double refillAmountForEachMonth = 0.0; // на сколько пополнять каждый месяц
    term calculateEndDate(date::year_month_day, date::year_month_day);
    double income;
    virtual void setCurrnetProcent(int, int, currency); // расчет процентов (у каждого вклада свои проценты)
    virtual int correctAmountValueRU();
    virtual int correctDateValueRU();
    virtual int correctAmountValueUSD();
    virtual int correctDateValueUSD();
    virtual double yourIncome();

public:

    // Тестовые конструкторы чтобы проверить что все работает
    Maths();
    Maths(currency,date::year_month_day,date::year_month_day, amount,date::year_month_day);
    Maths(currency, date::year_month_day, date::year_month_day, amount, bool, bool);
    double showResult();
};

#endif // MATHS_H
