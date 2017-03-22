
// Follow up for "Search in Rotated Sorted Array":
//  What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Write a function to determine if a given target is in the array.

// The array may contain duplicates.

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0,right = nums.size() - 1;
//         while(left <= right){
//             if(right > nums.size() - 1|| left < 0 || left>right) return -1;
//             int mid  = left + (right - left)/2;
//             if(nums[mid] == target) return mid;
//               if(nums[mid] < target){
//                 if(nums[mid] > nums[left] || target <= nums[right]){
//                     left = mid + 1;
//                 }else{
//                     right = mid - 1;
//                 }
//               }
//               else if(nums[mid] > target){
//                   if(target >= nums[left] || nums[mid] < nums[right]){
//                      right = mid - 1;
//                   }else{
//                     left = mid + 1;
//                   }
//               }else right--;
//         }
//         return -1;
//     }
// };