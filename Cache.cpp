#include "Cache.h"

#include <stdio.h>

Cache::Cache(ReplaceAlgorithm *ra) 
{
        m_ra = ra; 
}
Cache::~Cache() 
{
    delete m_ra; 
}
void Cache::Replace()
{
    m_ra->Replace(); 
}