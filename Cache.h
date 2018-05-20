// #include "ReplaceAlgorithm.h"

class ReplaceAlgorithm;

class Cache
{
private:
	ReplaceAlgorithm *m_ra;
public:
	Cache(ReplaceAlgorithm *ra);
	~Cache();
	void Replace();
};