#include "Set.h"

Set::Set(void)
{
}


Set::~Set(void)
{
}

bool Set::isEmpty() const
{
    return m_storage.empty();
}

void Set::add( unsigned int to_add )
{
    if ( ( to_add > 0 ) && !contains(to_add) )
    {
        m_storage.push_back( to_add );
    }
}

bool Set::contains( unsigned int to_check ) const
{
    for ( unsigned int i = 0; i < m_storage.size(); ++i )
    {
        if ( to_check == m_storage[i] )
        {
            return true;
        }
    }
    return false;
}

void Set::remove( unsigned int to_remove )
{
    std::vector<unsigned int>::iterator it = m_storage.begin();
    std::vector<unsigned int>::iterator end_it = m_storage.end();
    for (; it != end_it; ++it )
    {
        if ( to_remove == *it )
        {
            m_storage.erase( it );
            return;
        }
    }

}

Set Set::getIntersection( const Set& other )
{
    Set ret;
    for ( unsigned int i = 0; i < m_storage.size(); ++i )
    {
        if ( other.contains( m_storage[i] ) )
        {
            ret.add( m_storage[i] );
        }
    }
    return ret;
}

Set Set::getUnion( const Set& other )
{
    Set ret;
    for ( unsigned int i = 0; i < m_storage.size(); ++i )
    {
        ret.add(m_storage[i]);
    }

    for ( unsigned int i = 0; i < other.m_storage.size(); ++i )
    {
        ret.add(other.m_storage[i]);
    }
    return ret;
}
