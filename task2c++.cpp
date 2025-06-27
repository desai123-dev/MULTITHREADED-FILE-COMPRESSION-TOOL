#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

mutex mtx;

// Run-Length Encoding Compression Logic
string runLengthEncode(const string& str) {
    string encoded = "";
    int n = str.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        encoded += str[i] + to_string(count);
    }
    return encoded;
}

// Thread Function
void compressPart(const string& part, string& result) {
    string encoded = runLengthEncode(part);
    lock_guard<mutex> lock(mtx); // prevent race conditions
    result += encoded;
}

// Multithreaded Compression Handler
void compressFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    if (!in.is_open()) {
        cerr << "❌ Error: Cannot open input file.\n";
        return;
    }

    // Read file content
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    // Divide content for threads
    int parts = 4;
    vector<thread> threads;
    vector<string> substrings(parts);
    string result = "";

    size_t partSize = content.size() / parts;
    for (int i = 0; i < parts; i++) {
        substrings[i] = content.substr(i * partSize, (i == parts - 1) ? string::npos : partSize);
    }

    auto start = chrono::high_resolution_clock::now();

    // Launch threads
    for (int i = 0; i < parts; i++) {
        threads.emplace_back(compressPart, substrings[i], ref(result));
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Write compressed output
    ofstream out(outputFile);
    out << result;
    out.close();

    cout << "✅ Compression complete.\n";
    cout << "📁 Compressed output saved to: " << outputFile << endl;
    cout << "⏱️ Time taken: " << duration.count() << " ms\n";
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "compressed.txt";

    // Optional: create sample input if not already present
    ofstream sample(inputFile);
    sample << "AAABBBCCCCDDDDDDAAEEEEEEEFFGGGGGHHHIIIIIIJ"; // Sample repeated characters
    sample.close();

    cout << "🔧 Starting multithreaded compression...\n";
    compressFile(inputFile, outputFile);

    // Optional: Show output content
    ifstream in(outputFile);
    cout << "\n🗃️ Compressed Data:\n";
    cout << in.rdbuf();
    in.close();

    return 0;
}
