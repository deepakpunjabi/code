# Array

- Arrays can have index starting from 0,1 or n based on usecase.
- Metrics usually requires lot of looping, better to save `#rows` and `#cols`
 in separate variables.

### Lambda Sort 2D vector, ie. `vector<vector<int>>`
---

```cpp
    [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
```

```cpp
sort(grid.begin(), grid(end), 
    [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
)
```
