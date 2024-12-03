# Insertion Sort vs. Selection Sort

## 1. Algorithm Overview

| Aspect              | **Insertion Sort**                                                                                                                                                     | **Selection Sort**                                                                                                                                         |
|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Approach**        | Builds the sorted portion of the array one element at a time by inserting elements into their correct position.                                                        | Finds the minimum (or maximum) element in the unsorted portion and swaps it with the first unsorted element.                                                |
| **Key Operation**   | Inserting the current element into the correct position in the sorted portion.                                                                                         | Selecting the minimum element from the unsorted portion of the array.                                                                                       |

## 2. Performance

| Aspect              | **Insertion Sort**                                   | **Selection Sort**                                   |
|----------------------|-----------------------------------------------------|-----------------------------------------------------|
| **Best Case (Sorted)** | \( O(n) \) (Only checks, no swaps needed)           | \( O(n^2) \) (Still performs all comparisons)       |
| **Worst Case**        | \( O(n^2) \) (Reversed order: maximum shifts)       | \( O(n^2) \) (No shifts, just comparisons)          |
| **Average Case**      | \( O(n^2) \)                                        | \( O(n^2) \)                                        |

## 3. Space Complexity

| **Aspect**          | **Insertion Sort**       | **Selection Sort**       |
|----------------------|--------------------------|--------------------------|
| **Space**           | \( O(1) \) (In-place)    | \( O(1) \) (In-place)    |

## 4. Stability

| Aspect              | **Insertion Sort**                                                                 | **Selection Sort**                                                                 |
|----------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| **Stability**       | Stable (Preserves the relative order of equal elements)                             | Not Stable (Swapping may change the relative order of equal elements)              |

## 5. Practical Usage

| **Aspect**          | **Insertion Sort**                                                                                                                                  | **Selection Sort**                                                                                                                                |
|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| **Small Datasets**  | Performs well on small datasets due to its simplicity and fewer comparisons when the array is partially sorted.                                     | Suitable for small datasets but less efficient compared to insertion sort for nearly sorted data.                                                 |
| **Nearly Sorted**   | Excellent for nearly sorted datasets as it requires minimal comparisons and shifts.                                                                | Performs poorly on nearly sorted datasets as it still scans the entire unsorted portion to find the minimum element.                              |
| **Large Datasets**  | Not ideal for large datasets due to quadratic time complexity.                                                                                     | Rarely used for large datasets due to quadratic time complexity and no advantage for partially sorted data.                                       |

## 6. Key Differences

| **Aspect**                | **Insertion Sort**                                                                                                                                             | **Selection Sort**                                                                                                                                         |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Comparison vs Swapping** | Compares elements and only moves/shifts them when necessary.                                                                                                   | Performs more swaps as it always swaps the smallest element with the first unsorted element, even if already in position.                                    |
| **Adaptability**          | Adaptive: Can take advantage of an already sorted or nearly sorted array, resulting in faster performance.                                                      | Non-Adaptive: Always performs the same number of comparisons, regardless of the order of elements.                                                          |

## Conclusion
- **Use Insertion Sort:** When working with small or nearly sorted datasets.
- **Use Selection Sort:** When memory writes/swaps need to be minimized, though other algorithms like Heap Sort are typically preferred for such scenarios.
