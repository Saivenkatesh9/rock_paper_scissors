#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Candidate {
    string name;
    int votes;
};

class Election {
private:
    vector<Candidate> candidates;

public:
    void addCandidate(const string& name) {
        candidates.push_back({name, 0});
    }

    void displayCandidates() {
        cout << "Candidates:" << endl;
        for (size_t i = 0; i < candidates.size(); ++i) {
            cout << i + 1 << ". " << candidates[i].name << endl;
        }
    }

    void vote(int candidateIndex) {
        if (candidateIndex >= 0 && candidateIndex < candidates.size()) {
            candidates[candidateIndex].votes++;
            cout << "Vote for " << candidates[candidateIndex].name << " recorded." << endl;
        } else {
            cout << "Invalid candidate index." << endl;
        }
    }

    void displayResults() {
        cout << "Election Results:" << endl;
        for (const Candidate& candidate : candidates) {
            cout << candidate.name << ": " << candidate.votes << " votes" << endl;
        }
    }
};

int main() {
    Election election;
    
    election.addCandidate("Candidate 1");
    election.addCandidate("Candidate 2");
    election.addCandidate("Candidate 3");
    
    while (true) {
        cout << "1. Display Candidates" << endl;
        cout << "2. Vote" << endl;
        cout << "3. Display Results" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                election.displayCandidates();
                break;
            case 2:
                int candidateIndex;
                cout << "Enter the candidate number to vote for: ";
                cin >> candidateIndex;
                election.vote(candidateIndex - 1);
                break;
            case 3:
                election.displayResults();
                break;
            case 4:
                cout << "Exiting the election system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

