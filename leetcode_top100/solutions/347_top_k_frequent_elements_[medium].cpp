class Solution {
 private:
  struct freq_number {
    int value, frequency;
  };

 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::vector<int> results(k);
    std::unordered_map<int, int> frequency;

    auto compare = [](freq_number left, freq_number right) {
      return left.frequency < right.frequency;
    };
    std::priority_queue<freq_number, std::vector<freq_number>,
                        decltype(compare)>
        ordered(compare);

    for (const int& num : nums) {
      freq_number f{num, ++frequency[num]};
      ordered.push(f);
    }

    std::set<int> blacklist;
    int pointer = 0;

    while (pointer < k && ordered.size()) {
      freq_number num = ordered.top();
      bool num_unique = !blacklist.count(num.value);
      if (num_unique) {
        results[pointer++] = num.value;
        blacklist.insert(num.value);
      }
      ordered.pop();
    }

    return results;
  }
};