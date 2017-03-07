#include "LunExServices.h"
#include "stockquote.h"

StockQuote::StockQuote( std::string symbol, LunExServices& service )
    : m_symbol( symbol ), m_service( service )
{
    m_price = m_service.currentPrice( m_symbol.c_str() );
}

double StockQuote::Price( double shares ) const
{
    return shares * m_price;
}

double StockQuote::Total( double shares ) const
{
    double subtotal, total;
    subtotal = shares * m_price;
    total = subtotal + subtotal * 0.02 + 10.0;

    return total;
}
