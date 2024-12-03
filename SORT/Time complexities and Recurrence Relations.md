# Time Complexity of Sorting Algorithms

## 1. **Bubble Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n)\)          | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\) (In-place)   |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = T(n-1) + O(n)\)
- Best Case: \(T(n) = O(n)\) (if the array is already sorted)

---

## 2. **Insertion Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n)\)          | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\) (In-place)   |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = T(n-1) + O(n)\)
- Best Case: \(T(n) = O(n)\) (if the array is already sorted)

---

## 3. **Selection Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n^2)\)        | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\) (In-place)   |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = T(n-1) + O(n)\)
- Selection Sort performs the same number of comparisons regardless of the order of the array.

---

## 4. **Merge Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n \log n)\)      | \(O(n)\)             |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = 2T(n/2) + O(n)\)
- Merge Sort always divides the list in half and merges the sublists, leading to \(O(n \log n)\) time complexity.

---

## 5. **Quick Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n^2)\)          | \(O(\log n)\)        |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = T(k) + T(n-k-1) + O(n)\), where \(k\) is the size of the partition.
- Worst case: \(T(n) = T(n-1) + O(n)\), leading to \(O(n^2)\) when the pivot selection is poor.

---

## 6. **Heap Sort**

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n \log n)\)      | \(O(1)\) (In-place)   |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = T(n-1) + O(\log n)\)
- Heap Sort has \(O(n \log n)\) time complexity in all cases.

---

## 7. **Radix Sort** (Non-comparative Sort)

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(nk)\)         | \(O(nk)\)           | \(O(nk)\)           | \(O(n + k)\)          |

### Recurrence Relation:
For a list of size \(n\) with digit length \(k\):
- \(T(n) = O(nk)\)
- Radix Sort performs \(k\) passes of \(O(n)\) work for sorting the numbers based on each digit.

---

## 8. **Tim Sort** (Used in Python's `sorted()` and Java's `Arrays.sort()`)

| **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|-------------------|--------------------|---------------------|----------------------|
| \(O(n)\)          | \(O(n \log n)\)     | \(O(n \log n)\)      | \(O(n)\)             |

### Recurrence Relation:
For a list of size \(n\):
- \(T(n) = 2T(n/2) + O(n)\) in the divide and conquer step
- Tim Sort combines merge sort and insertion sort for optimal performance.

---

## Conclusion

| **Algorithm**      | **Best Case**     | **Average Case**   | **Worst Case**      | **Space Complexity** |
|--------------------|-------------------|--------------------|---------------------|----------------------|
| **Bubble Sort**     | \(O(n)\)          | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\)             |
| **Insertion Sort**  | \(O(n)\)          | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\)             |
| **Selection Sort**  | \(O(n^2)\)        | \(O(n^2)\)          | \(O(n^2)\)          | \(O(1)\)             |
| **Merge Sort**      | \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n \log n)\)     | \(O(n)\)             |
| **Quick Sort**      | \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n^2)\)          | \(O(\log n)\)        |
| **Heap Sort**       | \(O(n \log n)\)   | \(O(n \log n)\)     | \(O(n \log n)\)     | \(O(1)\)             |
| **Radix Sort**      | \(O(nk)\)         | \(O(nk)\)           | \(O(nk)\)           | \(O(n + k)\)         |
| **Tim Sort**        | \(O(n)\)          | \(O(n \log n)\)     | \(O(n \log n)\)     | \(O(n)\)             |

