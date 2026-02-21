static const uint8_t nixieArray[40] =
{ 
//K01 K02 K03 K04 K05 K06 K07 K08 K09 K10
    7,  6,  5,  4,  3,  2,  1,  8, 16, 31,

//K11 K12 K13 K14 K15 K16 K17 K18 K19 K20
   30, 29, 28, 27, 26, 25, 32, 39, 38, 37,  

//K21 K22 K23 K24 K25 K26 K27 K28 K29 K30
    0,  9, 10, 11, 12, 13, 14, 15, 17, 18,   

//K31 K32 K33 K34 K35 K36 K37 K38 K39 K40
   19, 20, 21, 22, 23, 24, 33, 34, 35, 36
};

static const uint8_t nixieTube1[5] =
{
static const uint8_t K01 = 0;
static const uint8_t K02 = 1;
static const uint8_t K03 = 2;
static const uint8_t K04 = 3;
static const uint8_t K05 = 4;
};


static const uint8_t nixieTube1[10] =


static const uint8_t nixieTube1[10] =


static const uint8_t nixieTube1[10] =

#define K01   34  //  wyjście 01 → bit 34
#define K02    7  //  wyjście 02 → bit  7
#define K03   22  //  wyjście 03 → bit 22
#define K04    0  //  wyjście 04 → bit  0
#define K05   15  //  wyjście 05 → bit 15
#define K06   38  //  wyjście 06 → bit 38
#define K07    9  //  wyjście 07 → bit  9
#define K08   27  //  wyjście 08 → bit 27
#define K09   31  //  wyjście 09 → bit 31
#define K10    3  //  wyjście 10 → bit  3

#define K11   18  //  wyjście 11 → bit 18
#define K12   12  //  wyjście 12 → bit 12
#define K13   36  //  wyjście 13 → bit 36
#define K14   25  //  wyjście 14 → bit 25
#define K15    5  //  wyjście 15 → bit  5
#define K16   29  //  wyjście 16 → bit 29
#define K17   14  //  wyjście 17 → bit 14
#define K18   39  //  wyjście 18 → bit 39
#define K19   20  //  wyjście 19 → bit 20
#define K20    1  //  wyjście 20 → bit  1

#define K21   33  //  wyjście 21 → bit 33
#define K22   11  //  wyjście 22 → bit 11
#define K23   26  //  wyjście 23 → bit 26
#define K24    6  //  wyjście 24 → bit  6
#define K25   17  //  wyjście 25 → bit 17
#define K26   37  //  wyjście 26 → bit 37
#define K27    2  //  wyjście 27 → bit  2
#define K28   23  //  wyjście 28 → bit 23
#define K29   35  //  wyjście 29 → bit 35
#define K30    8  //  wyjście 30 → bit  8

#define K31   19  //  wyjście 31 → bit 19
#define K32   30  //  wyjście 32 → bit 30
#define K33    4  //  wyjście 33 → bit  4
#define K34   28  //  wyjście 34 → bit 28
#define K35   13  //  wyjście 35 → bit 13
#define K36   21  //  wyjście 36 → bit 21
#define K37   10  //  wyjście 37 → bit 10
#define K38   32  //  wyjście 38 → bit 32
#define K39   16  //  wyjście 39 → bit 16
#define K40   24  //  wyjście 40 → bit 24

// ---------------------------------------------------------------------------
// Mapowanie: lampa[cyfra] → numer bitu w ramce 40-bit
//
// Indeks tablicy = wyświetlana cyfra (0–9)
// Wartość        = numer bitu do ustawienia w ramce
//
// Które wyjście Kxx steruje którą cyfrą danej lampy —
// zależy od tego, do której katody w lampie jest podłączone.
// ---------------------------------------------------------------------------

// Lampa 1 (godziny – dziesiątki)
static const uint8_t nixieTube1[10] = {
    K07,  // cyfra 0
    K05,  // cyfra 1
    K03,  // cyfra 2
    K01,  // cyfra 3
    K09,  // cyfra 4
    K02,  // cyfra 5
    K04,  // cyfra 6
    K06,  // cyfra 7
    K08,  // cyfra 8
    K10   // cyfra 9
};

// Lampa 2 (godziny – jednostki)
static const uint8_t nixieTube2[10] = {
    K17,  // cyfra 0
    K15,  // cyfra 1
    K13,  // cyfra 2
    K11,  // cyfra 3
    K19,  // cyfra 4
    K12,  // cyfra 5
    K14,  // cyfra 6
    K16,  // cyfra 7
    K18,  // cyfra 8
    K20   // cyfra 9
};

// Lampa 3 (minuty – dziesiątki)
static const uint8_t nixieTube3[10] = {
    K27,  // cyfra 0
    K25,  // cyfra 1
    K23,  // cyfra 2
    K21,  // cyfra 3
    K29,  // cyfra 4
    K22,  // cyfra 5
    K24,  // cyfra 6
    K26,  // cyfra 7
    K28,  // cyfra 8
    K30   // cyfra 9
};

// Lampa 4 (minuty – jednostki)
static const uint8_t nixieTube4[10] = {
    K37,  // cyfra 0
    K35,  // cyfra 1
    K33,  // cyfra 2
    K31,  // cyfra 3
    K39,  // cyfra 4
    K32,  // cyfra 5
    K34,  // cyfra 6
    K36,  // cyfra 7
    K38,  // cyfra 8
    K40   // cyfra 9
};

// ---------------------------------------------------------------------------
// Tablica wskaźników do lamp — pozwala adresować lampę numerem 0–3
// ---------------------------------------------------------------------------
static const uint8_t *const nixieTubes[4] = {
    nixieTube1,
    nixieTube2,
    nixieTube3,
    nixieTube4
};

// ---------------------------------------------------------------------------
// Funkcja: ustaw cyfrę na danej lampie w ramce 40-bit
// ---------------------------------------------------------------------------
//
//   tubeIndex : 0–3  (numer lampy)
//   digit     : 0–9  (wyświetlana cyfra)
//   frame     : wskaźnik na bufor 5 bajtów (40 bitów), LSB-first
//
static inline void nixieSetDigit(uint8_t tubeIndex, uint8_t digit,
                                 uint8_t frame[5])
{
    uint8_t bit = nixieTubes[tubeIndex][digit];
    frame[bit / 8] |= (1 << (bit % 8));
}

// ---------------------------------------------------------------------------
// Funkcja: wyczyść ramkę (zgaś wszystkie katody)
// ---------------------------------------------------------------------------
static inline void nixieClearFrame(uint8_t frame[5])
{
    frame[0] = 0;
    frame[1] = 0;
    frame[2] = 0;
    frame[3] = 0;
    frame[4] = 0;
}

#endif // NIXIE_TUBES_H
