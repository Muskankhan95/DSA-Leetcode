class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int subarrcnt = 0;
        int n = arr.size();

        // First window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if ((sum / k) >= threshold) {
            subarrcnt++;
        }

        // Sliding window
        for (int i = k; i < n; i++) {
            sum += arr[i];        // add next element
            sum -= arr[i - k];    // remove previous element

            if ((sum / k) >= threshold) {
                subarrcnt++;
            }
        }

        return subarrcnt;
    }
};