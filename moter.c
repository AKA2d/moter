#include <stdio.h>

// define bitboard data type
#define U64 unsigned long long
// get bit from bitboard
#define get_bit(bitboard, square) (bitboard & (1ULL << square))
// define set bit macro
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))
// define clear bit macro
#define clear_bit(bitboard, square) (bitboard &= ~(1ULL << square))

enum squares
{
    a8,
    b8,
    c8,
    d8,
    e8,
    f8,
    g8,
    h8,
    a7,
    b7,
    c7,
    d7,
    e7,
    f7,
    g7,
    h7,
    a6,
    b6,
    c6,
    d6,
    e6,
    f6,
    g6,
    h6,
    a5,
    b5,
    c5,
    d5,
    e5,
    f5,
    g5,
    h5,
    a4,
    b4,
    c4,
    d4,
    e4,
    f4,
    g4,
    h4,
    a3,
    b3,
    c3,
    d3,
    e3,
    f3,
    g3,
    h3,
    a2,
    b2,
    c2,
    d2,
    e2,
    f2,
    g2,
    h2,
    a1,
    b1,
    c1,
    d1,
    e1,
    f1,
    g1,
    h1
};

const char *square_to_cordinates[] = {
    "a8",
    "b8",
    "c8",
    "d8",
    "e8",
    "f8",
    "g8",
    "h8",
    "a7",
    "b7",
    "c7",
    "d7",
    "e7",
    "f7",
    "g7",
    "h7",
    "a6",
    "b6",
    "c6",
    "d6",
    "e6",
    "f6",
    "g6",
    "h6",
    "a5",
    "b5",
    "c5",
    "d5",
    "e5",
    "f5",
    "g5",
    "h5",
    "a4",
    "b4",
    "c4",
    "d4",
    "e4",
    "f4",
    "g4",
    "h4",
    "a3",
    "b3",
    "c3",
    "d3",
    "e3",
    "f3",
    "g3",
    "h3",
    "a2",
    "b2",
    "c2",
    "d2",
    "e2",
    "f2",
    "g2",
    "h2",
    "a1",
    "b1",
    "c1",
    "d1",
    "e1",
    "f1",
    "g1",
    "h1"};

// count bits within a board
static inline int count_bits(U64 bitbord)
{
    int count = 0;

    while (bitbord > 0)
    {
        count++;
        bitbord &= bitbord - 1;
    }

    return count;
}

// get least significant 1st bit index
static inline int lsb(U64 bitbord)
{
    // make sure its not 0
    if (bitbord)
    {
        return count_bits((bitbord & -bitbord) - 1);
    }
    else
        return -1;
}

// board squares name as strings as enum

enum
{
    white,
    black
};

U64 get_u64()
{
    U64 u64;
    scanf("%llu", &u64);
    return u64;
}

// print bitboard
void print_bitboard(U64 bitboard)
{
    printf("\n");
    // loop over board ranks
    for (int rank = 0; rank < 8; rank++)
    {
        // loop over board files
        for (int file = 0; file < 8; file++)
        {
            // convert file and rank to square index
            int square = rank * 8 + file;

            // print ranks
            if (file == 0)
                printf(" %d ", 8 - rank);

            // print bit state (1 or 0)
            printf(" %d ", get_bit(bitboard, square) ? 1 : 0);
        }
        // print new line every rank
        printf("\n");
    }
    // print files
    printf("\n    a  b  c  d  e  f  g  h  \n\n");

    // print bitboard as unsigned decimal number
    printf("    bitboard: %llu\n\n", bitboard);
}

