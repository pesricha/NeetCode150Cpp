class Solution:
    def findMedianSortedArrays(self, arr1: List[int], arr2: List[int]) -> float:
        n = len(arr1)
        m = len(arr2)
        
        # If arr1 has more elements, then call median_of_two 
        # with reversed parameters
        if n > m:
            return self.findMedianSortedArrays(arr2, arr1)
        
        low = 0
        high = n
        while low <= high:
            mid1 = (low + high) // 2
            mid2 = (n + m + 1) // 2 - mid1
            
            # Find elements to the left and right of partition in arr1
            l1 = arr1[mid1 - 1] if mid1 > 0 else float("-inf")
            r1 = arr1[mid1] if mid1 < n else float("inf")

            # Find elements to the left and right of partition in arr2
            l2 = arr2[mid2 - 1] if mid2 > 0 else float("-inf")
            r2 = arr2[mid2] if mid2 < m else float("inf")

            # If it is a valid partition
            if l1 <= r2 and l2 <= r1:
                # If the total elements are even, then median is 
                # the average of two middle elements
                if (n + m) % 2 == 0:
                    return (max(l1, l2) + min(r1, r2)) / 2.0
                
                # If the total elements are odd, then median is 
                # the middle element
                else:
                    return max(l1, l2)

            # Check if we need to take fewer elements from arr1
            if l1 > r2:
                high = mid1 - 1
            # Check if we need to take more elements from arr1
            else:
                low = mid1 + 1

        return 0

