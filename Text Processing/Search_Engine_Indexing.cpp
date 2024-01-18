// A very basic implementation of search engine indexing
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
class SearchEngineIndex {
private:
    std::unordered_map<std::string, std::set<int>> index;
public:
    void indexDocument(int documentId, const std::string& document) {
        std::istringstream iss(document);
        std::string word;
        while (iss >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            index[word].insert(documentId);
        }
    }
    std::set<int> search(const std::string& query) const {
        std::string queryLower = query;
        std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);
        auto it = index.find(queryLower);
        if (it != index.end()) {
            return it->second;
        } else {
            return {}; 
        }
    }
};
int main() {
    SearchEngineIndex searchIndex;
    searchIndex.indexDocument(1, "A sample document for the search engine.");
    searchIndex.indexDocument(2, "This shows how to index documents.");
    searchIndex.indexDocument(3, "Indexing is essential for search engine.");
    std::string query1 = "search";
    std::string query2 = "document";
    std::cout << "Search for '" << query1 << "':" << std::endl;
    auto result1 = searchIndex.search(query1);
    for (int documentId : result1) {
        std::cout << "Document " << documentId << std::endl;
    }
    std::cout << "\nSearch for '" << query2 << "':" << std::endl;
    auto result2 = searchIndex.search(query2);
    for (int documentId : result2) {
        std::cout << "Document " << documentId << std::endl;
    }
    return 0;
}
