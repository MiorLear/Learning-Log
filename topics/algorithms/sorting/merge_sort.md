##Merge Sort — First Look
Today I started learning about Merge Sort, one of the most classic sorting algorithms in computer science. It's a "divide and conquer" algorithm — which basically means it breaks a problem down into smaller parts, solves each one, and then combines the results.

#How it works
- **Divide:** It splits the list into halves until each sublist has only one element.
- **Conquer:** Then it starts merging the sublists back together, in order, like shuffling two sorted decks.
- Repeat this merging process all the way back up until you have the full list — sorted.

It’s kind of like sorting tiny parts first, and then building up the big solution from those.

#Why it's useful
- **Efficient:** It runs in O(n log n) time, even in the worst case.
- **Stable:** It doesn’t change the order of equal elements (which is important in some cases).
- **Predictable** performance: Not like quicksort, which can degrade if it gets unlucky.

But it does use more memory than some other sorts because of the extra arrays created during merging.
