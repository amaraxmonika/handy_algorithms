
# O(n) solution for finding
# maximum sum of a subarray of size k


def max_sum(arr: list[int], k: int) -> int:
    # length of the array
    n = len(arr)

    # n must be greater than k
    if n <= k:
        print("Invalid")
        return -1

    # Compute sum of first window of size k
    window_sum = sum(arr[:k])

    # first sum available
    max_sum = window_sum

    # Compute the sums of remaining windows by
    # removing first element of previous
    # window and adding last element of
    # the current window.
    # k = 4
    # n = 10
    # [a, b, c, d, e, f, g, h, i, j]
    #     ^--------^
    # i = 0
    # window_sum = window_sum - arr[i] + arr[i + k]
    # window_sum = (a + b + c + d) - arr[0] + arr[0 + 4]
    # window_sum = (a + b + c + d) - a + e
    # window_sum = (b + c + d + e)
    for i in range(n - k):
        window_sum = window_sum - arr[i] + arr[i + k]
        max_sum = max(window_sum, max_sum)

    return max_sum


# Driver code
arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
k = 4
print(max_sum(arr, k))

def max_sum_better(arr: list[int], k: int) -> int:

    if len(arr) <= k:
        print("Invalid array length")

    # Compute sum of first k elements
    current_sum: int = sum(arr[:k])
    max_sum: int = current_sum

    for i in range(len(arr) - k):
        current_sum = current_sum - arr[i] + arr[i + k]
        max_sum = max(max_sum, current_sum)

    return max_sum

arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
k = 4
print(max_sum_better(arr, k))
