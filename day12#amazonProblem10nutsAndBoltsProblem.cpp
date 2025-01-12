class Solution {
  public:
    int prt(int start, int end, char *nuts, char *bolts)
    {
        char pivot = nuts[start];
        
        int count = 0;
        
        for (int i = start; i <= end; i++)
        {
            if (bolts[i] < pivot) {
                count++;
            }
        }
        
        int pivotIn = start + count;
        
        swap(bolts[start], bolts[pivotIn]);
        
        int one = start, two = end;
        
        while (one < two && one != pivotIn && two != pivotIn)
        {
            while (one < pivotIn && bolts[one] < pivot)
            {
                one++;
            }
            
            while (two > pivotIn && bolts[two] > pivot)
            {
                two--;
            }
            
            if (one < two && one != pivotIn && two != pivotIn) {
                swap(bolts[one++], bolts[two--]);
            }
        }
        
        for (int i = start; i <= end; i++)
        {
            nuts[i] = bolts[i];
        }
        
        return pivotIn;
    }
  
    void quickSort(int start, int end, char *nuts, char *bolts)
    {
        if (start >= end) {
            return;
        }
        
        int pivot = prt(start, end, nuts, bolts);
        
        quickSort(start, pivot - 1, nuts, bolts);
        quickSort(pivot + 1, end, nuts, bolts);
    }

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        for (int i = 0; i < n; i++)
        {
            nuts[i] = bolts[i];
        }
        
        quickSort(0, n - 1, nuts, bolts);
    }
};
