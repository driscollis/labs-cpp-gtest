#ifndef STOCKQUOTE_H
#define STOCKQUOTE_H

#include <string>

class LunExServices;

class StockQuote
{
public:
    StockQuote( std::string symbol, LunExServices& service );

    double Price( double shares ) const;
    double Total( double shares ) const;

private:
    double m_price;
    std::string m_symbol;
    LunExServices& m_service;
};

#endif // STOCKQUOTE_H
