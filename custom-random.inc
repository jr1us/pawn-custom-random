/*
*
*   - Author: jrius ( vk.com/s.fridom | t.me/dcapybarov )
*   - Include: custom-random
*   - Developed for compiler version 3.10.8
*   
*   - English documentation - https://github.com/jr1us/pawn-custom-random/blob/main/README.md
*   - Russain documentation - https://github.com/jr1us/pawn-custom-random/blob/main/README.ru.md
*
*/

#if !defined callback
    #define #define callback%0(%1) forward%0(%1);public%0(%1)
#endif

static gCustomSeed = 0;

stock SetRandomWithSeed(seed)
    return gCustomSeed = seed;

stock RandomValue(value, seed = 0) 
{
    if(seed)
        gCustomSeed = seed;
        
    gCustomSeed = (gCustomSeed * 214013 + 2531011) & 0x7FFFFFFF;
    return gCustomSeed % (value + 1);
}

#if defined _ALS_random
    #undef random
#else
    #define _ALS_random
#endif
#define	random RandomValue


stock RandomEx(...)
{
    static totalArgs, seed, result;
    
    totalArgs = numargs();

    if(totalArgs <= 0)
        return print("[randomEx] requires min one argument");

    seed = (getarg(totalArgs) * 214013 + 2531011) & 0x7FFFFFFF;
    result = 0;

    for(new i; i < totalArgs; i++)
        result += seed % (getarg(i) + 1);

    return result;
}

// Examples

callback random_OnGameModeInit()
{
    SetRandomWithSeed(12345); 
    
    for (new i = 0; i < 5; i++) 
        printf("[1] random number %d: %d", i, RandomEx(1, 100));
    
    printf("[-----------------------------------------------------]");

    for (new i = 0; i < 5; i++) 
        printf("[2] random number %d: %d", i, RandomEx(1, 100));
    
    printf("[-----------------------------------------------------]");

    for (new i = 0; i < 5; i++) 
        printf("[3] random number %d: %d", i, RandomEx(1, 100));
    
    printf("[-----------------------------------------------------]");

    for (new i = 0; i < 5; i++) 
        printf("[4] random number %d: %d", i, RandomEx(1, 100, 12346));
    
    printf("[-----------------------------------------------------]");

    SetRandomWithSeed(gettime() - 5 + 30000 + 200);

    for (new i = 0; i < 5; i++) 
        printf("[5] random number %d: %d", i, random(499999999));
    
    return 1;
}

/*

Tests

Test: 1

[1] random number 0: 53
[1] random number 1: 12
[1] random number 2: 62
[1] random number 3: 49
[1] random number 4: 22
[-----------------------------------------------------]
[2] random number 0: 53
[2] random number 1: 12
[2] random number 2: 62
[2] random number 3: 49
[2] random number 4: 22
[-----------------------------------------------------]
[3] random number 0: 53
[3] random number 1: 12
[3] random number 2: 62
[3] random number 3: 49
[3] random number 4: 22
[-----------------------------------------------------]
[4] random number 0: 12276
[4] random number 1: 5181
[4] random number 2: 4222
[4] random number 3: 6023
[4] random number 4: 8121
[-----------------------------------------------------]
[5] random number 0: 8
[5] random number 1: 11
[5] random number 2: 2
[5] random number 3: 13
[5] random number 4: 12

Test 2

[1] random number 0: 53
[1] random number 1: 12
[1] random number 2: 62
[1] random number 3: 49
[1] random number 4: 22
[-----------------------------------------------------]
[2] random number 0: 53
[2] random number 1: 12
[2] random number 2: 62
[2] random number 3: 49
[2] random number 4: 22
[-----------------------------------------------------]
[3] random number 0: 53
[3] random number 1: 12
[3] random number 2: 62
[3] random number 3: 49
[3] random number 4: 22
[-----------------------------------------------------]
[4] random number 0: 12276
[4] random number 1: 5181
[4] random number 2: 4222
[4] random number 3: 6023
[4] random number 4: 8121
[-----------------------------------------------------]
[5] random number 0: 8
[5] random number 1: 11
[5] random number 2: 2
[5] random number 3: 13
[5] random number 4: 12

*/