/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

/*
0 1 0
1 1 1
0 1 0
*/
class Solution {
    unordered_map<int, unordered_set<int>> visited;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    void dfs(int r, int c, Robot& robot, int& dir) {
        int initDir = dir;
        robot.clean();
        for(int i = 0; i < 4; ++i, dir = (dir + 1) % 4) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(visited.count(nr) && visited[nr].count(nc)) {
                robot.turnRight();
                continue;
            }
            if(robot.move()) {
                visited[nr].insert(nc);
                dfs(nr, nc, robot, dir);
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
    }
public:
    void cleanRoom(Robot& robot) {
        int dir = 0;
        visited[0].insert(0);
        dfs(0, 0, robot, dir);
    }
};