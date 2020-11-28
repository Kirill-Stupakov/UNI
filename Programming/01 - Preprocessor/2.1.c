#define p 1
#define q 3
#define r 1

#if !((p+q > r) && (p+r > q) && (r+q > p))
    #error p,q,r do not form a triangle!
#endif
