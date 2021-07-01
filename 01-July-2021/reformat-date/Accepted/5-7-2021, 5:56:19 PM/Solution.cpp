// https://leetcode.com/problems/reformat-date

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}

class Solution {
public:
    string reformatDate(string date) {
        map<string, string> months = {
                {"Jan", "01"},
                {"Feb", "02"},
                {"Mar", "03"},
                {"Apr", "04"},
                {"May", "05"},
                {"Jun", "06"},
                {"Jul", "07"},
                {"Aug", "08"},
                {"Sep", "09"},
                {"Oct", "10"},
                {"Nov", "11"},
                {"Dec", "12"}
        };
        auto d = splitWord(date);
        string day = d[0], month = d[1], year = d[2];
        month = months[month];
        day = (day.size() == 3) ? ("0" + day.substr(0, 1)) : day.substr(0, 2);
        return year + "-" + month + "-" + day;
    }
};