class TaskManager {
private:
    unordered_map<int, pair<int, int>> mpp;
    set<pair<int, pair<int, int>>> st;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            st.insert({-priority, {-taskId, -userId}});
            mpp[taskId] = {userId, priority};
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({-priority, {-taskId, -userId}});
        mpp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto temp = mpp[taskId];
        int userId = temp.first;
        int oldPriority = temp.second;

        st.erase({-oldPriority, {-taskId, -userId}});
        st.insert({-newPriority, {-taskId, -userId}});

        mpp[taskId] = {userId, newPriority};
    }
    
    void rmv(int taskId) {
        auto temp = mpp[taskId];
        int userId = temp.first;
        int oldPriority = temp.second;

        st.erase({-oldPriority, {-taskId, -userId}});
        mpp.erase(taskId);
    }
    
    int execTop() {
        if (st.empty()) return -1;

        auto temp = *st.begin();
        st.erase(st.begin());

        return -temp.second.second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
