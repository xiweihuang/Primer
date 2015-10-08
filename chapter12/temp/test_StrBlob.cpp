#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdio.h>
#include <string>


int main()
{
	StrBlob sb;
	sb.push_back("Kobe");
	sb.push_back("Jordan");

	// for (auto beg = sb.begin(); beg != sb.end(); beg.incr()) {
	// 	printf("%s\n", beg.deref().c_str());
	// }

	for ( StrBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg != pend; pbeg.incr() ) {
		printf("%s\n", pbeg.deref().c_str());
	}
	return 0;
}
