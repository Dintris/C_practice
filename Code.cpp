#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Person {

public:

        void ChangeFirstName(int year, const string& first_name)
        {
                First[year] = first_name;
                if (HistoryFirst.count(year) == 0)
                {
                        HistoryFirst[year].push_back(first_name);
                }

        }

        void ChangeLastName(int year, const string& last_name)
        {
                Last[year] = last_name;
                if (HistoryLast.count(year) == 0)
                {
                        HistoryLast[year].push_back(last_name);
                }
        }

        string GetFullName(int year)
        {
                string firstname = Find(year, First);
                string lastname  = Find(year,  Last);

                if (firstname.empty() && lastname.empty())
                {
                        return "Incognito";
                }
                else if (firstname.empty())
                {
                        return lastname + " with unknown first name";
                }
                else if (lastname.empty())
                {
                        return firstname + " with unknown last name";
                }
                return  firstname + " " + lastname;
        }

        string GetFullNameWithHistory(int year)
        {
                string firstname = Find(year, First);
                string lastname  = Find(year,  Last);
                string Histfirst;
                string HistLast;



        }

private:

        map<int, string> First;
        map<int, string> Last;
        map<int, vector<string>> HistoryFirst;
        map<int, vector<string>> HistoryLast;

        string Find(int year, map<int, string>& m)
        {
                string lastdata;
                if (m.count(year) == 0)
                {
                        for (const auto& item : m)
                        {
                                if (item.first > year)
                                {
                                        return lastdata;
                                }
                                lastdata = item.second;
                        }
                        return lastdata;
                }
                return m[year];
        }

        string FindHistory(int year, map<int, vector<string>>& m)
        {

        }

};


int main() {
        Person person;
        person.ChangeFirstName(1965, "Polina");
          person.ChangeLastName(1967, "Sergeeva");
          for (int year : {1900, 1965, 1990}) {
            cout << person.GetFullName(year) << endl;
          }

          person.ChangeFirstName(1970, "Appolinaria");
          for (int year : {1969, 1970}) {
            cout << person.GetFullName(year) << endl;
          }

          person.ChangeLastName(1968, "Volkova");
          for (int year : {1969, 1970}) {
            cout << person.GetFullName(year) << endl;
          }


    return 0;
}
