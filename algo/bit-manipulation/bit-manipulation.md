# Bit Manipulation

- Get LSB (least significant bit): 1. check `if (n % 2 == 0)` for even or 2. check `if (n & 1)` for odd
- Memoization could become more advantageous when dealing with the input of long bit stream. Eg. reversing an arbitary length bit stream. Here you can store each `byte->reversed` as cache.

## [Bit Hacks](http://graphics.stanford.edu/~seander/bithacks.html)

- Reverse a byte
    ```python
    def reverseByte(byte):
        return (byte * 0x0202020202 & 0x010884422010) % 1023
    ```
