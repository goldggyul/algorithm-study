// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
    /*
     * 증가하는 서로 다른 수 배열
     * zero base 인덱스
     * target을 찾아서 인덱스 리턴, 없으면 -1
     * log n에 풀어야 함
     */
    public int binarySearch(int[] nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            }
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        // 1. 시작점을 찾는다
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= nums[hi] && nums[mid] >= nums[lo]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // 2. 절반 나눠서 두번 탐색한다.
        return Math.max(binarySearch(nums, 0, lo - 1, target), binarySearch(nums, lo, nums.length - 1, target));
    }

    public int search2(int[] nums, int target) {
        // 1. 시작점을 찾는다
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        // 2. 절반 나눠서 두번 탐색한다.
        return Math.max(binarySearch(nums, 0, lo - 1, target), binarySearch(nums, lo, nums.length - 1, target));
    }

    public int search3(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            // int mid=(lo+hi)/2;
            int mid = lo + (hi - lo) / 2; // better not to cause overflow
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[lo] <= nums[mid]) { // 왼쪽이 정렬된 상태일 때
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else { // 왼쪽이 정렬되지 않은 상태
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        if (nums[lo] == target) {
            return lo;
        }
        return -1;
    }

}