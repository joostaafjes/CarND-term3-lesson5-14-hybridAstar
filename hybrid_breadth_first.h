#ifndef HYBRID_BREADTH_FIRST_H_
#define HYBRID_BREADTH_FIRST_H_

#include <vector>

using std::vector;

class HBF {
 public:
  // Constructor
  HBF();

  // Destructor
  virtual ~HBF();

  // HBF structs
  struct maze_s {
    int g;  // iteration
    int f; // heuristic
    double x;
    double y;
    double theta;

    void to_string() {
      char string[50];
      std::sprintf(string, "x:%0.2f, y:%0.2f, g:%d, f:%d", x, y, g, f);
      std::cout << string << std::endl;
    }
  };

  struct maze_path {
    vector<vector<vector<int>>> closed;
    vector<vector<vector<maze_s>>> came_from;
    maze_s final;
  };

  // HBF functions
  int theta_to_stack_number(double theta);

  int heuristic(int x, int y, vector<int> &goal);

  int idx(double float_num);

  vector<maze_s> expand(HBF::maze_s &state, vector<int> &goal);

  vector<maze_s> reconstruct_path(vector<vector<vector<maze_s>>> &came_from,
                                  vector<double> &start, HBF::maze_s &final);

  maze_path search(vector<vector<int>> &grid, vector<double> &start,
                   vector<int> &goal);

 private:
  const int NUM_THETA_CELLS = 90;
  const double SPEED = 1.45;
  const double LENGTH = 0.5;
};

#endif  // HYBRID_BREADTH_FIRST_H_