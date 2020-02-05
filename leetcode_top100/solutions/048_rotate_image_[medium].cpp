class Solution {
 private:
  enum dir_enum { left = 0, top = 1, right = 2, bottom = 3 };

  struct rotation_dir {
    dir_enum current;
    void next() {
      int next = current + 1;
      current = dir_enum(next > 3 ? 0 : next);
    }
  };

  void transform(std::vector<std::vector<int>>& matrix, int depth,
                 std::pair<int, int> start_pos) {
    std::pair<int, int> pos = start_pos;
    rotation_dir dir{dir_enum::top};
    int prev_value = matrix[start_pos.first][start_pos.second];
    int rotation_moves = 4;

    while (rotation_moves--) {
      if (dir.current == dir_enum::left) {
        pos = start_pos;
      } else {
        pos.first = pos.second;
        if (dir.current == dir_enum::top) {  // turn right
          pos.second = matrix.size() - depth;
        } else if (dir.current == dir_enum::right) {  // turn bottom
          pos.second = matrix.size() - start_pos.second - 1;
        } else {  // turn left
          pos.second = depth - 1;
        }
      }

      dir.next();
      int cur_value = matrix[pos.first][pos.second];
      matrix[pos.first][pos.second] = prev_value;
      prev_value = cur_value;
    }
  }

 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int max_depth = matrix.size() / 2;
    for (int y = 0; y < max_depth; ++y) {
      for (int x = y; x < matrix.size() - y - 1; ++x) {
        transform(matrix, y + 1, {y, x});
      }
    }
  }
};