/*
        NOT A FILE
 8  0  1  1  1  1  1  1  1
 7  0  1  1  1  1  1  1  1
 6  0  1  1  1  1  1  1  1
 5  0  1  1  1  1  1  1  1
 4  0  1  1  1  1  1  1  1
 3  0  1  1  1  1  1  1  1
 2  0  1  1  1  1  1  1  1
 1  0  1  1  1  1  1  1  1
    a  b  c  d  e  f  g  h

        NOT H FILE
 8  1  1  1  1  1  1  1  0
 7  1  1  1  1  1  1  1  0
 6  1  1  1  1  1  1  1  0
 5  1  1  1  1  1  1  1  0
 4  1  1  1  1  1  1  1  0
 3  1  1  1  1  1  1  1  0
 2  1  1  1  1  1  1  1  0
 1  1  1  1  1  1  1  1  0
    a  b  c  d  e  f  g  h

        NOT HG FILE
 8  1  1  1  1  1  1  0  0
 7  1  1  1  1  1  1  0  0
 6  1  1  1  1  1  1  0  0
 5  1  1  1  1  1  1  0  0
 4  1  1  1  1  1  1  0  0
 3  1  1  1  1  1  1  0  0
 2  1  1  1  1  1  1  0  0
 1  1  1  1  1  1  1  0  0
    a  b  c  d  e  f  g  h

        NOT AB FILE
 8  0  0  1  1  1  1  1  1
 7  0  0  1  1  1  1  1  1
 6  0  0  1  1  1  1  1  1
 5  0  0  1  1  1  1  1  1
 4  0  0  1  1  1  1  1  1
 3  0  0  1  1  1  1  1  1
 2  0  0  1  1  1  1  1  1
 1  0  0  1  1  1  1  1  1
    a  b  c  d  e  f  g  h
*/
// not a file constant
const U64 not_a_file = 18374403900871474942ULL;

// not h file constant
const U64 not_h_file = 9187201950435737471ULL;

// not hg file constant
const U64 not_hg_file = 4557430888798830399ULL;

// not ab file constant
const U64 not_ab_file = 18229723555195321596ULL;

// bishop relevant occupancy bit count for every square on board
const int bishop_relevant_bits[64] = {
    6,
    5,
    5,
    5,
    5,
    5,
    5,
    6,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    7,
    7,
    7,
    7,
    5,
    5,
    5,
    5,
    7,
    9,
    9,
    7,
    5,
    5,
    5,
    5,
    7,
    9,
    9,
    7,
    5,
    5,
    5,
    5,
    7,
    7,
    7,
    7,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    6,
    5,
    5,
    5,
    5,
    5,
    5,
    6,
};
// rook relevant occupancy bit count for every square on board
const int rook_relevant_bits[64] = {
    12,
    11,
    11,
    11,
    11,
    11,
    11,
    12,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    10,
    10,
    10,
    10,
    10,
    10,
    11,
    12,
    11,
    11,
    11,
    11,
    11,
    11,
    12,
};

// pawn attacks table [side][square]
U64 pawn_attacks[2][64];

// knight attacks table [square]
U64 knight_attacks[64];

// king attacks table [square]
U64 king_attacks[64];

// genreate pawn attacks
U64 mask_pawn_attacks(int side, int square)
{
    U64 attacks = 0ULL;
    U64 bitboard = 0ULL;

    set_bit(bitboard, square);

    if (!side)
    {
        if ((bitboard >> 7) & not_a_file)
            attacks |= bitboard >> 7;
        if ((bitboard >> 9) & not_h_file)
            attacks |= bitboard >> 9;
    }
    else
    {
        if ((bitboard << 7) & not_h_file)
            attacks |= bitboard << 7;
        if ((bitboard << 9) & not_a_file)
            attacks |= bitboard << 9;
    }

    return attacks;
};

// generate knight attacks
U64 mask_knight_attacks(int square)
{
    U64 attacks = 0ULL;
    U64 bitboard = 0ULL;

    set_bit(bitboard, square);

    if ((bitboard >> 17) & not_h_file)
        attacks |= bitboard >> 17;
    if ((bitboard << 17) & not_a_file)
        attacks |= bitboard << 17;
    if ((bitboard >> 15) & not_a_file)
        attacks |= bitboard >> 15;
    if ((bitboard << 15) & not_h_file)
        attacks |= bitboard << 15;
    if ((bitboard >> 10) & not_hg_file)
        attacks |= bitboard >> 10;
    if ((bitboard << 10) & not_ab_file)
        attacks |= bitboard << 10;
    if ((bitboard << 6) & not_hg_file)
        attacks |= bitboard << 6;
    if ((bitboard >> 6) & not_ab_file)
        attacks |= bitboard >> 6;

    return attacks;
}

// generate king attacks
U64 mask_king_attacks(int square)
{
    U64 attacks = 0ULL;
    U64 bitboard = 0ULL;

    set_bit(bitboard, square);

    if ((bitboard >> 1) & not_h_file)
        attacks |= bitboard >> 1;
    if ((bitboard << 7) & not_h_file)
        attacks |= bitboard << 7;
    if ((bitboard >> 9) & not_h_file)
        attacks |= bitboard >> 9;
    if ((bitboard << 1) & not_a_file)
        attacks |= bitboard << 1;
    if ((bitboard >> 7) & not_a_file)
        attacks |= bitboard >> 7;
    if ((bitboard << 9) & not_a_file)
        attacks |= bitboard << 9;

    attacks |= bitboard >> 8;
    attacks |= bitboard << 8;

    return attacks;
}

