#ifndef LADDER_WITH_FAKES_HPP_
#define LADDER_WITH_FAKES_HPP_

#include <vector>
#include <string>
#include <queue>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

class LadderWithFakes {
 private:


  struct distanceString
  {
    int distEnd {};
    int distOrigin {};
    std::string word {};
    int k {};
    auto operator<=>(const distanceString& other) const = default;
  };
  std::unordered_set<std::string> list {};
  // add some private member variables if needed

 public:

  using minPQ = std::priority_queue<distanceString, std::vector<distanceString>, std::greater<distanceString>>;
  LadderWithFakes();

  // initialise any private member variables you want 
  // in order to be ready to compute shortest paths with fakes
  explicit LadderWithFakes(const std::string&);

  bool isValid(std::string word); 

  std::vector<std::string> generateEdges(std::string start);

  int heuristic(std::string start, std::string end);

  std::vector<std::string> 
  path(const std::string& origin, const std::string& dest, const std::map<std::string, std::string>& prev);
  // given two strings and a budget of fake words k, find the shortest 
  // path between the two strings using at most k fake words
  std::vector<std::string>
  shortestPathWithFakes(const std::string&, const std::string&, int k);
};

#endif      // LADDER_WITH_FAKES_HPP_
