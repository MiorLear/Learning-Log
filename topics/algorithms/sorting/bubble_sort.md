# Bubble Sort Algorithm

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

## How it Works

1.  **Comparison and Swapping:** It starts at the beginning of the list and compares the first two elements. If the first element is greater than the second, they are swapped.
2.  **Iteration:** It then moves to the next pair of elements and repeats the comparison and swapping process. This continues until the end of the list is reached. At the end of the first pass, the largest element will "bubble up" to its correct position at the end of the list.
3.  **Repetition:** The algorithm then repeats the entire process for the remaining unsorted portion of the list, excluding the already sorted elements at the end.
4.  **Termination:** This process continues until no swaps are performed in a full pass, indicating that the array is sorted.

## Characteristics

*   **Time Complexity:**
    *   **Worst-case and Average-case:** O(n^2), where 'n' is the number of items being sorted. This makes it inefficient for large datasets.
    *   **Best-case:** O(n) if the list is already sorted (no swaps are made in the first pass).
*   **Space Complexity:** O(1) as it only requires a small, constant amount of extra memory for temporary variables.
*   **Stability:** Bubble Sort is a stable sorting algorithm, meaning that elements with equal values maintain their relative order in the sorted output.
*   **In-place:** It is an in-place sorting algorithm, as it sorts the array within the original memory space.

## Example (Conceptual)

Consider the array `[5, 1, 4, 2, 8]`.

**First Pass:**
*   (5, 1) -> (1, 5), 4, 2, 8
*   1, (5, 4) -> 1, (4, 5), 2, 8
*   1, 4, (5, 2) -> 1, 4, (2, 5), 8
*   1, 4, 2, (5, 8) -> 1, 4, 2, 5, 8 (8 is now in its correct position)

**Second Pass:**
*   (1, 4) -> 1, 4, 2, 5, 8
*   1, (4, 2) -> 1, (2, 4), 5, 8
*   1, 2, (4, 5) -> 1, 2, 4, 5, 8 (5 is now in its correct position)

**Third Pass:**
*   (1, 2) -> 1, 2, 4, 5, 8
*   1, (2, 4) -> 1, 2, 4, 5, 8

No swaps in the third pass, so the array is sorted.

## When to Use (and Not Use)

Bubble Sort is primarily a pedagogical tool for introducing sorting concepts due to its simplicity. It is generally **not recommended for practical applications** due to its poor performance compared to more efficient algorithms like Merge Sort, Quick Sort, or Heap Sort, especially for large datasets.