// mask bishop attacks
U64 mask_bishop_attacks(int square)
{
    // result attacks bitboard
    U64 attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // mask relevant bishop occupancy bits
    for (r = tr + 1, f = tf + 1; r <= 6 && f <= 6; r++, f++)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr - 1, f = tf + 1; r >= 1 && f <= 6; r--, f++)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr + 1, f = tf - 1; r <= 6 && f >= 1; r++, f--)
        attacks |= (1ULL << (r * 8 + f));
    for (r = tr - 1, f = tf - 1; r >= 1 && f >= 1; r--, f--)
        attacks |= (1ULL << (r * 8 + f));

    // return attack map
    return attacks;
}

// mask rook attacks
U64 mask_rook_attacks(int square)
{
    // result attacks bitboard
    U64 attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // mask relevant rook occupancy bits
    for (r = tr + 1; r <= 6; r++)
        attacks |= (1ULL << (r * 8 + tf));
    for (r = tr - 1; r >= 1; r--)
        attacks |= (1ULL << (r * 8 + tf));
    for (f = tf + 1; f <= 6; f++)
        attacks |= (1ULL << (tr * 8 + f));
    for (f = tf - 1; f >= 1; f--)
        attacks |= (1ULL << (tr * 8 + f));

    // return attack map
    return attacks;
}

// generate bishop attacks on the fly
U64 bishop_attacks_on_the_fly(int square, U64 block)
{
    // result attacks bitboard
    U64 attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // generate bishop atacks
    for (r = tr + 1, f = tf + 1; r <= 7 && f <= 7; r++, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr - 1, f = tf + 1; r >= 0 && f <= 7; r--, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr + 1, f = tf - 1; r <= 7 && f >= 0; r++, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    for (r = tr - 1, f = tf - 1; r >= 0 && f >= 0; r--, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if ((1ULL << (r * 8 + f)) & block)
            break;
    }

    // return attack map
    return attacks;
}

// generate rook attacks on the fly
U64 rook_attacks_on_the_fly(int square, U64 block)
{
    // result attacks bitboard
    U64 attacks = 0ULL;

    // init ranks & files
    int r, f;

    // init target rank & files
    int tr = square / 8;
    int tf = square % 8;

    // generate rook attacks
    for (r = tr + 1; r <= 7; r++)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block)
            break;
    }

    for (r = tr - 1; r >= 0; r--)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if ((1ULL << (r * 8 + tf)) & block)
            break;
    }

    for (f = tf + 1; f <= 7; f++)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block)
            break;
    }

    for (f = tf - 1; f >= 0; f--)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if ((1ULL << (tr * 8 + f)) & block)
            break;
    }

    // return attack map
    return attacks;
}

// initialize leaper pieces attack
void init_leaper_attacks()
{
    for (int square = 0; square < 64; square++)
    {
        // init pawn attacks
        pawn_attacks[white][square] = mask_pawn_attacks(white, square);
        pawn_attacks[black][square] = mask_pawn_attacks(black, square);

        // init knight attacks
        knight_attacks[square] = mask_knight_attacks(square);

        // init king attacks
        king_attacks[square] = mask_king_attacks(square);
    }
}

// set occupancies
U64 set_occupancies(int index, int bit_in_mask, U64 attack_mask)
{
    // init occupancies
    U64 occupancy = 0ULL;

    // loop over the range of bits within the attack mask
    for (int count = 0; count < bit_in_mask; count++)
    {
        // get lsb index of attack mask
        int square = lsb(attack_mask);

        // pop lsb in attack map
        clear_bit(attack_mask, square);

        // make sure occupancy is on board
        if (index & (1 << count))
            // poppulate occupancy map
            occupancy |= (1ULL << square);
    }

    return occupancy;
}

int main()
{
    printf("I am moter!\n");

    // init leaper pieces attack
    init_leaper_attacks();

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            int square = (rank * 8) + file;

            printf(" %d, ", count_bits(mask_rook_attacks(square)));
        }
        printf("\n");
    }

    return 0;
}