#pragma once

#include <vector>

class Set
{
public:
    Set(void);
    ~Set(void);

    bool isEmpty() const;
    void add( unsigned int to_add );
    bool contains( unsigned int to_check ) const;
    void remove( unsigned int to_remove );
    Set getIntersection( const Set& other );
    Set getUnion( const Set& other );

private:
    std::vector<unsigned int> m_storage;
};

