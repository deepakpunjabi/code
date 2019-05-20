package main

import (
	"fmt"
	"os"
)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func leftRotate(arr []int, d int) {
	n := len(arr)
	if d >= n {
		d = d % n
	}
	if d == 0 || n == 0 {
		return
	}

	var j, tmp int
	n := len(arr)
	gcd := gcd(n, d)
	for i := 0; i < gcd; i++ {
		tmp = arr[i]
		j = i
		for {
			k := j + d
			// fmt.Printf("i: %d, j: %d, k: %d\n", i, j, k)
			if k >= n {
				k -= n
			}
			if k == i {
				break
			}
			arr[j] = arr[k]
			j = k
		}
		arr[j] = tmp
	}
}

func rightRotate(arr []int, d int) {
	n := len(arr)
	if d >= n {
		d = d % n
	}
	if d == 0 || n == 0 {
		return
	}

	var j, tmp int
	gcd := gcd(n, d)
	for i, g := n-1, 0; g < gcd; i, g = i-1, g+1 {
		tmp = arr[i]
		j = i
		for {
			k := j - d
			// fmt.Printf("i: %d, j: %d, k: %d\n", i, j, k)
			if k < 0 {
				k += n
			}
			if k == i {
				break
			}
			arr[j] = arr[k]
			j = k
		}
		arr[j] = tmp
	}
}

func printArray(arr []int) {
	fmt.Printf("%v\n", arr)
}

func main() {
	fmt.Println("enter your array size:")

	var n, d int
	if _, err := fmt.Scanf("%d", &n); err != nil {
		println("unable to read array size: ", err.Error())
		os.Exit(1)
	}

	arr := make([]int, n)
	fmt.Println("enter your array")
	for i := 0; i < n; i++ {
		if _, err := fmt.Scanf("%d", &arr[i]); err != nil {
			println("error occurred while reading array: ", err.Error())
			os.Exit(1)
		}
	}

	fmt.Println("enter displacement")
	if _, err := fmt.Scanf("%d", &d); err != nil {
		println("error occurred while reading displacement: ", err.Error())
		os.Exit(1)
	}

	rightRotate(arr, d)
	printArray(arr)
}
