#ifndef GOP_RANDOM_H_
#define GOP_RANDOM_H_

namespace rnd
{

void Init();

int RandInt();
int RandInt(int limit);           // Inclusive
int RandInt(int start, int end);  // Inclusive

} // Namespace rnd

#endif