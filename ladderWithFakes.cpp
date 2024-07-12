#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include <map>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cassert>
#include "ladderWithFakes.hpp"

// default initialiser does not need to do anything
LadderWithFakes::LadderWithFakes() = default;

// initialise any private member variables you want 
// in order to be ready to compute shortest paths with fakes
// *** put your implementation here

LadderWithFakes::LadderWithFakes(const std::string& inputFile) {

  std::string word {};
  std::ifstream infile(inputFile); 
  while(infile >> word) {
    list.insert(word);
  }

}

bool LadderWithFakes::isValid(std::string word) {
  return list.contains(word);
}

std::vector<std::string> LadderWithFakes::generateEdges(std::string start) {
  std::vector<std::string> result {};

  for (int i = 0; i < (int)start.size(); i++) {
    std::string word = start; 
    for (char c = 'a'; c <= 'z'; c++) {
      if (word[i] != c) {
        word[i] = c; 
        result.push_back(word);
      }
    }
  }
  return result; 

}



std::vector<std::string> LadderWithFakes::path(const std::string& origin, const std::string& dest, const std::map<std::string, std::string>& prev) {
  std::vector<std::string> result{}; 
  
  for (std::string current = dest; current != origin; current = prev.at(current)) {
    result.push_back(current); 
  }
  result.push_back(origin); 
  std::reverse(result.begin(), result.end()); 
  return result;

}

int LadderWithFakes::heuristic(std::string start, std::string end) {
  int distance = 0;
  for (int i = 0; i < (int)start.size(); i++) {
    if (start[i] != end[i]) {
      ++distance; 
    }
  }

  return distance; 
}

// given two strings and a budget of fake words k, find the shortest 
// path between the two strings using at most k fake words
// *** put your implementation here



std::vector<std::string>
LadderWithFakes::shortestPathWithFakes(const std::string& origin, const std::string& dest, int k) {

  // std::pair<std::string, int> firstNode = {origin, 0}; 

  minPQ wordQueue {}; 
  // std::queue<std::pair<std::string, int>> wordQueue {}; 
  wordQueue.push({heuristic(origin, dest), 0, origin, 0}); 

  std::map<std::string, int> bestDistance { {origin, heuristic(origin, dest)}};

  std::map<std::string, std::string> prev {};
  std::set<std::string> visited {};

  while(!wordQueue.empty()) {
    auto current = wordQueue.top();
    wordQueue.pop(); 

    if (visited.contains(current.word)) {
      continue;
    }

    visited.insert(current.word);

    if (current.word == dest && current.k <= k) {
      return path(origin, dest, prev); 
    }

    std::vector<std::string> neighbours = generateEdges(current.word); 

    for (std::string neighbour : neighbours) {

      distanceString next {current.distOrigin + 1 + heuristic(neighbour, dest), current.distOrigin+1, neighbour, current.k};

      if (!bestDistance.contains(next.word) || next.distEnd < bestDistance.at(next.word)) {

        if (!isValid(next.word)) {
          next.k++; 
        }

        if (next.k <= k) {
          bestDistance[next.word] = next.distEnd;
          prev[next.word] = current.word;
          wordQueue.push(next);
        }
        

      }
    }
  }


  return {};
}
