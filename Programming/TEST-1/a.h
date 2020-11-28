#if (!defined(b_def) && defined(a_def))
    #error A must be included!
#endif

#if (defined(b_def) || !defined(a_def))
    #define a_def
    #undef b_def

    //File Content
#endif

if (...)
{
    ...
}