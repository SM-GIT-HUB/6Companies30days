class Solution {
public:
    vector<vector<int> > store;
    vector<int> areas;
    int totalArea = 0;

    Solution(vector<vector<int>>& rects) {
        store = rects;
        int height = 0, width = 0;

        for (auto &curr : store)
        {
            width = curr[2] - curr[0] + 1;
            height = curr[3] - curr[1] + 1;

            areas.push_back(width * height);
            totalArea += width * height;
        }
    }
    
    vector<int> pick() {
        int randArea = rand() % totalArea;
        int currRect = 0;

        while (randArea >= areas[currRect])
        {
            randArea = randArea - areas[currRect];
            currRect++;
        }

        vector<int> curr = store[currRect];

        int x = curr[0] + rand() % (curr[2] - curr[0] + 1);
        int y = curr[1] + rand() % (curr[3] - curr[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
