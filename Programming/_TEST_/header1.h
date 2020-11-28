#if (!defined(first_def) || !defined(second_def))
    #ifdef first_def
        #define second_def
    #endif

    #define first_def

    x++;
#endif
