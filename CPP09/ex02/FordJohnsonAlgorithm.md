# Ford-Johnson Algorithm

## Steps
1. Divide the list into pairs of elements.
2. Sort each pair.
3. Merge the sorted pairs into a single list.
4. Insert any remaining elements into the merged list.

## Example

### Initial Vector

**[3, 6, 8, 2]**


### Step-by-Step Execution

1. **Initial Call to `mergeInsertSort`**
   - `mergeInsertSort(vec)` is called with `vec = [3, 6, 8, 2]`.

2. **First Call to `fordJohnsonSort`**
   - `fordJohnsonSort(vec, 0, 3)` is called.
   - `mid = 0 + (3 - 0) / 2 = 1`.

3. **Recursive Calls to `fordJohnsonSort`**
   - `fordJohnsonSort(vec, 0, 1)` is called.
     - `mid = 0 + (1 - 0) / 2 = 0`.
     - `fordJohnsonSort(vec, 0, 0)` is called and returns immediately (base case).
     - `fordJohnsonSort(vec, 1, 1)` is called and returns immediately (base case).
     - `merge(vec, 0, 0, 1)` is called to merge `[3]` and `[6]`.
       - Result after merge: `[3, 6, 8, 2]`.
   - `fordJohnsonSort(vec, 2, 3)` is called.
     - `mid = 2 + (3 - 2) / 2 = 2`.
     - `fordJohnsonSort(vec, 2, 2)` is called and returns immediately (base case).
     - `fordJohnsonSort(vec, 3, 3)` is called and returns immediately (base case).
     - `merge(vec, 2, 2, 3)` is called to merge `[8]` and `[2]`.
       - Result after merge: `[3, 6, 2, 8]`.

4. **Final Merge**
   - `merge(vec, 0, 1, 3)` is called to merge `[3, 6]` and `[2, 8]`.
     - Result after merge: `[2, 3, 6, 8]`.