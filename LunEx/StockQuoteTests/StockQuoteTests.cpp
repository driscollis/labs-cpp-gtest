#include "../src/LunExServices.h"
#include "../src/stockquote.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Return;

class HandMock : public LunExServices{
public:
    HandMock() : transactions( 0 ) {}

    double currentPrice( const char* symbol )
    {
        ++transactions;
        return 10.0;
    }

    int transactions;
};

class GoogleMock : public LunExServices{
public:
    MOCK_METHOD1(currentPrice, double(const char* symbol));
};


TEST(StockQuotes, DISABLED_CanConstruct) {
    LunExServices l;
    StockQuote( "MIKE", l );
}

TEST(StockQuotes, DISABLED_ReturnsTotal) {
    LunExServices l;
    StockQuote q( "MIKE", l );
    EXPECT_NE( 0, q.Total( 1 ) );
}

TEST(HandMockTests, GetsCurrentPrice)
{
    HandMock m;
    StockQuote q( "STEVE", m );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
}

TEST(HandMockTests, GetsCurrentPriceMultiShare) {
    HandMock m;
    StockQuote q( "Steve", m );
    EXPECT_EQ( 50.0, q.Price( 5.0 ) );
}

TEST(HandMockTests, GetSameStockQuoteTwice){
    HandMock m;
    StockQuote q( "STEVE", m );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
}

TEST(HandMockTests, GetTransactionTotal){
    HandMock m;
    StockQuote q( "DELL", m );
    EXPECT_EQ(112.0, q.Total( 10 ));
}

TEST(HandMockTests, OnlyOneTransaction) {
    HandMock m;
    StockQuote q( "DELL", m );
    q.Price( 50 );
    q.Total( 100 );
    EXPECT_EQ(1, m.transactions);
}

TEST(GoogleMockTests, GetsCurrentPrice)
{
    GoogleMock m;
    EXPECT_CALL(m, currentPrice( ::testing::StrEq("STEVE") ) ).WillOnce(Return(10.0));
    StockQuote q( "STEVE", m );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
}

TEST(GoogleMockTests, GetsCurrentPriceMultiShare) {
    GoogleMock m;
    EXPECT_CALL(m, currentPrice( ::testing::StrEq("STEVE") ) ).WillOnce(Return(10.0));
    StockQuote q( "STEVE", m );
    EXPECT_EQ( 50.0, q.Price( 5.0 ) );
}

TEST(GoogleMockTests, GetSameStockQuoteTwice){
    GoogleMock m;
    EXPECT_CALL(m, currentPrice( ::testing::StrEq("STEVE") ) ).WillOnce(Return(10.0));
    StockQuote q( "STEVE", m );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
    EXPECT_EQ( 10.0, q.Price( 1.0 ) );
}

TEST(GoogleMockTests, GetTransactionTotal){
    GoogleMock m;
    EXPECT_CALL(m, currentPrice( ::testing::StrEq("DELL") ) ).WillOnce(Return(10.0));
    StockQuote q( "DELL", m );
    EXPECT_EQ(112.0, q.Total( 10 ));
}

TEST(GoogleMockTests, OnlyOneTransaction) {

    GoogleMock m;
    EXPECT_CALL(m, currentPrice( ::testing::StrEq("DELL") ) ).WillOnce(Return(10.0));
    StockQuote q( "DELL", m );
    q.Price( 50 );
    q.Total( 100 );
//    EXPECT_EQ(1, m.transactions);
}

int main(int argc, char** argv)
{
    // run all tests
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
