/* 

    Reverse bits of a given 32 bits unsigned integer.

    Example 1:
    Input: 00000010100101000001111010011100
    Output: 00111001011110000010100101000000
    Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
    so return 964176192 which its binary representation is 00111001011110000010100101000000.

    Example 2:
    Input: 11111111111111111111111111111101
    Output: 10111111111111111111111111111111
    Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
    so return 3221225471 which its binary representation is 10111111111111111111111111111111.
    
    Note:
    Note that in some languages such as Java, there is no unsigned integer type. 
    In this case, both input and output will be given as signed integer type and should not affect your implementation, 
    as the internal binary representation of the integer is the same whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. 
    Therefore, in Example 2 above the input represents the signed integer -3 and 
    the output represents the signed integer -1073741825.
    
    Follow up:
    If this function is called many times, how would you optimize it?

*/

#include <cinttypes>
#include <unordered_map>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    // set most significant bit as 1 followed by 31 zeros
    uint32_t msb = 1 << 31;
    uint32_t res = 0;
    long power = 1;

    for (int i = 0; i < 32; ++i) {
        // if most significant bit for input is 1
        if (msb & n) {
            res += power;
        }

        power *= 2;  // adjust power for bit position
        n <<= 1;     // shift left by 1
    }

    return res;
}

// this approach works little bit differently
// take lsb and start power from 31
// instead of take msb and start power from 0
uint32_t reverseBits2(uint32_t n) {
    uint32_t ret = 0;
    uint32_t power = 31;

    while (n != 0) {
        // left shift LSB to power times
        int tmp = (n & 1) << power;
        ret += tmp;

        n >>= 1;
        --power;
    }
    return ret;
}

/* 

    Time Complexity: O(1). Though we have a loop in the algorithm, the number of iteration is fixed regardless the input, 
    since the integer is of fixed-size (32-bits) in our problem.
    Space Complexity: O(1), since the consumption of memory is constant regardless the input.

*/

// Nobody will ask you to do this in interview, this is just FYI
class Memoization {
   public:
    uint32_t reverseByte(uint32_t byte, unordered_map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        unordered_map<uint32_t, uint32_t> cache;
        while (n != 0) {
            // 0xff = 1111 1111
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};

/* 
    Algorithm
    We can implement the algorithm in the following steps:
    1). First, we break the original 32-bit into 2 blocks of 16 bits, and switch them.
    2). We then break the 16-bits block into 2 blocks of 8 bits. Similarly, we switch the position of the 8-bits blocks
    3). We then continue to break the blocks into smaller blocks, until we reach the level with the block of 1 bit.
    4). At each of the above steps, we merge the intermediate results into a single integer which serves as the input 
    for the next step.
*/

class DivideAndConquer {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
