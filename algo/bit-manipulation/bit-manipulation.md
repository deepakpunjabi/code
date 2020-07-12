# Bit Manipulation

- Get LSB (least significant bit): 1. check `if (n % 2 == 0)` for even or 2. check `if (n & 1)` for odd
- Memoization could become more advantageous when dealing with the input of long bit stream. Eg. reversing an arbitary length bit stream. Here you can store each `byte->reversed` as cache.
- The left shift and right shift operators should not be used for negative numbers.

## [Bit Hacks](http://graphics.stanford.edu/~seander/bithacks.html)

- Reverse a byte
    ```python
    def reverseByte(byte):
        return (byte * 0x0202020202 & 0x010884422010) % 1023
    ```
- Reverse a number bit by bit
    ```cpp
    for (i = 0; i < NO_OF_BITS; i++) {
        temp = (num & (1 << i));
        if(temp)
            // set size-ith bit via OR if ith bit is set in original string
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
    ```
