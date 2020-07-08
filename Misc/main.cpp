
#include <iostream>
#include <cassert>
#include <bitset>

using namespace std;

#define BIT(bit_index) (1 << (bit_index - 1))

using u8_t = unsigned char;
using u32_t = unsigned int;

int main()
{
    //Asserts
    int i = 5;
    assert(i == 5);

    int* ptr{ nullptr };
    ptr = &i;
    assert(ptr);

    const int n = 6;
    static_assert(n == 6, "Invalid Value");
    static_assert(sizeof(int) == 4, "Invalid Value");

    //Pointer Arithmetic
    int int_array[4] = { 34, 65, 78, 12 };
    cout << int_array << endl;
    int* int_ptr = int_array;
    cout << *int_ptr << endl;
    int_ptr++;
    int_ptr++;
    cout << *int_ptr << endl;
    int_ptr = int_array + 2;
    int_ptr = int_ptr - 1;
    cout << *int_ptr << endl;
    int* int_ptr2 = int_ptr;
    if (int_ptr == int_ptr2) cout << "Same" << endl;

    //Bitwise Operations
    const u8_t player = BIT(1);
    const u8_t invisible = BIT(2);
    const u8_t flight = BIT(3);

    u8_t character_stats{ flight | player }; //                     [0][0][0][0][0][1][0][1]
    character_stats = character_stats | invisible; //Turn on bit    [0][0][0][0][0][1][1][1]
    character_stats = character_stats & ~flight; //Turn off bit     [0][0][0][0][0][0][1][1]
    character_stats = character_stats ^ player; //Toggle bit        [0][0][0][0][0][0][1][0]

    cout << bitset<8>{ character_stats } << endl;

    u32_t color{ (134 << 8) | 255 }; // a8 r8 g8 b8
    color = (color >> 8) & 0xff;

    cout << bitset<32>{ color } << endl;

    if ((character_stats & player) && (character_stats & invisible))
    {
        cout << "Invisible player" << endl;
    }

    /*
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __FUNCTION__ << endl;
    */
}


