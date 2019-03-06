agma once
#ifdef MYLIB_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" _declspec(dllimport)
#endif
MYLIBAPI int add(int nleft, int nRight);
MYLIBAPI int sub(int nleft, int nRight);
MYLIBAPI int mul(int nleft, int nRight);
MYLIBAPI int divi(int nleft, int nRight);
