

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "StarTrek/Game.h"
#include "StarTrek/Klingon.h"

using ::testing::Return;
using namespace StarTrek;

class WebGadgetProxyMock : public WebGadgetProxy
{
public:
    WebGadgetProxyMock() : WebGadgetProxy( NULL ) {}
    MOCK_METHOD1(parameter, string(string));
    MOCK_METHOD1(variable, void*(string));
    MOCK_METHOD1(writeLine, void(string));
};

class KlingonMock : public Klingon
{
public:
    MOCK_METHOD0(distance, int());
    MOCK_METHOD0(energy, int());
    MOCK_METHOD0(destroy, void());
};

class RandomNumberMock : public StarTrek::Game::RandomGenerator
{
public:
    MOCK_METHOD1(Get, int(int));

};

TEST(StarTrekCharacterization, FirePhotonDestroyKlingon) {
    std::unique_ptr<RandomNumberMock> gen( new RandomNumberMock() );
    EXPECT_CALL( *gen, Get( ::testing::_ ) ).WillRepeatedly(Return(1));
    Game g( std::move( gen ) );
    WebGadgetProxyMock wg;
    KlingonMock kl;
    EXPECT_CALL( wg, parameter( ::testing::StrEq("command"))).WillRepeatedly(Return(string("photon")));
    EXPECT_CALL( wg, variable( ::testing::StrEq("target"))).WillOnce(Return((void*)&kl));
    EXPECT_CALL( wg, writeLine( "Photons hit Klingon at 0 sectors with 801 units" )).WillRepeatedly(Return());
    EXPECT_CALL( wg, writeLine( "Klingon destroyed!" )).WillRepeatedly(Return());
    EXPECT_CALL( kl, distance() ).WillOnce(Return(0));
    EXPECT_CALL( kl, energy() ).WillOnce(Return(1));
    EXPECT_CALL( kl, destroy() ).WillOnce( Return() );
    g.fireWeapon( wg );
}


int main(int argc, char** argv)
{
    StarTrek::Game game;
    // run all tests
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
