// SetTests.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include <Set.h>

TEST(SuperSet, InitializedEmpty) {
    Set set;
    EXPECT_EQ( true, set.isEmpty() );
}

TEST(SuperSet, isNotEmpty) {
    Set set;
    set.add(1);
    EXPECT_EQ( false, set.isEmpty() );
}

TEST(SuperSet, doesNotContainNaturalNumber)
{
    Set set;
    EXPECT_EQ(false, set.contains(2));
}

TEST(SuperSet, doesContainNaturalNumber)
{
    Set set;
    set.add(2);
    EXPECT_EQ(true, set.contains(2));
}

TEST(SuperSet, stillEmptyAddingZero)
{
    Set set;
    set.add(0);
    EXPECT_EQ(true, set.isEmpty());
}

TEST(SuperSet, zeroNotAdded)
{
    Set set;
    set.add(1);
    set.add(0);
    EXPECT_EQ( false, set.contains(0) );
}

TEST(SuperSet, removeItem)
{
    Set set;
    set.add(1);
    set.remove(1);
    EXPECT_EQ( false, set.contains(1) );
}

TEST(SuperSet, removeNonExistantItem)
{
    Set set;
    set.add(1);
    set.add(2);
    set.remove(3);
    EXPECT_EQ( true, set.contains(1) );
    EXPECT_EQ( true, set.contains(2) );
    EXPECT_EQ( false, set.contains(3) );
}

TEST(SuperSet, sameNumberAddedRemovedOnce)
{
    Set set;
    set.add(1);
    set.add(1);
    set.remove(1);
    EXPECT_EQ( false, set.contains(1) );
}

TEST(SuperSet, sameNumberAddedThenRemovedAndReadded)
{
    Set set;
    set.add(1);
    set.add(1);
    set.remove(1);
    set.add(1);
    EXPECT_EQ( true, set.contains(1) );
}

TEST(SuperSet, emptySetIntersections)
{
    Set set1;
    Set set2;
    Set intersection = set1.getIntersection(set2);
    EXPECT_EQ( true, intersection.isEmpty() );
}

TEST(SuperSet, bothHaveOne)
{
    Set set1;
    Set set2;
    set1.add(1);
    set2.add(1);
    Set intersection = set1.getIntersection(set2);
    EXPECT_EQ( true, intersection.contains(1) );
}

TEST(SuperSet, bothHaveDifferentValues)
{
    Set set1;
    Set set2;
    set1.add(1);
    set1.add(5);
    set2.add(1);
    set2.add(2);
    Set intersection = set1.getIntersection(set2);
    EXPECT_EQ( true, intersection.contains(1) );
    EXPECT_EQ( false, intersection.contains(5) );
}

TEST(SuperSet, reversable)
{
    Set set1;
    Set set2;
    set1.add(1);
    set1.add(5);
    set2.add(1);
    set2.add(2);
    Set intersection = set1.getIntersection(set2);
    Set intersection2 = set2.getIntersection(set1);

    EXPECT_EQ( true, intersection.contains(1) );
    EXPECT_EQ( false, intersection.contains(5) );

    EXPECT_EQ( true, intersection2.contains(1) );
    EXPECT_EQ( false, intersection2.contains(5) );
}

TEST(SuperSet, emptySetWithNonEmpty)
{
    Set set1;
    Set set2;
    set1.add(1);

    Set intersection = set1.getIntersection(set2);
    EXPECT_EQ( false, intersection.contains(1) );
    EXPECT_EQ( true, intersection.isEmpty() );
}

TEST(SuperSet, emptyUnion)
{
    Set set1;
    Set set2;

    Set union1 = set1.getUnion(set2);
    EXPECT_EQ( true, union1.isEmpty() );
}

TEST(SuperSet, emptyUnionPlusNonEmpty)
{
    Set set1;
    Set set2;

    set1.add(1);

    Set union1 = set1.getUnion(set2);
    EXPECT_EQ( true, union1.contains(1) );
}

TEST(SuperSet, bothSetsHaveDataUnion)
{
    Set set1;
    Set set2;

    set1.add(1);
    set2.add(2);

    Set union1 = set1.getUnion(set2);
    EXPECT_EQ( true, union1.contains(1) );
    EXPECT_EQ( true, union1.contains(2) );
}

TEST(SuperSet, unionIsReversible)
{
    Set set1;
    Set set2;

    set1.add(2);
    set1.add(7);
    set2.add(10);
    set2.add(11);

    Set union_1_to_2 = set1.getUnion(set2);
    Set union_2_to_1 = set2.getUnion(set1);

}


/*TEST(SuperSet, InitialSizeIsZero) {
    Set set;
    EXPECT_EQ(0, set.size());
}*/

int main(int argc, char** argv)
{
    // run all tests
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
