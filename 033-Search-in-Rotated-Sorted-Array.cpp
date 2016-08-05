class Solution {
public:
	int search(vector<int>& nums, int target) {

		return search(&*nums.begin(), 0, nums.size() - 1, target);
	}

private:
	int search(int *arr, int left, int right, int target) {
		
		while (left <= right) {
		    
		    if (arr[left] < arr[right]) {
			    return binarySearch(arr, left, right, target);
	    	}
	    	
    	    int mid = (right - left) / 2 + left;
    		if (arr[mid] < arr[left]) {
    			if (target == arr[mid]) {
    				return mid;
    			} else if (target < arr[mid]) {
    				right = mid - 1;
    			} else {
    				if (target == arr[left]) {
    					return left;
    				} else if (target > arr[left]) {
    					right = mid - 1;
    				} else {
    					left = mid + 1;
    				}
    			}
    		} else {
    			if (target == arr[mid]) {
    				return mid;
    			} else if (target > arr[mid]) {
    				left = mid + 1;
    			} else {
    				if (target == arr[left]) {
    					return left;
    				} else if (target < arr[left]) {
    					left = mid + 1;
    				} else {
    					right = mid - 1;
    				}
    			}
    		}	
		}
		
		return -1;
	}

	int binarySearch(int *arr, int left, int right, int target) {
		int low = left;
		int high = right;

		while (low <= high) {
			int mid = (high - low) / 2  + low;

			if (arr[mid] == target) {
				return mid;
			} else if (arr[mid] < target) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		return -1;
	}
};