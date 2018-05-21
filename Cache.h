 #include "ReplaceAlgorithm.h"

class Cache
{
private:
	ReplaceAlgorithm *m_ra;
public:
	Cache(ReplaceAlgorithm *ra);
	~Cache();
	void Replace();
};