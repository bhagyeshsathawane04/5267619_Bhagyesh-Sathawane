#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int calculate_swaps(vector<int> arr, vector<int> sorted_arr) {
    int swaps = 0;
    int n = arr.size();

    // Create a map to store the current index of each value
    map<int, int> current_pos;
    for (int i = 0; i < n; i++) {
        current_pos[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted_arr[i]) {
            swaps++;
            int original_val = arr[i];
            int correct_val = sorted_arr[i];
            int correct_val_pos = current_pos[correct_val];
            
            // Swap in the arr
            swap(arr[i], arr[correct_val_pos]);
            
            // Update the map
            current_pos[correct_val] = i;
            current_pos[original_val] = correct_val_pos;
        }
    }
    return swaps;
}
/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
vector<int> arr_asc = arr;
    sort(arr_asc.begin(), arr_asc.end());
    
    vector<int> arr_desc = arr_asc;
    reverse(arr_desc.begin(), arr_desc.end());
    
    int swaps_asc = calculate_swaps(arr, arr_asc);
    int swaps_desc = calculate_swaps(arr, arr_desc);
    
    return min(swaps_asc, swaps_desc);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
